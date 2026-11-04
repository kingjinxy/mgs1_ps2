extern char R_GM_ConfigMotionAdjust[] __asm__("GM_ConfigMotionAdjust");
extern char R_s10a_800DD238[] __asm__("s10a_800DD238");
extern char R_s10a_800DD370[] __asm__("s10a_800DD370");
int G_s10a_800DD9EC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800DD9EC");
int G_s10a_800DD9EC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)r[16] + 160;
    r[5] = (u)r[16] + 1436;
    r[2] = (u)0 + 6;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[16] + 1700) = 0;
    *(int *)((u)r[16] + 1696) = 0;
    *(int *)((u)r[16] + 1704) = 0;
    *(int *)((u)r[16] + 1692) = 0;
    *(int *)((u)r[16] + 1708) = 0;
    *(int *)((u)r[16] + 1680) = 0;
    *(int *)((u)r[16] + 1672) = r[2]; CALL(R_GM_ConfigMotionAdjust);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 16; CALL(R_s10a_800DD238);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + (u)0; CALL(R_s10a_800DD370);
    *(int *)((u)r[16] + 1912) = 0;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
