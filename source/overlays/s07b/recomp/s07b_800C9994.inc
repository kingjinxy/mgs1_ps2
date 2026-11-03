extern char R_DG_ZeroVector[] __asm__("DG_ZeroVector");
extern char R_s07b_800C5CFC[] __asm__("s07b_800C5CFC");
extern char R_GM_ConfigMotionAdjust[] __asm__("GM_ConfigMotionAdjust");
extern char R_GM_ConfigObjectOverride[] __asm__("GM_ConfigObjectOverride");
extern char R_s07b_800C54E8[] __asm__("s07b_800C54E8");
int G_s07b_800C9994(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800C9994");
int G_s07b_800C9994(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 28) = r[31]; if (c) goto L800c9a48;
    r[4] = (u)r[16] + 156;
    r[5] = (u)0 + (u)0; CALL(R_GM_ConfigMotionAdjust);
    r[4] = (u)0 + (u)0;
    r[5] = 0;
    r[3] = (u)r[16] + (u)0;
    L800c99c0:;
    r[11] = (u)r[5] + (int)R_DG_ZeroVector;
    r[8] = LWL(((u)r[11] + 3), r[8]);
    r[8] = LWR(((u)r[11] + 0), r[8]);
    r[9] = LWL(((u)r[11] + 7), r[9]);
    r[9] = LWR(((u)r[11] + 4), r[9]);
    SWL(((u)r[3] + 1819), r[8]);
    SWR(((u)r[3] + 1816), r[8]);
    SWL(((u)r[3] + 1823), r[9]);
    SWR(((u)r[3] + 1820), r[9]);
    r[4] = (u)r[4] + 1;
    r[2] = (int)r[4] < 16;
    c = ((r[2] != 0)); r[3] = (u)r[3] + 8; if (c) goto L800c99c0;
    r[2] = *(int *)((u)r[16] + 2128);
    r[3] = *(short *)((u)r[16] + 172);
    r[2] = r[2] | 1024;
    c = ((r[3] == 0)); *(int *)((u)r[16] + 2128) = r[2]; if (c) goto L800c9a20;
    *(int *)((u)r[29] + 16) = 0;
    r[4] = (u)r[16] + 156;
    r[5] = (u)0 + (u)0;
    r[6] = (u)r[5] + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectOverride);
    L800c9a20:;
    r[4] = (u)r[16] + (u)0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s07b_800C5CFC;
    *(int *)((u)r[4] + 2132) = r[2];
    *(int *)((u)r[4] + 2144) = 0;
    *(short *)((u)r[4] + 2246) = 0;
    *(short *)((u)r[4] + 2244) = 0;
    *(short *)((u)r[4] + 112) = 0;
    *(short *)((u)r[4] + 108) = 0; CALL(R_s07b_800C54E8);
    L800c9a48:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
