extern char R_s19a_800D2C50[] __asm__("s19a_800D2C50");
int G_s19a_800D3F88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D3F88");
int G_s19a_800D3F88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = (u)0 + 5;
    *(int *)((u)r[29] + 20) = r[31];
    *(short *)((u)r[16] + 2850) = r[2];
    *(short *)((u)r[16] + 2852) = r[2]; CALL(R_s19a_800D2C50);
    *(char *)((u)r[16] + 2972) = r[2];
    *(int *)((u)r[16] + 2856) = 0;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
