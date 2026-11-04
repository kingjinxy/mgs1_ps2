extern char R_GM_GameOverTimer[] __asm__("GM_GameOverTimer");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s07b_dword_800C33F0[] __asm__("s07b_dword_800C33F0");
extern char R_GCL_ExecProc[] __asm__("GCL_ExecProc");
int G_s07b_800C500C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800C500C");
int G_s07b_800C500C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 40) = r[31];
    r[3] = *(int *)((u)r[4] + 2128);
    r[2] = r[3] & 256;
    c = ((r[2] == 0)); r[2] = (u)0 + -257; if (c) goto L800c50c8;
    r[2] = r[3] & r[2];
    *(int *)((u)r[4] + 2128) = r[2];
    r[2] = *(short *)((u)r[4] + 2118);
    r[3] = *(unsigned short *)((u)r[4] + 2118);
    c = (((int)r[2] >= 0));  if (c) goto L800c50c0;
    r[2] = *(int *)((u)r[4] + 2272);
    c = (((int)r[2] < 0)); r[2] = 0; if (c) goto L800c50c8;
    r[2] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 22));
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800c50c8;
    r[2] = *(int *)((u)r[2] + (int)R_GM_GameOverTimer);
    c = ((r[2] != 0)); r[2] = (u)0 + 4; if (c) goto L800c50c8;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = (u)r[29] + 24;
    *(int *)((u)r[29] + 20) = r[2];
    r[2] = 0;
    r[3] = *(int *)((u)r[4] + 2012);
    r[2] = *(short *)((u)r[2] + (int)R_s07b_dword_800C33F0);
    r[3] = *(short *)((u)r[3] + 38);
    *(int *)((u)r[29] + 28) = r[2];
    *(int *)((u)r[29] + 24) = r[3];
    r[2] = *(short *)((u)r[4] + 32);
    *(int *)((u)r[29] + 32) = r[2];
    r[2] = *(short *)((u)r[4] + 36);
    *(int *)((u)r[29] + 36) = r[2];
    r[4] = *(int *)((u)r[4] + 2272);
    r[5] = (u)r[29] + 16; CALL(R_GCL_ExecProc);
     goto L800c50c8;
    L800c50c0:;
    *(short *)((u)r[4] + 2116) = r[3];
    *(int *)((u)r[4] + 2120) = 0;
    L800c50c8:;
    r[31] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
