extern char R_s08b_bunsin2_800D0078[] __asm__("s08b_bunsin2_800D0078");
extern char R_s08b_bunsin2_800D17F8[] __asm__("s08b_bunsin2_800D17F8");
extern char R_s08b_bunsin2_800D195C[] __asm__("s08b_bunsin2_800D195C");
extern char R_s08b_bunsin2_800D1A18[] __asm__("s08b_bunsin2_800D1A18");
int G_s08b_bunsin2_800D2F80(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s08b_bunsin2_800D2F80");
int G_s08b_bunsin2_800D2F80(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[3] = *(int *)((u)r[16] + 6604);
    r[17] = (u)0 + 36;
    c = ((r[3] == r[17])); r[2] = (int)r[3] < 37; if (c) goto L800d2ffc;
    c = ((r[2] == 0)); r[2] = (u)0 + 5; if (c) goto L800d2fbc;
    c = ((r[3] == r[2]));  if (c) goto L800d2fd8;
     goto L800d3050;
    L800d2fbc:;
    r[2] = (u)0 + 37;
    c = ((r[3] == r[2])); r[2] = (u)0 + 38; if (c) goto L800d3014;
    c = ((r[3] == r[2]));  if (c) goto L800d302c;
     goto L800d3050;
    L800d2fd8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D0078);
    c = ((r[2] == 0));  if (c) goto L800d3050;
    *(int *)((u)r[16] + 6604) = r[17];
    *(int *)((u)r[16] + 6612) = 0;
    *(int *)((u)r[16] + 6608) = 0;
    *(int *)((u)r[16] + 6620) = 0; goto L800d3050;
    L800d2ffc:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D17F8);
    c = ((r[2] == 0)); r[2] = (u)0 + 37; if (c) goto L800d3050;
    *(int *)((u)r[16] + 6604) = r[2]; goto L800d3048;
    L800d3014:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D195C);
    c = ((r[2] == 0)); r[2] = (u)0 + 38; if (c) goto L800d3050;
    *(int *)((u)r[16] + 6604) = r[2]; goto L800d3048;
    L800d302c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D1A18);
    c = ((r[2] == 0)); r[2] = (u)0 + 4; if (c) goto L800d3050;
    *(int *)((u)r[16] + 6600) = r[2];
    r[2] = (u)0 + 11;
    *(int *)((u)r[16] + 6604) = r[2];
    L800d3048:;
    *(int *)((u)r[16] + 6612) = 0;
    *(int *)((u)r[16] + 6608) = 0;
    L800d3050:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
