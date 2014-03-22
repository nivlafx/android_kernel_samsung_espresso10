/*
 *
 * arch/arm/mach-u300/include/mach/syscon.h
 *
 *
 * Copyright (C) 2008 ST-Ericsson AB
 *
 * Author: Rickard Andersson <rickard.andersson@stericsson.com>
 */

#ifndef __MACH_SYSCON_H
#define __MACH_SYSCON_H

/*
 * All register defines for SYSCON registers that concerns individual
 * block clocks and reset lines are registered here. This is because
 * we don't want any other file to try to fool around with this stuff.
 */

/* APP side SYSCON registers */
/* TODO: this is incomplete. Add all from asic_syscon_map.h eventually. */
/* CLK Control Register 16bit (R/W) */
#define U300_SYSCON_CCR						(0x0000)
#define U300_SYSCON_CCR_I2S1_USE_VCXO				(0x0040)
#define U300_SYSCON_CCR_I2S0_USE_VCXO				(0x0020)
#define U300_SYSCON_CCR_TURN_VCXO_ON				(0x0008)
#define U300_SYSCON_CCR_CLKING_PERFORMANCE_MASK			(0x0007)
#define U300_SYSCON_CCR_CLKING_PERFORMANCE_LOW_POWER		(0x04)
#define U300_SYSCON_CCR_CLKING_PERFORMANCE_LOW			(0x03)
#define U300_SYSCON_CCR_CLKING_PERFORMANCE_INTERMEDIATE		(0x02)
#define U300_SYSCON_CCR_CLKING_PERFORMANCE_HIGH			(0x01)
#define U300_SYSCON_CCR_CLKING_PERFORMANCE_BEST			(0x00)
/* CLK Status Register 16bit (R/W) */
#define U300_SYSCON_CSR						(0x0004)
#define U300_SYSCON_CSR_PLL208_LOCK_IND				(0x0002)
#define U300_SYSCON_CSR_PLL13_LOCK_IND				(0x0001)
/* Reset lines for SLOW devices 16bit (R/W) */
#define U300_SYSCON_RSR						(0x0014)
#ifdef CONFIG_MACH_U300_BS335
#define U300_SYSCON_RSR_PPM_RESET_EN				(0x0200)
#endif
#define U300_SYSCON_RSR_ACC_TMR_RESET_EN			(0x0100)
#define U300_SYSCON_RSR_APP_TMR_RESET_EN			(0x0080)
#define U300_SYSCON_RSR_RTC_RESET_EN				(0x0040)
#define U300_SYSCON_RSR_KEYPAD_RESET_EN				(0x0020)
#define U300_SYSCON_RSR_GPIO_RESET_EN				(0x0010)
#define U300_SYSCON_RSR_EH_RESET_EN				(0x0008)
#define U300_SYSCON_RSR_BTR_RESET_EN				(0x0004)
#define U300_SYSCON_RSR_UART_RESET_EN				(0x0002)
#define U300_SYSCON_RSR_SLOW_BRIDGE_RESET_EN			(0x0001)
/* Reset lines for FAST devices 16bit (R/W) */
#define U300_SYSCON_RFR						(0x0018)
#ifdef CONFIG_MACH_U300_BS335
#define U300_SYSCON_RFR_UART1_RESET_ENABLE			(0x0080)
#endif
#define U300_SYSCON_RFR_SPI_RESET_ENABLE			(0x0040)
#define U300_SYSCON_RFR_MMC_RESET_ENABLE			(0x0020)
#define U300_SYSCON_RFR_PCM_I2S1_RESET_ENABLE			(0x0010)
#define U300_SYSCON_RFR_PCM_I2S0_RESET_ENABLE			(0x0008)
#define U300_SYSCON_RFR_I2C1_RESET_ENABLE			(0x0004)
#define U300_SYSCON_RFR_I2C0_RESET_ENABLE			(0x0002)
#define U300_SYSCON_RFR_FAST_BRIDGE_RESET_ENABLE		(0x0001)
/* Reset lines for the rest of the peripherals 16bit (R/W) */
#define U300_SYSCON_RRR						(0x001c)
#ifdef CONFIG_MACH_U300_BS335
#define U300_SYSCON_RRR_CDS_RESET_EN				(0x4000)
#define U300_SYSCON_RRR_ISP_RESET_EN				(0x2000)
#endif
#define U300_SYSCON_RRR_INTCON_RESET_EN				(0x1000)
#define U300_SYSCON_RRR_MSPRO_RESET_EN				(0x0800)
#define U300_SYSCON_RRR_XGAM_RESET_EN				(0x0100)
#define U300_SYSCON_RRR_XGAM_VC_SYNC_RESET_EN			(0x0080)
#define U300_SYSCON_RRR_NANDIF_RESET_EN				(0x0040)
#define U300_SYSCON_RRR_EMIF_RESET_EN				(0x0020)
#define U300_SYSCON_RRR_DMAC_RESET_EN				(0x0010)
#define U300_SYSCON_RRR_CPU_RESET_EN				(0x0008)
#define U300_SYSCON_RRR_APEX_RESET_EN				(0x0004)
#define U300_SYSCON_RRR_AHB_RESET_EN				(0x0002)
#define U300_SYSCON_RRR_AAIF_RESET_EN				(0x0001)
/* Clock enable for SLOW peripherals 16bit (R/W) */
#define U300_SYSCON_CESR					(0x0020)
#ifdef CONFIG_MACH_U300_BS335
#define U300_SYSCON_CESR_PPM_CLK_EN				(0x0200)
#endif
#define U300_SYSCON_CESR_ACC_TMR_CLK_EN				(0x0100)
#define U300_SYSCON_CESR_APP_TMR_CLK_EN				(0x0080)
#define U300_SYSCON_CESR_KEYPAD_CLK_EN				(0x0040)
#define U300_SYSCON_CESR_GPIO_CLK_EN				(0x0010)
#define U300_SYSCON_CESR_EH_CLK_EN				(0x0008)
#define U300_SYSCON_CESR_BTR_CLK_EN				(0x0004)
#define U300_SYSCON_CESR_UART_CLK_EN				(0x0002)
#define U300_SYSCON_CESR_SLOW_BRIDGE_CLK_EN			(0x0001)
/* Clock enable for FAST peripherals 16bit (R/W) */
#define U300_SYSCON_CEFR					(0x0024)
#ifdef CONFIG_MACH_U300_BS335
#define U300_SYSCON_CEFR_UART1_CLK_EN				(0x0200)
#endif
#define U300_SYSCON_CEFR_I2S1_CORE_CLK_EN			(0x0100)
#define U300_SYSCON_CEFR_I2S0_CORE_CLK_EN			(0x0080)
#define U300_SYSCON_CEFR_SPI_CLK_EN				(0x0040)
#define U300_SYSCON_CEFR_MMC_CLK_EN				(0x0020)
#define U300_SYSCON_CEFR_I2S1_CLK_EN    			(0x0010)
#define U300_SYSCON_CEFR_I2S0_CLK_EN     			(0x0008)
#define U300_SYSCON_CEFR_I2C1_CLK_EN     			(0x0004)
#define U300_SYSCON_CEFR_I2C0_CLK_EN     			(0x0002)
#define U300_SYSCON_CEFR_FAST_BRIDGE_CLK_EN			(0x0001)
/* Clock enable for the rest of the peripherals 16bit (R/W) */
#define U300_SYSCON_CERR					(0x0028)
#ifdef CONFIG_MACH_U300_BS335
#define U300_SYSCON_CERR_CDS_CLK_EN				(0x2000)
#define U300_SYSCON_CERR_ISP_CLK_EN				(0x1000)
#endif
#define U300_SYSCON_CERR_MSPRO_CLK_EN				(0x0800)
#define U300_SYSCON_CERR_AHB_SUBSYS_BRIDGE_CLK_EN		(0x0400)
#define U300_SYSCON_CERR_SEMI_CLK_EN				(0x0200)
#define U300_SYSCON_CERR_XGAM_CLK_EN				(0x0100)
#define U300_SYSCON_CERR_VIDEO_ENC_CLK_EN			(0x0080)
#define U300_SYSCON_CERR_NANDIF_CLK_EN				(0x0040)
#define U300_SYSCON_CERR_EMIF_CLK_EN				(0x0020)
#define U300_SYSCON_CERR_DMAC_CLK_EN				(0x0010)
#define U300_SYSCON_CERR_CPU_CLK_EN				(0x0008)
#define U300_SYSCON_CERR_APEX_CLK_EN				(0x0004)
#define U300_SYSCON_CERR_AHB_CLK_EN				(0x0002)
#define U300_SYSCON_CERR_AAIF_CLK_EN				(0x0001)
/* Single block clock enable 16bit (-/W) */
#define U300_SYSCON_SBCER					(0x002c)
#ifdef CONFIG_MACH_U300_BS335
#define U300_SYSCON_SBCER_PPM_CLK_EN				(0x0009)
#endif
#define U300_SYSCON_SBCER_ACC_TMR_CLK_EN			(0x0008)
#define U300_SYSCON_SBCER_APP_TMR_CLK_EN			(0x0007)
#define U300_SYSCON_SBCER_KEYPAD_CLK_EN				(0x0006)
#define U300_SYSCON_SBCER_GPIO_CLK_EN				(0x0004)
#define U300_SYSCON_SBCER_EH_CLK_EN				(0x0003)
#define U300_SYSCON_SBCER_BTR_CLK_EN				(0x0002)
#define U300_SYSCON_SBCER_UART_CLK_EN				(0x0001)
#define U300_SYSCON_SBCER_SLOW_BRIDGE_CLK_EN			(0x0000)
#ifdef CONFIG_MACH_U300_BS335
#define U300_SYSCON_SBCER_UART1_CLK_EN				(0x0019)
#endif
#define U300_SYSCON_SBCER_I2S1_CORE_CLK_EN			(0x0018)
#define U300_SYSCON_SBCER_I2S0_CORE_CLK_EN			(0x0017)
#define U300_SYSCON_SBCER_SPI_CLK_EN				(0x0016)
#define U300_SYSCON_SBCER_MMC_CLK_EN				(0x0015)
#define U300_SYSCON_SBCER_I2S1_CLK_EN				(0x0014)
#define U300_SYSCON_SBCER_I2S0_CLK_EN				(0x0013)
#define U300_SYSCON_SBCER_I2C1_CLK_EN				(0x0012)
#define U300_SYSCON_SBCER_I2C0_CLK_EN				(0x0011)
#define U300_SYSCON_SBCER_FAST_BRIDGE_CLK_EN			(0x0010)
#ifdef CONFIG_MACH_U300_BS335
#define U300_SYSCON_SBCER_CDS_CLK_EN				(0x002D)
#define U300_SYSCON_SBCER_ISP_CLK_EN				(0x002C)
#endif
#define U300_SYSCON_SBCER_MSPRO_CLK_EN				(0x002B)
#define U300_SYSCON_SBCER_AHB_SUBSYS_BRIDGE_CLK_EN		(0x002A)
#define U300_SYSCON_SBCER_SEMI_CLK_EN				(0x0029)
#define U300_SYSCON_SBCER_XGAM_CLK_EN				(0x0028)
#define U300_SYSCON_SBCER_VIDEO_ENC_CLK_EN			(0x0027)
#define U300_SYSCON_SBCER_NANDIF_CLK_EN				(0x0026)
#define U300_SYSCON_SBCER_EMIF_CLK_EN				(0x0025)
#define U300_SYSCON_SBCER_DMAC_CLK_EN				(0x0024)
#define U300_SYSCON_SBCER_CPU_CLK_EN				(0x0023)
#define U300_SYSCON_SBCER_APEX_CLK_EN				(0x0022)
#define U300_SYSCON_SBCER_AHB_CLK_EN				(0x0021)
#define U300_SYSCON_SBCER_AAIF_CLK_EN				(0x0020)
/* Single block clock disable 16bit (-/W) */
#define U300_SYSCON_SBCDR					(0x0030)
/* Same values as above for SBCER */
/* Clock force SLOW peripherals 16bit (R/W) */
#define U300_SYSCON_CFSR					(0x003c)
#ifdef CONFIG_MACH_U300_BS335
#define U300_SYSCON_CFSR_PPM_CLK_FORCE_EN			(0x0200)
#endif
#define U300_SYSCON_CFSR_ACC_TMR_CLK_FORCE_EN			(0x0100)
#define U300_SYSCON_CFSR_APP_TMR_CLK_FORCE_EN			(0x0080)
#define U300_SYSCON_CFSR_KEYPAD_CLK_FORCE_EN			(0x0020)
#define U300_SYSCON_CFSR_GPIO_CLK_FORCE_EN			(0x0010)
#define U300_SYSCON_CFSR_EH_CLK_FORCE_EN			(0x0008)
#define U300_SYSCON_CFSR_BTR_CLK_FORCE_EN			(0x0004)
#define U300_SYSCON_CFSR_UART_CLK_FORCE_EN			(0x0002)
#define U300_SYSCON_CFSR_SLOW_BRIDGE_CLK_FORCE_EN		(0x0001)
/* Clock force FAST peripherals 16bit (R/W) */
#define U300_SYSCON_CFFR					(0x40)
/* Values not defined. Define if you want to use them. */
/* Clock force the rest of the peripherals 16bit (R/W) */
#define U300_SYSCON_CFRR					(0x44)
#ifdef CONFIG_MACH_U300_BS335
#define U300_SYSCON_CFRR_CDS_CLK_FORCE_EN			(0x2000)
#define U300_SYSCON_CFRR_ISP_CLK_FORCE_EN			(0x1000)
#endif
#define U300_SYSCON_CFRR_MSPRO_CLK_FORCE_EN			(0x0800)
#define U300_SYSCON_CFRR_AHB_SUBSYS_BRIDGE_CLK_FORCE_EN		(0x0400)
#define U300_SYSCON_CFRR_SEMI_CLK_FORCE_EN			(0x0200)
#define U300_SYSCON_CFRR_XGAM_CLK_FORCE_EN			(0x0100)
#define U300_SYSCON_CFRR_VIDEO_ENC_CLK_FORCE_EN			(0x0080)
#define U300_SYSCON_CFRR_NANDIF_CLK_FORCE_EN			(0x0040)
#define U300_SYSCON_CFRR_EMIF_CLK_FORCE_EN			(0x0020)
#define U300_SYSCON_CFRR_DMAC_CLK_FORCE_EN			(0x0010)
#define U300_SYSCON_CFRR_CPU_CLK_FORCE_EN			(0x0008)
#define U300_SYSCON_CFRR_APEX_CLK_FORCE_EN			(0x0004)
#define U300_SYSCON_CFRR_AHB_CLK_FORCE_EN			(0x0002)
#define U300_SYSCON_CFRR_AAIF_CLK_FORCE_EN			(0x0001)
/* PLL208 Frequency Control 16bit (R/W) */
#define U300_SYSCON_PFCR					(0x48)
#define U300_SYSCON_PFCR_DPLL_MULT_NUM				(0x000F)
/* Power Management Control 16bit (R/W) */
#define U300_SYSCON_PMCR					(0x50)
#define U300_SYSCON_PMCR_DCON_ENABLE				(0x0002)
#define U300_SYSCON_PMCR_PWR_MGNT_ENABLE			(0x0001)
/*
 * All other clocking registers moved to clock.c!
 */
