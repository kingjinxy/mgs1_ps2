#include "ps1align.h"
#include "game/game.h"

int s07a_dword_800C35F8[8] PS1_ALIGN(4) = { 2500, 3500, 4000, 5000, 5500, 5600, 5700, 5800 };
unsigned short s07a_dword_800C3618[8] PS1_ALIGN(2) = { 450, 15, 30, 60, 90, 0, 32001, 30000 };

short ActTable_800C3628[54] =
{
    0x13, 0x36, 0x0A, 0x16, 0x09, 0x22, 0x23, 0x24, 0x2D,
    0x0D, 0x0C, 0x1A, 0x0F, 0x0E, 0x10, 0x1B, 0x08, 0x2E,
    0x32, 0x15, 0x1E, 0x1F, 0x20, 0x21, 0x25, 0x34, 0x35,
    0x19, 0x05, 0x02, 0x2A, 0x04, 0x27, 0x28, 0x06, 0x07,
    0x26, 0x03, 0x29, 0x11, 0x12, 0x2B, 0x17, 0x18, 0x1C,
    0x1D, 0x00, 0x01, 0x33, 0x11, 0x12, 0x2B, 0x16, 0x00
};

SVECTOR s07a_dword_800C3694 = {-150, 0, 300};
SVECTOR s07a_dword_800C369C = {0, 0, 100};
SVECTOR s07a_dword_800C36A4 = {-1024, 0, 0};
SVECTOR s07a_dword_800C36AC = {0, 0, 100};
SVECTOR s07a_dword_800C36B4 = {-1024, 0, 0};

extern const char s07a_dword_800E2FA4[], s07a_aSocomx_800E2F98[], s07a_aFamasx_800E2F8C[];
void MERYL_PutSound(), MERYL_PutBreath(), MERYL_PutLSight(), MERYL_PutBullet();

char *s07a_dword_800C36BC[] =
{
    (char *)s07a_dword_800E2FA4,
    (char *)s07a_aSocomx_800E2F98,
    (char *)s07a_aFamasx_800E2F8C
};

void *s07a_dword_800C36C8[] = 
{
    (void *)MERYL_PutSound,
    (void *)MERYL_PutBreath,
    (void *)MERYL_PutLSight,
    (void *)MERYL_PutBullet
};

SVECTOR s07a_dword_800C36D8 = {5, -500, 80};
SVECTOR s07a_dword_800C36E0 = {0, -550, 950};

u_short s07a_dword_800C36E8[] PS1_ALIGN(2) = {100, 50, 25, 10};

int s07a_dword_800C36F0[32] =
{
    0,
    0x1,
    0x2,
    0x4,
    0x2000,
    0x40,
    0x80,
    0x200,
    0x400,
    0x800,
    0x100,
    0x800000,
    0x1000000,
    0,
    0,
    0,
    0,
    0x1,
    0x2,
    0x4,
    0x2000,
    0x40,
    0x80,
    0x200,
    0x400,
    0x800,
    0,
    0,
    0,
    0,
    0,
    0x1F
};

SVECTOR s07a_dword_800C3770 = {7500, 0, -20000};
SVECTOR s07a_dword_800C3778 = {4500, 0, -7500};
