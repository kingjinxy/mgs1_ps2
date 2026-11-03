int G_s10a_800D1DD8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D1DD8");
int G_s10a_800D1DD8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(unsigned short *)((u)r[4] + 42);
    *(short *)((u)r[4] + 92) = r[2]; goto out;
out:
    return r[2];
}
