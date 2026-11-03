int G_s10a_800D96D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D96D4");
int G_s10a_800D96D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2604);
    c = (((int)r[2] > 0));  if (c) goto L800d9718;
    r[3] = *(int *)((u)r[4] + 1628);
    r[2] = *(unsigned short *)((u)r[3] + 6);
    r[2] = r[2] & 65531;
    *(short *)((u)r[3] + 6) = r[2];
    r[3] = *(int *)((u)r[4] + 1632);
    r[2] = *(unsigned short *)((u)r[3] + 6);
    r[2] = r[2] & 65531;
    *(short *)((u)r[3] + 6) = r[2];
    *(int *)((u)r[4] + 1864) = 0;
    L800d9718:;
     goto out;
out:
    return r[2];
}
