extern char R_GV_PauseLevel[] __asm__("GV_PauseLevel");
extern char R_GCL_ExecProc[] __asm__("GCL_ExecProc");
int G_s18a_800C3E10(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C3E10");
int G_s18a_800C3E10(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[5] = 0;
    r[2] = *(int *)((u)r[5] + (int)R_GV_PauseLevel);
    r[3] = (u)0 + -5;
    *(int *)((u)r[29] + 16) = r[31];
    r[4] = *(int *)((u)r[4] + 32);
    r[2] = r[2] & r[3];
    c = (((int)r[4] < 0)); *(int *)((u)r[5] + (int)R_GV_PauseLevel) = r[2]; if (c) goto L800c3e3c;
    r[5] = (u)0 + (u)0; CALL(R_GCL_ExecProc);
    L800c3e3c:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
