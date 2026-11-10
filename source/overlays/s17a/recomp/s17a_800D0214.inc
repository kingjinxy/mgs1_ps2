extern char R_s17a_dat_800E5D80[] __asm__("s17a_dat_800E5D80");
extern char R_s17a_dat_800E5DA4[] __asm__("s17a_dat_800E5DA4");
int G_s17a_800D0214(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800D0214");
int G_s17a_800D0214(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = 0;
    r[2] = (u)0 + 2;
    *(int *)((u)r[3] + (int)R_s17a_dat_800E5DA4) = r[2]; goto out;
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s17a_dat_800E5D80) = r[4]; goto out;
out:
    RECOMP_RETURN;
}
