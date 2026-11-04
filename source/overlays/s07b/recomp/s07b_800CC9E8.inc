int G_s07b_800CC9E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800CC9E8");
int G_s07b_800CC9E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2124);
    r[3] = *(int *)((u)r[4] + 2016);
    *(char *)((u)r[4] + 2658) = r[5];
    r[2] = r[2] | 2;
    *(int *)((u)r[4] + 2124) = r[2];
    r[2] = *(unsigned short *)((u)r[3] + 0);
    r[2] = r[2] & 65387;
    *(short *)((u)r[3] + 0) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
