int G_s14e_800CCC70(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CCC70");
int G_s14e_800CCC70(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)0 + 1;
    *(short *)((u)r[4] + 2848) = 0;
    *(short *)((u)r[4] + 2850) = 0;
    *(short *)((u)r[4] + 2852) = 0;
    *(int *)((u)r[4] + 2856) = 0;
    *(int *)((u)r[4] + 2876) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
