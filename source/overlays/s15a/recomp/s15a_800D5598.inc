extern char R_s15a_dat_800D9298[] __asm__("s15a_dat_800D9298");
int G_s15a_800D5598(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D5598");
int G_s15a_800D5598(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s15a_dat_800D9298);
     goto out;
out:
    RECOMP_RETURN;
}
