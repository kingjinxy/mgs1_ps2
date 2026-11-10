extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_GM_PlayerMap[] __asm__("GM_PlayerMap");
extern char R_s18a_800DF938[] __asm__("s18a_800DF938");
int G_s18a_800DFD74(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DFD74");
int G_s18a_800DFD74(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    r[2] = 0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[4] = *(int *)((u)r[17] + 3300);
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerMap);
    r[2] = r[4] & r[2];
    c = ((r[2] == 0)); r[16] = (u)0 + (u)0; if (c) goto L800dfdd4;
    r[3] = *(int *)((u)r[17] + 2336);
    r[2] = 0;
    c = (((int)r[3] <= 0)); *(int *)((u)r[2] + (int)R_GM_CurrentMap) = r[4]; if (c) goto L800dfdd4;
    r[4] = (u)r[17] + (u)0;
    L800dfdb8:;
    r[5] = (u)r[16] + (u)0; CALL(R_s18a_800DF938);
    r[2] = *(int *)((u)r[17] + 2336);
    r[16] = (u)r[16] + 1;
    r[2] = (int)r[16] < (int)r[2];
    c = ((r[2] != 0)); r[4] = (u)r[17] + (u)0; if (c) goto L800dfdb8;
    L800dfdd4:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
