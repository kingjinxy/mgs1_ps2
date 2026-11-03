extern char R_GV_DelayedFree[] __asm__("GV_DelayedFree");
int G_s10a_800DFB50(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800DFB50");
int G_s10a_800DFB50(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[4] + 64);
    c = ((r[2] == 0));  if (c) goto L800dfb74;
    r[4] = *(int *)((u)r[4] + 40);
     CALL(R_GV_DelayedFree);
    L800dfb74:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
