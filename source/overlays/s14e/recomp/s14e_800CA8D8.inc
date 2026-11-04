int G_s14e_800CA8D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CA8D8");
int G_s14e_800CA8D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = (u)0 + (u)0;
    L800ca8dc:;
    r[2] = *(int *)((u)r[4] + 2816);
    c = ((r[2] != r[5])); r[3] = (u)r[3] + 1; if (c) goto L800ca8f8;
    *(int *)((u)r[4] + 2816) = 0;
    r[2] = (u)0 + 1; goto out;
    L800ca8f8:;
    r[2] = (int)r[3] < 8;
    c = ((r[2] != 0)); r[4] = (u)r[4] + 4; if (c) goto L800ca8dc;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
