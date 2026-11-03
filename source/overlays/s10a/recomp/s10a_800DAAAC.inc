extern char R_s10a_800D9E1C[] __asm__("s10a_800D9E1C");
int G_s10a_800DAAAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800DAAAC");
int G_s10a_800DAAAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[4] + 1744);
    c = ((r[2] != 0));  if (c) goto L800daacc;
     CALL(R_s10a_800D9E1C);
    L800daacc:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
