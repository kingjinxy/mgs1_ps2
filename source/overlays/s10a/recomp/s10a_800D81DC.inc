int G_s10a_800D81DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D81DC");
int G_s10a_800D81DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = (u)0 + 2;
    r[5] = (u)0 + 255;
    r[3] = (u)0 + 63;
    r[4] = (u)r[4] + 6;
    L800d81ec:;
    *(char *)((u)r[4] + -2) = r[5];
    *(char *)((u)r[4] + -1) = r[3];
    *(char *)((u)r[4] + 0) = r[3];
    r[2] = (u)r[2] + -1;
    c = (((int)r[2] > 0)); r[4] = (u)r[4] + 16; if (c) goto L800d81ec;
     goto out;
out:
    return r[2];
}
