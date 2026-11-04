int G_s10a_800CC838(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800CC838");
int G_s10a_800CC838(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)0 + 4;
    *(short *)((u)r[4] + 2850) = r[2];
    *(short *)((u)r[4] + 2852) = r[2];
    *(int *)((u)r[4] + 2856) = 0;
    *(char *)((u)r[4] + 2970) = 0; goto out;
out:
    RECOMP_RETURN;
}
