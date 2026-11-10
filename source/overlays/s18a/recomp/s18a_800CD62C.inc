extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_GM_VoxStream[] __asm__("GM_VoxStream");
extern char R_s18a_800C70E8[] __asm__("s18a_800C70E8");
extern char R_s18a_800C7124[] __asm__("s18a_800C7124");
extern char R_s18a_800D0E40[] __asm__("s18a_800D0E40");
int G_s18a_800CD62C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CD62C");
int G_s18a_800CD62C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = (u)0 + 6;
    r[3] = 0;
    r[4] = 0x10000000;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[16] + 2384) = r[2];
    r[2] = *(int *)((u)r[3] + (int)R_GM_GameStatus);
    r[5] = *(int *)((u)r[16] + 2476);
    r[6] = *(int *)((u)r[16] + 2408);
    r[2] = r[2] | r[4];
    *(int *)((u)r[3] + (int)R_GM_GameStatus) = r[2];
    c = ((r[6] != 0)); *(int *)((u)r[16] + 2388) = r[5]; if (c) goto L800cd68c;
    r[4] = (u)0 + 1;
    r[5] = 0 | 60000; CALL(R_s18a_800D0E40);
    r[4] = *(int *)((u)r[16] + 2604);
    r[5] = 0x40000000; CALL(R_GM_VoxStream);
    r[4] = (u)0 + 5400;
    r[5] = (u)0 + -1; CALL(R_s18a_800C7124);
    L800cd68c:;
    r[4] = (u)0 + 5400; CALL(R_s18a_800C70E8);
    r[3] = *(int *)((u)r[16] + 2408);
    r[2] = (int)r[3] < 31;
    c = ((r[2] != 0)); r[2] = (u)r[3] + 1; if (c) goto L800cd6bc;
    r[2] = (u)0 + 2;
    *(int *)((u)r[16] + 2404) = r[2];
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0; goto L800cd6c0;
    L800cd6bc:;
    *(int *)((u)r[16] + 2408) = r[2];
    L800cd6c0:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
