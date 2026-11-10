extern char R_DG_PutVector[] __asm__("DG_PutVector");
extern char R_GM_C4Target[] __asm__("GM_C4Target");
extern char R_GM_MoveTarget[] __asm__("GM_MoveTarget");
extern char R_GM_SetCaptureTarget[] __asm__("GM_SetCaptureTarget");
extern char R_GM_SetTarget[] __asm__("GM_SetTarget");
int G_s18a_800D62DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D62DC");
int G_s18a_800D62DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
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
    r[5] = (u)0 + 64;
    *(int *)((u)r[29] + 44) = r[31];
    r[6] = *(int *)((u)r[18] + 2352);
    r[7] = (u)r[16] + 8; CALL(R_GM_SetTarget);
    r[4] = (u)r[17] + (u)0;
    r[6] = (u)0 + (u)0;
    r[2] = (u)r[18] + 2120;
    *(int *)((u)r[29] + 16) = r[2];
    r[5] = *(int *)((u)r[16] + 24);
    r[7] = (u)r[18] + 2112; CALL(R_GM_SetCaptureTarget);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[29] + 24;
    r[6] = (u)0 + 1; CALL(R_DG_PutVector);
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[29] + 24; CALL(R_GM_MoveTarget);
    r[4] = (u)r[17] + (u)0; CALL(R_GM_C4Target);
    r[4] = (u)r[2] + (u)0;
    c = ((r[4] != 0)); *(int *)((u)r[18] + 2100) = r[4]; if (c) goto L800d6364;
    r[2] = (u)0 + (u)0; goto L800d6394;
    L800d6364:;
    r[2] = *(unsigned short *)((u)r[4] + 0);
    r[2] = r[2] & 32;
    c = ((r[2] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800d6380;
    r[2] = (u)0 + 1; goto L800d6394;
    L800d6380:;
    r[3] = *(unsigned short *)((u)r[4] + 6);
    r[3] = r[3] & 65471;
    *(short *)((u)r[4] + 6) = r[3];
    *(int *)((u)r[18] + 2100) = 0;
    L800d6394:;
    r[31] = *(int *)((u)r[29] + 44);
    r[18] = *(int *)((u)r[29] + 40);
    r[17] = *(int *)((u)r[29] + 36);
    r[16] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
