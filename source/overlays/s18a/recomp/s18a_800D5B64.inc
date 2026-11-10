extern char R_s18a_dat_800C3A48[] __asm__("s18a_dat_800C3A48");
int G_s18a_800D5B64(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D5B64");
int G_s18a_800D5B64(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[7] = (u)r[2] + (int)R_s18a_dat_800C3A48;
    r[3] = LWL(((u)r[7] + 3), r[3]);
    r[3] = LWR(((u)r[7] + 0), r[3]);
    r[5] = LWL(((u)r[7] + 7), r[5]);
    r[5] = LWR(((u)r[7] + 4), r[5]);
    r[6] = LWL(((u)r[7] + 11), r[6]);
    r[6] = LWR(((u)r[7] + 8), r[6]);
    SWL(((u)r[4] + 2247), r[3]);
    SWR(((u)r[4] + 2244), r[3]);
    SWL(((u)r[4] + 2251), r[5]);
    SWR(((u)r[4] + 2248), r[5]);
    SWL(((u)r[4] + 2255), r[6]);
    SWR(((u)r[4] + 2252), r[6]);
    r[3] = LWL(((u)r[7] + 15), r[3]);
    r[3] = LWR(((u)r[7] + 12), r[3]);
    r[5] = LWL(((u)r[7] + 19), r[5]);
    r[5] = LWR(((u)r[7] + 16), r[5]);
    SWL(((u)r[4] + 2259), r[3]);
    SWR(((u)r[4] + 2256), r[3]);
    SWL(((u)r[4] + 2263), r[5]);
    SWR(((u)r[4] + 2260), r[5]);
     goto out;
out:
    RECOMP_RETURN;
}
