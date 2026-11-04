extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
int G_s11h_800C7CAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800C7CAC");
int G_s11h_800C7CAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    *(int *)((u)r[4] + 56) = r[5];
    r[3] = *(int *)((u)r[29] + 16);
    r[5] = *(int *)((u)r[29] + 20);
    r[2] = *(int *)((u)r[2] + (int)R_GM_CurrentMap);
    *(int *)((u)r[4] + 60) = r[6];
    *(int *)((u)r[4] + 52) = r[7];
    *(int *)((u)r[4] + 32) = r[2];
    r[2] = (u)0 + (u)0;
    r[8] = LWL(((u)r[3] + 3), r[8]);
    r[8] = LWR(((u)r[3] + 0), r[8]);
    r[9] = LWL(((u)r[3] + 7), r[9]);
    r[9] = LWR(((u)r[3] + 4), r[9]);
    SWL(((u)r[4] + 39), r[8]);
    SWR(((u)r[4] + 36), r[8]);
    SWL(((u)r[4] + 43), r[9]);
    SWR(((u)r[4] + 40), r[9]);
    r[8] = LWL(((u)r[5] + 3), r[8]);
    r[8] = LWR(((u)r[5] + 0), r[8]);
    r[9] = LWL(((u)r[5] + 7), r[9]);
    r[9] = LWR(((u)r[5] + 4), r[9]);
    SWL(((u)r[4] + 47), r[8]);
    SWR(((u)r[4] + 44), r[8]);
    SWL(((u)r[4] + 51), r[9]);
    SWR(((u)r[4] + 48), r[9]);
    *(int *)((u)r[4] + 64) = r[6];
    *(int *)((u)r[4] + 68) = 0; goto out;
out:
    RECOMP_RETURN;
}
