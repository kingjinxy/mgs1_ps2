int G_s15a_800D0070(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D0070");
int G_s15a_800D0070(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)0 + 1;
    c = ((r[5] == r[2])); r[2] = (int)r[5] < 2; if (c) goto L800d00c4;
    c = ((r[2] == 0));  if (c) goto L800d0094;
    c = ((r[5] == 0));  if (c) goto L800d00a8;
     goto out;
    L800d0094:;
    r[2] = (u)0 + 3;
    c = ((r[5] == r[2]));  if (c) goto L800d00d8;
     goto out;
    L800d00a8:;
    r[2] = *(short *)((u)r[4] + 0);
    r[3] = *(short *)((u)r[4] + 4);
    r[2] = (u)0 - (u)r[2];
    r[3] = (u)0 - (u)r[3];
    *(short *)((u)r[4] + 0) = r[2];
    *(short *)((u)r[4] + 4) = r[3]; goto out;
    L800d00c4:;
    r[2] = *(short *)((u)r[4] + 0);
    r[2] = (u)0 - (u)r[2];
    *(short *)((u)r[4] + 0) = r[2]; goto out;
    L800d00d8:;
    r[2] = *(short *)((u)r[4] + 4);
    r[2] = (u)0 - (u)r[2];
    *(short *)((u)r[4] + 4) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
