extern char R_s10a_dat_800E4A90[] __asm__("s10a_dat_800E4A90");
extern char R_s10a_dat_800E4A94[] __asm__("s10a_dat_800E4A94");
int G_s10a_800CE1B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800CE1B8");
int G_s10a_800CE1B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s10a_dat_800E4A94) = r[4]; goto out;
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s10a_dat_800E4A90) = r[4]; goto out;
out:
    RECOMP_RETURN;
}
