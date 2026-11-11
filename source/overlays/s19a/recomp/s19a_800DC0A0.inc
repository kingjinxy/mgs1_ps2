extern char R_s19a_dat_800E0E20[] __asm__("s19a_dat_800E0E20");
extern char R_s19a_800DC028[] __asm__("s19a_800DC028");
int G_s19a_800DC0A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DC0A0");
int G_s19a_800DC0A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[5] = 0;
    r[2] = *(int *)((u)r[5] + (int)R_s19a_dat_800E0E20);
    r[3] = 0xffff0000;
    *(int *)((u)r[29] + 16) = r[31];
    *(int *)((u)r[4] + 2048) = r[2];
    r[2] = r[2] & r[3];
    *(int *)((u)r[5] + (int)R_s19a_dat_800E0E20) = r[2]; CALL(R_s19a_800DC028);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
