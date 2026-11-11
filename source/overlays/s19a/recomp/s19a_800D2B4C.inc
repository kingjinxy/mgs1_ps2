extern char R_s19a_dat_800E0B38[] __asm__("s19a_dat_800E0B38");
int G_s19a_800D2B4C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D2B4C");
int G_s19a_800D2B4C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19a_dat_800E0B38;
    r[4] = (u)r[4] << 3;
    r[4] = (u)r[4] + (u)r[2];
    r[3] = LWL(((u)r[4] + 3), r[3]);
    r[3] = LWR(((u)r[4] + 0), r[3]);
    r[6] = LWL(((u)r[4] + 7), r[6]);
    r[6] = LWR(((u)r[4] + 4), r[6]);
    SWL(((u)r[5] + 3), r[3]);
    SWR(((u)r[5] + 0), r[3]);
    SWL(((u)r[5] + 7), r[6]);
    SWR(((u)r[5] + 4), r[6]); goto out;
out:
    RECOMP_RETURN;
}
