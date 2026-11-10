extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_800D9158[] __asm__("s18a_800D9158");
extern char R_s18a_800D5798[] __asm__("s18a_800D5798");
extern char R_s18a_800D7158[] __asm__("s18a_800D7158");
int G_s18a_800D9628(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D9628");
int G_s18a_800D9628(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = 0;
    r[2] = *(int *)((u)r[17] + (int)R_GM_PlayerStatus);
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = r[2] & 2;
    c = ((r[2] != 0)); *(int *)((u)r[29] + 24) = r[31]; if (c) goto L800d96c4;
    r[2] = *(int *)((u)r[16] + 2212);
    r[2] = *(unsigned short *)((u)r[2] + 2);
    r[2] = r[2] & 64;
    c = ((r[2] == 0));  if (c) goto L800d96c4;
     CALL(R_s18a_800D5798);
    c = ((r[2] != 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800d96c4;
    r[2] = (u)0 + 450;
    *(short *)((u)r[16] + 2304) = r[2]; CALL(R_s18a_800D7158);
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_800D9158;
    *(int *)((u)r[16] + 2220) = r[2];
    r[2] = *(int *)((u)r[17] + (int)R_GM_PlayerStatus);
    r[3] = (u)0 + -81;
    *(int *)((u)r[16] + 2224) = 0;
    *(short *)((u)r[16] + 2322) = 0;
    *(short *)((u)r[16] + 2320) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    r[2] = r[2] & r[3];
    *(int *)((u)r[17] + (int)R_GM_PlayerStatus) = r[2];
    r[2] = *(int *)((u)r[16] + 2020);
    r[3] = (u)0 + -531;
    r[2] = r[2] & r[3];
    *(int *)((u)r[16] + 2020) = r[2];
    L800d96c4:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
