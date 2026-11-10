extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_GM_StreamPlayStart[] __asm__("GM_StreamPlayStart");
extern char R_GM_StreamStatus[] __asm__("GM_StreamStatus");
extern char R_GM_VoxStream[] __asm__("GM_VoxStream");
int G_s18a_800CDA40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CDA40");
int G_s18a_800CDA40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = (u)0 + 3;
    r[3] = 0;
    r[4] = 0x10000000;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[16] + 2384) = r[2];
    r[2] = *(int *)((u)r[3] + (int)R_GM_GameStatus);
    r[5] = *(int *)((u)r[16] + 2476);
    r[6] = *(int *)((u)r[16] + 2408);
    r[2] = r[2] | r[4];
    *(int *)((u)r[3] + (int)R_GM_GameStatus) = r[2];
    c = ((r[6] != 0)); *(int *)((u)r[16] + 2388) = r[5]; if (c) goto L800cda8c;
    r[4] = *(int *)((u)r[16] + 2540);
    r[5] = 0x40000000; CALL(R_GM_VoxStream);
    L800cda8c:;
    r[2] = *(int *)((u)r[16] + 2408);
    r[2] = (int)r[2] < 61;
    c = ((r[2] != 0));  if (c) goto L800cdad4;
     CALL(R_GM_StreamStatus);
    r[17] = (u)r[2] + (u)0;
    r[2] = (u)0 + 1;
    c = ((r[17] != r[2]));  if (c) goto L800cdad4;
     CALL(R_GM_StreamPlayStart);
    r[2] = (u)0 + 2;
    *(int *)((u)r[16] + 2400) = r[17];
    *(int *)((u)r[16] + 2404) = r[2];
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0;
    L800cdad4:;
    r[2] = *(int *)((u)r[16] + 2408);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + 2408) = r[2];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
