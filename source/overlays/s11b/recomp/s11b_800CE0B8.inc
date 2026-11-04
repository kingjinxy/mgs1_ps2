int G_s11b_800CE0B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800CE0B8");
int G_s11b_800CE0B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[6] = (u)r[6] + -1;
    c = (((int)r[6] < 0)); r[11] = (u)0 + 9; if (c) goto L800ce188;
    r[10] = (u)0 + 46;
    r[9] = (u)r[5] + 14;
    r[8] = (u)r[4] + 14;
    L800ce0d0:;
    *(char *)((u)r[8] + -11) = r[11];
    *(char *)((u)r[8] + -7) = r[10];
    *(char *)((u)r[9] + -11) = r[11];
    *(char *)((u)r[9] + -7) = r[10];
    r[4] = *(unsigned char *)((u)r[7] + 8);
    r[3] = *(unsigned char *)((u)r[7] + 10);
    r[2] = *(unsigned char *)((u)r[7] + 9);
    r[5] = *(unsigned char *)((u)r[7] + 11);
    r[3] = (u)r[4] + (u)r[3];
    *(char *)((u)r[8] + -1) = r[2];
    *(char *)((u)r[8] + 7) = r[2];
    r[2] = (u)r[2] + (u)r[5];
    *(char *)((u)r[8] + -2) = r[4];
    *(char *)((u)r[8] + 6) = r[3];
    *(char *)((u)r[8] + 14) = r[4];
    *(char *)((u)r[8] + 15) = r[2];
    *(char *)((u)r[8] + 22) = r[3];
    *(char *)((u)r[8] + 23) = r[2];
    r[2] = *(unsigned short *)((u)r[7] + 4);
    *(short *)((u)r[8] + 8) = r[2];
    r[2] = *(unsigned short *)((u)r[7] + 6);
    *(short *)((u)r[8] + 0) = r[2];
    r[4] = *(unsigned char *)((u)r[7] + 8);
    r[3] = *(unsigned char *)((u)r[7] + 10);
    r[2] = *(unsigned char *)((u)r[7] + 9);
    r[5] = *(unsigned char *)((u)r[7] + 11);
    r[3] = (u)r[4] + (u)r[3];
    *(char *)((u)r[9] + -1) = r[2];
    *(char *)((u)r[9] + 7) = r[2];
    r[2] = (u)r[2] + (u)r[5];
    *(char *)((u)r[9] + -2) = r[4];
    *(char *)((u)r[9] + 6) = r[3];
    *(char *)((u)r[9] + 14) = r[4];
    *(char *)((u)r[9] + 15) = r[2];
    *(char *)((u)r[9] + 22) = r[3];
    *(char *)((u)r[9] + 23) = r[2];
    r[2] = *(unsigned short *)((u)r[7] + 4);
    r[6] = (u)r[6] + -1;
    *(short *)((u)r[9] + 8) = r[2];
    r[2] = *(unsigned short *)((u)r[7] + 6);
    r[8] = (u)r[8] + 40;
    *(short *)((u)r[9] + 0) = r[2];
    c = (((int)r[6] >= 0)); r[9] = (u)r[9] + 40; if (c) goto L800ce0d0;
    L800ce188:;
     goto out;
out:
    RECOMP_RETURN;
}
