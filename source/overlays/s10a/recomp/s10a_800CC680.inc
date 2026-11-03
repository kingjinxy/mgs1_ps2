int G_s10a_800CC680(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CC680");
int G_s10a_800CC680(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = (u)0 + 7;
    *(short *)((u)r[4] + 2850) = r[2];
    r[2] = (u)0 + 11;
    *(short *)((u)r[4] + 2852) = r[2];
    *(int *)((u)r[4] + 2856) = 0; goto out;
out:
    return r[2];
}
