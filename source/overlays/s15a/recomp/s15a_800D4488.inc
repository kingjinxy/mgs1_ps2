extern char R_GM_AllocTarget[] __asm__("GM_AllocTarget");
extern char R_GM_GetMap[] __asm__("GM_GetMap");
extern char R_GM_SetTarget[] __asm__("GM_SetTarget");
int G_s15a_800D4488(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D4488");
int G_s15a_800D4488(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 40) = r[20];
    r[20] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 44) = r[31];
    *(int *)((u)r[29] + 36) = r[19];
    *(int *)((u)r[29] + 32) = r[18];
    *(int *)((u)r[29] + 28) = r[17];
    *(int *)((u)r[29] + 24) = r[16];
    r[4] = *(int *)((u)r[20] + 32);
    r[16] = (u)0 + (u)0; CALL(R_GM_GetMap);
    r[2] = *(int *)((u)r[20] + 36);
    c = (((int)r[2] <= 0)); r[19] = (u)0 + 50; if (c) goto L800d4510;
    r[18] = (u)0 + 108;
    L800d44c8:;
    r[17] = (u)r[20] + (u)r[18]; CALL(R_GM_AllocTarget);
    c = ((r[2] == 0)); *(int *)((u)r[17] + 0) = r[2]; if (c) goto L800d44f8;
    r[4] = (u)r[2] + (u)0;
    r[5] = (u)0 + 20;
    r[6] = (u)0 + 2;
    r[7] = (u)r[29] + 16;
    *(short *)((u)r[29] + 16) = r[19];
    *(short *)((u)r[29] + 18) = r[19];
    *(short *)((u)r[29] + 20) = r[19]; CALL(R_GM_SetTarget);
    L800d44f8:;
    *(int *)((u)r[17] + 960) = 0;
    r[2] = *(int *)((u)r[20] + 36);
    r[16] = (u)r[16] + 1;
    r[2] = (int)r[16] < (int)r[2];
    c = ((r[2] != 0)); r[18] = (u)r[18] + 972; if (c) goto L800d44c8;
    L800d4510:;
    r[31] = *(int *)((u)r[29] + 44);
    r[20] = *(int *)((u)r[29] + 40);
    r[19] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
