#include "mgstype.h"
#include "game/game.h"

#ifdef MGS_PORT
/* Kept in this order, out of common (SECTION is empty in the port): s19b_dword_800DE64C: a Work.
   s03d's overlay3.c is the same. */
#undef SECTION
#define SECTION(x) __attribute__((section(".bss.s19b_overlay6")))
#endif

typedef struct _JEEP_SYSTEM
{
    char     pad1[0x4];
    CONTROL *control;
    char     pad2[0x10];
    SVECTOR  pos;
    char     pad3[0x40];
    OBJECT  *body;
    char     pad4[0x1C];
    MATRIX   world;
    char     pad5[0xCC];
} JEEP_SYSTEM;

int SECTION(".bss") s19b_dword_800DE648;
int SECTION(".bss") s19b_dword_800DE64C;
int SECTION(".bss") s19b_dword_800DE650;
int SECTION(".bss") s19b_dword_800DE654;

JEEP_SYSTEM SECTION(".bss") Takabe_JeepSystem;

int SECTION(".bss") s19b_dword_800DE7C4;
