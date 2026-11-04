extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_HZD_OnlineHazardCheck[] __asm__("HZD_OnlineHazardCheck");
int G_s11h_800D1D1C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800D1D1C");
int G_s11h_800D1D1C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[5] = 0;
    r[2] = *(short *)((u)r[5] + (int)R_GM_PlayerPosition);
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[31];
    r[3] = *(short *)((u)r[4] + 1596);
    r[5] = (u)r[5] + (int)R_GM_PlayerPosition;
    r[2] = (u)r[2] + (u)r[3];
    r[3] = (u)r[2] >> 31;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (int)r[2] >> 1;
    *(short *)((u)r[29] + 24) = r[2];
    r[2] = *(short *)((u)r[5] + 2);
    r[3] = *(short *)((u)r[4] + 1598);
    r[2] = (u)r[2] + (u)r[3];
    r[3] = (u)r[2] >> 31;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (int)r[2] >> 1;
    *(short *)((u)r[29] + 26) = r[2];
    r[2] = *(short *)((u)r[5] + 4);
    r[3] = *(short *)((u)r[4] + 1600);
    r[6] = (u)r[29] + 24;
    r[2] = (u)r[2] + (u)r[3];
    r[3] = (u)r[2] >> 31;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (int)r[2] >> 1;
    *(short *)((u)r[29] + 28) = r[2];
    r[3] = *(int *)((u)r[4] + 76);
    r[2] = (u)0 + 4;
    *(int *)((u)r[29] + 16) = r[2];
    r[4] = *(int *)((u)r[3] + 8);
    r[7] = (u)0 + 5; CALL(R_HZD_OnlineHazardCheck);
    r[31] = *(int *)((u)r[29] + 32);
    r[2] = (u)0 < (u)r[2];
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
