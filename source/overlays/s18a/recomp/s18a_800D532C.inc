extern char R_s18a_800D50C8[] __asm__("s18a_800D50C8");
extern char R_s18a_800D50DC[] __asm__("s18a_800D50DC");
int G_s18a_800D532C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D532C");
int G_s18a_800D532C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 3096);
    r[2] = (u)0 + 3;
    c = ((r[3] == r[2])); r[2] = (u)0 + 4; if (c) goto L800d5354;
    c = ((r[3] == r[2]));  if (c) goto L800d5364;
     goto L800d536c;
    L800d5354:;
     CALL(R_s18a_800D50C8);
     goto L800d536c;
    L800d5364:;
     CALL(R_s18a_800D50DC);
    L800d536c:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
