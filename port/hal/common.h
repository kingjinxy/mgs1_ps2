/** @brief What the HAL's generic sources (psx-to-ps2-HAL src/*.c) include as "common.h": the integer
 * types and PS1 memory macros of the SH1 decomp they came from. Only on their include path
 * (build/link_ps2.py), so it doesn't meet the game's own source/kojo/common.h. */

#ifndef _COMMON_H
#define _COMMON_H

#include <sys/types.h>

typedef signed char        s8;
typedef signed short       s16;
typedef signed int         s32;
typedef signed long long   s64;
typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef signed short       q3_12;
typedef signed int         q19_12;

#ifndef NULL
#define NULL 0
#endif

#define ARRAY_SIZE(arr) (s32)(sizeof(arr) / sizeof((arr)[0]))

#define PSX_RAM_SIZE     0x200000
#define PSX_SCRATCH_SIZE 0x400

extern u8 g_PsxRam[PSX_RAM_SIZE];
extern u8 g_PsxScratch[PSX_SCRATCH_SIZE];

#define PSX_RAM_ADDR(addr)        ((void*)&g_PsxRam[(u32)(addr) & (PSX_RAM_SIZE - 1)])
#define PSX_SCRATCH               ((void*)g_PsxScratch)
#define PSX_ADDR_CANON(ptr)       ((u32)(ptr))
#define PSX_SCRATCH_ADDR(offset)  ((void*)(((u8*)PSX_SCRATCH) + (offset)))

#endif
