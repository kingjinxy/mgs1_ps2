extern char R_HZD_GetAddress[] __asm__("HZD_GetAddress");
extern char R_s19a_800D2B4C[] __asm__("s19a_800D2B4C");
int G_s19a_800D3C6C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D3C6C");
int G_s19a_800D3C6C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[16] + 3036;
    *(int *)((u)r[29] + 24) = r[31];
    r[4] = *(signed char *)((u)r[16] + 2972);
    r[5] = (u)r[17] + (u)0; CALL(R_s19a_800D2B4C);
    r[2] = *(int *)((u)r[16] + 76);
    r[5] = (u)r[17] + (u)0;
    r[4] = *(int *)((u)r[2] + 8);
    r[6] = (u)0 + -1; CALL(R_HZD_GetAddress);
    r[3] = *(int *)((u)r[16] + 76);
    *(int *)((u)r[16] + 3056) = r[2];
    r[2] = *(int *)((u)r[3] + 0);
    *(int *)((u)r[16] + 3060) = r[2];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
