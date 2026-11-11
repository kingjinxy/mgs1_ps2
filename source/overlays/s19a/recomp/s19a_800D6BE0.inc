extern char R_s19a_dat_800E02E0[] __asm__("s19a_dat_800E02E0");
extern char R_s19a_800D68F4[] __asm__("s19a_800D68F4");
extern char R_s19a_800D6948[] __asm__("s19a_800D6948");
extern char R_s19a_800D699C[] __asm__("s19a_800D699C");
extern char R_s19a_800D69F0[] __asm__("s19a_800D69F0");
extern char R_s19a_800D6A44[] __asm__("s19a_800D6A44");
extern char R_s19a_800D6A98[] __asm__("s19a_800D6A98");
extern char R_s19a_800D6B28[] __asm__("s19a_800D6B28");
extern char R_s19a_800D6B7C[] __asm__("s19a_800D6B7C");
int G_s19a_800D6BE0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D6BE0");
int G_s19a_800D6BE0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[3] = (u)r[4] + -240;
    r[2] = (u)r[3] < (u)8;
    *(int *)((u)r[29] + 16) = r[31];
    c = ((r[2] == 0)); *(int *)((u)r[29] + 24) = r[4]; if (c) goto L800d6c90;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19a_dat_800E02E0;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d6c18: goto L800d6c18; case 0x800d6c28: goto L800d6c28; case 0x800d6c38: goto L800d6c38; case 0x800d6c48: goto L800d6c48; case 0x800d6c58: goto L800d6c58; case 0x800d6c68: goto L800d6c68; case 0x800d6c78: goto L800d6c78; case 0x800d6c88: goto L800d6c88; default: goto out; }
    L800d6c18:;
    r[4] = (u)r[29] + 24; CALL(R_s19a_800D68F4);
     goto L800d6c90;
    L800d6c28:;
    r[4] = (u)r[29] + 24; CALL(R_s19a_800D6948);
     goto L800d6c90;
    L800d6c38:;
    r[4] = (u)r[29] + 24; CALL(R_s19a_800D699C);
     goto L800d6c90;
    L800d6c48:;
    r[4] = (u)r[29] + 24; CALL(R_s19a_800D69F0);
     goto L800d6c90;
    L800d6c58:;
    r[4] = (u)r[29] + 24; CALL(R_s19a_800D6A44);
     goto L800d6c90;
    L800d6c68:;
    r[4] = (u)r[29] + 24; CALL(R_s19a_800D6B28);
     goto L800d6c90;
    L800d6c78:;
    r[4] = (u)r[29] + 24; CALL(R_s19a_800D6A98);
     goto L800d6c90;
    L800d6c88:;
    r[4] = (u)r[29] + 24; CALL(R_s19a_800D6B7C);
    L800d6c90:;
    r[2] = *(int *)((u)r[29] + 24);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
