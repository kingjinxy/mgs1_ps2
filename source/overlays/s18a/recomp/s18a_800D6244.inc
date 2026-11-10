extern char R_DG_PutVector[] __asm__("DG_PutVector");
extern char R_GM_CaptureTarget[] __asm__("GM_CaptureTarget");
extern char R_GM_MoveTarget[] __asm__("GM_MoveTarget");
extern char R_GM_SetCaptureTarget[] __asm__("GM_SetCaptureTarget");
extern char R_GM_SetTarget[] __asm__("GM_SetTarget");
int G_s18a_800D6244(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D6244");
int G_s18a_800D6244(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 40) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 32) = r[16];
    r[16] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 36) = r[17];
    r[17] = (u)r[18] + 2028;
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)0 + 2;
    *(int *)((u)r[29] + 44) = r[31];
    r[6] = *(int *)((u)r[18] + 2352);
    r[7] = (u)r[16] + 8; CALL(R_GM_SetTarget);
    r[4] = (u)r[17] + (u)0;
    r[2] = (u)r[18] + 2120;
    *(int *)((u)r[29] + 16) = r[2];
    r[5] = *(int *)((u)r[16] + 24);
    r[6] = *(int *)((u)r[16] + 28);
    r[7] = (u)r[18] + 2112; CALL(R_GM_SetCaptureTarget);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[29] + 24;
    r[6] = (u)0 + 1; CALL(R_DG_PutVector);
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[29] + 24; CALL(R_GM_MoveTarget);
    r[4] = (u)r[17] + (u)0; CALL(R_GM_CaptureTarget);
    r[3] = (u)r[2] + (u)0;
    *(int *)((u)r[18] + 2100) = r[3];
    r[31] = *(int *)((u)r[29] + 44);
    r[18] = *(int *)((u)r[29] + 40);
    r[17] = *(int *)((u)r[29] + 36);
    r[16] = *(int *)((u)r[29] + 32);
    r[2] = (u)0 < (u)r[3];
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
