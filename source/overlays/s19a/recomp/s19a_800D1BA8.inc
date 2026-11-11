extern char R_s19a_dat_800C3664[] __asm__("s19a_dat_800C3664");
int G_s19a_800D1BA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D1BA8");
int G_s19a_800D1BA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[6] = (u)0 + (u)0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19a_dat_800C3664;
    r[5] = (u)r[5] << 2;
    r[3] = (u)r[5] + (u)r[2];
    L800d1bbc:;
    r[2] = *(int *)((u)r[4] + 2816);
    c = ((r[2] != 0)); r[6] = (u)r[6] + 1; if (c) goto L800d1bdc;
    r[3] = *(int *)((u)r[3] + 0);
    r[2] = (u)0 + 1;
    *(int *)((u)r[4] + 2816) = r[3]; goto out;
    L800d1bdc:;
    r[2] = (int)r[6] < 8;
    c = ((r[2] != 0)); r[4] = (u)r[4] + 4; if (c) goto L800d1bbc;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
