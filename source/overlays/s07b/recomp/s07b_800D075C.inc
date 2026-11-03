int G_s07b_800D075C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800D075C");
int G_s07b_800D075C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[19] = *(int *)((u)r[29] + 116);
    r[18] = *(int *)((u)r[29] + 112);
    r[17] = *(int *)((u)r[29] + 108);
    r[16] = *(int *)((u)r[29] + 104);
    r[29] = (u)r[29] + 128; goto out;
out:
    RECOMP_RETURN;
}
