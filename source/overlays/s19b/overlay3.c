#include "ps1align.h"
#include "mgstype.h"

#ifdef MGS_PORT
/* Kept in this order, out of common (SECTION is empty in the port): s19b_dword_800DE5C8: JlampState.
   s03d's overlay3.c is the same. */
#undef SECTION
#define SECTION(x) __attribute__((section(".bss.s19b_overlay3")))
#endif

const char s19b_dword_800DDD4C[] STR_PIECE = {0xe4, 0xfd, 0xbe, 0x4};
const char s19b_dword_800DDD50[] STR_PIECE = {'=', 0xfc, 0x0, 0x0};
const char s19b_dword_800DDD54[] STR_PIECE = {0xac, 0x1, 'U', 0x2};
const char s19b_dword_800DDD58[] STR_PIECE = {0xb6, 0x6, 0x0, 0x0};
const char s19b_dword_800DDD5C[] STR_PIECE = {'O', 0xfd, 0xde, 0x3};
const char s19b_dword_800DDD60[] STR_PIECE = {'Q', 0xfe, 0x0, 0x0};
const char s19b_dword_800DDD64[] STR_PIECE = {0xcb, 0x1, 'o', 0x3};
const char s19b_a_800DDD68[] = ";";

int SECTION(".bss") s19b_dword_800DE5B0;
int SECTION(".bss") s19b_dword_800DE5B4;
int SECTION(".bss") s19b_dword_800DE5B8;
int SECTION(".bss") s19b_dword_800DE5BC;
int SECTION(".bss") s19b_dword_800DE5C0;
int SECTION(".bss") s19b_dword_800DE5C4;
int SECTION(".bss") s19b_dword_800DE5C8;
int SECTION(".bss") s19b_dword_800DE5CC;
int SECTION(".bss") s19b_dword_800DE5D0;
int SECTION(".bss") s19b_dword_800DE5D4;
int SECTION(".bss") s19b_dword_800DE5D8;
int SECTION(".bss") s19b_dword_800DE5DC;
int SECTION(".bss") s19b_dword_800DE5E0;
int SECTION(".bss") s19b_dword_800DE5E4;
int SECTION(".bss") s19b_dword_800DE5E8;
int SECTION(".bss") s19b_dword_800DE5EC;
