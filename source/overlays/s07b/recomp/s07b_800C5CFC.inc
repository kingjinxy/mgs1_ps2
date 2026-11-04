extern char R_s07b_800C5DC4[] __asm__("s07b_800C5DC4");
extern char R_GM_ConfigMotionAdjust[] __asm__("GM_ConfigMotionAdjust");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_GM_ConfigObjectOverride[] __asm__("GM_ConfigObjectOverride");
extern char R_GV_VecDir2[] __asm__("GV_VecDir2");
extern char R_s07b_800C4854[] __asm__("s07b_800C4854");
int G_s07b_800C5CFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800C5CFC");
int G_s07b_800C5CFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[5] + (u)0;
    c = ((r[17] != 0)); *(int *)((u)r[29] + 32) = r[31]; if (c) goto L800c5d74;
    r[2] = *(short *)((u)r[16] + 170);
    c = ((r[2] == 0)); r[4] = (u)r[16] + 156; if (c) goto L800c5d38;
    r[5] = (u)0 + (u)0;
    r[6] = (u)r[5] + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800c5d38:;
    r[2] = *(short *)((u)r[16] + 172);
    r[3] = (u)0 + 2;
    c = ((r[2] == r[3])); r[2] = (u)0 + 1022; if (c) goto L800c5d60;
    *(int *)((u)r[29] + 16) = r[2];
    r[4] = (u)r[16] + 156;
    r[5] = (u)r[3] + (u)0;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectOverride);
    L800c5d60:;
    r[2] = (u)0 + 1;
    *(short *)((u)r[16] + 2106) = r[2];
    r[4] = (u)r[16] + 156;
    r[5] = (u)r[16] + 1816; CALL(R_GM_ConfigMotionAdjust);
    L800c5d74:;
    r[4] = (u)r[16] + (u)0; CALL(R_s07b_800C4854);
    r[4] = (u)r[16] + 2160; CALL(R_GV_VecDir2);
    *(short *)((u)r[16] + 110) = r[2];
    r[2] = (u)0 + 100;
    c = ((r[17] != r[2])); r[2] = 0; if (c) goto L800c5db0;
    r[2] = (u)r[2] + (int)R_s07b_800C5DC4;
    *(int *)((u)r[16] + 2132) = r[2];
    *(int *)((u)r[16] + 2144) = 0;
    *(short *)((u)r[16] + 2246) = 0;
    *(short *)((u)r[16] + 2244) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    L800c5db0:;
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
