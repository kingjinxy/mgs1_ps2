extern char R_s19a_800CC9C0[] __asm__("s19a_800CC9C0");
extern char R_s19a_800CC9D4[] __asm__("s19a_800CC9D4");
int G_s19a_800CCC24(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CCC24");
int G_s19a_800CCC24(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 3096);
    r[2] = (u)0 + 3;
    c = ((r[3] == r[2])); r[2] = (u)0 + 4; if (c) goto L800ccc4c;
    c = ((r[3] == r[2]));  if (c) goto L800ccc5c;
     goto L800ccc64;
    L800ccc4c:;
     CALL(R_s19a_800CC9C0);
     goto L800ccc64;
    L800ccc5c:;
     CALL(R_s19a_800CC9D4);
    L800ccc64:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
