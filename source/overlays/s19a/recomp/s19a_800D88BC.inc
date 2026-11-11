extern char R_s19a_800D8840[] __asm__("s19a_800D8840");
int G_s19a_800D88BC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D88BC");
int G_s19a_800D88BC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    r[4] = r[4] & 255;
    *(int *)((u)r[29] + 16) = r[5];
    r[5] = (u)0 + (u)0;
    r[6] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    r[7] = (u)r[5] + (u)0; CALL(R_s19a_800D8840);
    r[31] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
