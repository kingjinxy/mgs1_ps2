int G_s18a_800CE93C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CE93C");
int G_s18a_800CE93C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2480);
    r[3] = *(int *)((u)r[4] + 2476);
    r[2] = (int)r[2] < 1000;
    c = ((r[2] == 0)); *(int *)((u)r[4] + 2388) = r[3]; if (c) goto L800ce968;
    r[2] = (u)0 + 5;
    *(int *)((u)r[4] + 2400) = r[2];
    r[2] = (u)0 + 27;
    *(int *)((u)r[4] + 2404) = r[2];
    *(int *)((u)r[4] + 2408) = 0; goto out;
    L800ce968:;
    r[2] = *(int *)((u)r[4] + 2408);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[4] + 2408) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
