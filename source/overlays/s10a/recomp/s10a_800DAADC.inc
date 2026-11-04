extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_GCL_ExecProc[] __asm__("GCL_ExecProc");
int G_s10a_800DAADC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800DAADC");
int G_s10a_800DAADC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    r[2] = (u)0 + 3;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = 0;
    r[5] = *(short *)((u)r[2] + (int)R_GM_PlayerPosition);
    r[3] = (u)r[2] + (int)R_GM_PlayerPosition;
    *(int *)((u)r[29] + 40) = r[31];
    r[6] = *(short *)((u)r[3] + 2);
    r[3] = *(short *)((u)r[3] + 4);
    r[2] = (u)r[29] + 24;
    *(int *)((u)r[29] + 20) = r[2];
    *(int *)((u)r[29] + 24) = r[5];
    *(int *)((u)r[29] + 28) = r[6];
    *(int *)((u)r[29] + 32) = r[3];
    r[4] = *(int *)((u)r[4] + 2504);
    r[5] = (u)r[29] + 16; CALL(R_GCL_ExecProc);
    r[31] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
