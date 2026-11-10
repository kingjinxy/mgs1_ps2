extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_800DAA50[] __asm__("s18a_800DAA50");
extern char R_GM_ConfigMotionControl[] __asm__("GM_ConfigMotionControl");
extern char R_s18a_800D5BF0[] __asm__("s18a_800D5BF0");
int G_s18a_800D706C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D706C");
int G_s18a_800D706C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 36) = r[17];
    r[17] = 0;
    r[2] = *(int *)((u)r[17] + (int)R_GM_PlayerStatus);
    *(int *)((u)r[29] + 32) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = r[2] & 4;
    c = ((r[2] != 0)); *(int *)((u)r[29] + 40) = r[31]; if (c) goto L800d7114;
    r[2] = *(unsigned short *)((u)r[16] + 2346);
    c = ((r[2] == 0));  if (c) goto L800d7114;
    r[2] = *(unsigned short *)((u)r[16] + 2264);
    c = ((r[2] == 0)); r[4] = (u)r[16] + 156; if (c) goto L800d7114;
    r[6] = *(unsigned short *)((u)r[16] + 2346);
    r[2] = (u)r[16] + 1076;
    *(int *)((u)r[29] + 16) = r[2];
    r[2] = (u)r[16] + 32;
    *(int *)((u)r[29] + 20) = r[2];
    r[2] = (u)r[16] + 1688;
    r[5] = (u)r[16] + 384;
    r[7] = (u)r[16] + 464;
    *(int *)((u)r[29] + 24) = r[2]; CALL(R_GM_ConfigMotionControl);
    r[4] = (u)r[16] + (u)0;
    r[2] = 0;
    r[5] = *(unsigned short *)((u)r[4] + 82);
    r[3] = *(int *)((u)r[17] + (int)R_GM_PlayerStatus);
    r[2] = (u)r[2] + (int)R_s18a_800DAA50;
    *(int *)((u)r[4] + 2220) = r[2];
    *(int *)((u)r[4] + 2224) = 0;
    *(short *)((u)r[4] + 2322) = 0;
    *(short *)((u)r[4] + 2320) = 0;
    *(short *)((u)r[4] + 112) = 0;
    *(short *)((u)r[4] + 108) = 0;
    r[3] = r[3] | 4;
    *(short *)((u)r[4] + 2286) = r[5];
    *(int *)((u)r[17] + (int)R_GM_PlayerStatus) = r[3]; CALL(R_s18a_800D5BF0);
    L800d7114:;
    r[31] = *(int *)((u)r[29] + 40);
    r[17] = *(int *)((u)r[29] + 36);
    r[16] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
