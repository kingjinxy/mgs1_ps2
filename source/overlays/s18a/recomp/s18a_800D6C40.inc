extern char R_s18a_dat_800E3B68[] __asm__("s18a_dat_800E3B68");
int G_s18a_800D6C40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D6C40");
int G_s18a_800D6C40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)r[4] < (u)8;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d6c80;
    r[2] = (u)r[2] + (int)R_s18a_dat_800E3B68;
    r[3] = (u)r[4] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d6c68: goto L800d6c68; case 0x800d6c70: goto L800d6c70; case 0x800d6c78: goto L800d6c78; default: goto out; }
    L800d6c68:;
    r[2] = (u)0 + (u)0; goto out;
    L800d6c70:;
    r[2] = (u)0 + 1; goto out;
    L800d6c78:;
    r[2] = (u)0 + 2; goto out;
    L800d6c80:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