/* Reset Out 16bit (R/W) */
#define U300_SYSCON_RCR						(0x6c)
#define U300_SYSCON_RCR_RESOUT0_RST_N_DISABLE			(0x0001)
/* EMIF Slew Rate Control 16bit (R/W) */
#define U300_SYSCON_SRCLR					(0x70)
#define U300_SYSCON_SRCLR_MASK					(0x03FF)
#define U300_SYSCON_SRCLR_VALUE					(0x03FF)
#define U300_SYSCON_SRCLR_EMIF_1_SLRC_5_B			(0x0200)
#define U300_SYSCON_SRCLR_EMIF_1_SLRC_5_A			(0x0100)
#define U300_SYSCON_SRCLR_EMIF_1_SLRC_4_B			(0x0080)
#define U300_SYSCON_SRCLR_EMIF_1_SLRC_4_A			(0x0040)
#define U300_SYSCON_SRCLR_EMIF_1_SLRC_3_B			(0x0020)
#define U300_SYSCON_SRCLR_EMIF_1_SLRC_3_A			(0x0010)
#define U300_SYSCON_SRCLR_EMIF_1_SLRC_2_B			(0x0008)
#define U300_SYSCON_SRCLR_EMIF_1_SLRC_2_A			(0x0004)
#define U300_SYSCON_SRCLR_EMIF_1_SLRC_1_B			(0x0002)
#define U300_SYSCON_SRCLR_EMIF_1_SLRC_1_A			(0x0001)
/* EMIF Clock Control Register 16bit (R/W) */
#define U300_SYSCON_ECCR					(0x0078)
#define U300_SYSCON_ECCR_MASK					(0x000F)
#define U300_SYSCON_ECCR_EMIF_1_STATIC_CLK_EN_N_DISABLE		(0x0008)
#define U300_SYSCON_ECCR_EMIF_1_RET_OUT_CLK_EN_N_DISABLE	(0x0004)
#define U300_SYSCON_ECCR_EMIF_MEMCLK_RET_EN_N_DISABLE		(0x0002)
#define U300_SYSCON_ECCR_EMIF_SDRCLK_RET_EN_N_DISABLE		(0x0001)
/* PAD MUX Control register 1 (LOW) 16bit (R/W) */
#define U300_SYSCON_PMC1LR					(0x007C)
#define U300_SYSCON_PMC1LR_MASK					(0xFFFF)
#define U300_SYSCON_PMC1LR_CDI_MASK				(0xC000)
#define U300_SYSCON_PMC1LR_CDI_CDI				(0x0000)
#define U300_SYSCON_PMC1LR_CDI_EMIF				(0x4000)
#ifdef CONFIG_MACH_U300_BS335
#define U300_SYSCON_PMC1LR_CDI_CDI2				(0x8000)
#define U300_SYSCON_PMC1LR_CDI_WCDMA_APP_GPIO			(0xC000)
#elif CONFIG_MACH_U300_BS365
#define U300_SYSCON_PMC1LR_CDI_GPIO				(0x8000)
#define U300_SYSCON_PMC1LR_CDI_WCDMA				(0xC000)
#endif
#define U300_SYSCON_PMC1LR_PDI_MASK				(0x3000)
#define U300_SYSCON_PMC1LR_PDI_PDI				(0x0000)
#define U300_SYSCON_PMC1LR_PDI_EGG				(0x1000)
#define U300_SYSCON_PMC1LR_PDI_WCDMA				(0x3000)
#define U300_SYSCON_PMC1LR_MMCSD_MASK				(0x0C00)
#define U300_SYSCON_PMC1LR_MMCSD_MMCSD				(0x0000)
#define U300_SYSCON_PMC1LR_MMCSD_MSPRO				(0x0400)
#define U300_SYSCON_PMC1LR_MMCSD_DSP				(0x0800)
#define U300_SYSCON_PMC1LR_MMCSD_WCDMA				(0x0C00)
#define U300_SYSCON_PMC1LR_ETM_MASK				(0x0300)
#define U300_SYSCON_PMC1LR_ETM_ACC				(0x0000)
#define U300_SYSCON_PMC1LR_ETM_APP				(0x0100)
#define U300_SYSCON_PMC1LR_EMIF_1_CS2_MASK			(0x00C0)
#define U300_SYSCON_PMC1LR_EMIF_1_CS2_STATIC			(0x0000)
#define U300_SYSCON_PMC1LR_EMIF_1_CS2_NFIF			(0x0040)
#define U300_SYSCON_PMC1LR_EMIF_1_CS2_SDRAM			(0x0080)
#define U300_SYSCON_PMC1LR_EMIF_1_CS2_STATIC_2GB		(0x00C0)
#define U300_SYSCON_PMC1LR_EMIF_1_CS1_MASK			(0x0030)
#define U300_SYSCON_PMC1LR_EMIF_1_CS1_STATIC			(0x0000)
#define U300_SYSCON_PMC1LR_EMIF_1_CS1_NFIF			(0x0010)
#define U300_SYSCON_PMC1LR_EMIF_1_CS1_SDRAM			(0x0020)
#define U300_SYSCON_PMC1LR_EMIF_1_CS1_SEMI			(0x0030)
#define U300_SYSCON_PMC1LR_EMIF_1_CS0_MASK			(0x000C)
#define U300_SYSCON_PMC1LR_EMIF_1_CS0_STATIC			(0x0000)
#define U300_SYSCON_PMC1LR_EMIF_1_CS0_NFIF			(0x0004)
#define U300_SYSCON_PMC1LR_EMIF_1_CS0_SDRAM			(0x0008)
#define U300_SYSCON_PMC1LR_EMIF_1_CS0_SEMI			(0x000C)
#define U300_SYSCON_PMC1LR_EMIF_1_MASK				(0x0003)
#define U300_SYSCON_PMC1LR_EMIF_1_STATIC			(0x0000)
#define U300_SYSCON_PMC1LR_EMIF_1_SDRAM0			(0x0001)
#define U300_SYSCON_PMC1LR_EMIF_1_SDRAM1			(0x0002)
#define U300_SYSCON_PMC1LR_EMIF_1				(0x0003)
/* PAD MUX Control register 2 (HIGH) 16bit (R/W) */
#define U300_SYSCON_PMC1HR					(0x007E)
#define U300_SYSCON_PMC1HR_MASK					(0xFFFF)
#define U300_SYSCON_PMC1HR_MISC_2_MASK				(0xC000)
#define U300_SYSCON_PMC1HR_MISC_2_APP_GPIO			(0x0000)
#define U300_SYSCON_PMC1HR_MISC_2_MSPRO				(0x4000)
#define U300_SYSCON_PMC1HR_MISC_2_DSP				(0x8000)
#define U300_SYSCON_PMC1HR_MISC_2_AAIF				(0xC000)
#define U300_SYSCON_PMC1HR_APP_GPIO_2_MASK			(0x3000)
#define U300_SYSCON_PMC1HR_APP_GPIO_2_APP_GPIO			(0x0000)
#define U300_SYSCON_PMC1HR_APP_GPIO_2_NFIF			(0x1000)
#define U300_SYSCON_PMC1HR_APP_GPIO_2_DSP			(0x2000)
#define U300_SYSCON_PMC1HR_APP_GPIO_2_AAIF			(0x3000)
#define U300_SYSCON_PMC1HR_APP_GPIO_1_MASK			(0x0C00)
#define U300_SYSCON_PMC1HR_APP_GPIO_1_APP_GPIO			(0x0000)
#define U300_SYSCON_PMC1HR_APP_GPIO_1_MMC			(0x0400)
#define U300_SYSCON_PMC1HR_APP_GPIO_1_DSP			(0x0800)
#define U300_SYSCON_PMC1HR_APP_GPIO_1_AAIF			(0x0C00)
#define U300_SYSCON_PMC1HR_APP_SPI_CS_2_MASK			(0x0300)
#define U300_SYSCON_PMC1HR_APP_SPI_CS_2_APP_GPIO		(0x0000)
#define U300_SYSCON_PMC1HR_APP_SPI_CS_2_SPI			(0x0100)
#define U300_SYSCON_PMC1HR_APP_SPI_CS_2_AAIF			(0x0300)
#define U300_SYSCON_PMC1HR_APP_SPI_CS_1_MASK			(0x00C0)
#define U300_SYSCON_PMC1HR_APP_SPI_CS_1_APP_GPIO		(0x0000)
#define U300_SYSCON_PMC1HR_APP_SPI_CS_1_SPI			(0x0040)
#define U300_SYSCON_PMC1HR_APP_SPI_CS_1_AAIF			(0x00C0)
#define U300_SYSCON_PMC1HR_APP_SPI_2_MASK			(0x0030)
#define U300_SYSCON_PMC1HR_APP_SPI_2_APP_GPIO			(0x0000)
#define U300_SYSCON_PMC1HR_APP_SPI_2_SPI			(0x0010)
#define U300_SYSCON_PMC1HR_APP_SPI_2_DSP			(0x0020)
#define U300_SYSCON_PMC1HR_APP_SPI_2_AAIF			(0x0030)
#define U300_SYSCON_PMC1HR_APP_UART0_2_MASK			(0x000C)
#define U300_SYSCON_PMC1HR_APP_UART0_2_APP_GPIO			(0x0000)
#define U300_SYSCON_PMC1HR_APP_UART0_2_UART0			(0x0004)
#define U300_SYSCON_PMC1HR_APP_UART0_2_NFIF_CS			(0x0008)
#define U300_SYSCON_PMC1HR_APP_UART0_2_AAIF			(0x000C)
#define U300_SYSCON_PMC1HR_APP_UART0_1_MASK			(0x0003)
#define U300_SYSCON_PMC1HR_APP_UART0_1_APP_GPIO			(0x0000)
#define U300_SYSCON_PMC1HR_APP_UART0_1_UART0			(0x0001)
#define U300_SYSCON_PMC1HR_APP_UART0_1_AAIF			(0x0003)
/* Step one for killing the applications system 16bit (-/W) */
#define U300_SYSCON_KA1R					(0x0080)
#define U300_SYSCON_KA1R_MASK					(0xFFFF)
#define U300_SYSCON_KA1R_VALUE					(0xFFFF)
/* Step two for killing the application system 16bit (-/W) */
#define U300_SYSCON_KA2R					(0x0084)
#define U300_SYSCON_KA2R_MASK					(0xFFFF)
#define U300_SYSCON_KA2R_VALUE					(0xFFFF)
/* MMC/MSPRO frequency divider register 0 16bit (R/W) */
#define U300_SYSCON_MMF0R					(0x90)
#define U300_SYSCON_MMF0R_MASK					(0x00FF)
#define U300_SYSCON_MMF0R_FREQ_0_HIGH_MASK			(0x00F0)
#define U300_SYSCON_MMF0R_FREQ_0_LOW_MASK			(0x000F)
/* MMC/MSPRO frequency divider register 1 16bit (R/W) */
#define U300_SYSCON_MMF1R					(0x94)
#define U300_SYSCON_MMF1R_MASK					(0x00FF)
#define U300_SYSCON_MMF1R_FREQ_1_HIGH_MASK			(0x00F0)
#define U300_SYSCON_MMF1R_FREQ_1_LOW_MASK			(0x000F)
/* AAIF control register 16 bit (R/W) */
#define U300_SYSCON_AAIFCR					(0x98)
#define U300_SYSCON_AAIFCR_MASK					(0x0003)
#define U300_SYSCON_AAIFCR_AASW_CTRL_MASK			(0x0003)
#define U300_SYSCON_AAIFCR_AASW_CTRL_FUNCTIONAL			(0x0000)
#define U300_SYSCON_AAIFCR_AASW_CTRL_MONITORING			(0x0001)
#define U300_SYSCON_AAIFCR_AASW_CTRL_ACC_TO_EXT			(0x0002)
#define U300_SYSCON_AAIFCR_AASW_CTRL_APP_TO_EXT			(0x0003)
/* Clock control for the MMC and MSPRO blocks 16bit (R/W) */
#define U300_SYSCON_MMCR					(0x9C)
#define U300_SYSCON_MMCR_MASK					(0x0003)
#define U300_SYSCON_MMCR_MMC_FB_CLK_SEL_ENABLE			(0x0002)
#define U300_SYSCON_MMCR_MSPRO_FREQSEL_ENABLE			(0x0001)
/* Pull up/down control (R/W) */
#define U300_SYSCON_PUCR					(0x104)
#define U300_SYSCON_PUCR_EMIF_1_WAIT_N_PU_ENABLE		(0x0200)
#define U300_SYSCON_PUCR_EMIF_1_NFIF_READY_PU_ENABLE		(0x0100)
#define U300_SYSCON_PUCR_EMIF_1_16BIT_PU_ENABLE			(0x0080)
#define U300_SYSCON_PUCR_EMIF_1_8BIT_PU_ENABLE			(0x0040)
#define U300_SYSCON_PUCR_KEY_IN_PU_EN_MASK			(0x003F)
/* Padmux 2 control */
#define U300_SYSCON_PMC2R					(0x100)
#define U300_SYSCON_PMC2R_APP_MISC_0_MASK			(0x00C0)
#define U300_SYSCON_PMC2R_APP_MISC_0_APP_GPIO			(0x0000)
#define U300_SYSCON_PMC2R_APP_MISC_0_EMIF_SDRAM			(0x0040)
#define U300_SYSCON_PMC2R_APP_MISC_0_MMC			(0x0080)
#define U300_SYSCON_PMC2R_APP_MISC_0_CDI2			(0x00C0)
#define U300_SYSCON_PMC2R_APP_MISC_1_MASK			(0x0300)
#define U300_SYSCON_PMC2R_APP_MISC_1_APP_GPIO			(0x0000)
#define U300_SYSCON_PMC2R_APP_MISC_1_EMIF_SDRAM			(0x0100)
#define U300_SYSCON_PMC2R_APP_MISC_1_MMC			(0x0200)
#define U300_SYSCON_PMC2R_APP_MISC_1_CDI2			(0x0300)
#define U300_SYSCON_PMC2R_APP_MISC_2_MASK			(0x0C00)
#define U300_SYSCON_PMC2R_APP_MISC_2_APP_GPIO			(0x0000)
#define U300_SYSCON_PMC2R_APP_MISC_2_EMIF_SDRAM			(0x0400)
#define U300_SYSCON_PMC2R_APP_MISC_2_MMC			(0x0800)
#define U300_SYSCON_PMC2R_APP_MISC_2_CDI2			(0x0C00)
#define U300_SYSCON_PMC2R_APP_MISC_3_MASK			(0x3000)
#define U300_SYSCON_PMC2R_APP_MISC_3_APP_GPIO			(0x0000)
#define U300_SYSCON_PMC2R_APP_MISC_3_EMIF_SDRAM			(0x1000)
#define U300_SYSCON_PMC2R_APP_MISC_3_MMC			(0x2000)
#define U300_SYSCON_PMC2R_APP_MISC_3_CDI2			(0x3000)
#define U300_SYSCON_PMC2R_APP_MISC_4_MASK			(0xC000)
#define U300_SYSCON_PMC2R_APP_MISC_4_APP_GPIO			(0x0000)
#define U300_SYSCON_PMC2R_APP_MISC_4_EMIF_SDRAM			(0x4000)
#define U300_SYSCON_PMC2R_APP_MISC_4_MMC			(0x8000)
#define U300_SYSCON_PMC2R_APP_MISC_4_ACC_GPIO			(0xC000)
/* TODO: More SYSCON registers missing */
#define U300_SYSCON_PMC3R					(0x10c)
#define U300_SYSCON_PMC3R_APP_MISC_11_MASK			(0xc000)
#define U300_SYSCON_PMC3R_APP_MISC_11_SPI			(0x4000)
#define U300_SYSCON_PMC3R_APP_MISC_10_MASK			(0x3000)
#define U300_SYSCON_PMC3R_APP_MISC_10_SPI			(0x1000)
/* TODO: Missing other configs */
#define U300_SYSCON_PMC4R					(0x168)
#define U300_SYSCON_PMC4R_APP_MISC_12_MASK			(0x0003)
#define U300_SYSCON_PMC4R_APP_MISC_12_APP_GPIO			(0x0000)
#define U300_SYSCON_PMC4R_APP_MISC_13_MASK			(0x000C)
#define U300_SYSCON_PMC4R_APP_MISC_13_CDI			(0x0000)
#define U300_SYSCON_PMC4R_APP_MISC_13_SMIA			(0x0004)
#define U300_SYSCON_PMC4R_APP_MISC_13_SMIA2			(0x0008)
#define U300_SYSCON_PMC4R_APP_MISC_13_APP_GPIO			(0x000C)
#define U300_SYSCON_PMC4R_APP_MISC_14_MASK			(0x0030)
#define U300_SYSCON_PMC4R_APP_MISC_14_CDI			(0x0000)
#define U300_SYSCON_PMC4R_APP_MISC_14_SMIA			(0x0010)
#define U300_SYSCON_PMC4R_APP_MISC_14_CDI2			(0x0020)
#define U300_SYSCON_PMC4R_APP_MISC_14_APP_GPIO			(0x0030)
#define U300_SYSCON_PMC4R_APP_MISC_16_MASK			(0x0300)
#define U300_SYSCON_PMC4R_APP_MISC_16_APP_GPIO_13		(0x0000)
#define U300_SYSCON_PMC4R_APP_MISC_16_APP_UART1_CTS		(0x0100)
#define U300_SYSCON_PMC4R_APP_MISC_16_EMIF_1_STATIC_CS5_N	(0x0200)
/* SYS_0_CLK_CONTROL first clock control 16bit (R/W) */
#define U300_SYSCON_S0CCR					(0x120)
#define U300_SYSCON_S0CCR_FIELD_MASK				(0x43FF)
#define U300_SYSCON_S0CCR_CLOCK_REQ				(0x4000)
#define U300_SYSCON_S0CCR_CLOCK_REQ_MONITOR			(0x2000)
#define U300_SYSCON_S0CCR_CLOCK_INV				(0x0200)
#define U300_SYSCON_S0CCR_CLOCK_FREQ_MASK			(0x01E0)
#define U300_SYSCON_S0CCR_CLOCK_SELECT_MASK			(0x001E)
#define U300_SYSCON_S0CCR_CLOCK_ENABLE				(0x0001)
#define U300_SYSCON_S0CCR_SEL_MCLK				(0x8<<1)
#define U300_SYSCON_S0CCR_SEL_ACC_FSM_CLK			(0xA<<1)
#define U300_SYSCON_S0CCR_SEL_PLL60_48_CLK			(0xC<<1)
#define U300_SYSCON_S0CCR_SEL_PLL60_60_CLK			(0xD<<1)
#define U300_SYSCON_S0CCR_SEL_ACC_PLL208_CLK			(0xE<<1)
#define U300_SYSCON_S0CCR_SEL_APP_PLL13_CLK			(0x0<<1)
#define U300_SYSCON_S0CCR_SEL_APP_FSM_CLK			(0x2<<1)
#define U300_SYSCON_S0CCR_SEL_RTC_CLK				(0x4<<1)
#define U300_SYSCON_S0CCR_SEL_APP_PLL208_CLK			(0x6<<1)
/* SYS_1_CLK_CONTROL second clock control 16 bit (R/W) */
#define U300_SYSCON_S1CCR					(0x124)
#define U300_SYSCON_S1CCR_FIELD_MASK				(0x43FF)
#define U300_SYSCON_S1CCR_CLOCK_REQ				(0x4000)
#define U300_SYSCON_S1CCR_CLOCK_REQ_MONITOR			(0x2000)
#define U300_SYSCON_S1CCR_CLOCK_INV				(0x0200)
#define U300_SYSCON_S1CCR_CLOCK_FREQ_MASK			(0x01E0)
#define U300_SYSCON_S1CCR_CLOCK_SELECT_MASK			(0x001E)
#define U300_SYSCON_S1CCR_CLOCK_ENABLE				(0x0001)
#define U300_SYSCON_S1CCR_SEL_MCLK				(0x8<<1)
#define U300_SYSCON_S1CCR_SEL_ACC_FSM_CLK			(0xA<<1)
#define U300_SYSCON_S1CCR_SEL_PLL60_48_CLK			(0xC<<1)
#define U300_SYSCON_S1CCR_SEL_PLL60_60_CLK			(0xD<<1)
#define U300_SYSCON_S1CCR_SEL_ACC_PLL208_CLK			(0xE<<1)
#define U300_SYSCON_S1CCR_SEL_ACC_PLL13_CLK			(0x0<<1)
#define U300_SYSCON_S1CCR_SEL_APP_FSM_CLK			(0x2<<1)
#define U300_SYSCON_S1CCR_SEL_RTC_CLK				(0x4<<1)
#define U300_SYSCON_S1CCR_SEL_APP_PLL208_CLK			(0x6<<1)
/* SYS_2_CLK_CONTROL third clock contol 16 bit (R/W) */
#define U300_SYSCON_S2CCR					(0x128)
#define U300_SYSCON_S2CCR_FIELD_MASK				(0xC3FF)
#define U300_SYSCON_S2CCR_CLK_STEAL				(0x8000)
#define U300_SYSCON_S2CCR_CLOCK_REQ				(0x4000)
#define U300_SYSCON_S2CCR_CLOCK_REQ_MONITOR			(0x2000)
#define U300_SYSCON_S2CCR_CLOCK_INV				(0x0200)
#define U300_SYSCON_S2CCR_CLOCK_FREQ_MASK			(0x01E0)
#define U300_SYSCON_S2CCR_CLOCK_SELECT_MASK			(0x001E)
#define U300_SYSCON_S2CCR_CLOCK_ENABLE				(0x0001)
#define U300_SYSCON_S2CCR_SEL_MCLK				(0x8<<1)
#define U300_SYSCON_S2CCR_SEL_ACC_FSM_CLK			(0xA<<1)
#define U300_SYSCON_S2CCR_SEL_PLL60_48_CLK			(0xC<<1)
#define U300_SYSCON_S2CCR_SEL_PLL60_60_CLK			(0xD<<1)
#define U300_SYSCON_S2CCR_SEL_ACC_PLL208_CLK			(0xE<<1)
#define U300_SYSCON_S2CCR_SEL_ACC_PLL13_CLK			(0x0<<1)
#define U300_SYSCON_S2CCR_SEL_APP_FSM_CLK			(0x2<<1)
#define U300_SYSCON_S2CCR_SEL_RTC_CLK				(0x4<<1)
#define U300_SYSCON_S2CCR_SEL_APP_PLL208_CLK			(0x6<<1)
/* SYS_MISC_CONTROL, miscellaneous 16bit (R/W) */
#define U300_SYSCON_MCR						(0x12c)
#define U300_SYSCON_MCR_FIELD_MASK				(0x00FF)
#define U300_SYSCON_MCR_PMGEN_CR_4_MASK				(0x00C0)
#define U300_SYSCON_MCR_PMGEN_CR_4_GPIO				(0x0000)
#define U300_SYSCON_MCR_PMGEN_CR_4_SPI				(0x0040)
#define U300_SYSCON_MCR_PMGEN_CR_4_AAIF				(0x00C0)
#define U300_SYSCON_MCR_PMGEN_CR_2_MASK				(0x0030)
#define U300_SYSCON_MCR_PMGEN_CR_2_GPIO				(0x0000)
#define U300_SYSCON_MCR_PMGEN_CR_2_EMIF_1_STATIC		(0x0010)
#define U300_SYSCON_MCR_PMGEN_CR_2_DSP				(0x0020)
#define U300_SYSCON_MCR_PMGEN_CR_2_AAIF				(0x0030)
#define U300_SYSCON_MCR_PMGEN_CR_0_MASK				(0x000C)
#define U300_SYSCON_MCR_PMGEN_CR_0_EMIF_1_SDRAM_M1		(0x0000)
#define U300_SYSCON_MCR_PMGEN_CR_0_EMIF_1_SDRAM_M2		(0x0004)
#define U300_SYSCON_MCR_PMGEN_CR_0_EMIF_1_SDRAM_M3		(0x0008)
#define U300_SYSCON_MCR_PMGEN_CR_0_EMIF_0_SDRAM			(0x000C)
#define U300_SYSCON_MCR_PM1G_MODE_ENABLE			(0x0002)
#define U300_SYSCON_MCR_PMTG5_MODE_ENABLE			(0x0001)
/* SC_PLL_IRQ_CONTROL 16bit (R/W) */
#define U300_SYSCON_PICR					(0x0130)
#define U300_SYSCON_PICR_MASK					(0x00FF)
#define U300_SYSCON_PICR_FORCE_PLL208_LOCK_LOW_ENABLE		(0x0080)
#define U300_SYSCON_PICR_FORCE_PLL208_LOCK_HIGH_ENABLE		(0x0040)
#define U300_SYSCON_PICR_FORCE_PLL13_LOCK_LOW_ENABLE		(0x0020)
#define U300_SYSCON_PICR_FORCE_PLL13_LOCK_HIGH_ENABLE		(0x0010)
#define U300_SYSCON_PICR_IRQMASK_PLL13_UNLOCK_ENABLE		(0x0008)
#define U300_SYSCON_PICR_IRQMASK_PLL13_LOCK_ENABLE		(0x0004)
#define U300_SYSCON_PICR_IRQMASK_PLL208_UNLOCK_ENABLE		(0x0002)
#define U300_SYSCON_PICR_IRQMASK_PLL208_LOCK_ENABLE		(0x0001)
/* SC_PLL_IRQ_STATUS 16 bit (R/-) */
#define U300_SYSCON_PISR					(0x0134)
#define U300_SYSCON_PISR_MASK					(0x000F)
#define U300_SYSCON_PISR_PLL13_UNLOCK_IND			(0x0008)
#define U300_SYSCON_PISR_PLL13_LOCK_IND				(0x0004)
#define U300_SYSCON_PISR_PLL208_UNLOCK_IND			(0x0002)
#define U300_SYSCON_PISR_PLL208_LOCK_IND			(0x0001)
/* SC_PLL_IRQ_CLEAR 16 bit (-/W) */
#define U300_SYSCON_PICLR					(0x0138)
#define U300_SYSCON_PICLR_MASK					(0x000F)
#define U300_SYSCON_PICLR_RWMASK				(0x0000)
#define U300_SYSCON_PICLR_PLL13_UNLOCK_SC			(0x0008)
#define U300_SYSCON_PICLR_PLL13_LOCK_SC				(0x0004)
#define U300_SYSCON_PICLR_PLL208_UNLOCK_SC			(0x0002)
#define U300_SYSCON_PICLR_PLL208_LOCK_SC			(0x0001)
/* CAMIF_CONTROL 16 bit (-/W) */
#define U300_SYSCON_CICR					(0x013C)
#define U300_SYSCON_CICR_MASK					(0x0FFF)
#define U300_SYSCON_CICR_APP_SUBLVDS_TESTMODE_MASK		(0x0F00)
#define U300_SYSCON_CICR_APP_SUBLVDS_TESTMODE_PORT1		(0x0C00)
#define U300_SYSCON_CICR_APP_SUBLVDS_TESTMODE_PORT0		(0x0300)
#define U300_SYSCON_CICR_APP_SUBLVDS_RESCON_MASK		(0x00F0)
#define U300_SYSCON_CICR_APP_SUBLVDS_RESCON_PORT1		(0x00C0)
#define U300_SYSCON_CICR_APP_SUBLVDS_RESCON_PORT0		(0x0030)
#define U300_SYSCON_CICR_APP_SUBLVDS_PWR_DWN_N_MASK		(0x000F)
#define U300_SYSCON_CICR_APP_SUBLVDS_PWR_DWN_N_PORT1		(0x000C)
#define U300_SYSCON_CICR_APP_SUBLVDS_PWR_DWN_N_PORT0		(0x0003)
/* Clock activity observability register 0 */
#define U300_SYSCON_C0OAR					(0x140)
#define U300_SYSCON_C0OAR_MASK					(0xFFFF)
#define U300_SYSCON_C0OAR_VALUE					(0xFFFF)
#define U300_SYSCON_C0OAR_BT_H_CLK				(0x8000)
#define U300_SYSCON_C0OAR_ASPB_P_CLK				(0x4000)
#define U300_SYSCON_C0OAR_APP_SEMI_H_CLK			(0x2000)
#define U300_SYSCON_C0OAR_APP_SEMI_CLK				(0x1000)
#define U300_SYSCON_C0OAR_APP_MMC_MSPRO_CLK			(0x0800)
#define U300_SYSCON_C0OAR_APP_I2S1_CLK				(0x0400)
#define U300_SYSCON_C0OAR_APP_I2S0_CLK				(0x0200)
#define U300_SYSCON_C0OAR_APP_CPU_CLK				(0x0100)
#define U300_SYSCON_C0OAR_APP_52_CLK				(0x0080)
#define U300_SYSCON_C0OAR_APP_208_CLK				(0x0040)
#define U300_SYSCON_C0OAR_APP_104_CLK				(0x0020)
#define U300_SYSCON_C0OAR_APEX_CLK				(0x0010)
#define U300_SYSCON_C0OAR_AHPB_M_H_CLK				(0x0008)
#define U300_SYSCON_C0OAR_AHB_CLK				(0x0004)
#define U300_SYSCON_C0OAR_AFPB_P_CLK				(0x0002)
#define U300_SYSCON_C0OAR_AAIF_CLK				(0x0001)
/* Clock activity observability register 1 */
#define U300_SYSCON_C1OAR					(0x144)
#define U300_SYSCON_C1OAR_MASK					(0x3FFE)
#define U300_SYSCON_C1OAR_VALUE					(0x3FFE)
#define U300_SYSCON_C1OAR_NFIF_F_CLK				(0x2000)
#define U300_SYSCON_C1OAR_MSPRO_CLK				(0x1000)
#define U300_SYSCON_C1OAR_MMC_P_CLK				(0x0800)
#define U300_SYSCON_C1OAR_MMC_CLK				(0x0400)
#define U300_SYSCON_C1OAR_KP_P_CLK				(0x0200)
#define U300_SYSCON_C1OAR_I2C1_P_CLK				(0x0100)
#define U300_SYSCON_C1OAR_I2C0_P_CLK				(0x0080)
#define U300_SYSCON_C1OAR_GPIO_CLK				(0x0040)
#define U300_SYSCON_C1OAR_EMIF_MPMC_CLK				(0x0020)
#define U300_SYSCON_C1OAR_EMIF_H_CLK				(0x0010)
#define U300_SYSCON_C1OAR_EVHIST_CLK				(0x0008)
#define U300_SYSCON_C1OAR_PPM_CLK				(0x0004)
#define U300_SYSCON_C1OAR_DMA_CLK				(0x0002)
/* Clock activity observability register 2 */
#define U300_SYSCON_C2OAR					(0x148)
#define U300_SYSCON_C2OAR_MASK					(0x0FFF)
#define U300_SYSCON_C2OAR_VALUE					(0x0FFF)
#define U300_SYSCON_C2OAR_XGAM_CDI_CLK				(0x0800)
#define U300_SYSCON_C2OAR_XGAM_CLK				(0x0400)
#define U300_SYSCON_C2OAR_VC_H_CLK				(0x0200)
#define U300_SYSCON_C2OAR_VC_CLK				(0x0100)
#define U300_SYSCON_C2OAR_UA_P_CLK				(0x0080)
#define U300_SYSCON_C2OAR_TMR1_CLK				(0x0040)
#define U300_SYSCON_C2OAR_TMR0_CLK				(0x0020)
#define U300_SYSCON_C2OAR_SPI_P_CLK				(0x0010)
#define U300_SYSCON_C2OAR_PCM_I2S1_CORE_CLK			(0x0008)
#define U300_SYSCON_C2OAR_PCM_I2S1_CLK				(0x0004)
#define U300_SYSCON_C2OAR_PCM_I2S0_CORE_CLK			(0x0002)
#define U300_SYSCON_C2OAR_PCM_I2S0_CLK				(0x0001)

