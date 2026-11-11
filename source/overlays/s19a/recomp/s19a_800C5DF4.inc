extern char R_s19a_800C5AFC[] __asm__("s19a_800C5AFC");
extern char R_s19a_800C5C3C[] __asm__("s19a_800C5C3C");
extern char R_s19a_800C5CE4[] __asm__("s19a_800C5CE4");
int G_s19a_800C5DF4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C5DF4");
int G_s19a_800C5DF4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 680);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 2; if (c) goto L800c5e48;
    c = ((r[2] == 0));  if (c) goto L800c5e24;
    c = ((r[3] == 0));  if (c) goto L800c5e38;
     goto L800c5e60;
    L800c5e24:;
    r[2] = (u)0 + 2;
    c = ((r[3] == r[2]));  if (c) goto L800c5e58;
     goto L800c5e60;
    L800c5e38:;
     CALL(R_s19a_800C5AFC);
     goto L800c5e60;
    L800c5e48:;
     CALL(R_s19a_800C5C3C);
     goto L800c5e60;
    L800c5e58:;
     CALL(R_s19a_800C5CE4);
    L800c5e60:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
