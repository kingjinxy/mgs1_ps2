/** @brief Scripted pad presses for test runs in PCSX2, which has no pad input of its own here.
 * MGS_PAD_SCRIPT="from-to:buttons,..." (build/link_ps2.py): port 1 holds the buttons (hex, libgv.h's PAD_*
 * bits: 0800 START, 0020 Circle, 0040 Cross, 1000 up, 4000 down) from vertical blank `from` to `to`
 * (decimal, mts_get_tick_count). mts_pad.c's do_control clears them from the (active-low) state it reads.
 * It runs in the vertical blank interrupt: no C library calls here (strtoul or printf there crashed the
 * EE). Without the define nothing is pressed. */

#ifdef MGS_PAD_SCRIPT
static const char* number(const char* p, int base, unsigned int* out)
{
    unsigned int v = 0, d;
    for (;; p++)
    {
        if (*p >= '0' && *p <= '9')
        {
            d = (unsigned int)(*p - '0');
        }
        else if (base == 16 && (*p | 0x20) >= 'a' && (*p | 0x20) <= 'f')
        {
            d = (unsigned int)((*p | 0x20) - 'a' + 10);
        }
        else
        {
            break;
        }
        v = v * (unsigned int)base + d;
    }
    *out = v;
    return p;
}
#endif

int Port_PadScript(int port, int vblank)
{
#ifdef MGS_PAD_SCRIPT
    const char*  p = MGS_PAD_SCRIPT;
    unsigned int now = (unsigned int)vblank, from, to, buttons, held = 0;
    if (port != 0)
    {
        return 0;
    }
    while (*p)
    {
        p  = number(p, 10, &from);
        to = from;
        if (*p == '-')
        {
            p = number(p + 1, 10, &to);
        }
        if (*p != ':')
        {
            break; /* malformed */
        }
        p = number(p + 1, 16, &buttons);
        if (now >= from && now <= to)
        {
            held |= buttons;
        }
        if (*p != ',')
        {
            break;
        }
        p++;
    }
    return (int)held;
#else
    (void)port;
    (void)vblank;
    return 0;
#endif
}
