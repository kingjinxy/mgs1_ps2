#ifdef MGS_PORT
#include "recomp.h"
#endif
#include "mgstype.h"

const int SECTION(".rdata") jpt_800DD2C4[] = {0x800DC774, 0x800DC774, 0x800DC77C, 0x800DC77C, 0x800DC784};
#ifdef MGS_PORT
#include "overlays/s11g/recomp/s11g_blastoff_800DBF88.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s11g/s11g_blastoff_800DBF88.s")
#endif