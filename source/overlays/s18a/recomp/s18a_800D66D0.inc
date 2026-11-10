extern char R_GM_WeaponChanged[] __asm__("GM_WeaponChanged");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
int G_s18a_800D66D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D66D0");
int G_s18a_800D66D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 2148);
    r[2] = (u)r[3] + -5;
    r[2] = (u)r[2] < (u)2;
    c = ((r[2] != 0)); r[2] = (u)0 + 2; if (c) goto L800d6700;
    c = ((r[3] == r[2])); r[2] = (u)0 + 7; if (c) goto L800d6700;
    c = ((r[3] == r[2])); r[2] = (u)0 + 8; if (c) goto L800d6700;
    c = ((r[3] != r[2]));  if (c) goto L800d6730;
    L800d6700:;
    r[4] = *(int *)((u)r[4] + 2144);
    r[2] = *(short *)((u)r[4] + 0);
    c = ((r[2] != 0)); r[3] = (u)0 + -1; if (c) goto L800d6730;
    r[2] = 0;
    *(short *)((u)r[4] + 0) = r[3];
    *(short *)((u)r[2] + ((int)R_linkvarbuf + 28)) = r[3];
    r[3] = 0;
    r[2] = (u)0 + 1;
    *(short *)((u)r[3] + (int)R_GM_WeaponChanged) = r[2];
    L800d6730:;
     goto out;
out:
    RECOMP_RETURN;
}
