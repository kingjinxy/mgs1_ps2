extern char R_s17a_dat_800C34C4[] __asm__("s17a_dat_800C34C4");
extern char R_GV_DelayedFree[] __asm__("GV_DelayedFree");
int G_s17a_800CA9DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800CA9DC");
int G_s17a_800CA9DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[4] = *(int *)((u)r[4] + 32);
    c = ((r[4] == 0));  if (c) goto L800ca9fc;
     CALL(R_GV_DelayedFree);
    L800ca9fc:;
    r[31] = *(int *)((u)r[29] + 16);
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s17a_dat_800C34C4) = 0;
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
