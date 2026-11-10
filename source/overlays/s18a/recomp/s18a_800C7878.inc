extern char R_s18a_800CB9D0[] __asm__("s18a_800CB9D0");
extern char R_s18a_800CC0F0[] __asm__("s18a_800CC0F0");
extern char R_GM_ConfigMotionAdjust[] __asm__("GM_ConfigMotionAdjust");
int G_s18a_800C7878(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C7878");
int G_s18a_800C7878(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[6] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = *(int *)((u)r[6] + 2236);
    r[2] = *(unsigned short *)((u)r[16] + 6);
    r[2] = r[2] & 2;
    c = ((r[2] == 0)); r[2] = (u)0 + 36; if (c) goto L800c78f0;
    r[3] = *(short *)((u)r[16] + 62);
    c = ((r[3] != r[2])); r[4] = (u)r[6] + 156; if (c) goto L800c78c4;
    r[5] = (u)0 + (u)0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_800CB9D0; goto L800c78d0;
    L800c78c4:;
    r[5] = (u)0 + (u)0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_800CC0F0;
    L800c78d0:;
    *(int *)((u)r[6] + 2348) = r[2];
    *(int *)((u)r[6] + 2356) = 0;
    *(short *)((u)r[6] + 112) = 0;
    *(short *)((u)r[6] + 108) = 0; CALL(R_GM_ConfigMotionAdjust);
    *(short *)((u)r[16] + 6) = 0;
    r[2] = (u)0 + 1; goto L800c78f4;
    L800c78f0:;
    r[2] = (u)0 + (u)0;
    L800c78f4:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
