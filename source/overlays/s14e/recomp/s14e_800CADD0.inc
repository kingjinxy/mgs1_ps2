extern char R_ZAKO14Command[] __asm__("ZAKO14Command");
extern char R_s14e_800CA998[] __asm__("s14e_800CA998");
extern char R_s14e_800CAA7C[] __asm__("s14e_800CAA7C");
extern char R_s14e_800CABFC[] __asm__("s14e_800CABFC");
extern char R_s14e_800CAD24[] __asm__("s14e_800CAD24");
int G_s14e_800CADD0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CADD0");
int G_s14e_800CADD0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    *(char *)((u)r[16] + 2978) = 0; CALL(R_s14e_800CAA7C);
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + ((int)R_ZAKO14Command + 28));
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2]));  if (c) goto L800cae14;
    r[4] = (u)r[16] + (u)0; CALL(R_s14e_800CA998);
    r[4] = (u)r[16] + (u)0; CALL(R_s14e_800CABFC);
    r[4] = (u)r[16] + (u)0; CALL(R_s14e_800CAD24);
    L800cae14:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
