int G_s11b_800CAAEC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800CAAEC");
int G_s11b_800CAAEC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[6] = (u)r[6] + -1;
    c = (((int)r[6] < 0)); r[9] = (u)r[4] + 24748; if (c) goto L800cab7c;
    r[11] = (u)0 + 9;
    r[10] = (u)0 + 46;
    r[8] = (u)r[5] + 22;
    L800cab04:;
    *(int *)((u)r[9] + 0) = 0;
    r[9] = (u)r[9] + 4;
    *(char *)((u)r[8] + -19) = r[11];
    *(char *)((u)r[8] + -15) = r[10];
    *(char *)((u)r[8] + -18) = 0;
    *(char *)((u)r[8] + -17) = 0;
    *(char *)((u)r[8] + -16) = 0;
    r[4] = *(unsigned char *)((u)r[7] + 8);
    r[3] = *(unsigned char *)((u)r[7] + 10);
    r[2] = *(unsigned char *)((u)r[7] + 9);
    r[5] = *(unsigned char *)((u)r[7] + 11);
    r[3] = (u)r[4] + (u)r[3];
    *(char *)((u)r[8] + -9) = r[2];
    *(char *)((u)r[8] + -1) = r[2];
    r[2] = (u)r[2] + (u)r[5];
    *(char *)((u)r[8] + -10) = r[4];
    *(char *)((u)r[8] + -2) = r[3];
    *(char *)((u)r[8] + 6) = r[4];
    *(char *)((u)r[8] + 7) = r[2];
    *(char *)((u)r[8] + 14) = r[3];
    *(char *)((u)r[8] + 15) = r[2];
    r[2] = *(unsigned short *)((u)r[7] + 4);
    r[6] = (u)r[6] + -1;
    *(short *)((u)r[8] + 0) = r[2];
    r[3] = *(unsigned short *)((u)r[7] + 6);
    r[2] = r[2] | 32;
    *(short *)((u)r[8] + 0) = r[2];
    *(short *)((u)r[8] + -8) = r[3];
    c = (((int)r[6] >= 0)); r[8] = (u)r[8] + 40; if (c) goto L800cab04;
    L800cab7c:;
     goto out;
out:
    RECOMP_RETURN;
}
