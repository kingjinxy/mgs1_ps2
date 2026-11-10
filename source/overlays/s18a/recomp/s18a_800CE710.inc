extern char R_s18a_800CC800[] __asm__("s18a_800CC800");
extern char R_s18a_800CC8F0[] __asm__("s18a_800CC8F0");
int G_s18a_800CE710(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CE710");
int G_s18a_800CE710(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s18a_800CC800);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 2000; CALL(R_s18a_800CC8F0);
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800ce750;
    *(int *)((u)r[16] + 2400) = r[2];
    r[2] = (u)0 + 3;
    *(int *)((u)r[16] + 2404) = r[2];
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0; goto L800ce760;
    L800ce750:;
    r[2] = *(int *)((u)r[16] + 2408);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + 2408) = r[2];
    L800ce760:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
