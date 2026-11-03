extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
int G_s07b_800CBCE8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CBCE8");
int G_s07b_800CBCE8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[2] = *(int *)((u)r[16] + 2108);
    r[17] = (u)0 + -1;
    c = ((r[2] == r[17]));  if (c) goto L800cbd38;
    r[4] = *(int *)((u)r[16] + 2104);
    c = ((r[4] == 0));  if (c) goto L800cbd24;
     CALL(R_GV_DestroyActor);
    L800cbd24:;
    r[3] = *(int *)((u)r[16] + 2012);
    r[2] = (u)0 + 1;
    *(int *)((u)r[16] + 2104) = 0;
    *(int *)((u)r[16] + 2108) = r[17];
    *(int *)((u)r[3] + 0) = r[2];
    L800cbd38:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
