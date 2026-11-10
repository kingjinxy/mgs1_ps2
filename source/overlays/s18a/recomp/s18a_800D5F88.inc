int G_s18a_800D5F88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D5F88");
int G_s18a_800D5F88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)0 + 1;
    c = ((r[5] != r[2])); r[6] = (u)r[4] + 412; if (c) goto L800d5f98;
    r[6] = (u)r[4] + 388;
    L800d5f98:;
    c = ((r[5] != r[2]));  if (c) goto L800d5fac;
    r[2] = *(short *)((u)r[4] + 170);
     goto L800d5fb0;
    L800d5fac:;
    r[2] = *(short *)((u)r[4] + 172);
    L800d5fb0:;
    r[3] = *(short *)((u)r[6] + 0);
    r[4] = *(short *)((u)r[6] + 2);
    r[3] = (u)r[3] + (u)r[4];
    r[4] = (u)0 + 1;
    c = ((r[3] == r[4]));  if (c) goto L800d5fd0;
    r[2] = (u)0 + -1;
    L800d5fd0:;
     goto out;
out:
    RECOMP_RETURN;
}
