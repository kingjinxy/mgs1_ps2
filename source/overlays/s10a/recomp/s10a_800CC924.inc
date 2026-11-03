extern char R_s10a_800C4B4C[] __asm__("s10a_800C4B4C");
int G_s10a_800CC924(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CC924");
int G_s10a_800CC924(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = (u)0 + 5;
    *(int *)((u)r[29] + 20) = r[31];
    *(short *)((u)r[16] + 2850) = r[2];
    *(short *)((u)r[16] + 2852) = r[2]; CALL(R_s10a_800C4B4C);
    *(char *)((u)r[16] + 2972) = r[2];
    *(int *)((u)r[16] + 2856) = 0;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
