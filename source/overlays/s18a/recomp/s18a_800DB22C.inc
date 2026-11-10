extern char R_s18a_rc_800D9784[] __asm__("s18a_rc_800D9784");
extern char R_s18a_800DB1EC[] __asm__("s18a_800DB1EC");
int G_s18a_800DB22C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DB22C");
int G_s18a_800DB22C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[4] + 2212);
    r[2] = *(unsigned short *)((u)r[2] + 0);
    r[2] = r[2] & 20480;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800db270;
    r[2] = (u)r[2] + (int)R_s18a_rc_800D9784;
    *(int *)((u)r[4] + 2220) = r[2];
    *(int *)((u)r[4] + 2224) = 0;
    *(short *)((u)r[4] + 2322) = 0;
    *(short *)((u)r[4] + 2320) = 0;
    *(short *)((u)r[4] + 112) = 0;
    *(short *)((u)r[4] + 108) = 0; goto L800db278;
    L800db270:;
     CALL(R_s18a_800DB1EC);
    L800db278:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
