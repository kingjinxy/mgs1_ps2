int G_s17a_800C96AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800C96AC");
int G_s17a_800C96AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[7] = (u)r[5] - (u)r[6];
    r[6] = (u)r[5] + (u)r[6];
    r[10] = (u)r[5] << 1;
    r[9] = (u)r[7] << 1;
    r[9] = (u)r[4] + (u)r[9];
    r[8] = (u)r[6] << 1;
    r[8] = (u)r[4] + (u)r[8];
    r[10] = (u)r[4] + (u)r[10];
    r[5] = (u)r[5] << 2;
    r[7] = (u)r[7] << 2;
    r[7] = (u)r[4] + (u)r[7];
    r[6] = (u)r[6] << 2;
    r[2] = *(short *)((u)r[8] + 830);
    r[3] = *(short *)((u)r[9] + 830);
    r[6] = (u)r[4] + (u)r[6];
    r[2] = (u)r[2] - (u)r[3];
    r[3] = (u)r[2] << 1;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(unsigned short *)((u)r[9] + 830);
    r[3] = (int)r[3] >> 2;
    r[2] = (u)r[2] + (u)r[3];
    *(short *)((u)r[10] + 830) = r[2];
    r[2] = *(int *)((u)r[6] + 864);
    r[3] = *(int *)((u)r[7] + 864);
    r[4] = (u)r[4] + (u)r[5];
    r[2] = (u)r[2] - (u)r[3];
    r[2] = (int)r[2] >> 1;
    r[3] = (u)r[3] + (u)r[2];
    *(int *)((u)r[4] + 864) = r[3];
    r[3] = *(short *)((u)r[8] + 796);
    r[2] = *(short *)((u)r[9] + 796);
    r[3] = (u)r[3] - (u)r[2];
    r[2] = *(unsigned short *)((u)r[9] + 796);
    r[3] = (int)r[3] >> 1;
    r[2] = (u)r[2] + (u)r[3];
    *(short *)((u)r[10] + 796) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
