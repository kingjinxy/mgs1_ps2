extern char R_s08b_bunsin2_800D3B00[] __asm__("s08b_bunsin2_800D3B00");
int G_s08b_bunsin2_800D3EA4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800D3EA4");
int G_s08b_bunsin2_800D3EA4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s08b_bunsin2_800D3B00);
    r[2] = *(int *)((u)r[16] + 6700);
    r[2] = (int)r[2] < 2000;
    c = ((r[2] == 0)); r[2] = (u)0 + 3; if (c) goto L800d3ef8;
    r[3] = *(int *)((u)r[16] + 6604);
    c = ((r[3] == r[2])); r[2] = (u)0 + 4; if (c) goto L800d3ef8;
    *(int *)((u)r[16] + 6600) = r[2];
    r[2] = (u)0 + 10;
    *(int *)((u)r[16] + 6604) = r[2];
    r[2] = (u)0 + 1;
    *(int *)((u)r[16] + 6608) = 0;
    *(int *)((u)r[16] + 6612) = 0; goto L800d3f48;
    L800d3ef8:;
    r[3] = *(int *)((u)r[16] + 6708);
    r[2] = (u)0 + 2;
    c = ((r[3] != r[2])); r[2] = (u)r[3] + -3; if (c) goto L800d3f28;
    r[2] = (u)0 + 4;
    *(int *)((u)r[16] + 6600) = r[2];
    r[2] = (u)0 + 10;
    *(int *)((u)r[16] + 6604) = r[2];
    r[2] = (u)0 + 1;
    *(int *)((u)r[16] + 6608) = 0;
    *(int *)((u)r[16] + 6612) = 0; goto L800d3f48;
    L800d3f28:;
    r[2] = (u)r[2] < (u)2;
    c = ((r[2] == 0)); r[2] = (u)0 + 7; if (c) goto L800d3f4c;
    *(int *)((u)r[16] + 6600) = r[2];
    r[2] = (u)0 + 23;
    *(int *)((u)r[16] + 6604) = r[2];
    r[2] = (u)0 + 1;
    *(int *)((u)r[16] + 6608) = 0;
    L800d3f48:;
    *(int *)((u)r[16] + 6584) = r[2];
    L800d3f4c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
