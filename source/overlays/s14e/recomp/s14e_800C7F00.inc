extern char R_s14e_800C7398[] __asm__("s14e_800C7398");
extern char R_s14e_dword_800C3378[] __asm__("s14e_dword_800C3378");
extern char R_GM_ConfigMotionAdjust[] __asm__("GM_ConfigMotionAdjust");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_s14e_800C6E08[] __asm__("s14e_800C6E08");
int G_s14e_800C7F00(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800C7F00");
int G_s14e_800C7F00(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    c = ((r[5] != 0)); *(short *)((u)r[16] + 2960) = 0; if (c) goto L800c7f38;
    r[4] = (u)r[16] + 156;
    r[2] = (u)0 + 21;
    *(short *)((u)r[16] + 2272) = r[2];
    r[2] = 0;
    r[6] = (u)0 + (u)0;
    r[5] = *(short *)((u)r[2] + ((int)R_s14e_dword_800C3378 + 2));
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800c7f38:;
    r[4] = (u)r[16] + (u)0; CALL(R_s14e_800C6E08);
    c = ((r[2] != 0));  if (c) goto L800c7f98;
    r[2] = *(int *)((u)r[16] + 2304);
    r[3] = *(unsigned short *)((u)r[2] + 0);
    r[3] = r[3] | 159;
    *(short *)((u)r[2] + 0) = r[3];
    r[2] = *(short *)((u)r[16] + 182);
    c = ((r[2] == 0)); r[4] = (u)r[16] + 156; if (c) goto L800c7f98;
    r[5] = (u)0 + (u)0;
    r[2] = (u)0 + 1;
    *(int *)((u)r[16] + 2300) = r[2];
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s14e_800C7398;
    *(int *)((u)r[16] + 2284) = r[2];
    *(int *)((u)r[16] + 2292) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0; CALL(R_GM_ConfigMotionAdjust);
    L800c7f98:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
