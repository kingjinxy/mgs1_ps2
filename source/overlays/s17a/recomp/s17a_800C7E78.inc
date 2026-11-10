int G_s17a_800C7E78(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800C7E78");
int G_s17a_800C7E78(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[5] + -1;
    c = (((int)r[5] < 0)); r[2] = (u)r[6] >> 31; if (c) goto L800c7ea8;
    r[2] = (u)r[6] + (u)r[2];
    r[2] = (int)r[2] >> 1;
    r[4] = (u)r[4] + 6;
    L800c7e90:;
    *(char *)((u)r[4] + -2) = r[2];
    *(char *)((u)r[4] + -1) = r[6];
    *(char *)((u)r[4] + 0) = r[6];
    r[5] = (u)r[5] + -1;
    c = (((int)r[5] >= 0)); r[4] = (u)r[4] + 40; if (c) goto L800c7e90;
    L800c7ea8:;
     goto out;
out:
    RECOMP_RETURN;
}
