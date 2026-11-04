extern char R_s10a_800C9228[] __asm__("s10a_800C9228");
extern char R_s10a_800C9408[] __asm__("s10a_800C9408");
int G_s10a_800C9458(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800C9458");
int G_s10a_800C9458(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 3092);
    c = ((r[3] == 0)); r[2] = (u)0 + 1; if (c) goto L800c9480;
    c = ((r[3] == r[2]));  if (c) goto L800c9490;
     goto L800c9498;
    L800c9480:;
     CALL(R_s10a_800C9228);
     goto L800c9498;
    L800c9490:;
     CALL(R_s10a_800C9408);
    L800c9498:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
