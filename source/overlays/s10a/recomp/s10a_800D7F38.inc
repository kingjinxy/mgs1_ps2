extern char R_GV_RandS[] __asm__("GV_RandS");
extern char R_s10a_800D7E98[] __asm__("s10a_800D7E98");
int G_s10a_800D7F38(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800D7F38");
int G_s10a_800D7F38(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 24) = r[31];
    r[17] = (u)r[5] + (u)0; CALL(R_s10a_800D7E98);
    r[4] = (u)0 + 16; CALL(R_GV_RandS);
    r[4] = (u)0 + 16;
    *(int *)((u)r[16] + 1808) = r[2]; CALL(R_GV_RandS);
    *(int *)((u)r[16] + 1812) = r[2];
    *(int *)((u)r[16] + 1748) = r[17];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
