extern char R_s10a_dat_800C3728[] __asm__("s10a_dat_800C3728");
extern char R_GV_DelayedFree[] __asm__("GV_DelayedFree");
int G_s10a_800D448C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D448C");
int G_s10a_800D448C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[4] = *(int *)((u)r[4] + 32);
    c = ((r[4] == 0));  if (c) goto L800d44ac;
     CALL(R_GV_DelayedFree);
    L800d44ac:;
    r[31] = *(int *)((u)r[29] + 16);
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s10a_dat_800C3728) = 0;
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
