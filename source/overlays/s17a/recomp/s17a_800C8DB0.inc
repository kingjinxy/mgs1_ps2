int G_s17a_800C8DB0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800C8DB0");
int G_s17a_800C8DB0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[6] = (u)r[6] + -1;
    c = (((int)r[6] < 0)); r[15] = (u)r[4] + (u)0; if (c) goto L800c8e68;
    r[14] = (u)0 + 9;
    r[13] = (u)0 + 46;
    r[12] = (u)0 + 1;
    r[10] = (u)0 + 150;
    r[11] = (u)0 + 250;
    r[9] = (u)0 + 80;
    r[8] = (u)r[5] + 22;
    L800c8dd8:;
    *(char *)((u)r[8] + -19) = r[14];
    *(char *)((u)r[8] + -15) = r[13];
    r[2] = *(int *)((u)r[15] + 956);
    c = ((r[2] != r[12]));  if (c) goto L800c8e00;
    *(char *)((u)r[8] + -18) = r[10];
    *(char *)((u)r[8] + -17) = r[10];
    *(char *)((u)r[8] + -16) = r[11]; goto L800c8e0c;
    L800c8e00:;
    *(char *)((u)r[8] + -18) = r[9];
    *(char *)((u)r[8] + -17) = r[9];
    *(char *)((u)r[8] + -16) = r[9];
    L800c8e0c:;
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
    c = (((int)r[6] >= 0)); r[8] = (u)r[8] + 40; if (c) goto L800c8dd8;
    L800c8e68:;
     goto out;
out:
    RECOMP_RETURN;
}
