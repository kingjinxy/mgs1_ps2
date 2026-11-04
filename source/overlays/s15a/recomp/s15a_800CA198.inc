extern char R_s15a_dat_800D9258[] __asm__("s15a_dat_800D9258");
extern char R_s15a_800C9C10[] __asm__("s15a_800C9C10");
int G_s15a_800CA198(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CA198");
int G_s15a_800CA198(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[2] = 0;
    *(int *)((u)r[29] + 16) = r[31];
    *(int *)((u)r[2] + (int)R_s15a_dat_800D9258) = 0; CALL(R_s15a_800C9C10);
    r[3] = (u)r[2] + (u)0;
    c = (((int)r[3] < 0)); r[2] = (u)0 + -1; if (c) goto L800ca1bc;
    r[2] = (u)0 + (u)0;
    L800ca1bc:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
