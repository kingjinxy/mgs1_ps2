extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_s11b_800D9C4C[] __asm__("s11b_800D9C4C");
int G_s11b_800D9D5C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800D9D5C");
int G_s11b_800D9D5C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = 0;
    r[3] = *(int *)((u)r[29] + 40);
    r[2] = *(int *)((u)r[2] + (int)R_GM_CurrentMap);
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[16] + 60) = r[5];
    *(int *)((u)r[16] + 32) = r[2];
    r[8] = LWL(((u)r[5] + 3), r[8]);
    r[8] = LWR(((u)r[5] + 0), r[8]);
    r[9] = LWL(((u)r[5] + 7), r[9]);
    r[9] = LWR(((u)r[5] + 4), r[9]);
    SWL(((u)r[16] + 55), r[8]);
    SWR(((u)r[16] + 52), r[8]);
    SWL(((u)r[16] + 59), r[9]);
    SWR(((u)r[16] + 56), r[9]);
    r[8] = LWL(((u)r[5] + 3), r[8]);
    r[8] = LWR(((u)r[5] + 0), r[8]);
    r[9] = LWL(((u)r[5] + 7), r[9]);
    r[9] = LWR(((u)r[5] + 4), r[9]);
    SWL(((u)r[16] + 47), r[8]);
    SWR(((u)r[16] + 44), r[8]);
    SWL(((u)r[16] + 51), r[9]);
    SWR(((u)r[16] + 48), r[9]);
    *(int *)((u)r[16] + 64) = r[6];
    *(int *)((u)r[16] + 72) = r[7];
    *(int *)((u)r[16] + 76) = r[3]; CALL(R_s11b_800D9C4C);
    r[2] = (u)0 + 80;
    *(int *)((u)r[16] + 68) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
