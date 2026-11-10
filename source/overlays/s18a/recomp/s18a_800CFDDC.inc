extern char R_s18a_dat_800E314C[] __asm__("s18a_dat_800E314C");
extern char R_s18a_800CD59C[] __asm__("s18a_800CD59C");
extern char R_s18a_800CD62C[] __asm__("s18a_800CD62C");
extern char R_s18a_800CD6D0[] __asm__("s18a_800CD6D0");
extern char R_s18a_800CD758[] __asm__("s18a_800CD758");
extern char R_s18a_800CD7F4[] __asm__("s18a_800CD7F4");
extern char R_s18a_800CD8B4[] __asm__("s18a_800CD8B4");
extern char R_s18a_800CD98C[] __asm__("s18a_800CD98C");
extern char R_s18a_800CDA40[] __asm__("s18a_800CDA40");
int G_s18a_800CFDDC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CFDDC");
int G_s18a_800CFDDC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 2404);
    r[2] = (u)r[3] < (u)19;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800cfe8c;
    r[2] = (u)r[2] + (int)R_s18a_dat_800E314C;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800cfe14: goto L800cfe14; case 0x800cfe24: goto L800cfe24; case 0x800cfe34: goto L800cfe34; case 0x800cfe44: goto L800cfe44; case 0x800cfe54: goto L800cfe54; case 0x800cfe64: goto L800cfe64; case 0x800cfe74: goto L800cfe74; case 0x800cfe84: goto L800cfe84; case 0x800cfe8c: goto L800cfe8c; default: goto out; }
    L800cfe14:;
     CALL(R_s18a_800CD59C);
     goto L800cfe8c;
    L800cfe24:;
     CALL(R_s18a_800CD62C);
     goto L800cfe8c;
    L800cfe34:;
     CALL(R_s18a_800CD6D0);
     goto L800cfe8c;
    L800cfe44:;
     CALL(R_s18a_800CD758);
     goto L800cfe8c;
    L800cfe54:;
     CALL(R_s18a_800CD7F4);
     goto L800cfe8c;
    L800cfe64:;
     CALL(R_s18a_800CD8B4);
     goto L800cfe8c;
    L800cfe74:;
     CALL(R_s18a_800CD98C);
     goto L800cfe8c;
    L800cfe84:;
     CALL(R_s18a_800CDA40);
    L800cfe8c:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
