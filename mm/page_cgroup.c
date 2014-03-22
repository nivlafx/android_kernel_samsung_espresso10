#include <linux/mm.h>
#include <linux/mmzone.h>
#include <linux/bootmem.h>
#include <linux/bit_spinlock.h>
#include <linux/page_cgroup.h>
#include <linux/hash.h>
#include <linux/slab.h>
#include <linux/memory.h>
#include <linux/vmalloc.h>
#include <linux/cgroup.h>
#include <linux/swapops.h>
#include <linux/kmemleak.h>

static void __meminit init_page_cgroup(struct page_cgroup *pc, unsigned long id)
{
	pc->flags = 0;
	set_page_cgroup_array_id(pc, id);
	pc->mem_cgroup = NULL;
	INIT_LIST_HEAD(&pc->lru);
}
static unsigned long total_usage;

#if !defined(CONFIG_SPARSEMEM)

void __meminit pgdat_page_cgroup_init(struct pglist_data *pgdat)
{
	pgdat->node_page_cgroup = NULL;
}

struct page_cgroup *lookup_page_cgroup(struct page *page)
{
	unsigned long pfn = page_to_pfn(page);
	unsigned long offset;
	struct page_cgroup *base;

	base = NODE_DATA(page_to_nid(page))->node_page_cgroup;
	if (unlikely(!base))
		return NULL;

	offset = pfn - NODE_DATA(page_to_nid(page))->node_start_pfn;
	return base + offset;
}

struct page *lookup_cgroup_page(struct page_cgroup *pc)
{
	unsigned long pfn;
	struct page *page;
	pg_data_t *pgdat;

	pgdat = NODE_DATA(page_cgroup_array_id(pc));
	pfn = pc - pgdat->node_page_cgroup + pgdat->node_start_pfn;
	page = pfn_to_page(pfn);
	VM_BUG_ON(pc != lookup_page_cgroup(page));
	return page;
}

static int __init alloc_node_page_cgroup(int nid)
{
	struct page_cgroup *base, *pc;
	unsigned long table_size;
	unsigned long start_pfn, nr_pages, index;

	start_pfn = NODE_DATA(nid)->node_start_pfn;
	nr_pages = NODE_DATA(nid)->node_spanned_pages;

	if (!nr_pages)
		return 0;

	table_size = sizeof(struct page_cgroup) * nr_pages;

	base = __alloc_bootmem_node_nopanic(NODE_DATA(nid),
			table_size, PAGE_SIZE, __pa(MAX_DMA_ADDRESS));
	if (!base)
		return -ENOMEM;
	for (index = 0; index < nr_pages; index++) {
		pc = base + index;
		init_page_cgroup(pc, nid);
	}
	NODE_DATA(nid)->node_page_cgroup = base;
	total_usage += table_size;
	return 0;
}

void __init page_cgroup_init_flatmem(void)
{

	int nid, fail;

	if (mem_cgroup_disabled())
		return;

	for_each_online_node(nid)  {
		fail = alloc_node_page_cgroup(nid);
		if (fail)
			goto fail;
	}
	printk(KERN_INFO "allocated %ld bytes of page_cgroup\n", total_usage);
	printk(KERN_INFO "please try 'cgroup_disable=memory' option if you"
	" don't want memory cgroups\n");
	return;
fail:
	printk(KERN_CRIT "allocation of page_cgroup failed.\n");
	printk(KERN_CRIT "please try 'cgroup_disable=memory' boot option\n");
	panic("Out of memory");
}

#else /* CONFIG_FLAT_NODE_MEM_MAP */

struct page_cgroup *lookup_page_cgroup(struct page *page)
{
	unsigned long pfn = page_to_pfn(page);
	struct mem_section *section = __pfn_to_section(pfn);

	if (!section->page_cgroup)
		return NULL;
	return section->page_cgroup + pfn;
}

struct page *lookup_cgroup_page(struct page_cgroup *pc)
{
	struct mem_section *section;
	struct page *page;
	unsigned long nr;

	nr = page_cgroup_array_id(pc);
	section = __nr_to_section(nr);
	page = pfn_to_page(pc - section->page_cgroup);
	VM_BUG_ON(pc != lookup_page_cgroup(page));
	return page;
}

