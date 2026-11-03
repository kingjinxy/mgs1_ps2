int G_s07b_800C84FC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800C84FC");
int G_s07b_800C84FC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    return r[2];
}
