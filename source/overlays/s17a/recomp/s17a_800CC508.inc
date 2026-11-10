int G_s17a_800CC508(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800CC508");
int G_s17a_800CC508(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[6] = (u)0 + -88;
    r[3] = (u)0 + 160;
    r[8] = (u)0 + 32;
    r[2] = *(int *)((u)r[4] + 32);
    r[5] = (u)0 + 24;
    r[2] = (u)r[2] + 112;
    *(short *)((u)r[2] + 8) = 0;
    *(short *)((u)r[2] + 10) = r[6];
    *(short *)((u)r[2] + 16) = r[3];
    *(short *)((u)r[2] + 18) = r[3];
    *(char *)((u)r[2] + 12) = r[8];
    *(char *)((u)r[2] + 13) = r[5];
    r[2] = *(int *)((u)r[4] + 32);
    r[7] = (u)0 + -160;
    r[2] = (u)r[2] + 152;
    *(short *)((u)r[2] + 8) = r[7];
    *(short *)((u)r[2] + 10) = r[6];
    *(short *)((u)r[2] + 16) = r[3];
    *(short *)((u)r[2] + 18) = r[3];
    *(char *)((u)r[2] + 12) = 0;
    *(char *)((u)r[2] + 13) = r[5];
    r[2] = *(int *)((u)r[4] + 32);
    r[2] = (u)r[2] + 132;
    *(short *)((u)r[2] + 8) = 0;
    *(short *)((u)r[2] + 10) = r[6];
    *(short *)((u)r[2] + 16) = r[3];
    *(short *)((u)r[2] + 18) = r[3];
    *(char *)((u)r[2] + 12) = r[8];
    *(char *)((u)r[2] + 13) = r[5];
    r[2] = *(int *)((u)r[4] + 32);
    r[2] = (u)r[2] + 172;
    *(short *)((u)r[2] + 8) = r[7];
    *(short *)((u)r[2] + 10) = r[6];
    *(short *)((u)r[2] + 16) = r[3];
    *(short *)((u)r[2] + 18) = r[3];
    *(char *)((u)r[2] + 12) = 0;
    *(char *)((u)r[2] + 13) = r[5]; goto out;
out:
    RECOMP_RETURN;
}
