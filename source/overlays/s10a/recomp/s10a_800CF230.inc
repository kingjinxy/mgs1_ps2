int G_s10a_800CF230(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800CF230");
int G_s10a_800CF230(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[9] = (u)r[5] + -1;
    c = (((int)r[9] < 0)); r[12] = (u)0 + 9; if (c) goto L800cf2c0;
    r[11] = (u)0 + 46;
    r[2] = (u)r[7] >> 31;
    r[2] = (u)r[7] + (u)r[2];
    r[10] = (int)r[2] >> 1;
    r[8] = (u)r[4] + 6;
    L800cf250:;
    *(char *)((u)r[8] + -3) = r[12];
    *(char *)((u)r[8] + 1) = r[11];
    r[4] = *(unsigned char *)((u)r[6] + 8);
    r[3] = *(unsigned char *)((u)r[6] + 10);
    r[2] = *(unsigned char *)((u)r[6] + 9);
    r[5] = *(unsigned char *)((u)r[6] + 11);
    r[3] = (u)r[4] + (u)r[3];
    *(char *)((u)r[8] + 7) = r[2];
    *(char *)((u)r[8] + 15) = r[2];
    r[2] = (u)r[2] + (u)r[5];
    *(char *)((u)r[8] + 6) = r[4];
    *(char *)((u)r[8] + 14) = r[3];
    *(char *)((u)r[8] + 22) = r[4];
    *(char *)((u)r[8] + 23) = r[2];
    *(char *)((u)r[8] + 30) = r[3];
    *(char *)((u)r[8] + 31) = r[2];
    r[2] = *(unsigned short *)((u)r[6] + 4);
    r[9] = (u)r[9] + -1;
    *(short *)((u)r[8] + 16) = r[2];
    r[3] = *(unsigned short *)((u)r[6] + 6);
    r[2] = r[2] | 32;
    *(char *)((u)r[8] + -2) = r[10];
    *(char *)((u)r[8] + -1) = r[7];
    *(char *)((u)r[8] + 0) = r[7];
    *(short *)((u)r[8] + 16) = r[2];
    *(short *)((u)r[8] + 8) = r[3];
    c = (((int)r[9] >= 0)); r[8] = (u)r[8] + 40; if (c) goto L800cf250;
    L800cf2c0:;
     goto out;
out:
    RECOMP_RETURN;
}
