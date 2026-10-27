/* EE build: PSY-Q's libetc.h, with its scratchpad macro moved to the port's scratchpad (psx_mem.h). */
#include_next "libetc.h"
#include "psx_mem.h"
#undef getScratchAddr
#define getScratchAddr(offset) ((u_long *)(PSX_ADDR(0x1f800000) + (offset) * 4))