static void *__meminit alloc_page_cgroup(size_t size, int nid)
{
	void *addr = NULL;

	addr = alloc_pages_exact_nid(nid, size, GFP_KERNEL | __GFP_NOWARN);
	if (addr)
		return addr;

	if (node_state(nid, N_HIGH_MEMORY))
		addr = vmalloc_node(size, nid);
	else
		addr = vmalloc(size);

	return addr;
}

#ifdef CONFIG_MEMORY_HOTPLUG
static void free_page_cgroup(void *addr)
{
	if (is_vmalloc_addr(addr)) {
		vfree(addr);
	} else {
		struct page *page = virt_to_page(addr);
		size_t table_size =
			sizeof(struct page_cgroup) * PAGES_PER_SECTION;

		BUG_ON(PageReserved(page));
		free_pages_exact(addr, table_size);
	}
}
#endif

static int __meminit init_section_page_cgroup(unsigned long pfn, int nid)
{
	struct page_cgroup *base, *pc;
	struct mem_section *section;
	unsigned long table_size;
	unsigned long nr;
	int index;

	nr = pfn_to_section_nr(pfn);
	section = __nr_to_section(nr);

	if (section->page_cgroup)
		return 0;

	table_size = sizeof(struct page_cgroup) * PAGES_PER_SECTION;
	base = alloc_page_cgroup(table_size, nid);

	/*
	 * The value stored in section->page_cgroup is (base - pfn)
	 * and it does not point to the memory block allocated above,
	 * causing kmemleak false positives.
	 */
	kmemleak_not_leak(base);

	if (!base) {
		printk(KERN_ERR "page cgroup allocation failure\n");
		return -ENOMEM;
	}

	for (index = 0; index < PAGES_PER_SECTION; index++) {
		pc = base + index;
		init_page_cgroup(pc, nr);
	}
	/*
	 * The passed "pfn" may not be aligned to SECTION.  For the calculation
	 * we need to apply a mask.
	 */
	pfn &= PAGE_SECTION_MASK;
	section->page_cgroup = base - pfn;
	total_usage += table_size;
	return 0;
}
#ifdef CONFIG_MEMORY_HOTPLUG
void __free_page_cgroup(unsigned long pfn)
{
	struct mem_section *ms;
	struct page_cgroup *base;

	ms = __pfn_to_section(pfn);
	if (!ms || !ms->page_cgroup)
		return;
	base = ms->page_cgroup + pfn;
	free_page_cgroup(base);
	ms->page_cgroup = NULL;
}

int __meminit online_page_cgroup(unsigned long start_pfn,
			unsigned long nr_pages,
			int nid)
{
	unsigned long start, end, pfn;
	int fail = 0;

	start = start_pfn & ~(PAGES_PER_SECTION - 1);
	end = ALIGN(start_pfn + nr_pages, PAGES_PER_SECTION);

	if (nid == -1) {
		/*
		 * In this case, "nid" already exists and contains valid memory.
		 * "start_pfn" passed to us is a pfn which is an arg for
		 * online__pages(), and start_pfn should exist.
		 */
		nid = pfn_to_nid(start_pfn);
		VM_BUG_ON(!node_state(nid, N_ONLINE));
	}

	for (pfn = start; !fail && pfn < end; pfn += PAGES_PER_SECTION) {
		if (!pfn_present(pfn))
			continue;
		fail = init_section_page_cgroup(pfn, nid);
	}
	if (!fail)
		return 0;

	/* rollback */
	for (pfn = start; pfn < end; pfn += PAGES_PER_SECTION)
		__free_page_cgroup(pfn);

	return -ENOMEM;
}

int __meminit offline_page_cgroup(unsigned long start_pfn,
		unsigned long nr_pages, int nid)
{
	unsigned long start, end, pfn;

	start = start_pfn & ~(PAGES_PER_SECTION - 1);
	end = ALIGN(start_pfn + nr_pages, PAGES_PER_SECTION);

	for (pfn = start; pfn < end; pfn += PAGES_PER_SECTION)
		__free_page_cgroup(pfn);
	return 0;

}

static int __meminit page_cgroup_callback(struct notifier_block *self,
			       unsigned long action, void *arg)
{
	struct memory_notify *mn = arg;
	int ret = 0;
	switch (action) {
	case MEM_GOING_ONLINE:
		ret = online_page_cgroup(mn->start_pfn,
				   mn->nr_pages, mn->status_change_nid);
		break;
	case MEM_OFFLINE:
		offline_page_cgroup(mn->start_pfn,
				mn->nr_pages, mn->status_change_nid);
		break;
	case MEM_CANCEL_ONLINE:
	case MEM_GOING_OFFLINE:
		break;
	case MEM_ONLINE:
	case MEM_CANCEL_OFFLINE:
		break;
	}

	return notifier_from_errno(ret);
}

