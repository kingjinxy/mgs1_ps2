extern char R_s18a_800DDD80[] __asm__("s18a_800DDD80");
extern char R_s18a_800DE074[] __asm__("s18a_800DE074");
extern char R_s18a_dat_800E4348[] __asm__("s18a_dat_800E4348");
extern char R_s18a_rc_800D9034[] __asm__("s18a_rc_800D9034");
int G_s18a_800D9558(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D9558");
int G_s18a_800D9558(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[3] = 0;
    r[3] = *(int *)((u)r[3] + (int)R_s18a_dat_800E4348);
    r[2] = (u)r[2] + (int)R_s18a_rc_800D9034;
    *(int *)((u)r[4] + 2236) = r[2];
    c = (((int)r[3] < 0)); *(int *)((u)r[4] + 2240) = r[2]; if (c) goto L800d9580;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_800DDD80; goto L800d9588;
    L800d9580:;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_800DE074;
    L800d9588:;
    *(int *)((u)r[4] + 2220) = r[2];
    *(int *)((u)r[4] + 2224) = 0;
    *(short *)((u)r[4] + 2322) = 0;
    *(short *)((u)r[4] + 2320) = 0;
    *(short *)((u)r[4] + 112) = 0;
    *(short *)((u)r[4] + 108) = 0; goto out;
out:
    RECOMP_RETURN;
}
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_800D7EC4[] __asm__("s18a_800D7EC4");
extern char R_s18a_800D8100[] __asm__("s18a_800D8100");
extern char R_s18a_dat_800E4348[] __asm__("s18a_dat_800E4348");
int G_s18a_rc_800D95A4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_rc_800D95A4");
int G_s18a_rc_800D95A4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)0 + 2;
    c = ((r[5] != r[2])); r[2] = 0; if (c) goto L800d95e0;
    r[2] = *(int *)((u)r[2] + (int)R_s18a_dat_800E4348);
    c = (((int)r[2] < 0)); r[2] = 0; if (c) goto L800d95e0;
    r[2] = (u)r[2] + (int)R_s18a_800D8100;
    *(int *)((u)r[4] + 2220) = r[2];
    *(int *)((u)r[4] + 2224) = 0;
    *(short *)((u)r[4] + 2322) = 0;
    *(short *)((u)r[4] + 2320) = 0;
    *(short *)((u)r[4] + 112) = 0;
    *(short *)((u)r[4] + 108) = 0; goto out;
    L800d95e0:;
    r[2] = *(short *)((u)r[4] + 182);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d9620;
    r[2] = (u)r[2] + (int)R_s18a_800D7EC4;
    *(int *)((u)r[4] + 2220) = r[2];
    *(int *)((u)r[4] + 2224) = 0;
    *(short *)((u)r[4] + 2322) = 0;
    *(short *)((u)r[4] + 2320) = 0;
    *(short *)((u)r[4] + 112) = 0;
    *(short *)((u)r[4] + 108) = 0;
    r[4] = 0;
    r[2] = *(int *)((u)r[4] + (int)R_GM_PlayerStatus);
    r[3] = (u)0 + -17;
    r[2] = r[2] & r[3];
    *(int *)((u)r[4] + (int)R_GM_PlayerStatus) = r[2];
    L800d9620:;
     goto out;
out:
    RECOMP_RETURN;
}
