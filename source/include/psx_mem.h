/**
 * PS1 fixed addresses (main RAM buffers and the 1 KiB scratchpad).
 *
 * Every fixed address in the game goes through PSX_ADDR(literal), which keeps it an integer:
 * - Matching build: the literal itself.
 * - PS2 port: the same offset in the HAL's arenas (psx-to-ps2-HAL src/psx_mem.c), g_PsxRam for main
 *   RAM (any mirror) and g_PsxScratch for the scratchpad, so the game's memory map is kept while the
 *   program lives elsewhere.
 *
 * tools/port/find_fixed_addresses.py reports literals that aren't wrapped.
 */
#ifndef __MGS_PSX_MEM_H__
#define __MGS_PSX_MEM_H__

#define PSX_RAM_SIZE     0x200000
#define PSX_SCRATCH_SIZE 0x400

#ifdef MGS_PORT
extern unsigned char g_PsxRam[];
extern unsigned char g_PsxScratch[];

#define PSX_ADDR(addr)                                                                          \
    (((unsigned int)(addr) & 0xFFFFFC00) == 0x1F800000                                         \
         ? (unsigned int)g_PsxScratch + ((unsigned int)(addr) & (PSX_SCRATCH_SIZE - 1))        \
         : (unsigned int)g_PsxRam + ((unsigned int)(addr) & (PSX_RAM_SIZE - 1)))
#else
#define PSX_ADDR(addr) (addr)
#endif

#endif // __MGS_PSX_MEM_H__
