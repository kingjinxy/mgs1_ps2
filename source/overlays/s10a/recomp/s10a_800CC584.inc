int G_s10a_800CC584(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CC584");
int G_s10a_800CC584(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(unsigned char *)((u)r[4] + 2936);
    r[5] = *(int *)((u)r[4] + 76);
    r[3] = (u)r[2] << 1;
    r[3] = (u)r[3] + (u)r[2];
    r[5] = *(int *)((u)r[5] + 8);
    r[6] = (u)r[2] << 8;
    r[5] = *(int *)((u)r[5] + 0);
    r[2] = r[2] | r[6];
    r[5] = *(int *)((u)r[5] + 20);
    r[3] = (u)r[3] << 3;
    *(int *)((u)r[4] + 3056) = r[2];
    r[5] = (u)r[5] + (u)r[3];
    r[2] = *(unsigned short *)((u)r[5] + 0);
    *(short *)((u)r[4] + 3036) = r[2];
    r[2] = *(unsigned short *)((u)r[5] + 4);
    *(short *)((u)r[4] + 3038) = r[2];
    r[2] = *(int *)((u)r[4] + 3048);
    r[3] = *(unsigned short *)((u)r[5] + 2);
    *(int *)((u)r[4] + 3060) = r[2];
    *(short *)((u)r[4] + 3040) = r[3]; goto out;
out:
    return r[2];
}
