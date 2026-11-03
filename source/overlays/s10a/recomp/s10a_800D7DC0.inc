int G_s10a_800D7DC0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D7DC0");
int G_s10a_800D7DC0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[6] = (u)0 + 125;
    r[2] = *(int *)((u)r[4] + 1628);
    r[3] = (u)0 + 350;
    *(int *)((u)r[4] + 2652) = 0;
    *(short *)((u)r[4] + 1710) = r[6];
    *(short *)((u)r[2] + 16) = r[3];
    r[2] = *(int *)((u)r[4] + 1628);
    *(short *)((u)r[2] + 18) = r[6];
    r[2] = *(int *)((u)r[4] + 1628);
    *(short *)((u)r[2] + 20) = r[3];
    r[5] = *(int *)((u)r[4] + 1632);
    r[2] = (u)0 + -125;
    *(int *)((u)r[4] + 2656) = 0;
    *(short *)((u)r[4] + 1718) = r[2];
    *(short *)((u)r[5] + 16) = r[3];
    r[2] = *(int *)((u)r[4] + 1632);
    *(short *)((u)r[2] + 18) = r[6];
    r[2] = *(int *)((u)r[4] + 1632);
    *(short *)((u)r[2] + 20) = r[3]; goto out;
out:
    RECOMP_RETURN;
}
