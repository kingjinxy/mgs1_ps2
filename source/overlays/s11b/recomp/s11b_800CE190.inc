int G_s11b_800CE190(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800CE190");
int G_s11b_800CE190(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[6] = (u)r[6] + -1;
    c = (((int)r[6] < 0)); r[5] = (u)r[5] + 6; if (c) goto L800ce1c8;
    r[4] = (u)r[4] + 6;
    L800ce1a0:;
    *(char *)((u)r[4] + -2) = r[7];
    *(char *)((u)r[4] + -1) = r[7];
    *(char *)((u)r[4] + 0) = r[7];
    r[4] = (u)r[4] + 40;
    *(char *)((u)r[5] + -2) = r[7];
    *(char *)((u)r[5] + -1) = r[7];
    *(char *)((u)r[5] + 0) = r[7];
    r[6] = (u)r[6] + -1;
    c = (((int)r[6] >= 0)); r[5] = (u)r[5] + 40; if (c) goto L800ce1a0;
    L800ce1c8:;
     goto out;
out:
    RECOMP_RETURN;
}
