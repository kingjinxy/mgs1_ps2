#include "ps1align.h"
#include "game/game.h"

#ifdef MGS_PORT
/* Kept in this order, out of common (SECTION is empty in the port): s05a_dword_800E3800: a CONTROL.
   s03d's overlay3.c is the same. */
#undef SECTION
#define SECTION(x) __attribute__((section(".bss.s05a_overlay2")))
#endif

int s05a_dword_800C362C = 0x00000000;
int s05a_dword_800C3630 = 0x00000000;
int s05a_dword_800C3634 = 0x00000000;
int s05a_dword_800C3638 = 0x00000000;

const char s05a_dword_800E340C[] STR_PIECE = {'m', '1', 'e', '1'};
const char s05a_dword_800E3410[] STR_PIECE = {'.', 'c', 0x0, 0x0};
const char s05a_dword_800E3414[] STR_PIECE = {'m', '1', 'e', '1'};
const char s05a_dword_800E3418[] STR_PIECE = {0x0, 0x0, 0x0, 0x0};
const char s05a_dword_800E341C[] STR_PIECE = {'m', '1', 'e', '1'};
const char s05a_dword_800E3420[] STR_PIECE = {'c', 'l', '1', 0x0};
const char s05a_dword_800E3424[] STR_PIECE = {'m', '1', 'e', '1'};
const char s05a_dword_800E3428[] STR_PIECE = {'c', 'l', '2', 0x0};
const char s05a_dword_800E342C[] STR_PIECE = {'m', '1', 'e', '1'};
const char s05a_dword_800E3430[] STR_PIECE = {'c', 'l', '3', 0x0};
const char s05a_dword_800E3434[] STR_PIECE = {'m', '1', 'e', '1'};
const char s05a_dword_800E3438[] STR_PIECE = {'c', 'r', '1', 0x0};
const char s05a_dword_800E343C[] STR_PIECE = {'m', '1', 'e', '1'};
const char s05a_dword_800E3440[] STR_PIECE = {'c', 'r', '2', 0x0};
const char s05a_dword_800E3444[] STR_PIECE = {'m', '1', 'e', '1'};
const char s05a_dword_800E3448[] STR_PIECE = {'c', 'r', '3', 0x0};
const char s05a_dword_800E344C[] STR_PIECE = {'t', 'h', 'r', 'o'};
const char s05a_dword_800E3450[] STR_PIECE = {'w', 0x0, 0x0, 0x0};
const char s05a_dword_800E3454[] STR_PIECE = {'G', 'U', 'N', 'N'};
const char s05a_dword_800E3458[] STR_PIECE = {'E', 'R', 0x0, '0'};
const char s05a_dword_800E345C[] STR_PIECE = {'m', '1', 't', 'h'};
const char s05a_dword_800E3460[] STR_PIECE = {'r', 'o', 'w', '.'};
const char s05a_dword_800E3464[] STR_PIECE = {'c', 0x0, 'S', 't'};

int SECTION(".bss") s05a_dword_800E3800;
int SECTION(".bss") s05a_dword_800E3804;
int SECTION(".bss") s05a_dword_800E3808;
int SECTION(".bss") s05a_dword_800E380C;
int SECTION(".bss") s05a_dword_800E3810;
int SECTION(".bss") s05a_dword_800E3814;
int SECTION(".bss") s05a_dword_800E3818;
int SECTION(".bss") s05a_dword_800E381C;
int SECTION(".bss") s05a_dword_800E3820;
int SECTION(".bss") s05a_dword_800E3824;
int SECTION(".bss") s05a_dword_800E3828;
int SECTION(".bss") s05a_dword_800E382C;
int SECTION(".bss") s05a_dword_800E3830;
int SECTION(".bss") s05a_dword_800E3834;
int SECTION(".bss") s05a_dword_800E3838;
int SECTION(".bss") s05a_dword_800E383C;
int SECTION(".bss") s05a_dword_800E3840;
int SECTION(".bss") s05a_dword_800E3844;
int SECTION(".bss") s05a_dword_800E3848;
int SECTION(".bss") s05a_dword_800E384C;
int SECTION(".bss") s05a_dword_800E3850;
int SECTION(".bss") s05a_dword_800E3854;
int SECTION(".bss") s05a_dword_800E3858;
int SECTION(".bss") s05a_dword_800E385C;
int SECTION(".bss") s05a_dword_800E3860;
int SECTION(".bss") s05a_dword_800E3864;
int SECTION(".bss") s05a_dword_800E3868;
int SECTION(".bss") s05a_dword_800E386C;
int SECTION(".bss") s05a_dword_800E3870;
int SECTION(".bss") s05a_dword_800E3874;
int SECTION(".bss") s05a_dword_800E3878;
