extern char R_GV_ZeroMemory[] __asm__("GV_ZeroMemory");
int G_s14e_800C5DAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800C5DAC");
int G_s14e_800C5DAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[16] + 2248;
    r[4] = (u)r[17] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    r[5] = (u)0 + 36; CALL(R_GV_ZeroMemory);
    r[2] = (u)0 + 450;
    *(int *)((u)r[16] + 2248) = 0;
    *(short *)((u)r[17] + 28) = r[2];
    r[2] = (u)0 + 1;
    *(short *)((u)r[17] + 30) = r[2];
    *(int *)((u)r[16] + 2284) = 0;
    *(int *)((u)r[16] + 2288) = 0;
    *(int *)((u)r[16] + 2292) = 0;
    *(int *)((u)r[16] + 2296) = 0;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
