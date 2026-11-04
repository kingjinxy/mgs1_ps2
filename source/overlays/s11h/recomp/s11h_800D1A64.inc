extern char R_GM_StreamStatus[] __asm__("GM_StreamStatus");
extern char R_GM_VoxStream[] __asm__("GM_VoxStream");
int G_s11h_800D1A64(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800D1A64");
int G_s11h_800D1A64(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 24) = r[31];
    r[3] = *(int *)((u)r[16] + 2380);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); r[17] = (u)r[5] + (u)0; if (c) goto L800d1abc;
    r[2] = *(int *)((u)r[16] + 2352);
    c = ((r[2] != 0));  if (c) goto L800d1abc;
     CALL(R_GM_StreamStatus);
    r[3] = (u)0 + -1;
    c = ((r[2] != r[3])); r[2] = (u)r[17] << 2; if (c) goto L800d1abc;
    r[2] = (u)r[16] + (u)r[2];
    r[4] = *(int *)((u)r[2] + 2044);
    r[5] = (u)0 + (u)0; CALL(R_GM_VoxStream);
    L800d1abc:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
