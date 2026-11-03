extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s08b_bunsin2_800CF464[] __asm__("s08b_bunsin2_800CF464");
extern char R_s08b_bunsin2_800D3B00[] __asm__("s08b_bunsin2_800D3B00");
int G_s08b_bunsin2_800D3DBC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800D3DBC");
int G_s08b_bunsin2_800D3DBC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s08b_bunsin2_800CF464);
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800d3df8;
    *(int *)((u)r[16] + 6584) = r[2];
    r[2] = *(int *)((u)r[16] + 6592);
    r[3] = (u)0 + -3;
    *(int *)((u)r[16] + 6608) = 0;
    *(int *)((u)r[16] + 6612) = 0;
    r[2] = r[2] & r[3];
    *(int *)((u)r[16] + 6592) = r[2]; goto L800d3e94;
    L800d3df8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D3B00);
    r[2] = *(int *)((u)r[16] + 6592);
    r[2] = r[2] | 2;
    *(int *)((u)r[16] + 6592) = r[2];
    r[2] = 0;
    r[3] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 2));
    r[2] = (int)r[3] < 4;
    c = ((r[2] == 0)); r[4] = (u)0 + 3000; if (c) goto L800d3e34;
    c = (((int)r[3] <= 0));  if (c) goto L800d3e34;
    r[4] = (u)0 + 2000;
    L800d3e34:;
    r[2] = *(int *)((u)r[16] + 6700);
    r[2] = (int)r[2] < (int)r[4];
    c = ((r[2] == 0)); r[2] = (u)0 + 3; if (c) goto L800d3e94;
    r[3] = *(int *)((u)r[16] + 6604);
    c = ((r[3] == r[2])); r[2] = (u)0 + 1; if (c) goto L800d3e94;
    r[3] = *(int *)((u)r[16] + 6572);
    c = ((r[3] != r[2])); r[3] = (u)0 + 6; if (c) goto L800d3e94;
    r[2] = *(int *)((u)r[16] + 6700);
    r[2] = (int)r[2] < 1500;
    c = ((r[2] == 0)); *(int *)((u)r[16] + 6600) = r[3]; if (c) goto L800d3e84;
    r[2] = (u)0 + 14; goto L800d3e88;
    L800d3e84:;
    r[2] = (u)0 + 13;
    L800d3e88:;
    *(int *)((u)r[16] + 6604) = r[2];
    *(int *)((u)r[16] + 6608) = 0;
    *(int *)((u)r[16] + 6612) = 0;
    L800d3e94:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
