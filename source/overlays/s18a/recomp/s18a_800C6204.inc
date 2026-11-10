extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_s18a_dat_800E3ECC[] __asm__("s18a_dat_800E3ECC");
extern char R_s18a_dat_800E3ED0[] __asm__("s18a_dat_800E3ED0");
extern char R_s18a_dat_800E3ED4[] __asm__("s18a_dat_800E3ED4");
extern char R_s18a_dat_800E3ED8[] __asm__("s18a_dat_800E3ED8");
extern char R_s18a_rc_800C5E20[] __asm__("s18a_rc_800C5E20");
extern char R_GM_SetCameraCallbackFunc[] __asm__("GM_SetCameraCallbackFunc");
int G_s18a_800C6204(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C6204");
int G_s18a_800C6204(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[3] = 0;
    r[2] = (u)r[16] + 32;
    *(int *)((u)r[3] + (int)R_s18a_dat_800E3ECC) = r[2];
    r[3] = 0;
    r[2] = (u)r[16] + 2456;
    *(int *)((u)r[3] + (int)R_s18a_dat_800E3ED0) = r[2];
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s18a_dat_800E3ED4) = r[16];
    r[2] = 0;
    r[5] = 0;
    r[4] = (u)0 + 1;
    r[5] = (u)r[5] + (int)R_s18a_rc_800C5E20;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[2] + (int)R_s18a_dat_800E3ED8) = 0; CALL(R_GM_SetCameraCallbackFunc);
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_GM_Camera;
    r[5] = (u)0 + 2;
    r[4] = *(int *)((u)r[2] + 24);
    r[3] = (u)0 + 4;
    *(short *)((u)r[2] + 38) = r[3];
    r[3] = (u)0 + 440;
    *(short *)((u)r[2] + 16) = r[3];
    r[3] = (u)0 + 2048;
    *(short *)((u)r[2] + 18) = r[3];
    r[3] = (u)0 + 4000;
    *(short *)((u)r[2] + 42) = r[5];
    *(short *)((u)r[2] + 20) = 0;
    *(int *)((u)r[2] + 28) = r[3];
    *(short *)((u)r[2] + 40) = r[5];
    r[4] = r[4] | 2;
    *(int *)((u)r[2] + 24) = r[4];
    *(int *)((u)r[16] + 2456) = 0;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
