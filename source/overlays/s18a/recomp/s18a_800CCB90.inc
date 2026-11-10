extern char R_s18a_dat_800E30BC[] __asm__("s18a_dat_800E30BC");
int G_s18a_800CCB90(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CCB90");
int G_s18a_800CCB90(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)r[4] < (u)5;
    c = ((r[2] == 0)); r[6] = (u)0 + 3; if (c) goto L800ccbe0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_dat_800E30BC;
    r[3] = (u)r[4] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800ccbbc: goto L800ccbbc; case 0x800ccbc4: goto L800ccbc4; case 0x800ccbd4: goto L800ccbd4; case 0x800ccbdc: goto L800ccbdc; default: goto out; }
    L800ccbbc:;
    r[6] = (u)0 + 1; goto L800ccbe0;
    L800ccbc4:;
    r[2] = (u)r[5] + -513;
    r[2] = (u)r[2] < (u)2047;
    c = ((r[2] == 0)); r[6] = (u)0 + 1; if (c) goto L800ccbe0;
    L800ccbd4:;
    r[6] = (u)0 + 2; goto L800ccbe0;
    L800ccbdc:;
    r[6] = (u)0 + 3;
    L800ccbe0:;
    r[2] = (u)r[6] + (u)0; goto out;
out:
    RECOMP_RETURN;
}
