int G_s15a_800D0558(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D0558");
int G_s15a_800D0558(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[5] << 3;
    r[2] = *(int *)((u)r[29] + 16);
    r[3] = *(int *)((u)r[29] + 20);
    r[8] = *(int *)((u)r[29] + 24);
    r[9] = *(int *)((u)r[29] + 28);
    r[4] = (u)r[4] + (u)r[5];
    *(short *)((u)r[4] + 16224) = r[6];
    *(short *)((u)r[4] + 16226) = r[7];
    *(short *)((u)r[4] + 16228) = r[2];
    *(short *)((u)r[4] + 16192) = r[3];
    *(short *)((u)r[4] + 16194) = r[8];
    *(short *)((u)r[4] + 16196) = r[9]; goto out;
out:
    RECOMP_RETURN;
}
