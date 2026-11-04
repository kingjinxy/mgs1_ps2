extern char R_GCL_ExecProc[] __asm__("GCL_ExecProc");
int G_s11h_800D0758(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800D0758");
int G_s11h_800D0758(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    r[2] = (u)0 + 1;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = (u)r[29] + 24;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 24) = r[5];
    *(int *)((u)r[29] + 20) = r[2];
    r[4] = *(int *)((u)r[4] + 2288);
    r[5] = (u)r[29] + 16; CALL(R_GCL_ExecProc);
    r[31] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
