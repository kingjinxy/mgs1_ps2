int G_s10a_800E352C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800E352C");
int G_s10a_800E352C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)0 + 3;
    *(char *)((u)r[4] + 3) = r[2];
    r[2] = (u)0 + 96;
    *(char *)((u)r[4] + 7) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
