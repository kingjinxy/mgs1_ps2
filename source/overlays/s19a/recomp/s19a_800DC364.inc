extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_s19a_dat_800C393C[] __asm__("s19a_dat_800C393C");
extern char R_s19a_dat_800E03C0[] __asm__("s19a_dat_800E03C0");
extern char R_GM_GetMap[] __asm__("GM_GetMap");
extern char R_GV_StrCode[] __asm__("GV_StrCode");
extern char R_HZD_QueueDynamicSegment2[] __asm__("HZD_QueueDynamicSegment2");
extern char R_s19a_800D89D4[] __asm__("s19a_800D89D4");
extern char R_s19a_800DC2E4[] __asm__("s19a_800DC2E4");
extern char R_s19a_800DC4A8[] __asm__("s19a_800DC4A8");
int G_s19a_800DC364(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DC364");
int G_s19a_800DC364(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[6] + (u)0;
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s19a_dat_800E03C0;
    r[2] = 0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[17] + 36;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[2] + (int)R_GM_CurrentMap) = r[18];
    *(int *)((u)r[17] + 32) = r[18]; CALL(R_GV_StrCode);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[2] + (u)0;
    r[6] = (u)0 + 87; CALL(R_s19a_800DC4A8);
    r[16] = (u)r[17] + 272;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + (u)0;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s19a_dat_800C393C;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s19a_dat_800C393C + 8); CALL(R_s19a_800D89D4);
    r[4] = (u)r[18] + (u)0; CALL(R_GM_GetMap);
    r[5] = (u)r[16] + (u)0;
    r[4] = *(int *)((u)r[2] + 8);
    r[6] = (u)0 + 512;
    *(int *)((u)r[17] + 268) = r[4]; CALL(R_HZD_QueueDynamicSegment2);
    r[4] = (u)r[17] + (u)0; CALL(R_s19a_800DC2E4);
    *(int *)((u)r[17] + 292) = 0;
    *(int *)((u)r[17] + 288) = 0;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
