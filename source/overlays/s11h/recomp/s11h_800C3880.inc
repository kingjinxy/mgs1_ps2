extern char R_s11h_800C382C[] __asm__("s11h_800C382C");
int G_s11h_800C3880(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800C3880");
int G_s11h_800C3880(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s11h_800C382C);
    *(int *)((u)r[16] + 56) = r[2];
    *(int *)((u)r[16] + 60) = r[2];
    r[2] = (u)0 + -1;
    *(int *)((u)r[16] + 48) = 0;
    *(short *)((u)r[16] + 42) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
