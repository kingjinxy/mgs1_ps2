int G_s15c_dyncon_800D7A84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15c_dyncon_800D7A84");
int G_s15c_dyncon_800D7A84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[31] = *(int *)((u)r[29] + 188);
    r[30] = *(int *)((u)r[29] + 184);
    r[23] = *(int *)((u)r[29] + 180);
    r[22] = *(int *)((u)r[29] + 176);
    r[21] = *(int *)((u)r[29] + 172);
    r[20] = *(int *)((u)r[29] + 168);
    r[19] = *(int *)((u)r[29] + 164);
    r[18] = *(int *)((u)r[29] + 160);
    r[17] = *(int *)((u)r[29] + 156);
    r[16] = *(int *)((u)r[29] + 152);
    r[29] = (u)r[29] + 192; goto out;
out:
    RECOMP_RETURN;
}
