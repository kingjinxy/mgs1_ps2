int G_s17a_800E1D50(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800E1D50");
int G_s17a_800E1D50(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[8] = (u)r[5] + (u)0;
    c = ((r[6] == 0)); r[7] = (u)r[6] + -1; if (c) goto L800e1ddc;
    r[11] = (u)0 + 9;
    r[10] = (u)0 + 46;
    r[9] = (u)0 + -1;
    r[6] = (u)r[4] + 6;
    L800e1d6c:;
    *(char *)((u)r[6] + -3) = r[11];
    *(char *)((u)r[6] + 1) = r[10];
    r[4] = *(unsigned char *)((u)r[8] + 8);
    r[3] = *(unsigned char *)((u)r[8] + 10);
    r[2] = *(unsigned char *)((u)r[8] + 9);
    r[5] = *(unsigned char *)((u)r[8] + 11);
    r[3] = (u)r[4] + (u)r[3];
    *(char *)((u)r[6] + 7) = r[2];
    *(char *)((u)r[6] + 15) = r[2];
    r[2] = (u)r[2] + (u)r[5];
    *(char *)((u)r[6] + 6) = r[4];
    *(char *)((u)r[6] + 14) = r[3];
    *(char *)((u)r[6] + 22) = r[4];
    *(char *)((u)r[6] + 23) = r[2];
    *(char *)((u)r[6] + 30) = r[3];
    *(char *)((u)r[6] + 31) = r[2];
    r[2] = *(unsigned short *)((u)r[8] + 4);
    r[7] = (u)r[7] + -1;
    *(short *)((u)r[6] + 16) = r[2];
    r[3] = *(unsigned short *)((u)r[8] + 6);
    r[2] = r[2] | 96;
    *(char *)((u)r[6] + -2) = 0;
    *(char *)((u)r[6] + -1) = 0;
    *(char *)((u)r[6] + 0) = 0;
    *(short *)((u)r[6] + 16) = r[2];
    *(short *)((u)r[6] + 8) = r[3];
    c = ((r[7] != r[9])); r[6] = (u)r[6] + 40; if (c) goto L800e1d6c;
    L800e1ddc:;
     goto out;
out:
    RECOMP_RETURN;
}
