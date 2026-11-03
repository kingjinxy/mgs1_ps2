extern char R_s10a_800C91A4[] __asm__("s10a_800C91A4");
extern char R_s10a_800C91B8[] __asm__("s10a_800C91B8");
int G_s10a_800C9408(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C9408");
int G_s10a_800C9408(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 3096);
    r[2] = (u)0 + 3;
    c = ((r[3] == r[2])); r[2] = (u)0 + 4; if (c) goto L800c9430;
    c = ((r[3] == r[2]));  if (c) goto L800c9440;
     goto L800c9448;
    L800c9430:;
     CALL(R_s10a_800C91A4);
     goto L800c9448;
    L800c9440:;
     CALL(R_s10a_800C91B8);
    L800c9448:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
