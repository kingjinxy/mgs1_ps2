int G_s10a_800D6878(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D6878");
int G_s10a_800D6878(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[3] = (u)0 + 8;
    r[8] = (u)0 + 9;
    r[7] = (u)0 + 46;
    r[6] = (u)0 + 20;
    r[4] = (u)r[4] + 14;
    L800d688c:;
    *(char *)((u)r[4] + -11) = r[8];
    *(char *)((u)r[4] + -7) = r[7];
    *(char *)((u)r[4] + -10) = r[6];
    *(char *)((u)r[4] + -9) = r[6];
    *(char *)((u)r[4] + -8) = r[6];
    r[2] = *(unsigned short *)((u)r[5] + 4);
    *(short *)((u)r[4] + 8) = r[2];
    r[2] = *(unsigned short *)((u)r[5] + 6);
    r[3] = (u)r[3] + -1;
    *(short *)((u)r[4] + 0) = r[2];
    c = (((int)r[3] > 0)); r[4] = (u)r[4] + 40; if (c) goto L800d688c;
     goto out;
out:
    RECOMP_RETURN;
}
