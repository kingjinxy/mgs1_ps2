extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_GCL_StrToInt[] __asm__("GCL_StrToInt");
extern char R_NewRifleSightFast[] __asm__("NewRifleSightFast");
int G_s10a_800D65CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D65CC");
int G_s10a_800D65CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)0 + 112;
    r[2] = 0;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[16] + 32) = r[5];
    *(int *)((u)r[16] + 36) = r[6];
    *(int *)((u)r[2] + (int)R_GM_CurrentMap) = r[6]; CALL(R_GCL_GetOption);
    c = ((r[2] == 0));  if (c) goto L800d6608;
    r[4] = (u)r[2] + (u)0; CALL(R_GCL_StrToInt);
    *(int *)((u)r[16] + 92) = r[2];
    L800d6608:;
    r[2] = (u)0 + -28000;
    *(short *)((u)r[16] + 42) = r[2];
    r[2] = (u)0 + -23000;
    *(int *)((u)r[16] + 80) = 0;
    *(short *)((u)r[16] + 40) = 0;
    *(short *)((u)r[16] + 44) = r[2]; CALL(R_NewRifleSightFast);
    r[2] = (u)0 + (u)0;
    r[5] = 0;
    r[4] = 0x10000000;
    r[3] = *(int *)((u)r[5] + (int)R_GM_GameStatus);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[3] = r[3] | r[4];
    r[4] = 0x4a0000;
    r[3] = r[3] | r[4];
    *(int *)((u)r[5] + (int)R_GM_GameStatus) = r[3];
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
