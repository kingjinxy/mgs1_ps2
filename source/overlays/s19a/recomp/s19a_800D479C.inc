int G_s19a_800D479C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D479C");
int G_s19a_800D479C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(short *)((u)r[4] + 2272);
    c = ((r[2] != 0));  if (c) goto L800d47f4;
    r[2] = *(signed char *)((u)r[4] + 2970);
    c = ((r[2] != 0));  if (c) goto L800d47c8;
    r[2] = *(unsigned short *)((u)r[4] + 3116);
    *(short *)((u)r[4] + 2888) = r[2];
    L800d47c8:;
    r[2] = *(unsigned char *)((u)r[4] + 2970);
    r[2] = (u)r[2] + 1;
    *(char *)((u)r[4] + 2970) = r[2];
    r[2] = (u)r[2] << 24;
    r[2] = (int)r[2] >> 24;
    r[2] = (int)r[2] < 31;
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800d47f8;
     goto out;
    L800d47f4:;
    *(char *)((u)r[4] + 2970) = 0;
    L800d47f8:;
    r[3] = *(int *)((u)r[4] + 2856);
    r[2] = (u)0 + (u)0;
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[4] + 2856) = r[3]; goto out;
out:
    RECOMP_RETURN;
}
