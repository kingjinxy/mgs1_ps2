int G_s18a_800CEB78(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CEB78");
int G_s18a_800CEB78(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[2] = *(int *)((u)r[5] + 2476);
    r[4] = *(int *)((u)r[5] + 2368);
    r[3] = (u)0 + 14;
    *(int *)((u)r[5] + 2384) = r[3];
    c = ((r[4] == 0)); *(int *)((u)r[5] + 2388) = r[2]; if (c) goto L800cebb0;
    r[2] = (u)0 + 1;
    *(int *)((u)r[5] + 2400) = r[2];
    r[2] = (u)0 + 3;
    *(int *)((u)r[5] + 2404) = r[2];
    *(int *)((u)r[5] + 2428) = 0;
    *(int *)((u)r[5] + 2408) = 0; goto out;
    L800cebb0:;
    r[2] = *(int *)((u)r[5] + 2408);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[5] + 2408) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
