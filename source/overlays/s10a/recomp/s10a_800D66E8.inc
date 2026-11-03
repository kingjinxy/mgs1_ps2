extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_GCL_ExecProc[] __asm__("GCL_ExecProc");
int G_s10a_800D66E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D66E8");
int G_s10a_800D66E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    r[6] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 40) = r[31];
    r[2] = *(int *)((u)r[6] + 2496);
    c = (((int)r[2] < 0)); r[2] = (u)0 + 3; if (c) goto L800d673c;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = 0;
    r[3] = (u)r[2] + (int)R_GM_PlayerPosition;
    r[4] = *(short *)((u)r[2] + (int)R_GM_PlayerPosition);
    r[5] = *(short *)((u)r[3] + 2);
    r[3] = *(short *)((u)r[3] + 4);
    r[2] = (u)r[29] + 24;
    *(int *)((u)r[29] + 20) = r[2];
    *(int *)((u)r[29] + 24) = r[4];
    *(int *)((u)r[29] + 28) = r[5];
    *(int *)((u)r[29] + 32) = r[3];
    r[4] = *(int *)((u)r[6] + 2496);
    r[5] = (u)r[29] + 16; CALL(R_GCL_ExecProc);
    L800d673c:;
    r[31] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
