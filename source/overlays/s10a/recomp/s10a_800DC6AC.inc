int G_s10a_800DC6AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800DC6AC");
int G_s10a_800DC6AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = (u)0 + 9;
    *(char *)((u)r[4] + 3) = r[2];
    r[2] = (u)0 + 46;
    *(char *)((u)r[4] + 7) = r[2];
    r[6] = *(unsigned char *)((u)r[5] + 8);
    r[3] = *(unsigned char *)((u)r[5] + 10);
    r[2] = *(unsigned char *)((u)r[5] + 9);
    r[7] = *(unsigned char *)((u)r[5] + 11);
    r[3] = (u)r[6] + (u)r[3];
    *(char *)((u)r[4] + 13) = r[2];
    *(char *)((u)r[4] + 21) = r[2];
    r[2] = (u)r[2] + (u)r[7];
    *(char *)((u)r[4] + 12) = r[6];
    *(char *)((u)r[4] + 20) = r[3];
    *(char *)((u)r[4] + 28) = r[6];
    *(char *)((u)r[4] + 29) = r[2];
    *(char *)((u)r[4] + 36) = r[3];
    *(char *)((u)r[4] + 37) = r[2];
    r[2] = *(unsigned short *)((u)r[5] + 4);
    *(short *)((u)r[4] + 22) = r[2];
    r[2] = *(unsigned short *)((u)r[5] + 6);
    *(short *)((u)r[4] + 14) = r[2]; goto out;
out:
    return r[2];
}
