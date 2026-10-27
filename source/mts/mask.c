// I think this object was originally implemented in assembly.
//
// mask.obj in 5thMix's MTS builds have no source filename (as GCC inserts
// a .file directive in the assembly output) and PSY-Q object parsers usually
// complain about an unknown record type or some other bullshit.

void SetExMask()
{
    // unknown psyq-specific debug function ?
#ifndef MGS_PORT // the EE assembler has no single-operand break code above 1023; a debug trap anyway
    __asm__("break 1030");
#endif
}

void *mts_get_bss_tail(void)
{
    // linker-defined symbol
    extern unsigned char _bss_orgend[];

    return (void *)_bss_orgend;
}
