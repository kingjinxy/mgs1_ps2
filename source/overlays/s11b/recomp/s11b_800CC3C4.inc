int G_s11b_800CC3C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800CC3C4");
int G_s11b_800CC3C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[12] = (u)r[4] + (u)0;
    r[6] = (u)r[6] + -1;
    c = (((int)r[6] < 0)); r[11] = (u)r[5] + (u)0; if (c) goto L800cc490;
    r[4] = (u)r[4] + 4;
    r[5] = (u)r[5] + 4;
    L800cc3dc:;
    r[7] = *(short *)((u)r[12] + 0);
    r[8] = *(short *)((u)r[4] + -2);
    r[9] = *(short *)((u)r[4] + 0);
    r[13] = LWL(((u)r[11] + 3), r[13]);
    r[13] = LWR(((u)r[11] + 0), r[13]);
    r[14] = LWL(((u)r[11] + 7), r[14]);
    r[14] = LWR(((u)r[11] + 4), r[14]);
    SWL(((u)r[5] + 7), r[13]);
    SWR(((u)r[5] + 4), r[13]);
    SWL(((u)r[5] + 11), r[14]);
    SWR(((u)r[5] + 8), r[14]);
    r[2] = *(unsigned short *)((u)r[11] + 0);
    r[10] = (u)r[7] + (u)0;
    r[2] = (u)r[2] + (u)r[7];
    *(short *)((u)r[11] + 0) = r[2];
    r[2] = *(unsigned short *)((u)r[5] + -2);
    r[3] = *(unsigned short *)((u)r[5] + 0);
    r[2] = (u)r[2] + (u)r[8];
    r[3] = (u)r[3] + (u)r[9];
    *(short *)((u)r[5] + -2) = r[2];
    c = (((int)r[7] >= 0)); *(short *)((u)r[5] + 0) = r[3]; if (c) goto L800cc438;
    r[10] = (u)r[7] + 3;
    L800cc438:;
    r[2] = (int)r[10] >> 2;
    r[2] = (u)r[7] - (u)r[2];
    *(short *)((u)r[12] + 0) = r[2];
    c = (((int)r[8] >= 0)); r[2] = (u)r[8] + (u)0; if (c) goto L800cc450;
    r[2] = (u)r[8] + 3;
    L800cc450:;
    r[2] = (int)r[2] >> 2;
    r[2] = (u)r[8] - (u)r[2];
    r[2] = (u)r[2] + -3;
    *(short *)((u)r[4] + -2) = r[2];
    c = (((int)r[9] >= 0)); r[2] = (u)r[9] + (u)0; if (c) goto L800cc46c;
    r[2] = (u)r[9] + 3;
    L800cc46c:;
    r[2] = (int)r[2] >> 2;
    r[2] = (u)r[9] - (u)r[2];
    *(short *)((u)r[4] + 0) = r[2];
    r[5] = (u)r[5] + 16;
    r[11] = (u)r[11] + 16;
    r[4] = (u)r[4] + 8;
    r[6] = (u)r[6] + -1;
    c = (((int)r[6] >= 0)); r[12] = (u)r[12] + 8; if (c) goto L800cc3dc;
    L800cc490:;
     goto out;
out:
    RECOMP_RETURN;
}
