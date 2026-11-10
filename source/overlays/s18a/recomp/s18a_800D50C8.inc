int G_s18a_800D50C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D50C8");
int G_s18a_800D50C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 3100);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[4] + 3100) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
