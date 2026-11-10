int G_s17a_800C8DA0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800C8DA0");
int G_s17a_800C8DA0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    *(char *)((u)r[4] + 4) = r[5];
    *(char *)((u)r[4] + 5) = r[5];
    *(char *)((u)r[4] + 6) = r[5]; goto out;
out:
    RECOMP_RETURN;
}
