int G_s07b_800CBDA0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CBDA0");
int G_s07b_800CBDA0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2128);
    r[2] = r[2] & 4;
    c = ((r[2] != 0)); r[3] = (u)0 + -32; if (c) goto L800cbdc4;
    r[2] = *(unsigned short *)((u)r[4] + 102);
    *(short *)((u)r[4] + 2170) = r[3];
    r[2] = (u)r[2] + -32;
    *(short *)((u)r[4] + 102) = r[2];
    L800cbdc4:;
     goto out;
out:
    return r[2];
}
