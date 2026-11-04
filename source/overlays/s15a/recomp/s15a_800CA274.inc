extern char R_MENU_DrawBar2[] __asm__("MENU_DrawBar2");
int G_s15a_800CA274(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CA274");
int G_s15a_800CA274(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[31];
    r[2] = *(int *)((u)r[4] + 2304);
    r[3] = *(int *)((u)r[4] + 1704);
    r[2] = (u)r[2] << 10;
    if (r[3]) { lo_ = (int)r[2] / (int)r[3]; hi_ = (int)r[2] % (int)r[3]; }
    c = ((r[3] != 0));  if (c) goto L800ca298;
    L800ca298:;
    r[1] = (u)0 + -1;
    c = ((r[3] != r[1])); r[1] = 0; if (c) goto L800ca2b0;
    c = ((r[2] != r[1]));  if (c) goto L800ca2b0;
    L800ca2b0:;
    r[3] = lo_;
    c = (((int)r[3] >= 0)); r[2] = (int)r[3] >> 3; if (c) goto L800ca2c8;
    r[3] = (u)r[3] + 7;
    r[2] = (int)r[3] >> 3;
    L800ca2c8:;
    r[6] = (u)r[2] << 3;
    c = (((int)r[6] >= 0));  if (c) goto L800ca2e4;
    r[2] = *(int *)((u)r[4] + 1636);
    r[6] = (u)0 + (u)0;
    *(short *)((u)r[2] + 38) = 0;
    *(int *)((u)r[4] + 2304) = 0;
    L800ca2e4:;
    r[5] = *(int *)((u)r[4] + 2308);
    r[2] = (int)r[5] < (int)r[6];
    c = ((r[2] == 0)); r[2] = (int)r[6] < (int)r[5]; if (c) goto L800ca300;
    r[5] = (u)r[6] + (u)0;
    r[2] = (int)r[6] < (int)r[5];
    L800ca300:;
    c = ((r[2] == 0)); r[2] = (int)r[5] < 8; if (c) goto L800ca31c;
    r[2] = *(int *)((u)r[4] + 2308);
    r[2] = (u)r[2] + -8;
    *(int *)((u)r[4] + 2308) = r[2];
    r[2] = (int)r[5] < 8;
    L800ca31c:;
    c = ((r[2] != 0)); r[2] = (int)r[6] < 8; if (c) goto L800ca32c;
    c = ((r[2] == 0)); r[2] = (u)r[4] + 2292; if (c) goto L800ca338;
    L800ca32c:;
    r[5] = (u)0 + 8;
    r[6] = (u)r[5] + (u)0;
    r[2] = (u)r[4] + 2292;
    L800ca338:;
    r[4] = (u)0 + 28;
    r[7] = (u)0 + 1024;
    *(int *)((u)r[29] + 16) = r[2]; CALL(R_MENU_DrawBar2);
    r[31] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
