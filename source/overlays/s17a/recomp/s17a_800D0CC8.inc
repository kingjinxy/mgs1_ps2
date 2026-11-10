extern char R_s17a_800D0C18[] __asm__("s17a_800D0C18");
int G_s17a_800D0CC8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800D0CC8");
int G_s17a_800D0CC8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[4] = (u)0 + 64;
    r[5] = (u)0 + 32;
    *(int *)((u)r[29] + 16) = r[31];
    r[6] = (u)0 + (u)0; CALL(R_s17a_800D0C18);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
