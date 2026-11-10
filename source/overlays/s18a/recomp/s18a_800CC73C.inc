int G_s18a_800CC73C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CC73C");
int G_s18a_800CC73C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 2236);
    r[2] = *(unsigned short *)((u)r[3] + 6);
    r[2] = r[2] & 6;
    c = ((r[2] == 0)); *(int *)((u)r[4] + 2488) = 0; if (c) goto L800cc764;
    r[2] = *(short *)((u)r[3] + 62);
    *(int *)((u)r[4] + 2488) = r[2];
    L800cc764:;
     goto out;
out:
    RECOMP_RETURN;
}
