int G_s17a_800CDD88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800CDD88");
int G_s17a_800CDD88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[5] + -1;
    c = (((int)r[5] < 0)); r[2] = (u)r[4] + (u)0; if (c) goto L800cddc8;
    r[7] = 0x4000000;
    r[6] = 0xe1000000;
    r[6] = r[6] | 544;
    r[3] = 0x42800000;
    r[3] = r[3] | 33023;
    r[4] = (u)r[4] + 8;
    L800cddac:;
    *(int *)((u)r[2] + 0) = r[7];
    *(int *)((u)r[4] + -4) = r[6];
    *(int *)((u)r[4] + 0) = r[3];
    r[4] = (u)r[4] + 20;
    r[5] = (u)r[5] + -1;
    c = (((int)r[5] >= 0)); r[2] = (u)r[2] + 20; if (c) goto L800cddac;
    L800cddc8:;
     goto out;
out:
    RECOMP_RETURN;
}
