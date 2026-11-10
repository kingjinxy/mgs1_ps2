extern char R_GCL_ExecProc[] __asm__("GCL_ExecProc");
int G_s18a_800CE6B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CE6B4");
int G_s18a_800CE6B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2408);
    c = ((r[2] != 0)); r[3] = (u)0 + 29; if (c) goto L800ce6f4;
    r[4] = *(int *)((u)r[16] + 2528);
    c = (((int)r[4] < 0));  if (c) goto L800ce6f4;
    r[5] = (u)0 + (u)0; CALL(R_GCL_ExecProc);
    r[2] = *(int *)((u)r[16] + 2408);
    r[3] = (u)0 + 29;
    L800ce6f4:;
    *(int *)((u)r[16] + 2384) = r[3];
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + 2408) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
