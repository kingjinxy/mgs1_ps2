extern char R_GM_GameOverTimer[] __asm__("GM_GameOverTimer");
extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_GV_DemoPadStatus[] __asm__("GV_DemoPadStatus");
extern char R_Takabe_JeepSystem[] __asm__("Takabe_JeepSystem");
extern char R_s19b_dword_800C3778[] __asm__("s19b_dword_800C3778");
extern char R_s19b_dword_800C3898[] __asm__("s19b_dword_800C3898");
extern char R_s19b_dword_800C38D0[] __asm__("s19b_dword_800C38D0");
extern char R_s19b_dword_800C3950[] __asm__("s19b_dword_800C3950");
extern char R_NewDemoCamera[] __asm__("NewDemoCamera");
int G_s19b_jlamp_800D0A20(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19b_jlamp_800D0A20");
int G_s19b_jlamp_800D0A20(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_GameOverTimer);
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 20) = r[31];
    c = ((r[2] != 0)); *(int *)((u)r[29] + 16) = r[16]; if (c) goto L800d0aac;
    r[2] = 0;
    r[16] = (u)r[2] + (int)R_Takabe_JeepSystem;
    r[2] = *(int *)((u)r[16] + 360);
    c = ((r[2] != 0));  if (c) goto L800d0aac;
    c = ((r[4] != 0)); r[2] = (u)0 + 1; if (c) goto L800d0a70;
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s19b_dword_800C3778; CALL(R_NewDemoCamera);
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_s19b_dword_800C3898; goto L800d0a88;
    L800d0a70:;
    c = ((r[4] != r[2])); r[4] = 0; if (c) goto L800d0aac;
    r[4] = (u)r[4] + (int)R_s19b_dword_800C38D0; CALL(R_NewDemoCamera);
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_s19b_dword_800C3950;
    L800d0a88:;
    *(int *)((u)r[16] + 360) = r[2];
    *(int *)((u)r[2] + 148) = r[3];
    r[2] = 0;
    r[4] = 0;
    *(short *)((u)r[2] + (int)R_GV_DemoPadStatus) = 0;
    r[2] = *(int *)((u)r[4] + (int)R_GM_GameStatus);
    r[3] = 0x40000000;
    r[2] = r[2] | r[3];
    *(int *)((u)r[4] + (int)R_GM_GameStatus) = r[2];
    L800d0aac:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
