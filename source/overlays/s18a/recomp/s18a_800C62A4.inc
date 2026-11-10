extern char R_s18a_dat_800C32A0[] __asm__("s18a_dat_800C32A0");
extern char R_s18a_dat_800C32A8[] __asm__("s18a_dat_800C32A8");
extern char R_GM_SetCaptureTarget[] __asm__("GM_SetCaptureTarget");
extern char R_GM_SetPowerTarget[] __asm__("GM_SetPowerTarget");
extern char R_GM_SetTarget[] __asm__("GM_SetTarget");
int G_s18a_800C62A4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C62A4");
int G_s18a_800C62A4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[18];
    r[18] = (u)r[4] + (u)0;
    r[5] = (u)0 + 23;
    r[6] = (u)0 + 2;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = 0;
    r[17] = (u)r[17] + (int)R_s18a_dat_800C32A0;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = *(int *)((u)r[18] + 2236);
    r[7] = (u)r[17] + (u)0;
    r[4] = (u)r[16] + (u)0; CALL(R_GM_SetTarget);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 1;
    r[6] = (u)0 + -1;
    r[7] = (u)0 + 255;
    r[2] = (u)r[7] + (u)0;
    *(int *)((u)r[29] + 16) = r[2];
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_dat_800C32A8;
    *(int *)((u)r[29] + 20) = r[2]; CALL(R_GM_SetPowerTarget);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + -1;
    r[6] = (u)0 + 255;
    r[7] = (u)0 + (u)0;
    *(int *)((u)r[29] + 16) = 0; CALL(R_GM_SetCaptureTarget);
    r[5] = (u)0 + 8;
    r[6] = (u)0 + (u)0;
    r[4] = *(int *)((u)r[18] + 2240);
    r[7] = (u)r[17] + (u)0; CALL(R_GM_SetTarget);
    r[31] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
