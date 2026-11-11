extern char R_s19a_dat_800E0B38[] __asm__("s19a_dat_800E0B38");
int G_s19a_800D2C28(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D2C28");
int G_s19a_800D2C28(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = (u)0 + 47;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19a_dat_800E0B38;
    r[2] = (u)r[2] + 376;
    L800d2c38:;
    *(short *)((u)r[2] + 6) = 0;
    r[3] = (u)r[3] + -1;
    c = (((int)r[3] >= 0)); r[2] = (u)r[2] + -8; if (c) goto L800d2c38;
     goto out;
out:
    RECOMP_RETURN;
}
