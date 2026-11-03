extern char R_s08b_bunsin2_800CDE74[] __asm__("s08b_bunsin2_800CDE74");
extern char R_s08b_bunsin2_800D0330[] __asm__("s08b_bunsin2_800D0330");
extern char R_s08b_bunsin2_800D0410[] __asm__("s08b_bunsin2_800D0410");
extern char R_s08b_bunsin2_800D06A0[] __asm__("s08b_bunsin2_800D06A0");
int G_s08b_bunsin2_800D2420(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800D2420");
int G_s08b_bunsin2_800D2420(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[3] = *(int *)((u)r[16] + 6604);
    r[17] = (u)0 + 28;
    c = ((r[3] == r[17])); r[2] = (int)r[3] < 29; if (c) goto L800d24cc;
    c = ((r[2] == 0)); r[2] = (u)0 + 23; if (c) goto L800d245c;
    c = ((r[3] == r[2])); r[2] = (u)0 + 1; if (c) goto L800d2470;
     goto L800d24fc;
    L800d245c:;
    r[2] = (u)0 + 29;
    c = ((r[3] == r[2])); r[2] = (u)0 + 1; if (c) goto L800d24b0;
     goto L800d24fc;
    L800d2470:;
    *(int *)((u)r[16] + 6664) = r[2];
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D06A0);
    c = ((r[2] == 0));  if (c) goto L800d24fc;
    r[2] = *(int *)((u)r[16] + 6628);
    r[2] = (int)r[2] < 6;
    c = ((r[2] == 0)); r[2] = (u)0 + 7; if (c) goto L800d24a8;
    *(int *)((u)r[16] + 6596) = r[2];
    *(int *)((u)r[16] + 6600) = 0;
    *(int *)((u)r[16] + 6604) = 0; goto L800d24f8;
    L800d24a8:;
    *(int *)((u)r[16] + 6604) = r[17]; goto L800d24f8;
    L800d24b0:;
    *(int *)((u)r[16] + 6664) = r[2];
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D0330);
    c = ((r[2] == 0));  if (c) goto L800d24fc;
    *(int *)((u)r[16] + 6608) = 0; goto L800d24fc;
    L800d24cc:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D0410);
    c = ((r[2] == 0));  if (c) goto L800d24fc;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800CDE74);
    r[2] = (u)0 + 1;
    *(int *)((u)r[16] + 6600) = r[2];
    r[2] = (u)0 + 26;
    *(int *)((u)r[16] + 6604) = r[2];
    *(int *)((u)r[16] + 6612) = 0;
    L800d24f8:;
    *(int *)((u)r[16] + 6608) = 0;
    L800d24fc:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
