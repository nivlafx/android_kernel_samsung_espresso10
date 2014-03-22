 /***************************************************************************\
|*                                                                           *|
|*       Copyright 1993-1999 NVIDIA, Corporation.  All rights reserved.      *|
|*                                                                           *|
|*     NOTICE TO USER:   The source code  is copyrighted under  U.S. and     *|
|*     international laws.  Users and possessors of this source code are     *|
|*     hereby granted a nonexclusive,  royalty-free copyright license to     *|
|*     use this code in individual and commercial software.                  *|
|*                                                                           *|
|*     Any use of this source code must include,  in the user documenta-     *|
|*     tion and  internal comments to the code,  notices to the end user     *|
|*     as follows:                                                           *|
|*                                                                           *|
|*       Copyright 1993-1999 NVIDIA, Corporation.  All rights reserved.      *|
|*                                                                           *|
|*     NVIDIA, CORPORATION MAKES NO REPRESENTATION ABOUT THE SUITABILITY     *|
|*     OF  THIS SOURCE  CODE  FOR ANY PURPOSE.  IT IS  PROVIDED  "AS IS"     *|
|*     WITHOUT EXPRESS OR IMPLIED WARRANTY OF ANY KIND.  NVIDIA, CORPOR-     *|
|*     ATION DISCLAIMS ALL WARRANTIES  WITH REGARD  TO THIS SOURCE CODE,     *|
|*     INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGE-     *|
|*     MENT,  AND FITNESS  FOR A PARTICULAR PURPOSE.   IN NO EVENT SHALL     *|
|*     NVIDIA, CORPORATION  BE LIABLE FOR ANY SPECIAL,  INDIRECT,  INCI-     *|
|*     DENTAL, OR CONSEQUENTIAL DAMAGES,  OR ANY DAMAGES  WHATSOEVER RE-     *|
|*     SULTING FROM LOSS OF USE,  DATA OR PROFITS,  WHETHER IN AN ACTION     *|
|*     OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,  ARISING OUT OF     *|
|*     OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOURCE CODE.     *|
|*                                                                           *|
|*     U.S. Government  End  Users.   This source code  is a "commercial     *|
|*     item,"  as that  term is  defined at  48 C.F.R. 2.101 (OCT 1995),     *|
|*     consisting  of "commercial  computer  software"  and  "commercial     *|
|*     computer  software  documentation,"  as such  terms  are  used in     *|
|*     48 C.F.R. 12.212 (SEPT 1995)  and is provided to the U.S. Govern-     *|
|*     ment only as  a commercial end item.   Consistent with  48 C.F.R.     *|
|*     12.212 and  48 C.F.R. 227.7202-1 through  227.7202-4 (JUNE 1995),     *|
|*     all U.S. Government End Users  acquire the source code  with only     *|
|*     those rights set forth herein.                                        *|
|*                                                                           *|
 \***************************************************************************/

/*
 * GPL licensing note -- nVidia is allowing a liberal interpretation of
 * the documentation restriction above, to merely say that this nVidia's
 * copyright and disclaimer should be included with all code derived
 * from this source.  -- Jeff Garzik <jgarzik@pobox.com>, 01/Nov/99
 */

/* $XFree86: xc/programs/Xserver/hw/xfree86/drivers/nv/riva_tbl.h,v 1.9 2002/01/30 01:35:03 mvojkovi Exp $ */

/*
 * RIVA Fixed Functionality Init Tables.
 */
