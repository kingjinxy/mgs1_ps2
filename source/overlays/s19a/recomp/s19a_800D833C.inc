extern char R_GM_FreeControl[] __asm__("GM_FreeControl");
extern char R_GM_FreeObject[] __asm__("GM_FreeObject");
extern char R_GM_FreeTarget[] __asm__("GM_FreeTarget");
extern char R_GM_ResetHomingTarget[] __asm__("GM_ResetHomingTarget");
extern char R_HZD_DequeueDynamicSegment[] __asm__("HZD_DequeueDynamicSegment");
int G_s19a_800D833C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D833C");
int G_s19a_800D833C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = *(int *)((u)r[18] + 524);
    c = (((int)r[16] <= 0)); r[17] = (u)r[18] + 532; if (c) goto L800d8380;
    r[5] = (u)r[17] + (u)0;
    L800d8368:;
    r[17] = (u)r[17] + 16;
    r[4] = *(int *)((u)r[18] + 528);
    r[16] = (u)r[16] + -1; CALL(R_HZD_DequeueDynamicSegment);
    c = (((int)r[16] > 0)); r[5] = (u)r[17] + (u)0; if (c) goto L800d8368;
    L800d8380:;
    r[4] = *(int *)((u)r[18] + 500);
     CALL(R_GM_ResetHomingTarget);
    r[4] = (u)r[18] + 36; CALL(R_GM_FreeControl);
    r[4] = (u)r[18] + 160; CALL(R_GM_FreeObject);
    r[4] = *(int *)((u)r[18] + 460);
     CALL(R_GM_FreeTarget);
    r[4] = *(int *)((u)r[18] + 464);
     CALL(R_GM_FreeTarget);
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
