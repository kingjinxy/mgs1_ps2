extern char R_GV_RandS[] __asm__("GV_RandS");
int G_s11h_800D3584(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800D3584");
int G_s11h_800D3584(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)0 + 128; CALL(R_GV_RandS);
    r[4] = (u)0 + 128;
    *(short *)((u)r[16] + 1628) = r[2]; CALL(R_GV_RandS);
    r[4] = (u)0 + 128;
    *(short *)((u)r[16] + 1630) = r[2]; CALL(R_GV_RandS);
    r[4] = (u)0 + 512;
    *(short *)((u)r[16] + 1632) = r[2]; CALL(R_GV_RandS);
    r[4] = (u)0 + 512;
    *(short *)((u)r[16] + 1636) = r[2]; CALL(R_GV_RandS);
    r[4] = (u)0 + 512;
    *(short *)((u)r[16] + 1638) = r[2]; CALL(R_GV_RandS);
    *(short *)((u)r[16] + 1640) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
