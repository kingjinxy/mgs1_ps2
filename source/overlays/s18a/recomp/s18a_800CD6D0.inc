extern char R_s18a_800C70E8[] __asm__("s18a_800C70E8");
int G_s18a_800CD6D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CD6D0");
int G_s18a_800CD6D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2408);
    c = ((r[2] != 0)); r[2] = (int)r[2] < 54; if (c) goto L800cd704;
    r[2] = (u)0 + 1;
    *(int *)((u)r[16] + 2384) = r[2];
    r[2] = *(int *)((u)r[16] + 2408);
    r[2] = (int)r[2] < 54;
    L800cd704:;
    c = ((r[2] == 0));  if (c) goto L800cd714;
    r[4] = (u)0 + 5400; CALL(R_s18a_800C70E8);
    L800cd714:;
    r[3] = *(int *)((u)r[16] + 2408);
    r[2] = (int)r[3] < 71;
    c = ((r[2] != 0)); r[2] = (u)r[3] + 1; if (c) goto L800cd744;
    r[2] = (u)0 + 6;
    *(int *)((u)r[16] + 2384) = r[2];
    r[2] = (u)0 + 3;
    *(int *)((u)r[16] + 2404) = r[2];
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0; goto L800cd748;
    L800cd744:;
    *(int *)((u)r[16] + 2408) = r[2];
    L800cd748:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
