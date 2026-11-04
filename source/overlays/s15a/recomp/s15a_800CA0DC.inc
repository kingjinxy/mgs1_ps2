extern char R_DG_ZeroVector[] __asm__("DG_ZeroVector");
extern char R_s15a_dat_800C34B0[] __asm__("s15a_dat_800C34B0");
extern char R_GM_AllocTarget[] __asm__("GM_AllocTarget");
extern char R_GM_SetPowerTarget[] __asm__("GM_SetPowerTarget");
extern char R_GM_SetTarget[] __asm__("GM_SetTarget");
int G_s15a_800CA0DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CA0DC");
int G_s15a_800CA0DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 24) = r[16]; CALL(R_GM_AllocTarget);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); *(int *)((u)r[17] + 1636) = r[16]; if (c) goto L800ca180;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 21;
    r[6] = (u)0 + 2;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s15a_dat_800C34B0 + 16); CALL(R_GM_SetTarget);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 1;
    r[2] = (u)0 + 255;
    *(int *)((u)r[29] + 16) = r[2];
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_DG_ZeroVector;
    *(int *)((u)r[29] + 20) = r[2];
    r[7] = *(int *)((u)r[17] + 1704);
    r[6] = (u)0 + -1; CALL(R_GM_SetPowerTarget);
    r[2] = *(int *)((u)r[17] + 1704);
    *(int *)((u)r[17] + 2304) = r[2]; CALL(R_GM_AllocTarget);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); *(int *)((u)r[17] + 1640) = r[16]; if (c) goto L800ca180;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 8;
    r[6] = (u)0 + (u)0;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s15a_dat_800C34B0 + 24); CALL(R_GM_SetTarget);
    r[2] = (u)0 + 1;
    *(short *)((u)r[16] + 60) = r[2];
    r[2] = (u)0 + (u)0; goto L800ca184;
    L800ca180:;
    r[2] = (u)0 + -1;
    L800ca184:;
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
