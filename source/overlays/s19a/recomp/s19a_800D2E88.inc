int G_s19a_800D2E88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D2E88");
int G_s19a_800D2E88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 4);
    r[3] = *(short *)((u)r[2] + 0);
    r[6] = *(int *)((u)r[2] + 16);
    c = (((int)r[3] <= 0)); r[7] = (u)0 + (u)0; if (c) goto L800d2f68;
    r[10] = 0 | 56405;
    r[9] = (u)0 + 30771;
    r[8] = (u)r[3] + (u)0;
    r[4] = (u)r[6] + 12;
    L800d2eb0:;
    r[2] = *(unsigned short *)((u)r[4] + 18);
    c = ((r[2] == r[10]));  if (c) goto L800d2ec8;
    c = ((r[2] != r[9]));  if (c) goto L800d2f54;
    L800d2ec8:;
    r[3] = *(short *)((u)r[5] + 0);
    r[2] = *(short *)((u)r[6] + 0);
    r[2] = (int)r[3] < (int)r[2];
    c = ((r[2] != 0));  if (c) goto L800d2f54;
    r[2] = *(short *)((u)r[4] + -4);
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] != 0));  if (c) goto L800d2f54;
    r[3] = *(short *)((u)r[5] + 4);
    r[2] = *(short *)((u)r[4] + -10);
    r[2] = (int)r[3] < (int)r[2];
    c = ((r[2] != 0));  if (c) goto L800d2f54;
    r[2] = *(short *)((u)r[4] + -2);
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] != 0));  if (c) goto L800d2f54;
    r[3] = *(short *)((u)r[5] + 2);
    r[2] = *(short *)((u)r[4] + -8);
    r[2] = (int)r[3] < (int)r[2];
    c = ((r[2] != 0));  if (c) goto L800d2f54;
    r[2] = *(short *)((u)r[4] + 0);
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] != 0)); r[4] = (u)r[4] + 32; if (c) goto L800d2f58;
    r[2] = (u)0 + 1; goto out;
    L800d2f54:;
    r[4] = (u)r[4] + 32;
    L800d2f58:;
    r[7] = (u)r[7] + 1;
    r[2] = (int)r[7] < (int)r[8];
    c = ((r[2] != 0)); r[6] = (u)r[6] + 32; if (c) goto L800d2eb0;
    L800d2f68:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