/* Chip ID register 16bit (R/-) */
#define U300_SYSCON_CIDR					(0x400)
/* Video IRQ clear 16bit (R/W) */
#define U300_SYSCON_VICR					(0x404)
#define U300_SYSCON_VICR_VIDEO1_IRQ_CLEAR_ENABLE		(0x0002)
#define U300_SYSCON_VICR_VIDEO0_IRQ_CLEAR_ENABLE		(0x0001)
/* SMCR */
#define U300_SYSCON_SMCR					(0x4d0)
#define U300_SYSCON_SMCR_FIELD_MASK				(0x000e)
#define U300_SYSCON_SMCR_SEMI_SREFACK_IND			(0x0008)
#define U300_SYSCON_SMCR_SEMI_SREFREQ_ENABLE			(0x0004)
#define U300_SYSCON_SMCR_SEMI_EXT_BOOT_MODE_ENABLE		(0x0002)
/* CPU_SW_DBGEN Software Debug Enable 16bit (R/W) */
#define U300_SYSCON_CSDR					(0x4f0)
#define U300_SYSCON_CSDR_SW_DEBUG_ENABLE			(0x0001)
/* PRINT_CONTROL Print Control 16bit (R/-) */
#define U300_SYSCON_PCR						(0x4f8)
#define U300_SYSCON_PCR_SERV_IND				(0x0001)
/* BOOT_CONTROL 16bit (R/-) */
#define U300_SYSCON_BCR						(0x4fc)
#define U300_SYSCON_BCR_ACC_CPU_SUBSYS_VINITHI_IND		(0x0400)
#define U300_SYSCON_BCR_APP_CPU_SUBSYS_VINITHI_IND		(0x0200)
#define U300_SYSCON_BCR_EXTRA_BOOT_OPTION_MASK			(0x01FC)
#define U300_SYSCON_BCR_APP_BOOT_SERV_MASK			(0x0003)

