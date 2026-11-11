extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_GM_GetMap[] __asm__("GM_GetMap");
extern char R_GV_ZeroMemory[] __asm__("GV_ZeroMemory");
extern char R_s19a_800DC5C8[] __asm__("s19a_800DC5C8");
int G_s19a_800DC4A8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DC4A8");
int G_s19a_800DC4A8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[6] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    r[5] = (u)0 + 228; CALL(R_GV_ZeroMemory);
    r[2] = 0;
    r[4] = *(int *)((u)r[2] + (int)R_GM_CurrentMap);
    r[2] = *(unsigned short *)((u)r[2] + (int)R_GM_CurrentMap);
    *(int *)((u)r[16] + 4) = r[17];
    *(short *)((u)r[16] + 12) = r[2]; CALL(R_GM_GetMap);
    r[5] = *(int *)((u)r[2] + 12);
    r[4] = (u)r[18] + (u)0; CALL(R_s19a_800DC5C8);
    *(int *)((u)r[16] + 0) = r[2];
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
