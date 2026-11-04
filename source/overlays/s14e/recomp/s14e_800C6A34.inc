extern char R_s14e_800C7FA8[] __asm__("s14e_800C7FA8");
extern char R_s14e_800C8350[] __asm__("s14e_800C8350");
extern char R_GM_ConfigMotionAdjust[] __asm__("GM_ConfigMotionAdjust");
int G_s14e_800C6A34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800C6A34");
int G_s14e_800C6A34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[6] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = *(int *)((u)r[6] + 2304);
    r[2] = *(unsigned short *)((u)r[16] + 6);
    r[2] = r[2] & 2;
    c = ((r[2] == 0)); r[2] = (u)0 + 36; if (c) goto L800c6aac;
    r[3] = *(short *)((u)r[16] + 62);
    c = ((r[3] != r[2])); r[4] = (u)r[6] + 156; if (c) goto L800c6a80;
    r[5] = (u)0 + (u)0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s14e_800C7FA8; goto L800c6a8c;
    L800c6a80:;
    r[5] = (u)0 + (u)0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s14e_800C8350;
    L800c6a8c:;
    *(int *)((u)r[6] + 2284) = r[2];
    *(int *)((u)r[6] + 2292) = 0;
    *(short *)((u)r[6] + 112) = 0;
    *(short *)((u)r[6] + 108) = 0; CALL(R_GM_ConfigMotionAdjust);
    *(short *)((u)r[16] + 6) = 0;
    r[2] = (u)0 + 1; goto L800c6ab0;
    L800c6aac:;
    r[2] = (u)0 + (u)0;
    L800c6ab0:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