/* CPU clock defines */
/**
 * CPU high frequency in MHz
 */
#define SYSCON_CPU_CLOCK_HIGH    208
/**
 * CPU medium frequency in MHz
 */
#define SYSCON_CPU_CLOCK_MEDIUM   52
/**
 * CPU low frequency in MHz
 */
#define SYSCON_CPU_CLOCK_LOW      13

/* EMIF clock defines */
/**
 * EMIF high frequency in MHz
 */
#define SYSCON_EMIF_CLOCK_HIGH   104
/**
 * EMIF medium frequency in MHz
 */
#define SYSCON_EMIF_CLOCK_MEDIUM  52
/**
 * EMIF low frequency in MHz
 */
#define SYSCON_EMIF_CLOCK_LOW     13

/* AHB clock defines */
/**
 * AHB high frequency in MHz
 */
#define SYSCON_AHB_CLOCK_HIGH     52
/**
 * AHB medium frequency in MHz
 */
#define SYSCON_AHB_CLOCK_MEDIUM   26
/**
 * AHB low frequency in MHz
 */
#define SYSCON_AHB_CLOCK_LOW       7  /* i.e 13/2=6.5MHz */

enum syscon_busmaster {
  SYSCON_BM_DMAC,
  SYSCON_BM_XGAM,
  SYSCON_BM_VIDEO_ENC
};

