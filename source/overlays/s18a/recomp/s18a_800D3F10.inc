extern char R_s18a_800D4380[] __asm__("s18a_800D4380");
int G_s18a_800D3F10(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D3F10");
int G_s18a_800D3F10(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 3068);
    r[2] = r[2] & 8191;
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800d3f2c;
    r[2] = (u)0 + (u)0; goto out;
    L800d3f2c:;
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_s18a_800D4380;
    *(int *)((u)r[4] + 3024) = r[3];
    *(int *)((u)r[4] + 3032) = 0;
    *(short *)((u)r[4] + 112) = 0;
    *(short *)((u)r[4] + 108) = 0; goto out;
out:
    RECOMP_RETURN;
}
