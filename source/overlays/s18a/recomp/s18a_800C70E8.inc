extern char R_s18a_dat_800E3EE0[] __asm__("s18a_dat_800E3EE0");
int G_s18a_800C70E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C70E8");
int G_s18a_800C70E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s18a_dat_800E3EE0) = r[4]; goto out;
out:
    RECOMP_RETURN;
}