/* Selectr a resistor or a set of resistors */
enum syscon_pull_up_down {
  SYSCON_PU_KEY_IN_EN,
  SYSCON_PU_EMIF_1_8_BIT_EN,
  SYSCON_PU_EMIF_1_16_BIT_EN,
  SYSCON_PU_EMIF_1_NFIF_READY_EN,
  SYSCON_PU_EMIF_1_NFIF_WAIT_N_EN,
};

/*
 * Note that this array must match the order of the array "clk_reg"
 * in syscon.c
 */
enum syscon_clk {
  SYSCON_CLKCONTROL_SLOW_BRIDGE,
  SYSCON_CLKCONTROL_UART,
  SYSCON_CLKCONTROL_BTR,
  SYSCON_CLKCONTROL_EH,
  SYSCON_CLKCONTROL_GPIO,
  SYSCON_CLKCONTROL_KEYPAD,
  SYSCON_CLKCONTROL_APP_TIMER,
  SYSCON_CLKCONTROL_ACC_TIMER,
  SYSCON_CLKCONTROL_FAST_BRIDGE,
  SYSCON_CLKCONTROL_I2C0,
  SYSCON_CLKCONTROL_I2C1,
  SYSCON_CLKCONTROL_I2S0,
  SYSCON_CLKCONTROL_I2S1,
  SYSCON_CLKCONTROL_MMC,
  SYSCON_CLKCONTROL_SPI,
  SYSCON_CLKCONTROL_I2S0_CORE,
  SYSCON_CLKCONTROL_I2S1_CORE,
  SYSCON_CLKCONTROL_UART1,
  SYSCON_CLKCONTROL_AAIF,
  SYSCON_CLKCONTROL_AHB,
  SYSCON_CLKCONTROL_APEX,
  SYSCON_CLKCONTROL_CPU,
  SYSCON_CLKCONTROL_DMA,
  SYSCON_CLKCONTROL_EMIF,
  SYSCON_CLKCONTROL_NAND_IF,
  SYSCON_CLKCONTROL_VIDEO_ENC,
  SYSCON_CLKCONTROL_XGAM,
  SYSCON_CLKCONTROL_SEMI,
  SYSCON_CLKCONTROL_AHB_SUBSYS,
  SYSCON_CLKCONTROL_MSPRO
};

