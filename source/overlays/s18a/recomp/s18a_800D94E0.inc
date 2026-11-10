extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_800DC884[] __asm__("s18a_800DC884");
extern char R_s18a_800DC964[] __asm__("s18a_800DC964");
extern char R_s18a_dat_800C3B0C[] __asm__("s18a_dat_800C3B0C");
extern char R_s18a_rc_800D9034[] __asm__("s18a_rc_800D9034");
extern char R_s18a_800D62DC[] __asm__("s18a_800D62DC");
int G_s18a_800D94E0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D94E0");
int G_s18a_800D94E0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[3] = 0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_rc_800D9034;
    r[5] = 0;
    r[4] = *(int *)((u)r[3] + (int)R_GM_PlayerStatus);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[5] + (int)R_s18a_dat_800C3B0C;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[16] + 2236) = r[2];
    *(int *)((u)r[16] + 2240) = r[2]; CALL(R_s18a_800D62DC);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d9528;
    r[2] = (u)r[2] + (int)R_s18a_800DC964; goto L800d9530;
    L800d9528:;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_800DC884;
    L800d9530:;
    *(int *)((u)r[16] + 2220) = r[2];
    *(int *)((u)r[16] + 2224) = 0;
    *(short *)((u)r[16] + 2322) = 0;
    *(short *)((u)r[16] + 2320) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
