extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_800D7FE0[] __asm__("s18a_800D7FE0");
extern char R_s18a_800D8220[] __asm__("s18a_800D8220");
extern char R_s18a_dat_800E434C[] __asm__("s18a_dat_800E434C");
extern char R_s18a_dat_800E4364[] __asm__("s18a_dat_800E4364");
extern char R_GM_ExitBehindCamera[] __asm__("GM_ExitBehindCamera");
extern char R_s18a_800D65AC[] __asm__("s18a_800D65AC");
extern char R_s18a_800D65F8[] __asm__("s18a_800D65F8");
int G_s18a_800D8F28(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D8F28");
int G_s18a_800D8F28(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(short *)((u)r[16] + 2320);
    r[3] = *(unsigned short *)((u)r[16] + 2320);
    c = ((r[2] == 0)); r[2] = (u)r[3] + -1; if (c) goto L800d8f4c;
    *(short *)((u)r[16] + 2320) = r[2];
    L800d8f4c:;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s18a_dat_800E4364);
    c = ((r[2] != 0));  if (c) goto L800d8fb8;
    r[2] = *(short *)((u)r[16] + 2320);
    c = ((r[2] != 0)); r[2] = (u)0 + 450; if (c) goto L800d8fb8;
    r[5] = 0xfffe0000;
    r[5] = r[5] | 65535;
    r[4] = 0;
    *(short *)((u)r[16] + 2304) = r[2];
    r[2] = 0;
    r[3] = *(int *)((u)r[4] + (int)R_GM_PlayerStatus);
    r[2] = (u)r[2] + (int)R_s18a_800D7FE0;
    *(int *)((u)r[16] + 2220) = r[2];
    *(int *)((u)r[16] + 2224) = 0;
    *(short *)((u)r[16] + 2322) = 0;
    *(short *)((u)r[16] + 2320) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    r[3] = r[3] & r[5];
    *(int *)((u)r[4] + (int)R_GM_PlayerStatus) = r[3]; CALL(R_GM_ExitBehindCamera);
     goto L800d9024;
    L800d8fb8:;
    r[2] = *(int *)((u)r[16] + 2212);
    r[2] = *(unsigned short *)((u)r[2] + 2);
    r[2] = r[2] & 64;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d9004;
    r[2] = (u)r[2] + (int)R_s18a_800D8220;
    r[4] = 0;
    *(int *)((u)r[16] + 2220) = r[2];
    r[2] = *(int *)((u)r[4] + (int)R_GM_PlayerStatus);
    r[3] = (u)0 + -33;
    *(int *)((u)r[16] + 2224) = 0;
    *(short *)((u)r[16] + 2322) = 0;
    *(short *)((u)r[16] + 2320) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    r[2] = r[2] & r[3];
    *(int *)((u)r[4] + (int)R_GM_PlayerStatus) = r[2];
    L800d9004:;
    r[2] = 0;
    r[2] = *(unsigned short *)((u)r[2] + (int)R_s18a_dat_800E434C);
    r[4] = (u)r[16] + (u)0;
    r[2] = (u)r[2] + -2048;
    *(short *)((u)r[16] + 110) = r[2]; CALL(R_s18a_800D65AC);
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D65F8);
    L800d9024:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
int G_s18a_rc_800D9034(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_rc_800D9034");
int G_s18a_rc_800D9034(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
