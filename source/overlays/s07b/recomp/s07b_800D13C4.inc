extern char R_dword_8009F434[] __asm__("dword_8009F434");
extern char R_dword_8009F444[] __asm__("dword_8009F444");
extern char R_dword_8009F480[] __asm__("dword_8009F480");
extern char R_dword_8009F49C[] __asm__("dword_8009F49C");
extern char R_dword_800BDD28[] __asm__("dword_800BDD28");
extern char R_GM_FreeControl[] __asm__("GM_FreeControl");
extern char R_GM_FreeObject[] __asm__("GM_FreeObject");
extern char R_GM_FreeTarget[] __asm__("GM_FreeTarget");
extern char R_GM_ResetHomingTarget[] __asm__("GM_ResetHomingTarget");
extern char R_GM_VoxInit[] __asm__("GM_VoxInit");
extern char R_GV_DestroyOtherActor[] __asm__("GV_DestroyOtherActor");
extern char R_s07b_800CBCE8[] __asm__("s07b_800CBCE8");
int G_s07b_800D13C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800D13C4");
int G_s07b_800D13C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s07b_800CBCE8);
    r[4] = *(int *)((u)r[16] + 2008);
    c = ((r[4] == 0));  if (c) goto L800d13f0;
     CALL(R_GV_DestroyOtherActor);
    L800d13f0:;
    r[4] = *(int *)((u)r[16] + 2096);
    c = ((r[4] == 0));  if (c) goto L800d1408;
     CALL(R_GV_DestroyOtherActor);
    L800d1408:;
    r[4] = *(int *)((u)r[16] + 2100);
    c = ((r[4] == 0));  if (c) goto L800d1420;
     CALL(R_GV_DestroyOtherActor);
    L800d1420:;
    r[4] = (u)r[16] + 32; CALL(R_GM_FreeControl);
    r[4] = (u)r[16] + 156; CALL(R_GM_FreeObject);
    r[4] = *(int *)((u)r[16] + 2016);
     CALL(R_GM_FreeTarget);
    r[4] = *(int *)((u)r[16] + 2092);
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_dword_800BDD28) = 0;
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_dword_8009F444) = 0;
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_dword_8009F434) = 0;
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_dword_8009F49C) = 0;
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_dword_8009F480) = 0; CALL(R_GM_ResetHomingTarget);
     CALL(R_GM_VoxInit);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
