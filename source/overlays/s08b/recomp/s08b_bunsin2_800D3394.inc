extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s08b_bunsin2_800CDDD8[] __asm__("s08b_bunsin2_800CDDD8");
extern char R_s08b_bunsin2_800CEEB8[] __asm__("s08b_bunsin2_800CEEB8");
extern char R_s08b_bunsin2_800CEFF4[] __asm__("s08b_bunsin2_800CEFF4");
extern char R_s08b_bunsin2_800D0720[] __asm__("s08b_bunsin2_800D0720");
int G_s08b_bunsin2_800D3394(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800D3394");
int G_s08b_bunsin2_800D3394(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 6612);
    r[2] = (int)r[2] < 151;
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800d33e0;
    r[3] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 28));
    r[2] = (u)0 + -1;
    c = ((r[3] != r[2])); r[2] = (u)0 + 2; if (c) goto L800d33e0;
    *(int *)((u)r[16] + 6600) = r[2];
    r[2] = (u)0 + 8;
    *(int *)((u)r[16] + 6604) = r[2];
    *(int *)((u)r[16] + 6576) = r[3];
    *(int *)((u)r[16] + 6612) = 0; goto L800d3454;
    L800d33e0:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800CEFF4);
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D0720);
    r[3] = (u)r[2] + (u)0;
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 2; if (c) goto L800d3430;
    c = ((r[2] == 0)); r[2] = (u)0 + 5; if (c) goto L800d3418;
    c = ((r[3] == 0)); r[2] = (u)0 + 2; if (c) goto L800d3428;
     goto L800d3440;
    L800d3418:;
    c = ((r[3] == r[2]));  if (c) goto L800d343c;
     goto L800d3440;
    L800d3428:;
    *(int *)((u)r[16] + 6604) = r[2]; goto L800d3440;
    L800d3430:;
    r[2] = (u)0 + 3;
    *(int *)((u)r[16] + 6604) = r[2]; goto L800d3440;
    L800d343c:;
    *(int *)((u)r[16] + 6604) = r[3];
    L800d3440:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800CDDD8);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 500; CALL(R_s08b_bunsin2_800CEEB8);
    L800d3454:;
    *(int *)((u)r[16] + 6608) = 0;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
