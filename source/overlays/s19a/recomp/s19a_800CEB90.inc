extern char R_s19a_800CFBF0[] __asm__("s19a_800CFBF0");
extern char R_s19a_dat_800C35FA[] __asm__("s19a_dat_800C35FA");
extern char R_GM_ConfigMotionAdjust[] __asm__("GM_ConfigMotionAdjust");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_s19a_800CDF9C[] __asm__("s19a_800CDF9C");
int G_s19a_800CEB90(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CEB90");
int G_s19a_800CEB90(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800cebcc;
    r[4] = (u)r[16] + 156;
    r[2] = (u)0 + 3;
    *(int *)((u)r[16] + 2268) = r[2];
    r[2] = (u)0 + 35;
    *(short *)((u)r[16] + 2272) = r[2];
    r[2] = 0;
    r[6] = (u)0 + (u)0;
    r[5] = *(short *)((u)r[2] + (int)R_s19a_dat_800C35FA);
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800cebcc:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800CDF9C);
    c = ((r[2] != 0));  if (c) goto L800cec10;
    r[2] = *(short *)((u)r[16] + 182);
    c = ((r[2] == 0)); r[4] = (u)r[16] + 156; if (c) goto L800cec10;
    r[5] = (u)0 + (u)0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19a_800CFBF0;
    *(int *)((u)r[16] + 2880) = 0;
    *(int *)((u)r[16] + 2284) = r[2];
    *(int *)((u)r[16] + 2292) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0; CALL(R_GM_ConfigMotionAdjust);
    L800cec10:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
