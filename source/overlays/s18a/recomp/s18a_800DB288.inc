extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_800D9210[] __asm__("s18a_800D9210");
extern char R_s18a_800D9724[] __asm__("s18a_800D9724");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_s18a_800DB1EC[] __asm__("s18a_800DB1EC");
int G_s18a_800DB288(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DB288");
int G_s18a_800DB288(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[5] = 0;
    r[4] = *(int *)((u)r[5] + (int)R_GM_PlayerStatus);
    r[2] = r[4] & 2;
    c = ((r[2] != 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800db2b8;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_800D9210; goto L800db2e8;
    L800db2b8:;
    r[2] = *(int *)((u)r[16] + 2212);
    r[3] = *(unsigned short *)((u)r[2] + 0);
    r[2] = r[3] & 20480;
    c = ((r[2] != 0)); r[2] = r[3] & 4096; if (c) goto L800db304;
    r[2] = (u)0 + -17;
    r[2] = r[4] & r[2];
    *(int *)((u)r[5] + (int)R_GM_PlayerStatus) = r[2];
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_800D9724;
    L800db2e8:;
    *(int *)((u)r[16] + 2220) = r[2];
    *(int *)((u)r[16] + 2224) = 0;
    *(short *)((u)r[16] + 2322) = 0;
    *(short *)((u)r[16] + 2320) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0; goto L800db360;
    L800db304:;
    c = ((r[2] == 0));  if (c) goto L800db328;
    r[2] = *(int *)((u)r[16] + 2216);
    r[2] = *(int *)((u)r[2] + 4);
    r[5] = *(unsigned char *)((u)r[2] + 3);
     goto L800db33c;
    L800db328:;
    r[2] = *(int *)((u)r[16] + 2216);
    r[2] = *(int *)((u)r[2] + 4);
    r[5] = *(unsigned char *)((u)r[2] + 4);
    L800db33c:;
    r[2] = *(short *)((u)r[16] + 170);
    c = ((r[2] == r[5])); r[4] = (u)r[16] + 156; if (c) goto L800db358;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800db358:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800DB1EC);
    L800db360:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_800DA0C8[] __asm__("s18a_800DA0C8");
int G_s18a_rc_800DB370(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_rc_800DB370");
int G_s18a_rc_800DB370(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2212);
    r[2] = *(unsigned short *)((u)r[2] + 2);
    r[2] = r[2] & 65519;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800db3bc;
    r[2] = (u)r[2] + (int)R_s18a_800DA0C8;
    *(int *)((u)r[4] + 2220) = r[2];
    *(int *)((u)r[4] + 2224) = 0;
    *(short *)((u)r[4] + 2322) = 0;
    *(short *)((u)r[4] + 2320) = 0;
    *(short *)((u)r[4] + 112) = 0;
    *(short *)((u)r[4] + 108) = 0;
    r[4] = 0;
    r[2] = *(int *)((u)r[4] + (int)R_GM_PlayerStatus);
    r[3] = (u)0 + -65;
    r[2] = r[2] & r[3];
    *(int *)((u)r[4] + (int)R_GM_PlayerStatus) = r[2];
    L800db3bc:;
     goto out;
out:
    RECOMP_RETURN;
}
extern char R_s18a_800DA84C[] __asm__("s18a_800DA84C");
extern char R_s18a_dat_800E4348[] __asm__("s18a_dat_800E4348");
int G_s18a_rc_800DB3C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_rc_800DB3C4");
int G_s18a_rc_800DB3C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s18a_dat_800E4348);
    c = (((int)r[2] < 0)); r[2] = 0; if (c) goto L800db3f4;
    r[2] = (u)r[2] + (int)R_s18a_800DA84C;
    *(int *)((u)r[4] + 2220) = r[2];
    *(int *)((u)r[4] + 2224) = 0;
    *(short *)((u)r[4] + 2322) = 0;
    *(short *)((u)r[4] + 2320) = 0;
    *(short *)((u)r[4] + 112) = 0;
    *(short *)((u)r[4] + 108) = 0;
    L800db3f4:;
     goto out;
out:
    RECOMP_RETURN;
}
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_800DA8CC[] __asm__("s18a_800DA8CC");
extern char R_s18a_dat_800E4348[] __asm__("s18a_dat_800E4348");
extern char R_s18a_800D5738[] __asm__("s18a_800D5738");
int G_s18a_rc_800DB3FC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_rc_800DB3FC");
int G_s18a_rc_800DB3FC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[2] = 0;
    r[5] = *(int *)((u)r[2] + (int)R_s18a_dat_800E4348);
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = (((int)r[5] >= 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800db450;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_800DA8CC;
    r[4] = 0;
    *(int *)((u)r[16] + 2220) = r[2];
    r[2] = *(int *)((u)r[4] + (int)R_GM_PlayerStatus);
    r[3] = (u)0 + -17;
    *(int *)((u)r[16] + 2224) = 0;
    *(short *)((u)r[16] + 2322) = 0;
    *(short *)((u)r[16] + 2320) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    r[2] = r[2] & r[3];
    *(int *)((u)r[4] + (int)R_GM_PlayerStatus) = r[2]; goto L800db45c;
    L800db450:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D5738);
    *(short *)((u)r[16] + 110) = r[2];
    L800db45c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
