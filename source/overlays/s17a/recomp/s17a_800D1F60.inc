extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_s17a_dat_800C35A8[] __asm__("s17a_dat_800C35A8");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s17a_800CE7B0[] __asm__("s17a_800CE7B0");
extern char R_s17a_800CEB48[] __asm__("s17a_800CEB48");
int G_s17a_800D1F60(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800D1F60");
int G_s17a_800D1F60(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[5] = (u)0 + 2;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s17a_dat_800C35A8;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = *(unsigned short *)((u)r[16] + 36);
    r[3] = *(int *)((u)r[16] + 32);
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_GM_CurrentMap) = r[3]; CALL(R_s17a_800CE7B0);
    r[3] = (u)0 + 1;
    c = ((r[2] != r[3]));  if (c) goto L800d1fbc;
    r[4] = *(int *)((u)r[16] + 68);
    r[5] = *(int *)((u)r[16] + 72);
    r[6] = *(int *)((u)r[16] + 64);
    r[7] = *(int *)((u)r[16] + 76);
     CALL(R_s17a_800CEB48);
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    L800d1fbc:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
