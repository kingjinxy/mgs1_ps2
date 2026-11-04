extern char R_s15a_dat_800C34AC[] __asm__("s15a_dat_800C34AC");
extern char R_GV_DelayedFree[] __asm__("GV_DelayedFree");
int G_s15a_800C7890(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800C7890");
int G_s15a_800C7890(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[4] = *(int *)((u)r[4] + 32);
    c = ((r[4] == 0));  if (c) goto L800c78b0;
     CALL(R_GV_DelayedFree);
    L800c78b0:;
    r[31] = *(int *)((u)r[29] + 16);
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s15a_dat_800C34AC) = 0;
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
