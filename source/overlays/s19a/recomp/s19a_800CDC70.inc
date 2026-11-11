extern char R_s19a_800CF340[] __asm__("s19a_800CF340");
extern char R_s19a_800CF6B8[] __asm__("s19a_800CF6B8");
extern char R_GM_ConfigMotionAdjust[] __asm__("GM_ConfigMotionAdjust");
int G_s19a_800CDC70(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CDC70");
int G_s19a_800CDC70(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[6] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = *(int *)((u)r[6] + 2304);
    r[2] = *(unsigned short *)((u)r[16] + 6);
    r[2] = r[2] & 2;
    c = ((r[2] == 0)); r[2] = (u)0 + 36; if (c) goto L800cdce8;
    r[3] = *(short *)((u)r[16] + 62);
    c = ((r[3] != r[2])); r[4] = (u)r[6] + 156; if (c) goto L800cdcbc;
    r[5] = (u)0 + (u)0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19a_800CF340; goto L800cdcc8;
    L800cdcbc:;
    r[5] = (u)0 + (u)0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19a_800CF6B8;
    L800cdcc8:;
    *(int *)((u)r[6] + 2284) = r[2];
    *(int *)((u)r[6] + 2292) = 0;
    *(short *)((u)r[6] + 112) = 0;
    *(short *)((u)r[6] + 108) = 0; CALL(R_GM_ConfigMotionAdjust);
    *(short *)((u)r[16] + 6) = 0;
    r[2] = (u)0 + 1; goto L800cdcec;
    L800cdce8:;
    r[2] = (u)0 + (u)0;
    L800cdcec:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
