extern char R_s19a_dat_800E053C[] __asm__("s19a_dat_800E053C");
int G_s19a_800C7D10(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C7D10");
int G_s19a_800C7D10(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_s19a_dat_800E053C);
    if (r[4]) { lo_ = (int)r[3] / (int)r[4]; hi_ = (int)r[3] % (int)r[4]; }
    c = ((r[4] != 0));  if (c) goto L800c7d2c;
    L800c7d2c:;
    r[1] = (u)0 + -1;
    c = ((r[4] != r[1])); r[1] = 0; if (c) goto L800c7d44;
    c = ((r[3] != r[1]));  if (c) goto L800c7d44;
    L800c7d44:;
    r[2] = hi_;
     goto out;
out:
    RECOMP_RETURN;
}
