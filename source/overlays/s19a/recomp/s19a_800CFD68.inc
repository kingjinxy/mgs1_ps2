extern char R_s19a_800D073C[] __asm__("s19a_800D073C");
extern char R_s19a_dat_800C3610[] __asm__("s19a_dat_800C3610");
extern char R_s19a_dat_800C3612[] __asm__("s19a_dat_800C3612");
extern char R_GM_ConfigMotionAdjust[] __asm__("GM_ConfigMotionAdjust");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_GM_SeSet[] __asm__("GM_SeSet");
extern char R_s19a_800D1638[] __asm__("s19a_800D1638");
int G_s19a_800CFD68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CFD68");
int G_s19a_800CFD68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    c = ((r[17] != 0)); *(int *)((u)r[29] + 24) = r[31]; if (c) goto L800cfdd8;
    r[2] = *(int *)((u)r[16] + 2268);
    r[2] = (int)r[2] < 3;
    c = ((r[2] == 0)); r[4] = (u)r[16] + 156; if (c) goto L800cfdb0;
    r[2] = (u)0 + 46;
    *(short *)((u)r[16] + 2272) = r[2];
    r[2] = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s19a_dat_800C3610);
    r[6] = (u)0 + (u)0; goto L800cfdc4;
    L800cfdb0:;
    r[6] = (u)0 + (u)0;
    r[2] = (u)0 + 47;
    *(short *)((u)r[16] + 2272) = r[2];
    r[2] = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s19a_dat_800C3612);
    L800cfdc4:;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    r[4] = (u)r[16] + 32;
    r[5] = (u)0 + 54; CALL(R_GM_SeSet);
    L800cfdd8:;
    r[2] = (u)0 + 4;
    c = ((r[17] != r[2]));  if (c) goto L800cfdec;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D1638);
    L800cfdec:;
    r[2] = *(short *)((u)r[16] + 182);
    c = ((r[2] == 0)); r[4] = (u)r[16] + 156; if (c) goto L800cfe1c;
    r[5] = (u)0 + (u)0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19a_800D073C;
    *(int *)((u)r[16] + 2284) = r[2];
    *(int *)((u)r[16] + 2292) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0; CALL(R_GM_ConfigMotionAdjust);
    L800cfe1c:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
