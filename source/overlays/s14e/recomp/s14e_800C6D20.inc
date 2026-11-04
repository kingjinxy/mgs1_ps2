extern char R_s14e_800C924C[] __asm__("s14e_800C924C");
extern char R_s14e_dword_800C339C[] __asm__("s14e_dword_800C339C");
extern char R_GM_ConfigMotionAdjust[] __asm__("GM_ConfigMotionAdjust");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
int G_s14e_800C6D20(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800C6D20");
int G_s14e_800C6D20(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(short *)((u)r[17] + 152);
    c = ((r[2] != 0)); r[16] = (u)r[17] + 156; if (c) goto L800c6d4c;
    r[2] = (u)0 + (u)0; goto L800c6d9c;
    L800c6d4c:;
    r[4] = (u)r[16] + (u)0;
    r[2] = *(int *)((u)r[17] + 2304);
    r[6] = (u)0 + (u)0;
    *(short *)((u)r[2] + 38) = 0;
    r[2] = (u)0 + 39;
    *(short *)((u)r[17] + 2272) = r[2];
    r[2] = 0;
    r[5] = *(short *)((u)r[2] + ((int)R_s14e_dword_800C339C + 2));
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + (u)0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s14e_800C924C;
    *(int *)((u)r[17] + 2284) = r[2];
    *(int *)((u)r[17] + 2292) = 0;
    *(short *)((u)r[17] + 112) = 0;
    *(short *)((u)r[17] + 108) = 0; CALL(R_GM_ConfigMotionAdjust);
    r[2] = (u)0 + 1;
    L800c6d9c:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
