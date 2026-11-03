int G_s10a_800DE2F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800DE2F8");
int G_s10a_800DE2F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[29] + 16);
    *(int *)((u)r[4] + 128) = 0;
    r[3] = LWL(((u)r[5] + 3), r[3]);
    r[3] = LWR(((u)r[5] + 0), r[3]);
    r[8] = LWL(((u)r[5] + 7), r[8]);
    r[8] = LWR(((u)r[5] + 4), r[8]);
    SWL(((u)r[4] + 135), r[3]);
    SWR(((u)r[4] + 132), r[3]);
    SWL(((u)r[4] + 139), r[8]);
    SWR(((u)r[4] + 136), r[8]);
    *(int *)((u)r[4] + 140) = r[6];
    *(int *)((u)r[4] + 144) = r[7];
    *(int *)((u)r[4] + 148) = r[2];
    r[2] = (u)0 + (u)0; goto out;
out:
    return r[2];
}
