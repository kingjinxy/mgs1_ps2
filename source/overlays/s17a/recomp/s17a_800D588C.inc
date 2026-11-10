extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
int G_s17a_800D588C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800D588C");
int G_s17a_800D588C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[4] = *(int *)((u)r[4] + 3724);
    c = ((r[4] == 0));  if (c) goto L800d58ac;
     CALL(R_GV_DestroyActor);
    L800d58ac:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
