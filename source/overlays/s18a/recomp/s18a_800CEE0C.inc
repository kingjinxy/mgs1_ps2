int G_s18a_800CEE0C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CEE0C");
int G_s18a_800CEE0C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[2] = *(int *)((u)r[5] + 2408);
    r[2] = (int)r[2] < 11;
    c = ((r[2] != 0)); r[2] = (u)0 + 11; if (c) goto L800cee3c;
    r[2] = (u)0 + 5;
    *(int *)((u)r[5] + 2400) = r[2];
    r[2] = (u)0 + 25;
    *(int *)((u)r[5] + 2404) = r[2];
    *(int *)((u)r[5] + 2408) = 0; goto out;
    L800cee3c:;
    r[4] = *(int *)((u)r[5] + 2476);
    r[3] = *(int *)((u)r[5] + 2408);
    *(int *)((u)r[5] + 2384) = r[2];
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[5] + 2388) = r[4];
    *(int *)((u)r[5] + 2408) = r[3]; goto out;
out:
    RECOMP_RETURN;
}
