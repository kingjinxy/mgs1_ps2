extern char R_s19a_dat_800E0B30[] __asm__("s19a_dat_800E0B30");
int G_s19a_800D2C50(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D2C50");
int G_s19a_800D2C50(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s19a_dat_800E0B30);
     goto out;
out:
    RECOMP_RETURN;
}
