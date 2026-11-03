extern char R_s07b_800CB2A4[] __asm__("s07b_800CB2A4");
int G_s07b_800D0A4C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800D0A4C");
int G_s07b_800D0A4C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
     CALL(R_s07b_800CB2A4);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
