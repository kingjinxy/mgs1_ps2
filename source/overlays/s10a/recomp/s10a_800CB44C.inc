int G_s10a_800CB44C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CB44C");
int G_s10a_800CB44C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(unsigned short *)((u)r[4] + 2952);
    r[3] = (u)r[4] + 2952;
    *(short *)((u)r[4] + 92) = r[2];
    r[2] = *(unsigned short *)((u)r[3] + 4);
    r[4] = (u)r[4] + 92;
    *(short *)((u)r[4] + 2) = r[2];
    r[2] = *(short *)((u)r[3] + 2);
    *(short *)((u)r[4] + 6) = 0;
    r[2] = (u)r[2] << 1;
    *(short *)((u)r[4] + 4) = r[2]; goto out;
out:
    return r[2];
}
