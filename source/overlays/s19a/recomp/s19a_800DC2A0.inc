extern char R_GM_FreeTarget[] __asm__("GM_FreeTarget");
extern char R_HZD_DequeueDynamicSegment[] __asm__("HZD_DequeueDynamicSegment");
extern char R_s19a_800DC60C[] __asm__("s19a_800DC60C");
int G_s19a_800DC2A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DC2A0");
int G_s19a_800DC2A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = *(int *)((u)r[16] + 268);
    r[5] = (u)r[16] + 272; CALL(R_HZD_DequeueDynamicSegment);
    r[4] = *(int *)((u)r[16] + 36);
     CALL(R_s19a_800DC60C);
    r[4] = *(int *)((u)r[16] + 264);
     CALL(R_GM_FreeTarget);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
