extern char R_s10a_800DCA7C[] __asm__("s10a_800DCA7C");
int G_s10a_800DCFAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800DCFAC");
int G_s10a_800DCFAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
     CALL(R_s10a_800DCA7C);
    r[3] = (u)r[2] + (u)0;
    c = (((int)r[3] < 0)); r[2] = (u)0 + -1; if (c) goto L800dcfcc;
    r[2] = (u)0 + (u)0;
    L800dcfcc:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
