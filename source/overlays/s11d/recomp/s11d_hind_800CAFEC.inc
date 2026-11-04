int G_s11d_hind_800CAFEC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11d_hind_800CAFEC");
int G_s11d_hind_800CAFEC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(unsigned short *)((u)r[4] + 0);
    r[7] = r[2] & 65535;
    r[7] = (u)r[7] + -1;
    *(short *)((u)r[5] + 0) = r[2];
    r[4] = *(int *)((u)r[4] + 4);
    c = (((int)r[7] < 0)); r[8] = (u)r[6] + (u)0; if (c) goto L800cb04c;
    r[6] = (u)r[6] + 6;
    r[3] = (u)r[4] + 6;
    L800cb014:;
    r[2] = *(unsigned short *)((u)r[4] + 0);
    r[4] = (u)r[4] + 8;
    *(short *)((u)r[8] + 0) = r[2];
    r[2] = *(unsigned short *)((u)r[3] + -2);
    r[7] = (u)r[7] + -1;
    *(short *)((u)r[6] + -4) = r[2];
    r[2] = *(unsigned short *)((u)r[3] + -4);
    r[8] = (u)r[8] + 8;
    *(short *)((u)r[6] + -2) = r[2];
    r[2] = *(unsigned short *)((u)r[3] + 0);
    r[3] = (u)r[3] + 8;
    *(short *)((u)r[6] + 0) = r[2];
    c = (((int)r[7] >= 0)); r[6] = (u)r[6] + 8; if (c) goto L800cb014;
    L800cb04c:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
