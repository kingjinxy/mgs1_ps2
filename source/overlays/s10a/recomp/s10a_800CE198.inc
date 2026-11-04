extern char R_s10a_dat_800E4970[] __asm__("s10a_dat_800E4970");
int G_s10a_800CE198(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800CE198");
int G_s10a_800CE198(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s10a_dat_800E4970;
    r[4] = (u)r[4] << 4;
    r[4] = (u)r[4] + (u)r[2];
    r[2] = (u)0 + 1;
    *(int *)((u)r[4] + 156) = 0;
    *(int *)((u)r[4] + 148) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
