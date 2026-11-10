extern char R_s18a_800CE634[] __asm__("s18a_800CE634");
extern char R_s18a_800CE6B4[] __asm__("s18a_800CE6B4");
int G_s18a_800D00C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D00C4");
int G_s18a_800D00C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 2404);
    r[2] = (u)0 + 30;
    c = ((r[3] == r[2])); r[2] = (u)0 + 31; if (c) goto L800d00ec;
    c = ((r[3] == r[2]));  if (c) goto L800d00fc;
     goto L800d0104;
    L800d00ec:;
     CALL(R_s18a_800CE634);
     goto L800d0104;
    L800d00fc:;
     CALL(R_s18a_800CE6B4);
    L800d0104:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
