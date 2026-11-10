int G_s18a_800CEE58(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CEE58");
int G_s18a_800CEE58(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2476);
    r[5] = *(int *)((u)r[4] + 2480);
    r[3] = (u)0 + 12;
    *(int *)((u)r[4] + 2384) = r[3];
    *(int *)((u)r[4] + 2388) = r[2];
    r[2] = (int)r[5] < 3000;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800cee90;
    *(int *)((u)r[4] + 2400) = r[2];
    r[2] = (u)0 + 3;
    L800cee80:;
    *(int *)((u)r[4] + 2404) = r[2];
    *(int *)((u)r[4] + 2428) = 0;
    *(int *)((u)r[4] + 2408) = 0; goto out;
    L800cee90:;
    r[2] = (int)r[5] < 8001;
    c = ((r[2] != 0)); r[2] = (u)0 + 3; if (c) goto L800ceea8;
    *(int *)((u)r[4] + 2400) = r[2];
    r[2] = (u)0 + 13; goto L800cee80;
    L800ceea8:;
    r[2] = *(int *)((u)r[4] + 2408);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[4] + 2408) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
