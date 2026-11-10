int G_s18a_800CCD5C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CCD5C");
int G_s18a_800CCD5C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(short *)((u)r[4] + 0);
    r[2] = (int)r[3] < -500;
    c = ((r[2] == 0)); r[2] = (u)0 + 5000; if (c) goto L800ccd78;
    L800ccd70:;
    r[2] = (u)0 + 1; goto out;
    L800ccd78:;
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] != 0));  if (c) goto L800ccd70;
    r[4] = *(short *)((u)r[4] + 4);
    r[2] = (int)r[4] < -750;
    c = ((r[2] != 0)); r[2] = (u)0 + 1250; if (c) goto L800ccda0;
    r[2] = (int)r[2] < (int)r[4]; goto out;
    L800ccda0:;
    r[2] = (u)0 + 1; goto out;
out:
    RECOMP_RETURN;
}
