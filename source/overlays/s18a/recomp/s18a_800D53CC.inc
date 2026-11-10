extern char R_GM_StreamStatus[] __asm__("GM_StreamStatus");
extern char R_GM_VoxStream[] __asm__("GM_VoxStream");
extern char R_s18a_800D537C[] __asm__("s18a_800D537C");
int G_s18a_800D53CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D53CC");
int G_s18a_800D53CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 3088);
    r[2] = (u)0 + -1;
    *(short *)((u)r[16] + 3082) = r[2];
    c = ((r[3] != 0)); *(int *)((u)r[16] + 3068) = 0; if (c) goto L800d53f8;
     CALL(R_s18a_800D537C);
    L800d53f8:;
    r[2] = *(int *)((u)r[16] + 3104);
    r[3] = *(int *)((u)r[16] + 3576);
    r[2] = (u)r[2] + 1;
    c = ((r[3] == 0)); *(int *)((u)r[16] + 3104) = r[2]; if (c) goto L800d5454;
     CALL(R_GM_StreamStatus);
    r[3] = (u)0 + -1;
    c = ((r[2] != r[3]));  if (c) goto L800d5454;
    r[2] = *(int *)((u)r[16] + 3640);
    r[4] = (u)r[2] + 1;
    r[2] = (u)r[4] << 2;
    r[3] = (u)r[16] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 3608);
    c = ((r[2] == 0));  if (c) goto L800d5454;
    *(int *)((u)r[16] + 3640) = r[4];
    r[4] = *(int *)((u)r[3] + 3608);
    r[5] = 0x40000000; CALL(R_GM_VoxStream);
    L800d5454:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
