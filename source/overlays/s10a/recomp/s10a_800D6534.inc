extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_GCL_ForceExecProc[] __asm__("GCL_ForceExecProc");
int G_s10a_800D6534(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D6534");
int G_s10a_800D6534(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[5] = (u)r[4] + (u)0;
    r[4] = 0xefff0000;
    r[3] = 0;
    r[2] = *(int *)((u)r[3] + (int)R_GM_GameStatus);
    r[4] = r[4] | 65535;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = r[2] & r[4];
    *(int *)((u)r[3] + (int)R_GM_GameStatus) = r[2];
    r[3] = *(int *)((u)r[5] + 88);
    r[2] = (u)0 + 9;
    c = ((r[3] == r[2])); r[2] = (u)0 + 4; if (c) goto L800d6570;
    c = ((r[3] != r[2]));  if (c) goto L800d657c;
    L800d6570:;
    r[3] = *(unsigned short *)((u)r[5] + 88);
    r[2] = 0;
    *(short *)((u)r[2] + ((int)R_linkvarbuf + 28)) = r[3];
    L800d657c:;
    r[3] = *(int *)((u)r[5] + 84);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); r[2] = (u)0 + 12; if (c) goto L800d65a4;
    c = ((r[3] == r[2])); r[2] = (u)0 + 5; if (c) goto L800d65a4;
    c = ((r[3] == r[2])); r[2] = (u)0 + 6; if (c) goto L800d65a4;
    c = ((r[3] != r[2]));  if (c) goto L800d65b0;
    L800d65a4:;
    r[3] = *(unsigned short *)((u)r[5] + 84);
    r[2] = 0;
    *(short *)((u)r[2] + ((int)R_linkvarbuf + 30)) = r[3];
    L800d65b0:;
    r[4] = *(int *)((u)r[5] + 92);
    r[5] = (u)0 + (u)0; CALL(R_GCL_ForceExecProc);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
