int G_s18a_800CD544(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CD544");
int G_s18a_800CD544(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 2488);
    r[2] = (u)r[3] + -3;
    r[2] = (u)r[2] < (u)2;
    c = ((r[2] != 0)); r[2] = (u)0 + 4; if (c) goto L800cd568;
    r[2] = (u)0 + 36;
    c = ((r[3] != r[2])); r[2] = (u)0 + 4; if (c) goto L800cd594;
    L800cd568:;
    c = ((r[3] != r[2])); r[2] = (u)0 + 1; if (c) goto L800cd578;
    *(int *)((u)r[4] + 2460) = 0; goto L800cd580;
    L800cd578:;
    *(int *)((u)r[4] + 2460) = r[2];
    r[2] = (u)0 + 1;
    L800cd580:;
    r[3] = (u)0 + 4;
    *(int *)((u)r[4] + 2400) = r[3];
    r[3] = (u)0 + 29;
    *(int *)((u)r[4] + 2404) = r[3]; goto out;
    L800cd594:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
