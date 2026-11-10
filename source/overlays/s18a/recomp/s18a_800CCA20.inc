extern char R_s18a_dat_800E305C[] __asm__("s18a_dat_800E305C");
int G_s18a_800CCA20(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CCA20");
int G_s18a_800CCA20(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)r[4] < (u)5;
    c = ((r[2] == 0)); r[6] = (u)0 + (u)0; if (c) goto L800cca80;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_dat_800E305C;
    r[3] = (u)r[4] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800cca4c: goto L800cca4c; case 0x800cca58: goto L800cca58; case 0x800cca64: goto L800cca64; case 0x800cca6c: goto L800cca6c; case 0x800cca7c: goto L800cca7c; default: goto out; }
    L800cca4c:;
    r[2] = (u)r[5] + -513;
    r[6] = (u)r[2] < (u)2047; goto L800cca80;
    L800cca58:;
    r[2] = (u)r[5] + -1537;
    r[6] = (u)r[2] < (u)2047; goto L800cca80;
    L800cca64:;
    r[2] = (u)r[5] + -1537; goto L800cca70;
    L800cca6c:;
    r[2] = (u)r[5] + -513;
    L800cca70:;
    r[2] = (u)r[2] < (u)2047;
    r[6] = r[2] ^ 1; goto L800cca80;
    L800cca7c:;
    r[6] = (int)r[5] < 2048;
    L800cca80:;
    r[2] = (u)r[6] + (u)0; goto out;
out:
    RECOMP_RETURN;
}
