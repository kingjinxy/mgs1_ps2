extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_GM_SnakeCamera[] __asm__("GM_SnakeCamera");
extern char R_s18a_800D98B4[] __asm__("s18a_800D98B4");
extern char R_s18a_800D9FBC[] __asm__("s18a_800D9FBC");
extern char R_s18a_800DA0C8[] __asm__("s18a_800DA0C8");
extern char R_s18a_800D5BF0[] __asm__("s18a_800D5BF0");
extern char R_s18a_800D5D8C[] __asm__("s18a_800D5D8C");
int G_s18a_800DC08C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DC08C");
int G_s18a_800DC08C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2212);
    r[2] = *(unsigned short *)((u)r[2] + 0);
    r[2] = r[2] & 16;
    c = ((r[2] != 0));  if (c) goto L800dc0c0;
     CALL(R_s18a_800D5BF0);
    L800dc0c0:;
    r[3] = *(int *)((u)r[16] + 2220);
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_800D9FBC;
    c = ((r[3] != r[2])); r[3] = 0; if (c) goto L800dc124;
    r[2] = *(int *)((u)r[16] + 2212);
    r[2] = *(unsigned short *)((u)r[2] + 2);
    r[2] = r[2] & 65519;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800dc124;
    r[2] = (u)r[2] + (int)R_s18a_800DA0C8;
    r[4] = 0;
    *(int *)((u)r[16] + 2220) = r[2];
    r[2] = *(int *)((u)r[4] + (int)R_GM_PlayerStatus);
    r[3] = (u)0 + -65;
    *(int *)((u)r[16] + 2224) = 0;
    *(short *)((u)r[16] + 2322) = 0;
    *(short *)((u)r[16] + 2320) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    r[2] = r[2] & r[3];
    *(int *)((u)r[4] + (int)R_GM_PlayerStatus) = r[2];
    r[3] = 0;
    L800dc124:;
    r[3] = (u)r[3] + (int)R_GM_SnakeCamera;
    r[2] = *(unsigned short *)((u)r[3] + 2);
    r[2] = (u)r[2] + 320;
    *(short *)((u)r[3] + 2) = r[2];
    r[2] = 0;
    r[3] = *(int *)((u)r[16] + 2220);
    r[2] = (u)r[2] + (int)R_s18a_800D98B4;
    c = ((r[3] == r[2]));  if (c) goto L800dc154;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D5D8C);
    L800dc154:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
