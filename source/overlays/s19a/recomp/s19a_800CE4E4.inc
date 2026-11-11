extern char R_s19a_dat_800C3774[] __asm__("s19a_dat_800C3774");
extern char R_GM_MoveTarget[] __asm__("GM_MoveTarget");
extern char R_GM_PowerTarget[] __asm__("GM_PowerTarget");
extern char R_GM_SetPowerTarget[] __asm__("GM_SetPowerTarget");
int G_s19a_800CE4E4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CE4E4");
int G_s19a_800CE4E4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[17] + 2308;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 7;
    r[2] = (u)0 + 3;
    *(int *)((u)r[29] + 16) = r[2];
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19a_dat_800C3774;
    r[6] = (u)0 + 5;
    r[7] = (u)0 + (u)0;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 20) = r[2]; CALL(R_GM_SetPowerTarget);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + 32; CALL(R_GM_MoveTarget);
    r[4] = (u)r[16] + (u)0; CALL(R_GM_PowerTarget);
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
