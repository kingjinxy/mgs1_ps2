/** @brief MGS's side of the HAL's game hooks (psx-to-ps2-HAL include/port/hal_game.h). PS2 side:
 * compiled against ps2sdk's headers (build/link_ps2.py). */

#include <stdio.h>
#include "port/hal_game.h"

extern void Port_LogDirect(void); /* HAL ps2/log_ps2.c */

void HalGame_Init(void)
{
    /* The PS1's printf writes at once; MGS prints its boot steps without newlines ("mem:", "pad:" ...). */
    setvbuf(stdout, NULL, _IONBF, 0);
#ifdef MGS_LOG_DIRECT
    /* Debugging: console writes straight through, not via the log thread (which the vertical blank
     * handler wakes, so it is silent until the game sets that up). */
    Port_LogDirect();
#endif
}
