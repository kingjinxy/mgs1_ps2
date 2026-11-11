extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
int G_s19a_800D34D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D34D0");
int G_s19a_800D34D0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[4] + 164);
    r[2] = (u)r[2] + -1;
    c = ((r[2] != 0)); *(int *)((u)r[4] + 164) = r[2]; if (c) goto L800d34f4;
     CALL(R_GV_DestroyActor);
    L800d34f4:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
