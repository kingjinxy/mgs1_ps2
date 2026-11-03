int G_s10a_800D6824(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D6824");
int G_s10a_800D6824(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[8] = (u)0 + 8;
    r[4] = (u)r[4] + 37;
    r[6] = r[6] & 63;
    r[2] = *(unsigned char *)((u)r[5] + 9);
    r[7] = *(unsigned char *)((u)r[5] + 8);
    r[3] = (u)r[2] + (u)r[6];
    L800d683c:;
    r[2] = (u)r[7] + 7;
    *(char *)((u)r[4] + -25) = r[7];
    *(char *)((u)r[4] + -9) = r[7];
    r[7] = (u)r[7] + 8;
    *(char *)((u)r[4] + -24) = r[3];
    *(char *)((u)r[4] + -17) = r[2];
    *(char *)((u)r[4] + -16) = r[3];
    *(char *)((u)r[4] + -8) = r[3];
    *(char *)((u)r[4] + -1) = r[2];
    *(char *)((u)r[4] + 0) = r[3];
    r[8] = (u)r[8] + -1;
    c = (((int)r[8] > 0)); r[4] = (u)r[4] + 40; if (c) goto L800d683c;
     goto out;
out:
    RECOMP_RETURN;
}
