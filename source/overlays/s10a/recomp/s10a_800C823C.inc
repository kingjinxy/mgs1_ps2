extern char R_DG_ZeroVector[] __asm__("DG_ZeroVector");
extern char R_s10a_800C8304[] __asm__("s10a_800C8304");
extern char R_s10a_dat_800C33A8[] __asm__("s10a_dat_800C33A8");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_s10a_800C814C[] __asm__("s10a_800C814C");
int G_s10a_800C823C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800C823C");
int G_s10a_800C823C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[16] + 32;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 24) = r[31]; if (c) goto L800c8274;
    r[4] = (u)r[16] + 156;
    r[2] = 0;
    r[6] = (u)0 + (u)0;
    *(int *)((u)r[16] + 3040) = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s10a_dat_800C33A8);
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800c8274:;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800C814C);
    c = ((r[2] == 0));  if (c) goto L800c829c;
    r[2] = *(short *)((u)r[16] + 3082);
    r[4] = *(unsigned short *)((u)r[16] + 3082);
    c = (((int)r[2] < 0));  if (c) goto L800c82f0;
    *(short *)((u)r[17] + 78) = r[4]; goto L800c82f0;
    L800c829c:;
    r[2] = *(short *)((u)r[16] + 3082);
    c = (((int)r[2] < 0)); r[2] = 0; if (c) goto L800c82c8;
    r[3] = *(unsigned short *)((u)r[16] + 3082);
    r[2] = (u)r[2] + (int)R_s10a_800C8304;
    *(int *)((u)r[16] + 3024) = r[2];
    *(int *)((u)r[16] + 3032) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    *(short *)((u)r[17] + 78) = r[3];
    L800c82c8:;
    r[2] = 0;
    r[11] = (u)r[2] + (int)R_DG_ZeroVector;
    r[8] = LWL(((u)r[11] + 3), r[8]);
    r[8] = LWR(((u)r[11] + 0), r[8]);
    r[9] = LWL(((u)r[11] + 7), r[9]);
    r[9] = LWR(((u)r[11] + 4), r[9]);
    SWL(((u)r[16] + 103), r[8]);
    SWR(((u)r[16] + 100), r[8]);
    SWL(((u)r[16] + 107), r[9]);
    SWR(((u)r[16] + 104), r[9]);
    L800c82f0:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
