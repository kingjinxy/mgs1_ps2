extern char R_s19a_dat_800E0CC8[] __asm__("s19a_dat_800E0CC8");
int G_s19a_800D659C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D659C");
int G_s19a_800D659C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19a_dat_800E0CC8;
    r[4] = (u)r[4] << 4;
    r[4] = (u)r[4] + (u)r[2];
    r[2] = (u)0 + 1;
    *(int *)((u)r[4] + 156) = 0;
    *(int *)((u)r[4] + 148) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
