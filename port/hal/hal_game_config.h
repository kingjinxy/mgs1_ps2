/** @brief MGS's settings for the HAL (psx-to-ps2-HAL include/port/hal_game.h). Plain macros only: the
 * HAL's PS2-side files include this against ps2sdk's headers, not the game's. */

#ifndef HAL_GAME_CONFIG_H
#define HAL_GAME_CONFIG_H

#define HAL_GAME_NAME         "MGS"
#define HAL_GAME_PSX_RAM_SIZE 0x200000

/* Found on PCSX2's host file system only (ps2/crash_ps2.c): the ELF build/link_ps2.py writes. */
#define HAL_GAME_HOST_PROBE "mgs.elf"

/* Memory card (psx_card.c, ps2/memcard_ps2.c): MGS Integral's PS1 product code (MGS_MemoryCardName,
 * main.c), the PS2 save folder holding the PS1 card images, its title, and the 16x16 save icon TIM
 * (port/src/hal_game.c builds it from the game's own icon data). */
#define HAL_GAME_PS1_PRODUCT          "BISLPM-86247"
#define HAL_GAME_PS2_SAVE_DIR         "BISLPM-86247MGS"
#define HAL_GAME_PS2_ICON_FILE        "MGS.ICO"
#define HAL_GAME_PS2_SAVE_TITLE       "METAL GEAR SOLIDPS1 saves"
#define HAL_GAME_PS2_SAVE_TITLE_BREAK 16
#define HAL_GAME_SAVE_ICON            g_MgsSaveIconTim
/* memcard.c waits for card events in mts_wait_vbl loops (their callbacks set its flags), never in
 * TestEvent: _card_info answers at once. */
#define HAL_GAME_CARD_INFO_WAIT 1

/* mts_pad.c reads the pads from the vertical blank callback, which the HAL runs in the interrupt: a thread
 * polls them instead of VSync (ps2/pad_ps2.c). */
#define HAL_GAME_PAD_THREAD 1

/* Restarts (crash restarts, tools/port/ps2_ctl.py restart/deploy) boot the disc's BOOT2 again
 * (build/link_ps2.py's SYSTEM.CNF). */
#define RELAUNCH_ELF "cdrom0:\\MGSP_000.01;1"

/* Not set yet: the disc (decision B in docs/Planning Doc.md replaces the HAL's libcd_ps2.c);
 * build/link_ps2.py leaves that file out until then. */

#endif