#endif

void __init page_cgroup_init(void)
{
	unsigned long pfn;
	int nid;

	if (mem_cgroup_disabled())
		return;

	for_each_node_state(nid, N_HIGH_MEMORY) {
		unsigned long start_pfn, end_pfn;

		start_pfn = node_start_pfn(nid);
		end_pfn = node_end_pfn(nid);
		/*
		 * start_pfn and end_pfn may not be aligned to SECTION and the
		 * page->flags of out of node pages are not initialized.  So we
		 * scan [start_pfn, the biggest section's pfn < end_pfn) here.
		 */
		for (pfn = start_pfn;
		     pfn < end_pfn;
                     pfn = ALIGN(pfn + 1, PAGES_PER_SECTION)) {

			if (!pfn_valid(pfn))
				continue;
			/*
			 * Nodes's pfns can be overlapping.
			 * We know some arch can have a nodes layout such as
			 * -------------pfn-------------->
			 * N0 | N1 | N2 | N0 | N1 | N2|....
			 */
			if (pfn_to_nid(pfn) != nid)
				continue;
			if (init_section_page_cgroup(pfn, nid))
				goto oom;
		}
	}
	hotplug_memory_notifier(page_cgroup_callback, 0);
	printk(KERN_INFO "allocated %ld bytes of page_cgroup\n", total_usage);
	printk(KERN_INFO "please try 'cgroup_disable=memory' option if you "
			 "don't want memory cgroups\n");
	return;
oom:
	printk(KERN_CRIT "try 'cgroup_disable=memory' boot option\n");
	panic("Out of memory");
}

void __meminit pgdat_page_cgroup_init(struct pglist_data *pgdat)
{
	return;
}

#endif

#ifdef CONFIG_CGROUP_MEM_RES_CTLR_SWAP

static DEFINE_MUTEX(swap_cgroup_mutex);
struct swap_cgroup_ctrl {
	struct page **map;
	unsigned long length;
	spinlock_t	lock;
};

struct swap_cgroup_ctrl swap_cgroup_ctrl[MAX_SWAPFILES];

struct swap_cgroup {
	unsigned short		id;
};
#define SC_PER_PAGE	(PAGE_SIZE/sizeof(struct swap_cgroup))
#define SC_POS_MASK	(SC_PER_PAGE - 1)

/*
 * SwapCgroup implements "lookup" and "exchange" operations.
 * In typical usage, this swap_cgroup is accessed via memcg's charge/uncharge
 * against SwapCache. At swap_free(), this is accessed directly from swap.
 *
 * This means,
 *  - we have no race in "exchange" when we're accessed via SwapCache because
 *    SwapCache(and its swp_entry) is under lock.
 *  - When called via swap_free(), there is no user of this entry and no race.
 * Then, we don't need lock around "exchange".
 *
 * TODO: we can push these buffers out to HIGHMEM.
 */

/*
 * allocate buffer for swap_cgroup.
 */
static int swap_cgroup_prepare(int type)
{
	struct page *page;
	struct swap_cgroup_ctrl *ctrl;
	unsigned long idx, max;

	ctrl = &swap_cgroup_ctrl[type];

	for (idx = 0; idx < ctrl->length; idx++) {
		page = alloc_page(GFP_KERNEL | __GFP_ZERO);
		if (!page)
			goto not_enough_page;
		ctrl->map[idx] = page;
	}
	return 0;
not_enough_page:
	max = idx;
	for (idx = 0; idx < max; idx++)
		__free_page(ctrl->map[idx]);

	return -ENOMEM;
}

/**
 * swap_cgroup_cmpxchg - cmpxchg mem_cgroup's id for this swp_entry.
 * @end: swap entry to be cmpxchged
 * @old: old id
 * @new: new id
 *
 * Returns old id at success, 0 at failure.
 * (There is no mem_cgroup using 0 as its id)
 */
