int G_s15a_800D3560(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D3560");
int G_s15a_800D3560(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(short *)((u)r[4] + 0);
    r[2] = *(short *)((u)r[5] + 0);
    r[2] = (int)r[3] < (int)r[2];
    c = ((r[2] != 0));  if (c) goto L800d35b8;
    r[2] = *(short *)((u)r[6] + 0);
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] != 0));  if (c) goto L800d35b8;
    r[4] = *(short *)((u)r[4] + 4);
    r[2] = *(short *)((u)r[5] + 4);
    r[2] = (int)r[4] < (int)r[2];
    c = ((r[2] != 0));  if (c) goto L800d35b8;
    r[2] = *(short *)((u)r[6] + 4);
    r[2] = (int)r[2] < (int)r[4];
    c = ((r[2] == 0));  if (c) goto L800d35c0;
    L800d35b8:;
    r[2] = (u)0 + -1; goto out;
    L800d35c0:;
    r[2] = (u)0 + 1; goto out;
out:
    RECOMP_RETURN;
}
