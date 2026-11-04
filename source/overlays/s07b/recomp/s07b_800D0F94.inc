extern char R_s07b_800CB2A4[] __asm__("s07b_800CB2A4");
extern char R_s07b_800CCBFC[] __asm__("s07b_800CCBFC");
int G_s07b_800D0F94(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800D0F94");
int G_s07b_800D0F94(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s07b_800CB2A4);
    r[4] = (u)r[16] + (u)0; CALL(R_s07b_800CCBFC);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
