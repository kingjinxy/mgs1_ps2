extern char R_s19a_dat_800E0E4C[] __asm__("s19a_dat_800E0E4C");
int G_s19a_800DD460(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DD460");
int G_s19a_800DD460(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = 0;
    r[2] = (u)0 + 1;
    *(int *)((u)r[3] + (int)R_s19a_dat_800E0E4C) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