unsigned short swap_cgroup_cmpxchg(swp_entry_t ent,
					unsigned short old, unsigned short new)
{
	int type = swp_type(ent);
	unsigned long offset = swp_offset(ent);
	unsigned long idx = offset / SC_PER_PAGE;
	unsigned long pos = offset & SC_POS_MASK;
	struct swap_cgroup_ctrl *ctrl;
	struct page *mappage;
	struct swap_cgroup *sc;
	unsigned long flags;
	unsigned short retval;

	ctrl = &swap_cgroup_ctrl[type];

	mappage = ctrl->map[idx];
	sc = page_address(mappage);
	sc += pos;
	spin_lock_irqsave(&ctrl->lock, flags);
	retval = sc->id;
	if (retval == old)
		sc->id = new;
	else
		retval = 0;
	spin_unlock_irqrestore(&ctrl->lock, flags);
	return retval;
}

/**
 * swap_cgroup_record - record mem_cgroup for this swp_entry.
 * @ent: swap entry to be recorded into
 * @mem: mem_cgroup to be recorded
 *
 * Returns old value at success, 0 at failure.
 * (Of course, old value can be 0.)
 */
unsigned short swap_cgroup_record(swp_entry_t ent, unsigned short id)
{
	int type = swp_type(ent);
	unsigned long offset = swp_offset(ent);
	unsigned long idx = offset / SC_PER_PAGE;
	unsigned long pos = offset & SC_POS_MASK;
	struct swap_cgroup_ctrl *ctrl;
	struct page *mappage;
	struct swap_cgroup *sc;
	unsigned short old;
	unsigned long flags;

	ctrl = &swap_cgroup_ctrl[type];

	mappage = ctrl->map[idx];
	sc = page_address(mappage);
	sc += pos;
	spin_lock_irqsave(&ctrl->lock, flags);
	old = sc->id;
	sc->id = id;
	spin_unlock_irqrestore(&ctrl->lock, flags);

	return old;
}

/**
 * lookup_swap_cgroup - lookup mem_cgroup tied to swap entry
 * @ent: swap entry to be looked up.
 *
 * Returns CSS ID of mem_cgroup at success. 0 at failure. (0 is invalid ID)
 */
unsigned short lookup_swap_cgroup(swp_entry_t ent)
{
	int type = swp_type(ent);
	unsigned long offset = swp_offset(ent);
	unsigned long idx = offset / SC_PER_PAGE;
	unsigned long pos = offset & SC_POS_MASK;
	struct swap_cgroup_ctrl *ctrl;
	struct page *mappage;
	struct swap_cgroup *sc;
	unsigned short ret;

	ctrl = &swap_cgroup_ctrl[type];
	mappage = ctrl->map[idx];
	sc = page_address(mappage);
	sc += pos;
	ret = sc->id;
	return ret;
}

int swap_cgroup_swapon(int type, unsigned long max_pages)
{
	void *array;
	unsigned long array_size;
	unsigned long length;
	struct swap_cgroup_ctrl *ctrl;

	if (!do_swap_account)
		return 0;

	length = DIV_ROUND_UP(max_pages, SC_PER_PAGE);
	array_size = length * sizeof(void *);

	array = vmalloc(array_size);
	if (!array)
		goto nomem;

	memset(array, 0, array_size);
	ctrl = &swap_cgroup_ctrl[type];
	mutex_lock(&swap_cgroup_mutex);
	ctrl->length = length;
	ctrl->map = array;
	spin_lock_init(&ctrl->lock);
	if (swap_cgroup_prepare(type)) {
		/* memory shortage */
		ctrl->map = NULL;
		ctrl->length = 0;
		mutex_unlock(&swap_cgroup_mutex);
		vfree(array);
		goto nomem;
	}
	mutex_unlock(&swap_cgroup_mutex);

	return 0;
nomem:
	printk(KERN_INFO "couldn't allocate enough memory for swap_cgroup.\n");
	printk(KERN_INFO
		"swap_cgroup can be disabled by noswapaccount boot option\n");
	return -ENOMEM;
}

void swap_cgroup_swapoff(int type)
{
	struct page **map;
	unsigned long i, length;
	struct swap_cgroup_ctrl *ctrl;

	if (!do_swap_account)
		return;

	mutex_lock(&swap_cgroup_mutex);
	ctrl = &swap_cgroup_ctrl[type];
	map = ctrl->map;
	length = ctrl->length;
	ctrl->map = NULL;
	ctrl->length = 0;
	mutex_unlock(&swap_cgroup_mutex);

	if (map) {
		for (i = 0; i < length; i++) {
			struct page *page = map[i];
			if (page)
				__free_page(page);
		}
		vfree(map);
	}
}

#endif
