extern char R_s18a_800CF470[] __asm__("s18a_800CF470");
extern char R_s18a_800CF4BC[] __asm__("s18a_800CF4BC");
int G_s18a_800D069C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D069C");
int G_s18a_800D069C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 2404);
    r[2] = (u)0 + 19;
    c = ((r[3] == r[2])); r[2] = (u)0 + 20; if (c) goto L800d06c4;
    c = ((r[3] == r[2]));  if (c) goto L800d06d4;
     goto L800d06dc;
    L800d06c4:;
     CALL(R_s18a_800CF470);
     goto L800d06dc;
    L800d06d4:;
     CALL(R_s18a_800CF4BC);
    L800d06dc:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
