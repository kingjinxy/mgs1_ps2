extern char R_s19a_800D38EC[] __asm__("s19a_800D38EC");
int G_s19a_800D3A18(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D3A18");
int G_s19a_800D3A18(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    r[8] = *(int *)((u)r[29] + 56);
    r[3] = *(int *)((u)r[29] + 60);
    r[2] = (u)0 + 1;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 24) = r[2];
    *(int *)((u)r[29] + 16) = r[3];
    *(int *)((u)r[29] + 20) = r[8]; CALL(R_s19a_800D38EC);
    r[31] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
