int G_s17a_800CA6D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800CA6D8");
int G_s17a_800CA6D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[29] + 16);
    *(int *)((u)r[4] + 40) = r[5];
    *(short *)((u)r[4] + 56) = r[6];
    *(short *)((u)r[4] + 58) = r[7];
    *(short *)((u)r[4] + 60) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
