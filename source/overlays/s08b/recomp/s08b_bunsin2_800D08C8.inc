extern char R_GM_PlayerAddress[] __asm__("GM_PlayerAddress");
extern char R_s08b_bunsin2_800CEA34[] __asm__("s08b_bunsin2_800CEA34");
extern char R_s08b_bunsin2_800CEE68[] __asm__("s08b_bunsin2_800CEE68");
extern char R_s08b_bunsin2_800CEF34[] __asm__("s08b_bunsin2_800CEF34");
int G_s08b_bunsin2_800D08C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800D08C8");
int G_s08b_bunsin2_800D08C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_s08b_bunsin2_800CEE68);
    r[16] = (u)r[2] + (u)0;
    r[4] = *(unsigned char *)((u)r[17] + 6520);
    r[3] = *(int *)((u)r[17] + 6608);
    r[5] = *(unsigned char *)((u)r[17] + 6524);
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[17] + 6608) = r[3]; CALL(R_s08b_bunsin2_800CEF34);
    c = ((r[2] != 0)); r[2] = (u)0 + 2; if (c) goto L800d0928;
    c = ((r[16] == 0)); r[2] = 0; if (c) goto L800d0924;
    r[5] = *(int *)((u)r[2] + (int)R_GM_PlayerAddress);
    r[4] = (u)r[17] + (u)0; CALL(R_s08b_bunsin2_800CEA34);
    r[3] = (u)r[2] < (u)3;
    c = ((r[3] == 0)); r[2] = (u)0 + 1; if (c) goto L800d0928;
    L800d0924:;
    r[2] = (u)0 + (u)0;
    L800d0928:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
