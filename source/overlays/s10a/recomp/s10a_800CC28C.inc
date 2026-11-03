extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
int G_s10a_800CC28C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CC28C");
int G_s10a_800CC28C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[4] + 164);
    r[2] = (u)r[2] + -1;
    c = ((r[2] != 0)); *(int *)((u)r[4] + 164) = r[2]; if (c) goto L800cc2b0;
     CALL(R_GV_DestroyActor);
    L800cc2b0:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
