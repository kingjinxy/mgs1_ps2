extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_s18a_dat_800E3ED4[] __asm__("s18a_dat_800E3ED4");
extern char R_s18a_dat_800E3ED8[] __asm__("s18a_dat_800E3ED8");
int G_s18a_800C59B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C59B0");
int G_s18a_800C59B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = 0;
    r[2] = *(int *)((u)r[5] + (int)R_s18a_dat_800E3ED8);
    c = ((r[2] != 0)); r[4] = 0; if (c) goto L800c59dc;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s18a_dat_800E3ED4);
    r[3] = *(unsigned short *)((u)r[2] + 2476);
    r[2] = 0;
    *(short *)((u)r[2] + ((int)R_GM_Camera + 18)) = r[3];
    L800c59dc:;
    r[2] = *(int *)((u)r[4] + (int)R_GM_GameStatus);
    r[3] = 0x10000000;
    r[2] = r[2] | r[3];
    *(int *)((u)r[4] + (int)R_GM_GameStatus) = r[2];
    r[4] = 0;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s18a_dat_800E3ED4);
    r[4] = (u)r[4] + (int)R_GM_Camera;
    r[6] = LWL(((u)r[2] + 35), r[6]);
    r[6] = LWR(((u)r[2] + 32), r[6]);
    r[7] = LWL(((u)r[2] + 39), r[7]);
    r[7] = LWR(((u)r[2] + 36), r[7]);
    SWL(((u)r[4] + 11), r[6]);
    SWR(((u)r[4] + 8), r[6]);
    SWL(((u)r[4] + 15), r[7]);
    SWR(((u)r[4] + 12), r[7]);
    r[2] = *(int *)((u)r[5] + (int)R_s18a_dat_800E3ED8);
    r[3] = (u)0 + 640;
    *(short *)((u)r[4] + 16) = r[3];
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[5] + (int)R_s18a_dat_800E3ED8) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
