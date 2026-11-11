extern char R_GM_FreeControl[] __asm__("GM_FreeControl");
extern char R_GM_FreeObject[] __asm__("GM_FreeObject");
extern char R_GM_FreeTarget[] __asm__("GM_FreeTarget");
extern char R_GM_ResetHomingTarget[] __asm__("GM_ResetHomingTarget");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s19a_800D659C[] __asm__("s19a_800D659C");
int G_s19a_800CD51C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CD51C");
int G_s19a_800CD51C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = *(signed char *)((u)r[16] + 2932);
     CALL(R_s19a_800D659C);
    r[4] = (u)r[16] + 32; CALL(R_GM_FreeControl);
    r[4] = (u)r[16] + 156; CALL(R_GM_FreeObject);
    r[4] = (u)r[16] + 1956; CALL(R_GM_FreeObject);
    r[4] = *(int *)((u)r[16] + 2304);
     CALL(R_GM_FreeTarget);
    r[4] = *(int *)((u)r[16] + 2808);
     CALL(R_GV_DestroyActor);
    r[4] = *(int *)((u)r[16] + 2800);
     CALL(R_GV_DestroyActor);
    r[4] = *(int *)((u)r[16] + 2524);
     CALL(R_GM_ResetHomingTarget);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
