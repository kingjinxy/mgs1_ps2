extern char R_GM_GetMap[] __asm__("GM_GetMap");
extern char R_GV_ZeroMemory[] __asm__("GV_ZeroMemory");
extern char R_s17a_800CEDB0[] __asm__("s17a_800CEDB0");
int G_s17a_800CE5C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800CE5C8");
int G_s17a_800CE5C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[6] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[7] + (u)0;
    *(int *)((u)r[29] + 32) = r[31];
    r[5] = (u)0 + 228; CALL(R_GV_ZeroMemory);
    r[4] = (u)r[17] + (u)0;
    *(int *)((u)r[16] + 4) = r[18];
    *(short *)((u)r[16] + 12) = r[4]; CALL(R_GM_GetMap);
    r[5] = *(int *)((u)r[2] + 12);
    r[4] = (u)r[19] + (u)0; CALL(R_s17a_800CEDB0);
    *(int *)((u)r[16] + 0) = r[2];
    *(int *)((u)r[2] + 40) = r[18];
    r[31] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
