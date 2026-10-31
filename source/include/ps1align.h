#ifndef __MGS_PS1ALIGN_H__
#define __MGS_PS1ALIGN_H__

/* Overlay data laid out as the PS1's: the code reaches some variables through others' addresses (a table
   indexed past its first word, a string split into 4-byte char arrays), but GCC for the EE aligns arrays to 8
   bytes, which opens gaps (s03d's "ippanhei" read as "ippa" + padding, its guards' action table). A variable
   aligned explicitly keeps that alignment. */
#ifdef MGS_PORT
#define PS1_ALIGN(n) __attribute__((aligned(n)))
#else
#define PS1_ALIGN(n)
#endif
#define STR_PIECE PS1_ALIGN(4)

#endif // __MGS_PS1ALIGN_H__
