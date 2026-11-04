extern char R_GCL_ForceExecProc[] __asm__("GCL_ForceExecProc");
int G_s10a_800D674C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800D674C");
int G_s10a_800D674C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(56)
    r[29] = (u)r[29] + -56;
    *(int *)((u)r[29] + 48) = r[31];
    r[2] = *(short *)((u)r[4] + 36);
    *(int *)((u)r[29] + 24) = r[2];
    r[2] = *(short *)((u)r[4] + 38);
    *(int *)((u)r[29] + 28) = r[2];
    r[2] = *(short *)((u)r[4] + 40);
    *(int *)((u)r[29] + 32) = r[2];
    r[2] = *(short *)((u)r[4] + 46);
    *(int *)((u)r[29] + 36) = r[2];
    r[3] = *(int *)((u)r[4] + 1788);
    r[2] = (u)0 + 5;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = (u)r[29] + 24;
    *(int *)((u)r[29] + 20) = r[2];
    *(int *)((u)r[29] + 40) = r[3];
    r[4] = *(int *)((u)r[4] + 2532);
    r[5] = (u)r[29] + 16; CALL(R_GCL_ForceExecProc);
    r[31] = *(int *)((u)r[29] + 48);
    r[29] = (u)r[29] + 56; goto out;
out:
    RECOMP_RETURN;
}
