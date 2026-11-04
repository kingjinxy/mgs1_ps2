extern char R_DG_ResetExtPaletteMakeFunc[] __asm__("DG_ResetExtPaletteMakeFunc");
extern char R_GV_DelayedFree[] __asm__("GV_DelayedFree");
int G_s15a_800D767C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D767C");
int G_s15a_800D767C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_DG_ResetExtPaletteMakeFunc);
    r[4] = *(int *)((u)r[16] + 32);
    c = ((r[4] == 0));  if (c) goto L800d76a8;
     CALL(R_GV_DelayedFree);
    L800d76a8:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
