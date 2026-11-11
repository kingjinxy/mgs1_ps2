extern char R_s19a_800CCA44[] __asm__("s19a_800CCA44");
extern char R_s19a_800CCC24[] __asm__("s19a_800CCC24");
int G_s19a_800CCC74(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CCC74");
int G_s19a_800CCC74(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 3092);
    c = ((r[3] == 0)); r[2] = (u)0 + 1; if (c) goto L800ccc9c;
    c = ((r[3] == r[2]));  if (c) goto L800cccac;
     goto L800cccb4;
    L800ccc9c:;
     CALL(R_s19a_800CCA44);
     goto L800cccb4;
    L800cccac:;
     CALL(R_s19a_800CCC24);
    L800cccb4:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
