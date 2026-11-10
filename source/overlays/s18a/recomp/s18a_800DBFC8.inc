extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_800D9724[] __asm__("s18a_800D9724");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_s18a_800DB6B4[] __asm__("s18a_800DB6B4");
extern char R_s18a_800DB8DC[] __asm__("s18a_800DB8DC");
int G_s18a_800DBFC8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DBFC8");
int G_s18a_800DBFC8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = 0;
    r[4] = (u)0 + -17;
    *(int *)((u)r[29] + 24) = r[31];
    r[3] = *(int *)((u)r[16] + 2216);
    r[2] = *(int *)((u)r[17] + (int)R_GM_PlayerStatus);
    r[3] = *(int *)((u)r[3] + 0);
    r[2] = r[2] & r[4];
    *(int *)((u)r[17] + (int)R_GM_PlayerStatus) = r[2];
    r[2] = *(short *)((u)r[16] + 170);
    r[5] = *(unsigned char *)((u)r[3] + 3);
    c = ((r[2] == r[5])); r[4] = (u)r[16] + 156; if (c) goto L800dc018;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    L800dc018:;
    r[2] = *(int *)((u)r[16] + 2212);
    r[2] = *(unsigned short *)((u)r[2] + 0);
    r[2] = r[2] & 16;
    c = ((r[2] != 0)); r[2] = 0xffff0000; if (c) goto L800dc068;
    r[2] = r[2] | 32766;
    r[3] = 0;
    r[4] = *(int *)((u)r[17] + (int)R_GM_PlayerStatus);
    r[3] = (u)r[3] + (int)R_s18a_800D9724;
    *(short *)((u)r[16] + 2342) = 0;
    *(int *)((u)r[16] + 2220) = r[3];
    *(int *)((u)r[16] + 2224) = 0;
    *(short *)((u)r[16] + 2322) = 0;
    *(short *)((u)r[16] + 2320) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    r[4] = r[4] & r[2];
    *(int *)((u)r[17] + (int)R_GM_PlayerStatus) = r[4];
    L800dc068:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800DB6B4);
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800DB8DC);
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
