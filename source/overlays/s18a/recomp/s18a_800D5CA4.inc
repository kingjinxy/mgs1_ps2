extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_s18a_800D5B64[] __asm__("s18a_800D5B64");
int G_s18a_800D5CA4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D5CA4");
int G_s18a_800D5CA4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[2] = (u)0 + 450;
    *(int *)((u)r[29] + 16) = r[31];
    *(short *)((u)r[4] + 2304) = r[2];
    r[2] = *(int *)((u)r[4] + 2020);
    r[3] = (u)0 + -2049;
    r[2] = r[2] & r[3];
    *(int *)((u)r[4] + 2020) = r[2];
    r[2] = 0;
    *(short *)((u)r[2] + ((int)R_GM_Camera + 34)) = 0;
    r[2] = (u)0 + 4;
    *(short *)((u)r[4] + 2296) = r[2]; CALL(R_s18a_800D5B64);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
