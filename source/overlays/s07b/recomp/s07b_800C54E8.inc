int G_s07b_800C54E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800C54E8");
int G_s07b_800C54E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2124);
    r[5] = *(int *)((u)r[4] + 2012);
    r[3] = (u)0 + -3;
    *(short *)((u)r[4] + 2242) = 0;
    r[2] = r[2] & r[3];
    *(int *)((u)r[4] + 2124) = r[2];
    r[2] = *(unsigned short *)((u)r[5] + 0);
    r[2] = r[2] | 158;
    *(short *)((u)r[5] + 0) = r[2]; goto out;
out:
    return r[2];
}
