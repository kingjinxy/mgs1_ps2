extern char R_s19a_dat_800E0198[] __asm__("s19a_dat_800E0198");
extern char R_GM_ConfigObjectRoot[] __asm__("GM_ConfigObjectRoot");
extern char R_GM_InitObject[] __asm__("GM_InitObject");
extern char R_printf[] __asm__("printf");
int G_s19a_800D387C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D387C");
int G_s19a_800D387C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[6] + (u)0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + 40;
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s19a_dat_800E0198;
    *(int *)((u)r[29] + 28) = r[31];
    r[5] = (u)0 + 15240; CALL(R_printf);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 15240;
    r[6] = (u)0 + 877;
    r[7] = (u)0 + (u)0; CALL(R_GM_InitObject);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)r[18] + (u)0; CALL(R_GM_ConfigObjectRoot);
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
