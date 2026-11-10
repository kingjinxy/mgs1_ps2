extern char R_s18a_dat_800C3388[] __asm__("s18a_dat_800C3388");
int G_s18a_800CC660(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CC660");
int G_s18a_800CC660(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[6] = (u)0 + (u)0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_dat_800C3388;
    r[5] = (u)r[5] << 2;
    r[3] = (u)r[5] + (u)r[2];
    L800cc674:;
    r[2] = *(int *)((u)r[4] + 2496);
    c = ((r[2] != 0)); r[6] = (u)r[6] + 1; if (c) goto L800cc694;
    r[3] = *(int *)((u)r[3] + 0);
    r[2] = (u)0 + 1;
    *(int *)((u)r[4] + 2496) = r[3]; goto out;
    L800cc694:;
    r[2] = (int)r[6] < 8;
    c = ((r[2] != 0)); r[4] = (u)r[4] + 4; if (c) goto L800cc674;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
