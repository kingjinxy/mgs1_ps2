int G_s19a_800D40CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D40CC");
int G_s19a_800D40CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2856);
    r[3] = *(unsigned short *)((u)r[4] + 3116);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[4] + 2856) = r[2];
    r[2] = (u)0 + (u)0;
    *(short *)((u)r[4] + 2888) = r[3]; goto out;
out:
    RECOMP_RETURN;
}
