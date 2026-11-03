extern char R_s10a_800DD0FC[] __asm__("s10a_800DD0FC");
extern char R_s10a_800DD440[] __asm__("s10a_800DD440");
int G_s10a_800DD1AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800DD1AC");
int G_s10a_800DD1AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s10a_800DD440);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800DD0FC);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
