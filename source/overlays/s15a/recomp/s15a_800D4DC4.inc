extern char R_GV_DelayedFree[] __asm__("GV_DelayedFree");
int G_s15a_800D4DC4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D4DC4");
int G_s15a_800D4DC4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[4] + 64);
    c = ((r[2] == 0));  if (c) goto L800d4de8;
    r[4] = *(int *)((u)r[4] + 40);
     CALL(R_GV_DelayedFree);
    L800d4de8:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