enum syscon_sysclk_mode {
  SYSCON_SYSCLK_DISABLED,
  SYSCON_SYSCLK_M_CLK,
  SYSCON_SYSCLK_ACC_FSM,
  SYSCON_SYSCLK_PLL60_48,
  SYSCON_SYSCLK_PLL60_60,
  SYSCON_SYSCLK_ACC_PLL208,
  SYSCON_SYSCLK_APP_PLL13,
  SYSCON_SYSCLK_APP_FSM,
  SYSCON_SYSCLK_RTC,
  SYSCON_SYSCLK_APP_PLL208
};

enum syscon_sysclk_req {
  SYSCON_SYSCLKREQ_DISABLED,
  SYSCON_SYSCLKREQ_ACTIVE_LOW,
  SYSCON_SYSCLKREQ_MONITOR
};

enum syscon_clk_mode {
  SYSCON_CLKMODE_OFF,
  SYSCON_CLKMODE_DEFAULT,
  SYSCON_CLKMODE_LOW,
  SYSCON_CLKMODE_MEDIUM,
  SYSCON_CLKMODE_HIGH,
  SYSCON_CLKMODE_PERMANENT,
  SYSCON_CLKMODE_ON,
};

enum syscon_call_mode {
  SYSCON_CLKCALL_NOWAIT,
  SYSCON_CLKCALL_WAIT,
};

int syscon_dc_on(bool keep_power_on);
int syscon_set_busmaster_active_state(enum syscon_busmaster busmaster,
				      bool active);
bool syscon_get_busmaster_active_state(void);
int syscon_set_sleep_mask(enum syscon_clk,
			  bool sleep_ctrl);
int syscon_config_sysclk(u32 sysclk,
			 enum syscon_sysclk_mode sysclkmode,
			 bool inverse,
			 u32 divisor,
			 enum syscon_sysclk_req sysclkreq);
bool syscon_can_turn_off_semi_clock(void);

/* This function is restricted to core.c */
int syscon_request_normal_power(bool req);

/* This function is restricted to be used by platform_speed.c */
int syscon_speed_request(enum syscon_call_mode wait_mode,
			 enum syscon_clk_mode req_clk_mode);
#endif /* __MACH_SYSCON_H */
