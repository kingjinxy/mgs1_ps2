extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_s18a_800C5200[] __asm__("s18a_800C5200");
int G_s18a_800CDBB8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CDBB8");
int G_s18a_800CDBB8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[5] = 0;
    r[2] = *(int *)((u)r[5] + (int)R_GM_GameStatus);
    r[3] = 0x10000000;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = *(int *)((u)r[16] + 2408);
    r[3] = r[2] | r[3];
    r[2] = (int)r[4] < 16;
    c = ((r[2] != 0)); *(int *)((u)r[5] + (int)R_GM_GameStatus) = r[3]; if (c) goto L800cdc28;
    r[2] = 0xefff0000;
    r[2] = r[2] | 65535;
    r[2] = r[3] & r[2];
    r[4] = (u)0 + 6;
    *(int *)((u)r[5] + (int)R_GM_GameStatus) = r[2]; CALL(R_s18a_800C5200);
    r[3] = (u)0 + 3;
    r[2] = (u)0 + 1;
    *(int *)((u)r[16] + 2400) = r[2];
    r[2] = (u)0 + 5400;
    *(int *)((u)r[16] + 2396) = r[3];
    *(int *)((u)r[16] + 2404) = r[3];
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0;
    *(int *)((u)r[16] + 2424) = r[2]; goto L800cdc30;
    L800cdc28:;
    r[2] = (u)r[4] + 1;
    *(int *)((u)r[16] + 2408) = r[2];
    L800cdc30:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
