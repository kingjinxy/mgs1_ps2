int G_s17a_800E1C48(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800E1C48");
int G_s17a_800E1C48(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[7] = (u)0 + 9;
    r[2] = *(int *)((u)r[4] + 64);
    r[6] = *(int *)((u)r[4] + 68);
    r[3] = (u)0 + 46;
    *(char *)((u)r[2] + 3) = r[7];
    *(char *)((u)r[2] + 7) = r[3];
    *(char *)((u)r[6] + 3) = r[7];
    *(char *)((u)r[6] + 7) = r[3];
    *(char *)((u)r[2] + 4) = 0;
    *(char *)((u)r[2] + 5) = 0;
    *(char *)((u)r[2] + 6) = 0;
    *(char *)((u)r[6] + 4) = 0;
    *(char *)((u)r[6] + 5) = 0;
    *(char *)((u)r[6] + 6) = 0;
    r[8] = *(unsigned char *)((u)r[5] + 8);
    r[7] = *(unsigned char *)((u)r[5] + 10);
    r[3] = *(unsigned char *)((u)r[5] + 9);
    r[9] = *(unsigned char *)((u)r[5] + 11);
    r[7] = (u)r[8] + (u)r[7];
    *(char *)((u)r[2] + 13) = r[3];
    *(char *)((u)r[2] + 21) = r[3];
    r[3] = (u)r[3] + (u)r[9];
    *(char *)((u)r[2] + 12) = r[8];
    *(char *)((u)r[2] + 20) = r[7];
    *(char *)((u)r[2] + 28) = r[8];
    *(char *)((u)r[2] + 29) = r[3];
    *(char *)((u)r[2] + 36) = r[7];
    *(char *)((u)r[2] + 37) = r[3];
    r[3] = *(unsigned short *)((u)r[5] + 4);
    *(short *)((u)r[2] + 22) = r[3];
    r[3] = *(unsigned short *)((u)r[5] + 6);
    *(short *)((u)r[2] + 14) = r[3];
    r[7] = *(unsigned char *)((u)r[5] + 8);
    r[3] = *(unsigned char *)((u)r[5] + 10);
    r[2] = *(unsigned char *)((u)r[5] + 9);
    r[8] = *(unsigned char *)((u)r[5] + 11);
    r[3] = (u)r[7] + (u)r[3];
    *(char *)((u)r[6] + 12) = r[7];
    *(char *)((u)r[6] + 13) = r[2];
    *(char *)((u)r[6] + 21) = r[2];
    r[2] = (u)r[2] + (u)r[8];
    *(char *)((u)r[6] + 20) = r[3];
    *(char *)((u)r[6] + 28) = r[7];
    *(char *)((u)r[6] + 29) = r[2];
    *(char *)((u)r[6] + 36) = r[3];
    *(char *)((u)r[6] + 37) = r[2];
    r[2] = *(unsigned short *)((u)r[5] + 4);
    *(short *)((u)r[6] + 22) = r[2];
    r[2] = *(unsigned short *)((u)r[5] + 6);
    *(short *)((u)r[6] + 14) = r[2];
    r[2] = (u)0 + 1000;
    *(short *)((u)r[4] + 46) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
