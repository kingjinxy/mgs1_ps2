/** @brief MGS's settings for the HAL (psx-to-ps2-HAL include/port/hal_game.h). Plain macros only: the
 * HAL's PS2-side files include this against ps2sdk's headers, not the game's. */

#ifndef HAL_GAME_CONFIG_H
#define HAL_GAME_CONFIG_H

#define HAL_GAME_NAME         "MGS"
#define HAL_GAME_PSX_RAM_SIZE 0x200000

/* Found on PCSX2's host file system only (ps2/crash_ps2.c): the ELF build/link_ps2.py writes. */
#define HAL_GAME_HOST_PROBE "mgs.elf"

/* Not set yet: the disc (decision B in docs/Planning Doc.md replaces the HAL's libcd_ps2.c) and the
 * memory card (psx_card.c, memcard_ps2.c); build/link_ps2.py leaves those files out until then. */

#endif
