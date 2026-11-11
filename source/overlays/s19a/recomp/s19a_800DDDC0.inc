extern char R_DG_Chanls[] __asm__("DG_Chanls");
extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_GM_PlayerBody[] __asm__("GM_PlayerBody");
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_GV_PadData[] __asm__("GV_PadData");
extern char R_DG_MakeCameraMatrix[] __asm__("DG_MakeCameraMatrix");
int G_s19a_800DDDC0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DDDC0");
int G_s19a_800DDDC0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = 0;
    r[4] = (u)r[4] + ((int)R_DG_Chanls + 492);
    r[5] = (u)r[16] + 32;
    *(int *)((u)r[29] + 20) = r[31];
    r[7] = *(int *)((u)r[16] + 48);
    r[6] = (u)r[16] + 40; CALL(R_DG_MakeCameraMatrix);
    r[3] = 0;
    r[4] = 0;
    r[2] = *(int *)((u)r[3] + (int)R_GM_GameStatus);
    r[5] = 0x4000000;
    r[2] = r[2] | 64;
    *(int *)((u)r[3] + (int)R_GM_GameStatus) = r[2];
    r[3] = 0;
    r[2] = *(int *)((u)r[4] + (int)R_GM_PlayerStatus);
    r[3] = *(int *)((u)r[3] + (int)R_GM_PlayerBody);
    r[2] = r[2] | r[5];
    c = ((r[3] == 0)); *(int *)((u)r[4] + (int)R_GM_PlayerStatus) = r[2]; if (c) goto L800dde30;
    r[2] = *(int *)((u)r[3] + 0);
    r[3] = *(int *)((u)r[2] + 40);
    r[4] = (u)0 + -129;
    r[3] = r[3] & r[4];
    *(int *)((u)r[2] + 40) = r[3];
    L800dde30:;
    r[3] = *(int *)((u)r[16] + 52);
    r[2] = (u)0 + 1;
    c = ((r[3] != r[2])); r[4] = 0; if (c) goto L800dde7c;
    r[3] = (u)r[4] + (int)R_GV_PadData;
    r[2] = *(unsigned char *)((u)r[3] + 2);
    c = ((r[2] == 0)); r[2] = (u)0 + -1; if (c) goto L800dde64;
    r[2] = *(int *)((u)r[16] + 56);
    *(int *)((u)r[2] + 0) = 0;
    r[2] = (u)0 + -1;
    L800dde64:;
    *(short *)((u)r[4] + (int)R_GV_PadData) = 0;
    *(short *)((u)r[3] + 2) = 0;
    *(short *)((u)r[3] + 4) = 0;
    *(short *)((u)r[3] + 6) = 0;
    *(short *)((u)r[3] + 8) = r[2];
    *(short *)((u)r[3] + 10) = 0;
    L800dde7c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
int G_s19a_rc_800DDE8C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_rc_800DDE8C");
int G_s19a_rc_800DDE8C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 60);
    r[2] = (u)0 + 1;
    *(int *)((u)r[3] + 0) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
