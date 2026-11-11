int G_s19a_800D49E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D49E8");
int G_s19a_800D49E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[7] = (u)r[6] + (u)0;
    r[6] = *(short *)((u)r[4] + 0);
    r[3] = *(short *)((u)r[5] + 0);
    r[4] = *(short *)((u)r[4] + 4);
    r[2] = *(short *)((u)r[5] + 4);
    r[6] = (u)r[6] - (u)r[3];
    r[4] = (u)r[4] - (u)r[2];
    r[3] = (u)0 - (u)r[7];
    r[2] = (int)r[3] < (int)r[6];
    c = ((r[2] != 0)); r[2] = (int)r[6] < (int)r[7]; if (c) goto L800d4a2c;
    c = ((r[2] != 0)); r[2] = (int)r[3] < (int)r[4]; if (c) goto L800d4a2c;
    c = ((r[2] != 0)); r[2] = (int)r[4] < (int)r[7]; if (c) goto L800d4a2c;
    c = ((r[2] == 0));  if (c) goto L800d4a34;
    L800d4a2c:;
    r[2] = (u)0 + (u)0; goto out;
    L800d4a34:;
    r[2] = (u)0 + 1; goto out;
out:
    RECOMP_RETURN;
}
