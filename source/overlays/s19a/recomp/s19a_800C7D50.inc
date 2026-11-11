extern char R_s19a_dat_800E06D4[] __asm__("s19a_dat_800E06D4");
int G_s19a_800C7D50(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C7D50");
int G_s19a_800C7D50(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s19a_dat_800E06D4);
    r[2] = r[2] & 1;
    c = ((r[2] == 0)); r[2] = (u)0 + 128; if (c) goto L800c7d74;
    r[2] = (u)0 + 130;
    *(int *)((u)r[4] + 0) = r[2]; goto out;
    L800c7d74:;
    *(int *)((u)r[4] + 0) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
