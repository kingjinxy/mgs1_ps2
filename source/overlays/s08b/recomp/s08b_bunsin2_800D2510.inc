extern char R_s08b_bunsin2_800D0330[] __asm__("s08b_bunsin2_800D0330");
extern char R_s08b_bunsin2_800D0410[] __asm__("s08b_bunsin2_800D0410");
extern char R_s08b_bunsin2_800D06A0[] __asm__("s08b_bunsin2_800D06A0");
int G_s08b_bunsin2_800D2510(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800D2510");
int G_s08b_bunsin2_800D2510(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[3] = *(int *)((u)r[16] + 6604);
    r[17] = (u)0 + 28;
    c = ((r[3] == r[17])); r[2] = (int)r[3] < 29; if (c) goto L800d25c8;
    c = ((r[2] == 0)); r[2] = (u)0 + 23; if (c) goto L800d254c;
    c = ((r[3] == r[2])); r[2] = (u)0 + 1; if (c) goto L800d2560;
     goto L800d25ec;
    L800d254c:;
    r[2] = (u)0 + 29;
    c = ((r[3] == r[2])); r[2] = (u)0 + 1; if (c) goto L800d25a0;
     goto L800d25ec;
    L800d2560:;
    *(int *)((u)r[16] + 6664) = r[2];
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D06A0);
    c = ((r[2] == 0));  if (c) goto L800d25ec;
    r[2] = *(int *)((u)r[16] + 6628);
    r[2] = (int)r[2] < 6;
    c = ((r[2] == 0)); r[2] = (u)0 + 7; if (c) goto L800d2598;
    *(int *)((u)r[16] + 6596) = r[2];
    *(int *)((u)r[16] + 6600) = 0;
    *(int *)((u)r[16] + 6604) = 0; goto L800d25e8;
    L800d2598:;
    *(int *)((u)r[16] + 6604) = r[17]; goto L800d25e8;
    L800d25a0:;
    *(int *)((u)r[16] + 6664) = r[2];
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D0330);
    c = ((r[2] != 0));  if (c) goto L800d25e8;
    r[2] = *(int *)((u)r[16] + 6592);
    r[2] = r[2] | 2;
    *(int *)((u)r[16] + 6592) = r[2]; goto L800d25ec;
    L800d25c8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D0410);
    c = ((r[2] == 0)); r[2] = (u)0 + 4; if (c) goto L800d25ec;
    *(int *)((u)r[16] + 6600) = r[2];
    r[2] = (u)0 + 10;
    *(int *)((u)r[16] + 6604) = r[2];
    *(int *)((u)r[16] + 6612) = 0;
    L800d25e8:;
    *(int *)((u)r[16] + 6608) = 0;
    L800d25ec:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
