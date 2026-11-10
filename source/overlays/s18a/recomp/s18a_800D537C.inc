extern char R_s18a_800D514C[] __asm__("s18a_800D514C");
extern char R_s18a_800D532C[] __asm__("s18a_800D532C");
int G_s18a_800D537C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D537C");
int G_s18a_800D537C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 3092);
    c = ((r[3] == 0)); r[2] = (u)0 + 1; if (c) goto L800d53a4;
    c = ((r[3] == r[2]));  if (c) goto L800d53b4;
     goto L800d53bc;
    L800d53a4:;
     CALL(R_s18a_800D514C);
     goto L800d53bc;
    L800d53b4:;
     CALL(R_s18a_800D532C);
    L800d53bc:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
