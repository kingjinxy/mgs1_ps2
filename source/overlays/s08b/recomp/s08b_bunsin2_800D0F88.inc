extern char R_linkvarbuf[] __asm__("linkvarbuf");
int G_s08b_bunsin2_800D0F88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800D0F88");
int G_s08b_bunsin2_800D0F88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 6608);
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800d0fa8;
    r[2] = *(int *)((u)r[4] + 6696);
    *(int *)((u)r[4] + 6580) = r[2];
    r[2] = 0;
    L800d0fa8:;
    r[3] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 2));
    r[2] = (u)0 + 1;
    c = ((r[3] != r[2])); r[5] = (u)0 + 5; if (c) goto L800d0fc4;
    r[2] = *(int *)((u)r[4] + 6592);
    r[2] = r[2] | 2; goto L800d0fe0;
    L800d0fc4:;
    c = (((int)r[3] <= 0)); r[2] = (int)r[3] < 4; if (c) goto L800d0fe8;
    c = ((r[2] == 0)); r[5] = (u)0 + 1; if (c) goto L800d0fe8;
    r[2] = *(int *)((u)r[4] + 6592);
    r[2] = r[2] | 2;
    L800d0fe0:;
    *(int *)((u)r[4] + 6592) = r[2]; goto L800d0fec;
    L800d0fe8:;
    r[5] = (u)0 + 10;
    L800d0fec:;
    r[3] = *(int *)((u)r[4] + 6608);
    r[2] = (int)r[5] < (int)r[3];
    c = ((r[2] != 0)); r[2] = (u)r[3] + 1; if (c) goto L800d100c;
    *(int *)((u)r[4] + 6608) = r[2];
    r[2] = (u)0 + (u)0; goto out;
    L800d100c:;
    r[2] = (u)0 + 1; goto out;
out:
    RECOMP_RETURN;
}
