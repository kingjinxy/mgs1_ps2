extern char R_s18a_800CEB78[] __asm__("s18a_800CEB78");
extern char R_s18a_800CEEBC[] __asm__("s18a_800CEEBC");
extern char R_s18a_800CF0EC[] __asm__("s18a_800CF0EC");
int G_s18a_800D03C0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D03C0");
int G_s18a_800D03C0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 2404);
    r[2] = (u)0 + 9;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 10; if (c) goto L800d041c;
    c = ((r[2] == 0)); r[2] = (u)0 + 8; if (c) goto L800d03f0;
    c = ((r[3] == r[2]));  if (c) goto L800d040c;
     goto L800d0424;
    L800d03f0:;
    r[2] = (u)0 + 10;
    c = ((r[3] != r[2]));  if (c) goto L800d0424;
     CALL(R_s18a_800CEB78);
     goto L800d0424;
    L800d040c:;
     CALL(R_s18a_800CEEBC);
     goto L800d0424;
    L800d041c:;
     CALL(R_s18a_800CF0EC);
    L800d0424:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
