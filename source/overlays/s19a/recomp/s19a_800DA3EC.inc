extern char R_DG_ZeroVector[] __asm__("DG_ZeroVector");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s19a_dat_800C38A8[] __asm__("s19a_dat_800C38A8");
extern char R_GM_SetPowerTarget[] __asm__("GM_SetPowerTarget");
extern char R_GM_SetTarget[] __asm__("GM_SetTarget");
int G_s19a_800DA3EC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DA3EC");
int G_s19a_800DA3EC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[18];
    r[18] = (u)r[4] + (u)0;
    r[5] = (u)0 + 20;
    r[6] = (u)0 + 1;
    r[7] = 0;
    r[7] = (u)r[7] + (int)R_s19a_dat_800C38A8;
    r[2] = 0;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 28) = r[17];
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = *(int *)((u)r[18] + 2320);
    r[17] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 22));
    r[4] = (u)r[16] + (u)0; CALL(R_GM_SetTarget);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 1;
    r[6] = (u)0 + -1;
    r[7] = (u)r[17] + (u)0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_DG_ZeroVector;
    *(int *)((u)r[29] + 16) = 0;
    *(int *)((u)r[29] + 20) = r[2]; CALL(R_GM_SetPowerTarget);
    r[2] = *(int *)((u)r[18] + 32);
    r[2] = *(int *)((u)r[2] + 44);
    r[2] = *(unsigned short *)((u)r[2] + 0);
    *(short *)((u)r[16] + 4) = r[2];
    r[31] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
