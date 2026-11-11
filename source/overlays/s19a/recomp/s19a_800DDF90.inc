extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_GM_PlayerBody[] __asm__("GM_PlayerBody");
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_GV_DestroyActorQuick[] __asm__("GV_DestroyActorQuick");
int G_s19a_800DDF90(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DDF90");
int G_s19a_800DDF90(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[4] + 40);
    c = ((r[2] != 0)); r[5] = 0xfbff0000; if (c) goto L800ddfb8;
    r[4] = *(int *)((u)r[4] + 36);
     CALL(R_GV_DestroyActorQuick);
    r[5] = 0xfbff0000;
    L800ddfb8:;
    r[5] = r[5] | 65535;
    r[4] = 0;
    r[2] = *(int *)((u)r[4] + (int)R_GM_GameStatus);
    r[3] = (u)0 + -65;
    r[2] = r[2] & r[3];
    r[3] = 0;
    *(int *)((u)r[4] + (int)R_GM_GameStatus) = r[2];
    r[2] = 0;
    r[6] = *(int *)((u)r[3] + (int)R_GM_PlayerStatus);
    r[4] = *(int *)((u)r[2] + (int)R_GM_PlayerBody);
    r[5] = r[6] & r[5];
    c = ((r[4] == 0)); *(int *)((u)r[3] + (int)R_GM_PlayerStatus) = r[5]; if (c) goto L800de02c;
    r[2] = r[6] & 16384;
    c = ((r[2] == 0));  if (c) goto L800de014;
    r[3] = *(int *)((u)r[4] + 0);
    r[2] = *(int *)((u)r[3] + 40);
    r[2] = r[2] | 128;
    *(int *)((u)r[3] + 40) = r[2]; goto L800de02c;
    L800de014:;
    r[2] = *(int *)((u)r[4] + 0);
    r[3] = *(int *)((u)r[2] + 40);
    r[4] = (u)0 + -129;
    r[3] = r[3] & r[4];
    *(int *)((u)r[2] + 40) = r[3];
    L800de02c:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
