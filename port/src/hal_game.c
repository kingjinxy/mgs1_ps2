/** @brief MGS's side of the HAL's game hooks (psx-to-ps2-HAL include/port/hal_game.h). PS2 side:
 * compiled against ps2sdk's headers (build/link_ps2.py). */

#include <stdio.h>
#include "port/hal_game.h"

extern void Port_LogDirect(void); /* HAL ps2/log_ps2.c */

/* The save icons of the game's data screen (menu/datasave.c): 16-colour CLUT (8 words), then 16x16
 * 4-bit pixels (32 words) each; the first is Snake. */
extern int clutsAndIcons_8009E774[6][40];

/** HAL_GAME_SAVE_ICON (hal_game_config.h): Snake's icon as a 4-bit TIM for the PS2 save's icon
 * (HAL psx_card.c). Header, CLUT block (12 + 32 bytes), image block (12 + 128 bytes). */
unsigned int g_MgsSaveIconTim[48];

static void save_icon_build(void)
{
    unsigned int* t = g_MgsSaveIconTim;
    int           i;
    t[0] = 0x10;           /* TIM */
    t[1] = 0x08;           /* 4-bit, with a CLUT */
    t[2] = 12 + 32;        /* CLUT block: size, x/y, w=16/h=1 */
    t[3] = 0;
    t[4] = 16 | 1 << 16;
    for (i = 0; i < 8; i++)
    {
        t[5 + i] = (unsigned int)clutsAndIcons_8009E774[0][i];
    }
    t[13] = 12 + 128;      /* image block: size, x/y, w=4 (16-bit units)/h=16 */
    t[14] = 0;
    t[15] = 4 | 16 << 16;
    for (i = 0; i < 32; i++)
    {
        t[16 + i] = (unsigned int)clutsAndIcons_8009E774[0][8 + i];
    }
}

void HalGame_Init(void)
{
    /* The PS1's printf writes at once; MGS prints its boot steps without newlines ("mem:", "pad:" ...). */
    setvbuf(stdout, NULL, _IONBF, 0);
    save_icon_build();
#ifdef MGS_LOG_DIRECT
    /* Debugging: console writes straight through, not via the log thread (which the vertical blank
     * handler wakes, so it is silent until the game sets that up). */
    Port_LogDirect();
#endif
}
