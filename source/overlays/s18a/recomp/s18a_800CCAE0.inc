extern char R_s18a_dat_800E308C[] __asm__("s18a_dat_800E308C");
int G_s18a_800CCAE0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CCAE0");
int G_s18a_800CCAE0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)r[4] < (u)5;
    c = ((r[2] == 0)); r[6] = (u)0 + 3; if (c) goto L800ccb30;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_dat_800E308C;
    r[3] = (u)r[4] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800ccb0c: goto L800ccb0c; case 0x800ccb14: goto L800ccb14; case 0x800ccb24: goto L800ccb24; case 0x800ccb2c: goto L800ccb2c; default: goto out; }
    L800ccb0c:;
    r[6] = (u)0 + 3; goto L800ccb30;
    L800ccb14:;
    r[2] = (u)r[5] + -1537;
    r[2] = (u)r[2] < (u)2047;
    c = ((r[2] == 0)); r[6] = (u)0 + 3; if (c) goto L800ccb30;
    L800ccb24:;
    r[6] = (u)0 + (u)0; goto L800ccb30;
    L800ccb2c:;
    r[6] = (u)0 + 1;
    L800ccb30:;
    r[2] = (u)r[6] + (u)0; goto out;
out:
    RECOMP_RETURN;
}
