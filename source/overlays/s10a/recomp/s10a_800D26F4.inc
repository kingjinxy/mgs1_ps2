int G_s10a_800D26F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D26F4");
int G_s10a_800D26F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[3] = (u)r[4] + 32;
    r[2] = *(unsigned short *)((u)r[3] + 58);
    r[2] = r[2] | 8192;
    *(short *)((u)r[3] + 58) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 868);
    r[3] = (u)r[4] + 92;
    *(short *)((u)r[4] + 92) = 0;
    *(short *)((u)r[3] + 2) = r[2];
    r[2] = *(int *)((u)r[4] + 872);
    *(short *)((u)r[3] + 6) = 0;
    r[2] = (u)r[2] << 1;
    *(short *)((u)r[3] + 4) = r[2]; goto out;
out:
    return r[2];
}
