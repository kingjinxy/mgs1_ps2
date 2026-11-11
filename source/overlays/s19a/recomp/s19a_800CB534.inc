extern char R_s19a_800CB4B8[] __asm__("s19a_800CB4B8");
int G_s19a_800CB534(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CB534");
int G_s19a_800CB534(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(int *)((u)r[4] + 52);
    r[2] = *(int *)((u)r[2] + 0);
    r[16] = r[2] & 3;
    c = ((r[16] == 0));  if (c) goto L800cb578;
     CALL(R_s19a_800CB4B8);
    r[3] = (u)r[2] + (u)0;
    c = ((r[3] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800cb57c;
    r[2] = (u)r[16] + (u)0; goto L800cb57c;
    L800cb578:;
    r[2] = (u)0 + (u)0;
    L800cb57c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
