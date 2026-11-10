int G_s18a_800CFA50(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CFA50");
int G_s18a_800CFA50(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2368);
    c = ((r[2] == 0)); r[3] = (u)0 + 20; if (c) goto L800cfa7c;
    r[2] = (u)0 + 3;
    *(int *)((u)r[4] + 2400) = r[2];
    r[2] = (u)0 + 14;
    *(int *)((u)r[4] + 2404) = r[2];
    *(int *)((u)r[4] + 2428) = 0;
    *(int *)((u)r[4] + 2408) = 0; goto out;
    L800cfa7c:;
    r[2] = *(int *)((u)r[4] + 2408);
    *(int *)((u)r[4] + 2384) = r[3];
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[4] + 2408) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