static unsigned RivaTablePMC[][2] =
{
    {0x00000050, 0x00000000},
    {0x00000080, 0xFFFF00FF},
    {0x00000080, 0xFFFFFFFF}
};
static unsigned RivaTablePTIMER[][2] =
{
    {0x00000080, 0x00000008},
    {0x00000084, 0x00000003},
    {0x00000050, 0x00000000},
    {0x00000040, 0xFFFFFFFF}
};
static unsigned RivaTableFIFO[][2] =
{
    {0x00000000, 0x80000000},
    {0x00000800, 0x80000001},
    {0x00001000, 0x80000002},
    {0x00001800, 0x80000010},
    {0x00002000, 0x80000011},
    {0x00002800, 0x80000012},
    {0x00003000, 0x80000016},
    {0x00003800, 0x80000013}
};
static unsigned nv3TablePFIFO[][2] =
{
    {0x00000140, 0x00000000},
    {0x00000480, 0x00000000},
    {0x00000490, 0x00000000},
    {0x00000494, 0x00000000},
    {0x00000481, 0x00000000},
    {0x00000084, 0x00000000},
    {0x00000086, 0x00002000},
    {0x00000085, 0x00002200},
    {0x00000484, 0x00000000},
    {0x0000049C, 0x00000000},
    {0x00000104, 0x00000000},
    {0x00000108, 0x00000000},
    {0x00000100, 0x00000000},
    {0x000004A0, 0x00000000},
    {0x000004A4, 0x00000000},
    {0x000004A8, 0x00000000},
    {0x000004AC, 0x00000000},
    {0x000004B0, 0x00000000},
    {0x000004B4, 0x00000000},
    {0x000004B8, 0x00000000},
    {0x000004BC, 0x00000000},
    {0x00000050, 0x00000000},
    {0x00000040, 0xFFFFFFFF},
    {0x00000480, 0x00000001},
    {0x00000490, 0x00000001},
    {0x00000140, 0x00000001}
};
static unsigned nv3TablePGRAPH[][2] =
{
    {0x00000020, 0x1230001F},
    {0x00000021, 0x10113000},
    {0x00000022, 0x1131F101},
    {0x00000023, 0x0100F531},
    {0x00000060, 0x00000000},
    {0x00000065, 0x00000000},
    {0x00000068, 0x00000000},
    {0x00000069, 0x00000000},
    {0x0000006A, 0x00000000},
    {0x0000006B, 0x00000000},
    {0x0000006C, 0x00000000},
    {0x0000006D, 0x00000000},
    {0x0000006E, 0x00000000},
    {0x0000006F, 0x00000000},
    {0x000001A8, 0x00000000},
    {0x00000440, 0xFFFFFFFF},
    {0x00000480, 0x00000001},
    {0x000001A0, 0x00000000},
    {0x000001A2, 0x00000000},
    {0x0000018A, 0xFFFFFFFF},
    {0x00000190, 0x00000000},
    {0x00000142, 0x00000000},
    {0x00000154, 0x00000000},
    {0x00000155, 0xFFFFFFFF},
    {0x00000156, 0x00000000},
    {0x00000157, 0xFFFFFFFF},
    {0x00000064, 0x10010002},
    {0x00000050, 0x00000000},
    {0x00000051, 0x00000000},
    {0x00000040, 0xFFFFFFFF},
    {0x00000041, 0xFFFFFFFF},
    {0x00000440, 0xFFFFFFFF},
    {0x000001A9, 0x00000001}
};
static unsigned nv3TablePGRAPH_8BPP[][2] =
{
    {0x000001AA, 0x00001111}
};
static unsigned nv3TablePGRAPH_15BPP[][2] =
{
    {0x000001AA, 0x00002222}
};
static unsigned nv3TablePGRAPH_32BPP[][2] =
{
    {0x000001AA, 0x00003333}
};
static unsigned nv3TablePRAMIN[][2] =
{
    {0x00000500, 0x00010000},
    {0x00000501, 0x007FFFFF},
    {0x00000200, 0x80000000},
    {0x00000201, 0x00C20341},
    {0x00000204, 0x80000001},
    {0x00000205, 0x00C50342},
    {0x00000208, 0x80000002},
    {0x00000209, 0x00C60343},
    {0x0000020C, 0x80000003},
    {0x0000020D, 0x00DC0348},
    {0x00000210, 0x80000004},
    {0x00000211, 0x00DC0349},
    {0x00000214, 0x80000005},
    {0x00000215, 0x00DC034A},
    {0x00000218, 0x80000006},
    {0x00000219, 0x00DC034B},
    {0x00000240, 0x80000010},
    {0x00000241, 0x00D10344},
    {0x00000244, 0x80000011},
    {0x00000245, 0x00D00345},
    {0x00000248, 0x80000012},
    {0x00000249, 0x00CC0346},
    {0x0000024C, 0x80000013},
    {0x0000024D, 0x00D70347},
    {0x00000258, 0x80000016},
    {0x00000259, 0x00CA034C},
    {0x00000D05, 0x00000000},
    {0x00000D06, 0x00000000},
    {0x00000D07, 0x00000000},
    {0x00000D09, 0x00000000},
    {0x00000D0A, 0x00000000},
    {0x00000D0B, 0x00000000},
    {0x00000D0D, 0x00000000},
    {0x00000D0E, 0x00000000},
    {0x00000D0F, 0x00000000},
    {0x00000D11, 0x00000000},
    {0x00000D12, 0x00000000},
    {0x00000D13, 0x00000000},
    {0x00000D15, 0x00000000},
    {0x00000D16, 0x00000000},
    {0x00000D17, 0x00000000},
    {0x00000D19, 0x00000000},
    {0x00000D1A, 0x00000000},
    {0x00000D1B, 0x00000000},
    {0x00000D1D, 0x00000140},
    {0x00000D1E, 0x00000000},
    {0x00000D1F, 0x00000000},
    {0x00000D20, 0x10100200},
    {0x00000D21, 0x00000000},
    {0x00000D22, 0x00000000},
    {0x00000D23, 0x00000000},
    {0x00000D24, 0x10210200},
    {0x00000D25, 0x00000000},
    {0x00000D26, 0x00000000},
    {0x00000D27, 0x00000000},
    {0x00000D28, 0x10420200},
    {0x00000D29, 0x00000000},
    {0x00000D2A, 0x00000000},
    {0x00000D2B, 0x00000000},
    {0x00000D2C, 0x10830200},
    {0x00000D2D, 0x00000000},
    {0x00000D2E, 0x00000000},
    {0x00000D2F, 0x00000000},
    {0x00000D31, 0x00000000},
    {0x00000D32, 0x00000000},
    {0x00000D33, 0x00000000}
};
static unsigned nv3TablePRAMIN_8BPP[][2] =
{
    /*           0xXXXXX3XX For  MSB mono format */
    /*           0xXXXXX2XX For  LSB mono format */
    {0x00000D04, 0x10110203},
    {0x00000D08, 0x10110203},
    {0x00000D0C, 0x1011020B},
    {0x00000D10, 0x10118203},
    {0x00000D14, 0x10110203},
    {0x00000D18, 0x10110203},
    {0x00000D1C, 0x10419208},
    {0x00000D30, 0x10118203}
};
static unsigned nv3TablePRAMIN_15BPP[][2] =
{
    /*           0xXXXXX2XX For  MSB mono format */
    /*           0xXXXXX3XX For  LSB mono format */
    {0x00000D04, 0x10110200},
    {0x00000D08, 0x10110200},
    {0x00000D0C, 0x10110208},
    {0x00000D10, 0x10118200},
    {0x00000D14, 0x10110200},
    {0x00000D18, 0x10110200},
    {0x00000D1C, 0x10419208},
    {0x00000D30, 0x10118200}
};
static unsigned nv3TablePRAMIN_32BPP[][2] =
{
    /*           0xXXXXX3XX For  MSB mono format */
    /*           0xXXXXX2XX For  LSB mono format */
    {0x00000D04, 0x10110201},
    {0x00000D08, 0x10110201},
    {0x00000D0C, 0x10110209},
    {0x00000D10, 0x10118201},
    {0x00000D14, 0x10110201},
    {0x00000D18, 0x10110201},
    {0x00000D1C, 0x10419208},
    {0x00000D30, 0x10118201}
};
static unsigned nv4TableFIFO[][2] =
{
    {0x00003800, 0x80000014}
};
static unsigned nv4TablePFIFO[][2] =
{
    {0x00000140, 0x00000000},
    {0x00000480, 0x00000000},
    {0x00000494, 0x00000000},
    {0x00000481, 0x00000000},
    {0x0000048B, 0x00000000},
    {0x00000400, 0x00000000},
    {0x00000414, 0x00000000},
    {0x00000084, 0x03000100},
    {0x00000085, 0x00000110},
    {0x00000086, 0x00000112},
    {0x00000143, 0x0000FFFF},
    {0x00000496, 0x0000FFFF},
    {0x00000050, 0x00000000},
    {0x00000040, 0xFFFFFFFF},
    {0x00000415, 0x00000001},
    {0x00000480, 0x00000001},
    {0x00000494, 0x00000001},
    {0x00000495, 0x00000001},
    {0x00000140, 0x00000001}
};
static unsigned nv4TablePGRAPH[][2] =
{
    {0x00000020, 0x1231C001},
    {0x00000021, 0x72111101},
    {0x00000022, 0x11D5F071},
    {0x00000023, 0x10D4FF31},
    {0x00000060, 0x00000000},
    {0x00000068, 0x00000000},
    {0x00000070, 0x00000000},
    {0x00000078, 0x00000000},
    {0x00000061, 0x00000000},
    {0x00000069, 0x00000000},
    {0x00000071, 0x00000000},
    {0x00000079, 0x00000000},
    {0x00000062, 0x00000000},
    {0x0000006A, 0x00000000},
    {0x00000072, 0x00000000},
    {0x0000007A, 0x00000000},
    {0x00000063, 0x00000000},
    {0x0000006B, 0x00000000},
    {0x00000073, 0x00000000},
    {0x0000007B, 0x00000000},
    {0x00000064, 0x00000000},
    {0x0000006C, 0x00000000},
    {0x00000074, 0x00000000},
    {0x0000007C, 0x00000000},
    {0x00000065, 0x00000000},
    {0x0000006D, 0x00000000},
    {0x00000075, 0x00000000},
    {0x0000007D, 0x00000000},
    {0x00000066, 0x00000000},
    {0x0000006E, 0x00000000},
    {0x00000076, 0x00000000},
    {0x0000007E, 0x00000000},
    {0x00000067, 0x00000000},
    {0x0000006F, 0x00000000},
    {0x00000077, 0x00000000},
    {0x0000007F, 0x00000000},
    {0x00000058, 0x00000000},
    {0x00000059, 0x00000000},
    {0x0000005A, 0x00000000},
    {0x0000005B, 0x00000000},
    {0x00000196, 0x00000000},
    {0x000001A1, 0x01FFFFFF},
    {0x00000197, 0x00000000},
    {0x000001A2, 0x01FFFFFF},
    {0x00000198, 0x00000000},
    {0x000001A3, 0x01FFFFFF},
    {0x00000199, 0x00000000},
    {0x000001A4, 0x01FFFFFF},
    {0x00000050, 0x00000000},
    {0x00000040, 0xFFFFFFFF},
    {0x0000005C, 0x10010100},
    {0x000001C4, 0xFFFFFFFF},
    {0x000001C8, 0x00000001},
    {0x00000204, 0x00000000},
    {0x000001C3, 0x00000001}
};
static unsigned nv4TablePGRAPH_8BPP[][2] =
{
    {0x000001C9, 0x00111111},
    {0x00000186, 0x00001010},
    {0x0000020C, 0x03020202}
};
static unsigned nv4TablePGRAPH_15BPP[][2] =
{
    {0x000001C9, 0x00226222},
    {0x00000186, 0x00002071},
    {0x0000020C, 0x09080808}
};
static unsigned nv4TablePGRAPH_16BPP[][2] =
{
    {0x000001C9, 0x00556555},
    {0x00000186, 0x000050C2},
    {0x0000020C, 0x0C0B0B0B}
};
static unsigned nv4TablePGRAPH_32BPP[][2] =
{
    {0x000001C9, 0x0077D777},
    {0x00000186, 0x000070E5},
    {0x0000020C, 0x0E0D0D0D}
};
static unsigned nv4TablePRAMIN[][2] =
{
    {0x00000000, 0x80000010},
    {0x00000001, 0x80011145},
    {0x00000002, 0x80000011},
    {0x00000003, 0x80011146},
    {0x00000004, 0x80000012},
    {0x00000005, 0x80011147},
    {0x00000006, 0x80000013},
    {0x00000007, 0x80011148},
    {0x00000008, 0x80000014},
    {0x00000009, 0x80011149},
    {0x0000000A, 0x80000015},
    {0x0000000B, 0x8001114A},
    {0x0000000C, 0x80000016},
    {0x0000000D, 0x8001114F},
    {0x00000020, 0x80000000},
    {0x00000021, 0x80011142},
    {0x00000022, 0x80000001},
    {0x00000023, 0x80011143},
    {0x00000024, 0x80000002},
    {0x00000025, 0x80011144},
    {0x00000026, 0x80000003},
    {0x00000027, 0x8001114B},
    {0x00000028, 0x80000004},
    {0x00000029, 0x8001114C},
    {0x0000002A, 0x80000005},
    {0x0000002B, 0x8001114D},
    {0x0000002C, 0x80000006},
    {0x0000002D, 0x8001114E},
    {0x00000500, 0x00003000},
    {0x00000501, 0x01FFFFFF},
    {0x00000502, 0x00000002},
    {0x00000503, 0x00000002},
    {0x00000508, 0x01008043},
    {0x0000050A, 0x00000000},
    {0x0000050B, 0x00000000},
    {0x0000050C, 0x01008019},
    {0x0000050E, 0x00000000},
    {0x0000050F, 0x00000000},
#if 1
    {0x00000510, 0x01008018},
#else
    {0x00000510, 0x01008044},
#endif
    {0x00000512, 0x00000000},
    {0x00000513, 0x00000000},
    {0x00000514, 0x01008021},
    {0x00000516, 0x00000000},
    {0x00000517, 0x00000000},
    {0x00000518, 0x0100805F},
    {0x0000051A, 0x00000000},
    {0x0000051B, 0x00000000},
#if 1
    {0x0000051C, 0x0100804B},
#else
    {0x0000051C, 0x0100804A},
#endif
    {0x0000051E, 0x00000000},
    {0x0000051F, 0x00000000},
    {0x00000520, 0x0100A048},
    {0x00000521, 0x00000D01},
    {0x00000522, 0x11401140},
    {0x00000523, 0x00000000},
    {0x00000524, 0x0300A054},
    {0x00000525, 0x00000D01},
    {0x00000526, 0x11401140},
    {0x00000527, 0x00000000},
    {0x00000528, 0x0300A055},
    {0x00000529, 0x00000D01},
    {0x0000052A, 0x11401140},
    {0x0000052B, 0x00000000},
    {0x0000052C, 0x00000058},
    {0x0000052E, 0x11401140},
    {0x0000052F, 0x00000000},
    {0x00000530, 0x00000059},
    {0x00000532, 0x11401140},
    {0x00000533, 0x00000000},
    {0x00000534, 0x0000005A},
    {0x00000536, 0x11401140},
    {0x00000537, 0x00000000},
    {0x00000538, 0x0000005B},
    {0x0000053A, 0x11401140},
    {0x0000053B, 0x00000000},
    {0x0000053C, 0x0300A01C},
    {0x0000053E, 0x11401140},
    {0x0000053F, 0x00000000}
};
static unsigned nv4TablePRAMIN_8BPP[][2] =
{
    /*           0xXXXXXX01 For  MSB mono format */
    /*           0xXXXXXX02 For  LSB mono format */
    {0x00000509, 0x00000302},
    {0x0000050D, 0x00000302},
    {0x00000511, 0x00000202},
    {0x00000515, 0x00000302},
    {0x00000519, 0x00000302},
    {0x0000051D, 0x00000302},
    {0x0000052D, 0x00000302},
    {0x0000052E, 0x00000302},
    {0x00000535, 0x00000000},
    {0x00000539, 0x00000000},
    {0x0000053D, 0x00000302}
};
static unsigned nv4TablePRAMIN_15BPP[][2] =
{
    /*           0xXXXXXX01 For  MSB mono format */
    /*           0xXXXXXX02 For  LSB mono format */
    {0x00000509, 0x00000902},
    {0x0000050D, 0x00000902},
    {0x00000511, 0x00000802},
    {0x00000515, 0x00000902},
    {0x00000519, 0x00000902},
    {0x0000051D, 0x00000902},
    {0x0000052D, 0x00000902},
    {0x0000052E, 0x00000902},
    {0x00000535, 0x00000702},
    {0x00000539, 0x00000702},
    {0x0000053D, 0x00000902}
};
static unsigned nv4TablePRAMIN_16BPP[][2] =
{
    /*           0xXXXXXX01 For  MSB mono format */
    /*           0xXXXXXX02 For  LSB mono format */
    {0x00000509, 0x00000C02},
    {0x0000050D, 0x00000C02},
    {0x00000511, 0x00000B02},
    {0x00000515, 0x00000C02},
    {0x00000519, 0x00000C02},
    {0x0000051D, 0x00000C02},
    {0x0000052D, 0x00000C02},
    {0x0000052E, 0x00000C02},
    {0x00000535, 0x00000702},
    {0x00000539, 0x00000702},
    {0x0000053D, 0x00000C02}
};
static unsigned nv4TablePRAMIN_32BPP[][2] =
{
    /*           0xXXXXXX01 For  MSB mono format */
    /*           0xXXXXXX02 For  LSB mono format */
    {0x00000509, 0x00000E02},
    {0x0000050D, 0x00000E02},
    {0x00000511, 0x00000D02},
    {0x00000515, 0x00000E02},
    {0x00000519, 0x00000E02},
    {0x0000051D, 0x00000E02},
    {0x0000052D, 0x00000E02},
    {0x0000052E, 0x00000E02},
    {0x00000535, 0x00000E02},
    {0x00000539, 0x00000E02},
    {0x0000053D, 0x00000E02}
};
static unsigned nv10TableFIFO[][2] =
{
    {0x00003800, 0x80000014}
};
static unsigned nv10TablePFIFO[][2] =
{
    {0x00000140, 0x00000000},
    {0x00000480, 0x00000000},
    {0x00000494, 0x00000000},
    {0x00000481, 0x00000000},
    {0x0000048B, 0x00000000},
    {0x00000400, 0x00000000},
    {0x00000414, 0x00000000},
    {0x00000084, 0x03000100},
    {0x00000085, 0x00000110},
    {0x00000086, 0x00000112},
    {0x00000143, 0x0000FFFF},
    {0x00000496, 0x0000FFFF},
    {0x00000050, 0x00000000},
    {0x00000040, 0xFFFFFFFF},
    {0x00000415, 0x00000001},
    {0x00000480, 0x00000001},
    {0x00000494, 0x00000001},
    {0x00000495, 0x00000001},
    {0x00000140, 0x00000001}
};
static unsigned nv10TablePGRAPH[][2] =
{
    {0x00000020, 0x0003FFFF},
    {0x00000021, 0x00118701},
    {0x00000022, 0x24F82AD9},
    {0x00000023, 0x55DE0030},
    {0x00000020, 0x00000000},
    {0x00000024, 0x00000000},
    {0x00000058, 0x00000000},
    {0x00000060, 0x00000000},
    {0x00000068, 0x00000000},
    {0x00000070, 0x00000000},
    {0x00000078, 0x00000000},
    {0x00000059, 0x00000000},
    {0x00000061, 0x00000000},
    {0x00000069, 0x00000000},
    {0x00000071, 0x00000000},
    {0x00000079, 0x00000000},
    {0x0000005A, 0x00000000},
    {0x00000062, 0x00000000},
    {0x0000006A, 0x00000000},
    {0x00000072, 0x00000000},
    {0x0000007A, 0x00000000},
    {0x0000005B, 0x00000000},
    {0x00000063, 0x00000000},
    {0x0000006B, 0x00000000},
    {0x00000073, 0x00000000},
    {0x0000007B, 0x00000000},
    {0x0000005C, 0x00000000},
    {0x00000064, 0x00000000},
    {0x0000006C, 0x00000000},
    {0x00000074, 0x00000000},
    {0x0000007C, 0x00000000},
    {0x0000005D, 0x00000000},
    {0x00000065, 0x00000000},
    {0x0000006D, 0x00000000},
    {0x00000075, 0x00000000},
    {0x0000007D, 0x00000000},
    {0x0000005E, 0x00000000},
    {0x00000066, 0x00000000},
    {0x0000006E, 0x00000000},
    {0x00000076, 0x00000000},
    {0x0000007E, 0x00000000},
    {0x0000005F, 0x00000000},
    {0x00000067, 0x00000000},
    {0x0000006F, 0x00000000},
    {0x00000077, 0x00000000},
    {0x0000007F, 0x00000000},
    {0x00000053, 0x00000000},
    {0x00000054, 0x00000000},
    {0x00000055, 0x00000000},
    {0x00000056, 0x00000000},
    {0x00000057, 0x00000000},
    {0x00000196, 0x00000000},
    {0x000001A1, 0x01FFFFFF},
    {0x00000197, 0x00000000},
    {0x000001A2, 0x01FFFFFF},
    {0x00000198, 0x00000000},
    {0x000001A3, 0x01FFFFFF},
    {0x00000199, 0x00000000},
    {0x000001A4, 0x01FFFFFF},
    {0x0000019A, 0x00000000},
    {0x000001A5, 0x01FFFFFF},
    {0x0000019B, 0x00000000},
    {0x000001A6, 0x01FFFFFF},
    {0x00000050, 0x01111111},
    {0x00000040, 0xFFFFFFFF},
    {0x00000051, 0x10010100},
    {0x000001C5, 0xFFFFFFFF},
    {0x000001C8, 0x00000001},
    {0x00000204, 0x00000000},
    {0x000001C4, 0x00000001}
};
static unsigned nv10TablePGRAPH_8BPP[][2] =
{
    {0x000001C9, 0x00111111},
    {0x00000186, 0x00001010},
    {0x0000020C, 0x03020202}
};
static unsigned nv10TablePGRAPH_15BPP[][2] =
{
    {0x000001C9, 0x00226222},
    {0x00000186, 0x00002071},
    {0x0000020C, 0x09080808}
};
static unsigned nv10TablePGRAPH_16BPP[][2] =
{
    {0x000001C9, 0x00556555},
    {0x00000186, 0x000050C2},
    {0x0000020C, 0x000B0B0C}
};
static unsigned nv10TablePGRAPH_32BPP[][2] =
{
    {0x000001C9, 0x0077D777},
    {0x00000186, 0x000070E5},
    {0x0000020C, 0x0E0D0D0D}
};
static unsigned nv10tri05TablePGRAPH[][2] =
{
    {(0x00000E00/4), 0x00000000},
    {(0x00000E04/4), 0x00000000},
    {(0x00000E08/4), 0x00000000},
    {(0x00000E0C/4), 0x00000000},
    {(0x00000E10/4), 0x00001000},
    {(0x00000E14/4), 0x00001000},
    {(0x00000E18/4), 0x4003ff80},
    {(0x00000E1C/4), 0x00000000},
    {(0x00000E20/4), 0x00000000},
    {(0x00000E24/4), 0x00000000},
    {(0x00000E28/4), 0x00000000},
    {(0x00000E2C/4), 0x00000000},
    {(0x00000E30/4), 0x00080008},
    {(0x00000E34/4), 0x00080008},
    {(0x00000E38/4), 0x00000000},
    {(0x00000E3C/4), 0x00000000},
    {(0x00000E40/4), 0x00000000},
    {(0x00000E44/4), 0x00000000},
    {(0x00000E48/4), 0x00000000},
    {(0x00000E4C/4), 0x00000000},
    {(0x00000E50/4), 0x00000000},
    {(0x00000E54/4), 0x00000000},
    {(0x00000E58/4), 0x00000000},
    {(0x00000E5C/4), 0x00000000},
    {(0x00000E60/4), 0x00000000},
    {(0x00000E64/4), 0x10000000},
    {(0x00000E68/4), 0x00000000},
    {(0x00000E6C/4), 0x00000000},
    {(0x00000E70/4), 0x00000000},
    {(0x00000E74/4), 0x00000000},
    {(0x00000E78/4), 0x00000000},
    {(0x00000E7C/4), 0x00000000},
    {(0x00000E80/4), 0x00000000},
    {(0x00000E84/4), 0x00000000},
    {(0x00000E88/4), 0x08000000},
    {(0x00000E8C/4), 0x00000000},
    {(0x00000E90/4), 0x00000000},
    {(0x00000E94/4), 0x00000000},
    {(0x00000E98/4), 0x00000000},
    {(0x00000E9C/4), 0x4B7FFFFF},
    {(0x00000EA0/4), 0x00000000},
    {(0x00000EA4/4), 0x00000000},
    {(0x00000EA8/4), 0x00000000},
    {(0x00000F00/4), 0x07FF0800},
    {(0x00000F04/4), 0x07FF0800},
    {(0x00000F08/4), 0x07FF0800},
    {(0x00000F0C/4), 0x07FF0800},
    {(0x00000F10/4), 0x07FF0800},
    {(0x00000F14/4), 0x07FF0800},
    {(0x00000F18/4), 0x07FF0800},
    {(0x00000F1C/4), 0x07FF0800},
    {(0x00000F20/4), 0x07FF0800},
    {(0x00000F24/4), 0x07FF0800},
    {(0x00000F28/4), 0x07FF0800},
    {(0x00000F2C/4), 0x07FF0800},
    {(0x00000F30/4), 0x07FF0800},
    {(0x00000F34/4), 0x07FF0800},
    {(0x00000F38/4), 0x07FF0800},
    {(0x00000F3C/4), 0x07FF0800},
    {(0x00000F40/4), 0x10000000},
    {(0x00000F44/4), 0x00000000},
    {(0x00000F50/4), 0x00006740},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x3F800000},
    {(0x00000F50/4), 0x00006750},
    {(0x00000F54/4), 0x40000000},
    {(0x00000F54/4), 0x40000000},
    {(0x00000F54/4), 0x40000000},
    {(0x00000F54/4), 0x40000000},
    {(0x00000F50/4), 0x00006760},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x3F800000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F50/4), 0x00006770},
    {(0x00000F54/4), 0xC5000000},
    {(0x00000F54/4), 0xC5000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F50/4), 0x00006780},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x3F800000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F50/4), 0x000067A0},
    {(0x00000F54/4), 0x3F800000},
    {(0x00000F54/4), 0x3F800000},
    {(0x00000F54/4), 0x3F800000},
    {(0x00000F54/4), 0x3F800000},
    {(0x00000F50/4), 0x00006AB0},
    {(0x00000F54/4), 0x3F800000},
    {(0x00000F54/4), 0x3F800000},
    {(0x00000F54/4), 0x3F800000},
    {(0x00000F50/4), 0x00006AC0},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F50/4), 0x00006C10},
    {(0x00000F54/4), 0xBF800000},
    {(0x00000F50/4), 0x00007030},
    {(0x00000F54/4), 0x7149F2CA},
    {(0x00000F50/4), 0x00007040},
    {(0x00000F54/4), 0x7149F2CA},
    {(0x00000F50/4), 0x00007050},
    {(0x00000F54/4), 0x7149F2CA},
    {(0x00000F50/4), 0x00007060},
    {(0x00000F54/4), 0x7149F2CA},
    {(0x00000F50/4), 0x00007070},
    {(0x00000F54/4), 0x7149F2CA},
    {(0x00000F50/4), 0x00007080},
    {(0x00000F54/4), 0x7149F2CA},
    {(0x00000F50/4), 0x00007090},
    {(0x00000F54/4), 0x7149F2CA},
    {(0x00000F50/4), 0x000070A0},
    {(0x00000F54/4), 0x7149F2CA},
    {(0x00000F50/4), 0x00006A80},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x3F800000},
    {(0x00000F50/4), 0x00006AA0},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F50/4), 0x00000040},
    {(0x00000F54/4), 0x00000005},
    {(0x00000F50/4), 0x00006400},
    {(0x00000F54/4), 0x3F800000},
    {(0x00000F54/4), 0x3F800000},
    {(0x00000F54/4), 0x4B7FFFFF},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F50/4), 0x00006410},
    {(0x00000F54/4), 0xC5000000},
    {(0x00000F54/4), 0xC5000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F50/4), 0x00006420},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F50/4), 0x00006430},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F50/4), 0x000064C0},
    {(0x00000F54/4), 0x3F800000},
    {(0x00000F54/4), 0x3F800000},
    {(0x00000F54/4), 0x477FFFFF},
    {(0x00000F54/4), 0x3F800000},
    {(0x00000F50/4), 0x000064D0},
    {(0x00000F54/4), 0xC5000000},
    {(0x00000F54/4), 0xC5000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F50/4), 0x000064E0},
    {(0x00000F54/4), 0xC4FFF000},
    {(0x00000F54/4), 0xC4FFF000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F50/4), 0x000064F0},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F54/4), 0x00000000},
    {(0x00000F40/4), 0x30000000},
    {(0x00000F44/4), 0x00000004},
    {(0x00000F48/4), 0x10000000},
    {(0x00000F4C/4), 0x00000000}
};
static unsigned nv10TablePRAMIN[][2] =
{
    {0x00000000, 0x80000010},
    {0x00000001, 0x80011145},
    {0x00000002, 0x80000011},
    {0x00000003, 0x80011146},
    {0x00000004, 0x80000012},
    {0x00000005, 0x80011147},
    {0x00000006, 0x80000013},
    {0x00000007, 0x80011148},
    {0x00000008, 0x80000014},
    {0x00000009, 0x80011149},
    {0x0000000A, 0x80000015},
    {0x0000000B, 0x8001114A},
    {0x0000000C, 0x80000016},
    {0x0000000D, 0x80011150},
    {0x00000020, 0x80000000},
    {0x00000021, 0x80011142},
    {0x00000022, 0x80000001},
    {0x00000023, 0x80011143},
    {0x00000024, 0x80000002},
    {0x00000025, 0x80011144},
    {0x00000026, 0x80000003},
    {0x00000027, 0x8001114B},
    {0x00000028, 0x80000004},
    {0x00000029, 0x8001114C},
    {0x0000002A, 0x80000005},
    {0x0000002B, 0x8001114D},
    {0x0000002C, 0x80000006},
    {0x0000002D, 0x8001114E},
    {0x0000002E, 0x80000007},
    {0x0000002F, 0x8001114F},
    {0x00000500, 0x00003000},
    {0x00000501, 0x01FFFFFF},
    {0x00000502, 0x00000002},
    {0x00000503, 0x00000002},
#ifdef __BIG_ENDIAN
    {0x00000508, 0x01088043},
#else
    {0x00000508, 0x01008043},
#endif
    {0x0000050A, 0x00000000},
    {0x0000050B, 0x00000000},
#ifdef __BIG_ENDIAN
    {0x0000050C, 0x01088019},
#else
    {0x0000050C, 0x01008019},
#endif
    {0x0000050E, 0x00000000},
    {0x0000050F, 0x00000000},
#ifdef __BIG_ENDIAN
    {0x00000510, 0x01088018},
#else
    {0x00000510, 0x01008018},
#endif
    {0x00000512, 0x00000000},
    {0x00000513, 0x00000000},
#ifdef __BIG_ENDIAN
    {0x00000514, 0x01088021},
#else
    {0x00000514, 0x01008021},
#endif
    {0x00000516, 0x00000000},
    {0x00000517, 0x00000000},
#ifdef __BIG_ENDIAN
    {0x00000518, 0x0108805F},
#else
    {0x00000518, 0x0100805F},
#endif
    {0x0000051A, 0x00000000},
    {0x0000051B, 0x00000000},
#ifdef __BIG_ENDIAN
    {0x0000051C, 0x0108804B},
#else
    {0x0000051C, 0x0100804B},
#endif
    {0x0000051E, 0x00000000},
    {0x0000051F, 0x00000000},
    {0x00000520, 0x0100A048},
    {0x00000521, 0x00000D01},
    {0x00000522, 0x11401140},
    {0x00000523, 0x00000000},
    {0x00000524, 0x0300A094},
    {0x00000525, 0x00000D01},
    {0x00000526, 0x11401140},
    {0x00000527, 0x00000000},
    {0x00000528, 0x0300A095},
    {0x00000529, 0x00000D01},
    {0x0000052A, 0x11401140},
    {0x0000052B, 0x00000000},
#ifdef __BIG_ENDIAN
    {0x0000052C, 0x00080058},
#else
    {0x0000052C, 0x00000058},
#endif
    {0x0000052E, 0x11401140},
    {0x0000052F, 0x00000000},
#ifdef __BIG_ENDIAN
    {0x00000530, 0x00080059},
#else
    {0x00000530, 0x00000059},
#endif
    {0x00000532, 0x11401140},
    {0x00000533, 0x00000000},
    {0x00000534, 0x0000005A},
    {0x00000536, 0x11401140},
    {0x00000537, 0x00000000},
    {0x00000538, 0x0000005B},
    {0x0000053A, 0x11401140},
    {0x0000053B, 0x00000000},
    {0x0000053C, 0x00000093},
    {0x0000053E, 0x11401140},
    {0x0000053F, 0x00000000},
#ifdef __BIG_ENDIAN
    {0x00000540, 0x0308A01C},
#else
    {0x00000540, 0x0300A01C},
#endif
    {0x00000542, 0x11401140},
    {0x00000543, 0x00000000}
};
static unsigned nv10TablePRAMIN_8BPP[][2] =
{
    /*           0xXXXXXX01 For  MSB mono format */
    /*           0xXXXXXX02 For  LSB mono format */
    {0x00000509, 0x00000302},
    {0x0000050D, 0x00000302},
    {0x00000511, 0x00000202},
    {0x00000515, 0x00000302},
    {0x00000519, 0x00000302},
    {0x0000051D, 0x00000302},
    {0x0000052D, 0x00000302},
    {0x0000052E, 0x00000302},
    {0x00000535, 0x00000000},
    {0x00000539, 0x00000000},
    {0x0000053D, 0x00000000},
    {0x00000541, 0x00000302}
};
static unsigned nv10TablePRAMIN_15BPP[][2] =
{
    /*           0xXXXXXX01 For  MSB mono format */
    /*           0xXXXXXX02 For  LSB mono format */
    {0x00000509, 0x00000902},
    {0x0000050D, 0x00000902},
    {0x00000511, 0x00000802},
    {0x00000515, 0x00000902},
    {0x00000519, 0x00000902},
    {0x0000051D, 0x00000902},
    {0x0000052D, 0x00000902},
    {0x0000052E, 0x00000902},
    {0x00000535, 0x00000902},
    {0x00000539, 0x00000902},
    {0x0000053D, 0x00000902},
    {0x00000541, 0x00000902}
};
static unsigned nv10TablePRAMIN_16BPP[][2] =
{
    /*           0xXXXXXX01 For  MSB mono format */
    /*           0xXXXXXX02 For  LSB mono format */
    {0x00000509, 0x00000C02},
    {0x0000050D, 0x00000C02},
    {0x00000511, 0x00000B02},
    {0x00000515, 0x00000C02},
    {0x00000519, 0x00000C02},
    {0x0000051D, 0x00000C02},
    {0x0000052D, 0x00000C02},
    {0x0000052E, 0x00000C02},
    {0x00000535, 0x00000C02},
    {0x00000539, 0x00000C02},
    {0x0000053D, 0x00000C02},
    {0x00000541, 0x00000C02}
};
static unsigned nv10TablePRAMIN_32BPP[][2] =
{
    /*           0xXXXXXX01 For  MSB mono format */
    /*           0xXXXXXX02 For  LSB mono format */
    {0x00000509, 0x00000E02},
    {0x0000050D, 0x00000E02},
    {0x00000511, 0x00000D02},
    {0x00000515, 0x00000E02},
    {0x00000519, 0x00000E02},
    {0x0000051D, 0x00000E02},
    {0x0000052D, 0x00000E02},
    {0x0000052E, 0x00000E02},
    {0x00000535, 0x00000E02},
    {0x00000539, 0x00000E02},
    {0x0000053D, 0x00000E02},
    {0x00000541, 0x00000E02}
};
