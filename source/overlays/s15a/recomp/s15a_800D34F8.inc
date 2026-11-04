int G_s15a_800D34F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D34F8");
int G_s15a_800D34F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[6] = *(short *)((u)r[4] + 0);
    r[2] = *(short *)((u)r[5] + 0);
    r[3] = *(unsigned short *)((u)r[5] + 0);
    r[2] = (int)r[2] < (int)r[6];
    c = ((r[2] == 0));  if (c) goto L800d3518;
    *(short *)((u)r[4] + 0) = r[3];
    *(short *)((u)r[5] + 0) = r[6];
    L800d3518:;
    r[6] = *(short *)((u)r[4] + 2);
    r[2] = *(short *)((u)r[5] + 2);
    r[3] = *(unsigned short *)((u)r[5] + 2);
    r[2] = (int)r[2] < (int)r[6];
    c = ((r[2] == 0));  if (c) goto L800d3538;
    *(short *)((u)r[4] + 2) = r[3];
    *(short *)((u)r[5] + 2) = r[6];
    L800d3538:;
    r[6] = *(short *)((u)r[4] + 4);
    r[2] = *(short *)((u)r[5] + 4);
    r[3] = *(unsigned short *)((u)r[5] + 4);
    r[2] = (int)r[2] < (int)r[6];
    c = ((r[2] == 0));  if (c) goto L800d3558;
    *(short *)((u)r[4] + 4) = r[3];
    *(short *)((u)r[5] + 4) = r[6];
    L800d3558:;
     goto out;
out:
    RECOMP_RETURN;
}
