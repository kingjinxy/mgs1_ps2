extern char R_GCL_ExecProc[] __asm__("GCL_ExecProc");
int G_s19a_800D8E54(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D8E54");
int G_s19a_800D8E54(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[31];
    c = ((r[4] == 0)); *(int *)((u)r[29] + 24) = r[5]; if (c) goto L800d8e7c;
    r[2] = (u)0 + 1;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = (u)r[29] + 24;
    r[5] = (u)r[29] + 16;
    *(int *)((u)r[29] + 20) = r[2]; CALL(R_GCL_ExecProc);
    L800d8e7c:;
    r[31] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
