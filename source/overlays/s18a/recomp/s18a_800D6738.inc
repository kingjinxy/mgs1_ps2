extern char R_GM_AlertMode[] __asm__("GM_AlertMode");
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s18a_800DA37C[] __asm__("s18a_800DA37C");
extern char R_s18a_dat_800C39F0[] __asm__("s18a_dat_800C39F0");
int G_s18a_800D6738(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D6738");
int G_s18a_800D6738(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[2] = *(unsigned short *)((u)r[2] + ((int)R_linkvarbuf + 26));
    r[2] = r[2] & 1;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d67bc;
    r[2] = *(int *)((u)r[2] + (int)R_GM_AlertMode);
    c = ((r[2] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800d67c0;
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[3] & 2068;
    c = ((r[2] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800d67c0;
    r[2] = 0x10000;
    r[2] = r[2] | 4098;
    r[2] = r[3] & r[2];
    c = ((r[2] == 0)); r[5] = (u)0 + (u)0; if (c) goto L800d6794;
    L800d678c:;
    r[2] = (u)0 + 1; goto L800d67c0;
    L800d6794:;
    r[6] = *(int *)((u)r[4] + 2220);
    r[2] = 0;
    r[3] = (u)r[2] + (int)R_s18a_dat_800C39F0;
    L800d67a0:;
    r[2] = *(int *)((u)r[3] + 0);
    c = ((r[6] == r[2])); r[5] = (u)r[5] + 1; if (c) goto L800d678c;
    r[2] = (u)r[5] < (u)3;
    c = ((r[2] != 0)); r[3] = (u)r[3] + 4; if (c) goto L800d67a0;
    L800d67bc:;
    r[2] = (u)0 + (u)0;
    L800d67c0:;
    c = ((r[2] == 0));  if (c) goto L800d6808;
    r[2] = *(unsigned short *)((u)r[4] + 2348);
    r[2] = (u)r[2] + 1;
    *(short *)((u)r[4] + 2348) = r[2];
    r[2] = r[2] & 65535;
    r[2] = (u)r[2] < (u)120;
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800d6808;
    r[2] = (u)r[2] + (int)R_s18a_800DA37C;
    *(short *)((u)r[4] + 2348) = 0;
    *(int *)((u)r[4] + 2220) = r[2];
    *(int *)((u)r[4] + 2224) = 0;
    *(short *)((u)r[4] + 2322) = 0;
    *(short *)((u)r[4] + 2320) = 0;
    *(short *)((u)r[4] + 112) = 0;
    *(short *)((u)r[4] + 108) = 0;
    L800d6808:;
     goto out;
out:
    RECOMP_RETURN;
}
