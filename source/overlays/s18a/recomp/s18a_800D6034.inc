int G_s18a_800D6034(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D6034");
int G_s18a_800D6034(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    *(int *)((u)r[4] + 2132) = r[5];
    *(int *)((u)r[4] + 2136) = 0;
    *(short *)((u)r[4] + 2158) = 0;
    *(short *)((u)r[4] + 2156) = 0; goto out;
out:
    RECOMP_RETURN;
}
