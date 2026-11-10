extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_dat_800E3ED0[] __asm__("s18a_dat_800E3ED0");
extern char R_s18a_dat_800E3ED8[] __asm__("s18a_dat_800E3ED8");
extern char R_GV_NearExp8[] __asm__("GV_NearExp8");
extern char R_GV_NearExp8V[] __asm__("GV_NearExp8V");
int G_s18a_800C5A34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C5A34");
int G_s18a_800C5A34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = 0;
    r[16] = (u)r[16] + ((int)R_GM_Camera + 8);
    r[4] = (u)r[16] + (u)0;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_GM_PlayerPosition;
    *(int *)((u)r[29] + 20) = r[31];
    r[6] = (u)0 + 3; CALL(R_GV_NearExp8V);
    r[16] = (u)r[16] + -8;
    r[4] = *(short *)((u)r[16] + 16);
    r[5] = (u)0 + 440; CALL(R_GV_NearExp8);
    r[4] = *(short *)((u)r[16] + 18);
    r[5] = (u)0 + 2048;
    *(short *)((u)r[16] + 16) = r[2]; CALL(R_GV_NearExp8);
    r[4] = *(int *)((u)r[16] + 28);
    r[5] = (u)0 + 6000;
    *(short *)((u)r[16] + 18) = r[2]; CALL(R_GV_NearExp8);
    r[3] = 0;
    r[3] = *(int *)((u)r[3] + (int)R_GM_PlayerStatus);
    r[3] = r[3] & 4;
    c = ((r[3] != 0)); *(int *)((u)r[16] + 28) = r[2]; if (c) goto L800c5acc;
    r[2] = (u)0 + 440;
    *(short *)((u)r[16] + 16) = r[2];
    r[2] = (u)0 + 2048;
    *(short *)((u)r[16] + 18) = r[2];
    r[2] = (u)0 + 6000;
    *(int *)((u)r[16] + 28) = r[2];
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_s18a_dat_800E3ED0);
    r[2] = (u)0 + 6;
    *(int *)((u)r[3] + 0) = r[2];
    L800c5acc:;
    r[3] = 0;
    r[2] = *(int *)((u)r[3] + (int)R_s18a_dat_800E3ED8);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[3] + (int)R_s18a_dat_800E3ED8) = r[2];
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
