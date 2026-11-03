/* What tools/port/mips2c.py's C uses: the PS1's registers and stack frame, with room for stack arguments. */
#ifndef RECOMP_H
#define RECOMP_H
typedef unsigned int u;
/* the GTE, for translated cop2 instructions (the HAL's software GTE, port/gte.h) */
void Gte_DataWrite(unsigned int reg, unsigned int value);
unsigned int Gte_DataRead(unsigned int reg);
void Gte_CtrlWrite(unsigned int reg, unsigned int value);
unsigned int Gte_CtrlRead(unsigned int reg);
void Gte_Command(unsigned int cmd);
#define RECOMP_ENTRY(frame)                                                                  \
    int r[32], c, t, hi_ = 0, lo_ = 0; long long mul = 0;                                    \
    unsigned char stk[(frame) + 32] __attribute__((aligned(8)));                             \
    (void)c; (void)t; (void)hi_; (void)lo_; (void)mul;                                       \
    { extern const char *Port_RecompLast[8]; extern int Port_RecompN; Port_RecompLast[Port_RecompN++ & 7] = __func__; } \
    r[4] = a0; r[5] = a1; r[6] = a2; r[7] = a3; r[2] = 0; r[3] = 0;                          \
    r[29] = (int)stk + (frame);                                                              \
    ((int *)r[29])[4] = a4; ((int *)r[29])[5] = a5; ((int *)r[29])[6] = a6; ((int *)r[29])[7] = a7;
#define RECOMP_RETURN return r[2]
#define CALL(f) do { int *s_ = (int *)r[29]; \
        r[2] = ((int (*)(int, int, int, int, int, int, int, int))(f))(r[4], r[5], r[6], r[7], s_[4], s_[5], s_[6], s_[7]); } while (0)
static inline int LWL(u a, int v) { unsigned char *p = (unsigned char *)(a & ~3u); int n = a & 3, i; u x = v; for (i = 0; i <= n; i++) { x = (x & ~(0xffu << (24 - 8 * i))) | ((u)p[n - i] << (24 - 8 * i)); } return x; }
static inline int LWR(u a, int v) { unsigned char *p = (unsigned char *)(a & ~3u); int n = a & 3, i; u x = v; for (i = n; i < 4; i++) { x = (x & ~(0xffu << (8 * (i - n)))) | ((u)p[i] << (8 * (i - n))); } return x; }
static inline void SWL(u a, u v) { unsigned char *p = (unsigned char *)(a & ~3u); int n = a & 3, i; for (i = 0; i <= n; i++) { p[n - i] = v >> (24 - 8 * i); } }
static inline void SWR(u a, u v) { unsigned char *p = (unsigned char *)(a & ~3u); int n = a & 3, i; for (i = n; i < 4; i++) { p[i] = v >> (8 * (i - n)); } }
#endif
