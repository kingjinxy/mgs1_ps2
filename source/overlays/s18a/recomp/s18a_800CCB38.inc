extern char R_s18a_dat_800E30A4[] __asm__("s18a_dat_800E30A4");
int G_s18a_800CCB38(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CCB38");
int G_s18a_800CCB38(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)r[4] < (u)5;
    c = ((r[2] == 0)); r[6] = (u)0 + 3; if (c) goto L800ccb88;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_dat_800E30A4;
    r[3] = (u)r[4] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800ccb64: goto L800ccb64; case 0x800ccb6c: goto L800ccb6c; case 0x800ccb7c: goto L800ccb7c; case 0x800ccb84: goto L800ccb84; default: goto out; }
    L800ccb64:;
    r[6] = (u)0 + 2; goto L800ccb88;
    L800ccb6c:;
    r[2] = (u)r[5] + -1537;
    r[2] = (u)r[2] < (u)2047;
    c = ((r[2] == 0)); r[6] = (u)0 + 3; if (c) goto L800ccb88;
    L800ccb7c:;
    r[6] = (u)0 + (u)0; goto L800ccb88;
    L800ccb84:;
    r[6] = (u)0 + 3;
    L800ccb88:;
    r[2] = (u)r[6] + (u)0; goto out;
out:
    RECOMP_RETURN;
}
