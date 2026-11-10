extern char R_s17a_800DE7B4[] __asm__("s17a_800DE7B4");
int G_s17a_800DE8CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800DE8CC");
int G_s17a_800DE8CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[2] = (u)r[4] + (u)0;
    r[3] = (u)r[5] + (u)0;
    r[7] = (u)r[6] + (u)0;
    r[4] = (u)r[2] + 32;
    *(int *)((u)r[29] + 16) = r[31];
    r[5] = *(short *)((u)r[2] + 42);
    r[6] = (u)r[3] + (u)0; CALL(R_s17a_800DE7B4);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
