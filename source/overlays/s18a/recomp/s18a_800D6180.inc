extern char R_DG_PutVector[] __asm__("DG_PutVector");
extern char R_DG_RotVector[] __asm__("DG_RotVector");
extern char R_GM_MoveTarget[] __asm__("GM_MoveTarget");
extern char R_GM_PowerTarget[] __asm__("GM_PowerTarget");
extern char R_GM_SetPowerTarget[] __asm__("GM_SetPowerTarget");
extern char R_GM_SetTarget[] __asm__("GM_SetTarget");
int G_s18a_800D6180(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D6180");
int G_s18a_800D6180(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    r[2] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 36) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 32) = r[16];
    r[16] = (u)r[2] + 2028;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 4;
    *(int *)((u)r[29] + 40) = r[31];
    r[6] = *(int *)((u)r[2] + 2352);
    r[7] = (u)r[17] + 8; CALL(R_GM_SetTarget);
    r[4] = (u)r[17] + 16;
    r[5] = (u)r[29] + 24;
    r[6] = (u)0 + 1; CALL(R_DG_RotVector);
    r[3] = *(int *)((u)r[17] + 28);
    r[2] = (u)0 + 1;
    c = ((r[3] != r[2])); r[2] = (u)r[29] + 24; if (c) goto L800d61ec;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 3;
    *(int *)((u)r[29] + 16) = r[3];
    *(int *)((u)r[29] + 20) = r[2];
    r[7] = *(int *)((u)r[17] + 24);
    r[6] = (u)r[5] + (u)0; goto L800d6204;
    L800d61ec:;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 3;
    *(int *)((u)r[29] + 16) = r[3];
    *(int *)((u)r[29] + 20) = r[2];
    r[7] = *(int *)((u)r[17] + 24);
    r[6] = (u)0 + 4;
    L800d6204:;
     CALL(R_GM_SetPowerTarget);
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[29] + 24;
    r[6] = (u)0 + 1; CALL(R_DG_PutVector);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[29] + 24; CALL(R_GM_MoveTarget);
    r[4] = (u)r[16] + (u)0; CALL(R_GM_PowerTarget);
    r[31] = *(int *)((u)r[29] + 40);
    r[17] = *(int *)((u)r[29] + 36);
    r[16] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
