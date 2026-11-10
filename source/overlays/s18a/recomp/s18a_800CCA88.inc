extern char R_s18a_dat_800E3074[] __asm__("s18a_dat_800E3074");
int G_s18a_800CCA88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CCA88");
int G_s18a_800CCA88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)r[4] < (u)5;
    c = ((r[2] == 0)); r[6] = (u)0 + 2; if (c) goto L800ccad8;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_dat_800E3074;
    r[3] = (u)r[4] << (r[6] & 31);
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800ccab4: goto L800ccab4; case 0x800ccac4: goto L800ccac4; case 0x800ccacc: goto L800ccacc; case 0x800ccad4: goto L800ccad4; default: goto out; }
    L800ccab4:;
    r[2] = (u)r[5] + -513;
    r[2] = (u)r[2] < (u)2047;
    c = ((r[2] == 0)); r[6] = (u)0 + 1; if (c) goto L800ccad8;
    L800ccac4:;
    r[6] = (u)0 + 2; goto L800ccad8;
    L800ccacc:;
    r[6] = (u)0 + (u)0; goto L800ccad8;
    L800ccad4:;
    r[6] = (u)0 + 1;
    L800ccad8:;
    r[2] = (u)r[6] + (u)0; goto out;
out:
    RECOMP_RETURN;
}
