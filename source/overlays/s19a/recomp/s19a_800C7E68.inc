extern char R_s19a_dat_800DFBB4[] __asm__("s19a_dat_800DFBB4");
extern char R_s19a_800C7D50[] __asm__("s19a_800C7D50");
extern char R_s19a_800C7D7C[] __asm__("s19a_800C7D7C");
extern char R_s19a_800C7D88[] __asm__("s19a_800C7D88");
extern char R_s19a_800C7D94[] __asm__("s19a_800C7D94");
extern char R_s19a_800C7DA0[] __asm__("s19a_800C7DA0");
extern char R_s19a_800C7DAC[] __asm__("s19a_800C7DAC");
extern char R_s19a_800C7DF8[] __asm__("s19a_800C7DF8");
extern char R_s19a_800C7E04[] __asm__("s19a_800C7E04");
int G_s19a_800C7E68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C7E68");
int G_s19a_800C7E68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[3] = (u)r[4] + -240;
    r[2] = (u)r[3] < (u)8;
    *(int *)((u)r[29] + 16) = r[31];
    c = ((r[2] == 0)); *(int *)((u)r[29] + 24) = r[4]; if (c) goto L800c7f18;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s19a_dat_800DFBB4;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800c7ea0: goto L800c7ea0; case 0x800c7eb0: goto L800c7eb0; case 0x800c7ec0: goto L800c7ec0; case 0x800c7ed0: goto L800c7ed0; case 0x800c7ee0: goto L800c7ee0; case 0x800c7ef0: goto L800c7ef0; case 0x800c7f00: goto L800c7f00; case 0x800c7f10: goto L800c7f10; default: goto out; }
    L800c7ea0:;
    r[4] = (u)r[29] + 24; CALL(R_s19a_800C7D50);
     goto L800c7f18;
    L800c7eb0:;
    r[4] = (u)r[29] + 24; CALL(R_s19a_800C7D7C);
     goto L800c7f18;
    L800c7ec0:;
    r[4] = (u)r[29] + 24; CALL(R_s19a_800C7D88);
     goto L800c7f18;
    L800c7ed0:;
    r[4] = (u)r[29] + 24; CALL(R_s19a_800C7D94);
     goto L800c7f18;
    L800c7ee0:;
    r[4] = (u)r[29] + 24; CALL(R_s19a_800C7DA0);
     goto L800c7f18;
    L800c7ef0:;
    r[4] = (u)r[29] + 24; CALL(R_s19a_800C7DF8);
     goto L800c7f18;
    L800c7f00:;
    r[4] = (u)r[29] + 24; CALL(R_s19a_800C7DAC);
     goto L800c7f18;
    L800c7f10:;
    r[4] = (u)r[29] + 24; CALL(R_s19a_800C7E04);
    L800c7f18:;
    r[2] = *(int *)((u)r[29] + 24);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
