int G_s10a_800C66E0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C66E0");
int G_s10a_800C66E0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 76);
    r[2] = *(short *)((u)r[4] + 2694);
    r[3] = *(int *)((u)r[3] + 8);
    r[2] = (u)r[4] + (u)r[2];
    r[3] = *(int *)((u)r[3] + 0);
    r[2] = *(unsigned char *)((u)r[2] + 2700);
    r[3] = *(int *)((u)r[3] + 24);
    r[2] = (u)r[2] << 3;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(short *)((u)r[3] + 0);
    c = (((int)r[2] > 0)); *(int *)((u)r[4] + 2704) = r[2]; if (c) goto L800c671c;
    r[2] = (u)0 + -1; goto out;
    L800c671c:;
    r[7] = *(int *)((u)r[3] + 4);
    c = (((int)r[2] <= 0)); r[6] = (u)0 + (u)0; if (c) goto L800c6774;
    r[3] = (u)r[4] + (u)0;
    r[5] = (u)r[7] + 6;
    L800c6730:;
    r[2] = *(unsigned short *)((u)r[7] + 0);
    *(short *)((u)r[3] + 2708) = r[2];
    r[2] = *(unsigned short *)((u)r[5] + -2);
    r[7] = (u)r[7] + 8;
    *(short *)((u)r[3] + 2710) = r[2];
    r[2] = *(unsigned short *)((u)r[5] + -4);
    r[6] = (u)r[6] + 1;
    *(short *)((u)r[3] + 2712) = r[2];
    r[2] = *(unsigned short *)((u)r[5] + 0);
    r[5] = (u)r[5] + 8;
    *(short *)((u)r[3] + 2714) = r[2];
    r[2] = *(int *)((u)r[4] + 2704);
    r[2] = (int)r[6] < (int)r[2];
    c = ((r[2] != 0)); r[3] = (u)r[3] + 8; if (c) goto L800c6730;
    L800c6774:;
    r[2] = (u)0 + (u)0; goto out;
out:
    return r[2];
}
