extern char R_GCL_ExecProc[] __asm__("GCL_ExecProc");
int G_s19a_800CC5A8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CC5A8");
int G_s19a_800CC5A8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[5] = (u)r[5] << 2;
    r[4] = (u)r[4] + (u)r[5];
    *(int *)((u)r[29] + 16) = r[31];
    r[4] = *(int *)((u)r[4] + 3680);
    c = (((int)r[4] < 0));  if (c) goto L800cc5d0;
    r[5] = (u)0 + (u)0; CALL(R_GCL_ExecProc);
    L800cc5d0:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
