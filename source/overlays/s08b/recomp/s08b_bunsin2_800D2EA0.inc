extern char R_s08b_bunsin2_800CDE74[] __asm__("s08b_bunsin2_800CDE74");
extern char R_s08b_bunsin2_800D0078[] __asm__("s08b_bunsin2_800D0078");
extern char R_s08b_bunsin2_800D1638[] __asm__("s08b_bunsin2_800D1638");
extern char R_s08b_bunsin2_800D1738[] __asm__("s08b_bunsin2_800D1738");
int G_s08b_bunsin2_800D2EA0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s08b_bunsin2_800D2EA0");
int G_s08b_bunsin2_800D2EA0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[3] = *(int *)((u)r[16] + 6604);
    r[17] = (u)0 + 36;
    c = ((r[3] == r[17])); r[2] = (int)r[3] < 37; if (c) goto L800d2f08;
    c = ((r[2] == 0)); r[2] = (u)0 + 5; if (c) goto L800d2edc;
    c = ((r[3] == r[2]));  if (c) goto L800d2ef0;
     goto L800d2f6c;
    L800d2edc:;
    r[2] = (u)0 + 38;
    c = ((r[3] == r[2]));  if (c) goto L800d2f30;
     goto L800d2f6c;
    L800d2ef0:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D0078);
    c = ((r[2] == 0));  if (c) goto L800d2f6c;
    *(int *)((u)r[16] + 6604) = r[17]; goto L800d2f64;
    L800d2f08:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D1638);
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800d2f6c;
    *(int *)((u)r[16] + 6596) = r[2];
    r[2] = (u)0 + 2;
    *(int *)((u)r[16] + 6600) = r[2];
    r[2] = (u)0 + 8;
    *(int *)((u)r[16] + 6604) = r[2]; goto L800d2f60;
    L800d2f30:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D1738);
    c = ((r[2] == 0));  if (c) goto L800d2f6c;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800CDE74);
    r[3] = (u)0 + 1;
    r[2] = (u)0 + 26;
    *(int *)((u)r[16] + 6596) = r[3];
    *(int *)((u)r[16] + 6600) = r[3];
    *(int *)((u)r[16] + 6604) = r[2];
    *(int *)((u)r[16] + 6668) = r[3];
    L800d2f60:;
    *(int *)((u)r[16] + 6620) = 0;
    L800d2f64:;
    *(int *)((u)r[16] + 6612) = 0;
    *(int *)((u)r[16] + 6608) = 0;
    L800d2f6c:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
