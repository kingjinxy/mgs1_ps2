#ifdef MGS_PORT
#include "recomp.h"
#endif
#include "ps1align.h"
#include "game/game.h"

/*---------------------------------------------------------------------------*/

typedef struct _Work {
    /* 0x00 */ GV_ACT actor;
    /* 0x20 */ char   pad20[ 0x95C ];
} Work;

int s07b_dword_800C32F8 = 0x000001C0;
int s07b_dword_800C32FC = 0x000002EE;
int s07b_dword_800C3300 = 0x000000FA;
int s07b_dword_800C3304 = 0x000004FF;
int s07b_dword_800C3308 = 0x00000000;
int s07b_dword_800C330C = 0x00000064;
int s07b_dword_800C3310 = 0x0000FC00;
int s07b_dword_800C3314 = 0x00000000;
int s07b_dword_800C3318 = 0xFE8E0014;
int s07b_dword_800C331C = 0x0000003C;
int s07b_dword_800C3320 = 0x00000000;
int s07b_dword_800C3324 = 0x0000012C;
int s07b_dword_800C3328 = 0x0258012C;
int s07b_dword_800C332C = 0x0000012C;

const char s07b_dword_800E4B4C[] = "スネーク";
const char s07b_dword_800E4B58[] = "go_motion";
const char s07b_dword_800E4B64[] = "stance";
const char s07b_dword_800E4B6C[] = "run_move";
const char s07b_dword_800E4B78[] = "set voice %d\n";

const char s07b_dword_800E4B88[] PS1_ALIGN(4) = {0x0, 0x0, 0x0, 0x0};

const int s07b_dword_800E4B8C = -2146675940;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4B90 = -2146675940;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4B94 = -2146675872;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4B98 = -2146675852;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4B9C = -2146675940;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */

const char s07b_dword_800E4BA0[] = "MERYL";

const char s07b_dword_800E4BA8[] PS1_ALIGN(4) = {0x0, 0x0, 0x0, 0x0};

const int s07b_dword_800E4BAC = -2146663956;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4BB0 = -2146663624;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4BB4 = -2146663576;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4BB8 = -2146663380;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4BBC = -2146663316;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */

const char s07b_dword_800E4BC0[] PS1_ALIGN(4) = {0x0, 0x0, 0x0, 0x0};

const int s07b_dword_800E4BC4 = -2146656828;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4BC8 = -2146656812;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4BCC = -2146656796;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4BD0 = -2146656780;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4BD4 = -2146656764;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4BD8 = -2146656748;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4BDC = -2146656732;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4BE0 = -2146656716;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */
const int s07b_dword_800E4BE4 = -2146656700;  /* unused in the port: mips2c.py reads jump tables from the PS1 binary */

const char s07b_dword_800E4BE8[] = "meryl";
const char s07b_dword_800E4BF0[] = "mel_07b";
const char s07b_dword_800E4BF8[] = "meryl07b.c";

/* TODO: split out psyco.c data */
int SECTION(".bss") s07b_dword_800E5BA0;
int SECTION(".bss") s07b_dword_800E5BA4;
int SECTION(".bss") s07b_dword_800E5BA8;
int SECTION(".bss") s07b_dword_800E5BAC;
int SECTION(".bss") s07b_dword_800E5BB0;
int SECTION(".bss") s07b_dword_800E5BB4;
int SECTION(".bss") s07b_dword_800E5BB8;
int SECTION(".bss") s07b_dword_800E5BBC;
int SECTION(".bss") s07b_dword_800E5BC0;
int SECTION(".bss") s07b_dword_800E5BC4;
int SECTION(".bss") s07b_dword_800E5BC8;
int SECTION(".bss") s07b_dword_800E5BCC;
int SECTION(".bss") s07b_dword_800E5BD0;
int SECTION(".bss") s07b_dword_800E5BD4;
int SECTION(".bss") s07b_dword_800E5BD8;
int SECTION(".bss") s07b_dword_800E5BDC;

/*---------------------------------------------------------------------------*/

#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C46F0.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C46F0.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C473C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C473C.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C47D4.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C47D4.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C4854.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C4854.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C4974.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C4974.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C49CC.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C49CC.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C4A18.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C4A18.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C4A94.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C4A94.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C4B58.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C4B58.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C4E90.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C4E90.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C4F50.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C4F50.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C4FB8.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C4FB8.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C500C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C500C.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C50D8.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C50D8.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C5160.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C5160.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C51DC.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C51DC.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C52B8.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C52B8.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C53A0.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C53A0.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C5490.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C5490.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C54C0.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C54C0.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C54E8.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C54E8.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C5514.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C5514.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C5554.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C5554.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C5598.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C5598.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C5B14.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C5B14.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C5CFC.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C5CFC.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C5DC4.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C5DC4.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C6000.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C6000.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C60F0.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C60F0.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C61D8.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C61D8.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C627C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C627C.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C63F4.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C63F4.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C6538.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C6538.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C6634.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C6634.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C6964.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C6964.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C6AA4.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C6AA4.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C6B8C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C6B8C.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C6C5C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C6C5C.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C6D80.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C6D80.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C6E54.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C6E54.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C7040.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C7040.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C714C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C714C.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C73F0.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C73F0.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C7604.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C7604.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C76C8.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C76C8.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C77A8.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C77A8.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C796C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C796C.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C7AA8.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C7AA8.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C7C64.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C7C64.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C7D88.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C7D88.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C7E98.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C7E98.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C7F48.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C7F48.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C8010.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C8010.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C84FC.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C84FC.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C8510.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C8510.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C89E0.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C89E0.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C8BB4.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C8BB4.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C8F9C.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C8F9C.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C9044.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C9044.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C9304.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C9304.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C9454.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C9454.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C96B8.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C96B8.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C9738.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C9738.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C9954.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C9954.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C9994.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C9994.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C9A58.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C9A58.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C9B24.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C9B24.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C9B94.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C9B94.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C9C74.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C9C74.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800C9D44.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800C9D44.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CA1FC.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CA1FC.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CA2EC.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CA2EC.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CA4FC.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CA4FC.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CA584.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CA584.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CA5FC.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CA5FC.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CA674.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CA674.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CA6EC.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CA6EC.s")
#endif
#ifdef MGS_PORT
#include "overlays/s07b/recomp/s07b_800CA8F8.inc"
#else
#pragma INCLUDE_ASM("asm/overlays/s07b/s07b_800CA8F8.s")
#endif
