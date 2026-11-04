extern char R_GCL_ForceExecProc[] __asm__("GCL_ForceExecProc");
int G_s10a_800DD3F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800DD3F4");
int G_s10a_800DD3F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[31];
    r[2] = *(int *)((u)r[4] + 1924);
    c = (((int)r[2] < 0)); *(int *)((u)r[29] + 24) = 0; if (c) goto L800dd430;
    r[2] = *(int *)((u)r[4] + 1956);
    r[3] = (u)0 + 1;
    *(short *)((u)r[29] + 16) = r[3];
    r[3] = (u)r[29] + 24;
    *(int *)((u)r[29] + 20) = r[3];
    *(int *)((u)r[29] + 24) = r[2];
    r[4] = *(int *)((u)r[4] + 1924);
    r[5] = (u)r[29] + 16; CALL(R_GCL_ForceExecProc);
    L800dd430:;
    r[31] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
