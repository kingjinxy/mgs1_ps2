extern char R_s15a_dat_800D9288[] __asm__("s15a_dat_800D9288");
int G_s15a_800CBB68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CBB68");
int G_s15a_800CBB68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 1692);
    r[3] = *(int *)((u)r[4] + 1856);
    r[5] = (u)0 + 1;
    *(int *)((u)r[4] + 2088) = 0;
    r[2] = (u)r[2] + 1;
    c = ((r[3] == r[5])); *(int *)((u)r[4] + 1692) = r[2]; if (c) goto L800cbc00;
    r[2] = (int)r[3] < 2;
    c = ((r[2] == 0)); r[6] = (u)0 + 2; if (c) goto L800cbba0;
    c = ((r[3] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800cbbb8;
     goto L800cbc44;
    L800cbba0:;
    c = ((r[3] == r[6])); r[2] = (u)0 + 3; if (c) goto L800cbc18;
    c = ((r[3] == r[2])); r[2] = (u)0 + (u)0; if (c) goto L800cbc30;
     goto L800cbc44;
    L800cbbb8:;
    r[2] = *(short *)((u)r[4] + 1848);
    c = ((r[2] != r[5])); r[2] = 0; if (c) goto L800cbc40;
    r[3] = *(int *)((u)r[2] + (int)R_s15a_dat_800D9288);
    c = ((r[3] == 0)); r[2] = (u)r[2] + (int)R_s15a_dat_800D9288; if (c) goto L800cbc40;
    r[2] = *(int *)((u)r[2] + 8);
    c = ((r[2] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800cbc44;
    r[2] = (u)0 + 3;
    r[3] = (u)r[2] + (u)0;
    *(int *)((u)r[4] + 1904) = r[3];
    *(int *)((u)r[4] + 1700) = 0;
    *(int *)((u)r[4] + 1692) = 0; goto out;
    L800cbc00:;
    r[3] = *(short *)((u)r[4] + 1848);
    r[2] = (u)0 + 2;
    c = ((r[3] != r[2])); r[2] = (u)0 + (u)0; if (c) goto L800cbc44;
    r[2] = (u)0 + 1; goto out;
    L800cbc18:;
    r[2] = *(short *)((u)r[4] + 1850);
    c = ((r[2] != r[5])); r[2] = (u)0 + (u)0; if (c) goto L800cbc44;
    r[2] = (u)0 + 2; goto out;
    L800cbc30:;
    r[3] = *(short *)((u)r[4] + 1850);
    c = ((r[3] == r[6])); r[2] = (u)0 + 1; if (c) goto L800cbc44;
    L800cbc40:;
    r[2] = (u)0 + (u)0;
    L800cbc44:;
     goto out;
out:
    RECOMP_RETURN;
}
