extern char R_s18a_800CE674[] __asm__("s18a_800CE674");
extern char R_s18a_800CE6B4[] __asm__("s18a_800CE6B4");
int G_s18a_800D0164(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D0164");
int G_s18a_800D0164(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 2404);
    r[2] = (u)0 + 30;
    c = ((r[3] == r[2])); r[2] = (u)0 + 31; if (c) goto L800d018c;
    c = ((r[3] == r[2]));  if (c) goto L800d019c;
     goto L800d01a4;
    L800d018c:;
     CALL(R_s18a_800CE674);
     goto L800d01a4;
    L800d019c:;
     CALL(R_s18a_800CE6B4);
    L800d01a4:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
