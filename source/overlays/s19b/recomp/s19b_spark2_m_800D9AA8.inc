extern char R_s19b_dword_800DDE94[] __asm__("s19b_dword_800DDE94");
extern char R_s19b_spark2_m_800D9704[] __asm__("s19b_spark2_m_800D9704");
extern char R_s19b_spark2_m_800D97A8[] __asm__("s19b_spark2_m_800D97A8");
extern char R_s19b_spark2_m_800D985C[] __asm__("s19b_spark2_m_800D985C");
extern char R_s19b_spark2_m_800D9910[] __asm__("s19b_spark2_m_800D9910");
extern char R_s19b_spark2_m_800D99C4[] __asm__("s19b_spark2_m_800D99C4");
int G_s19b_spark2_m_800D9AA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19b_spark2_m_800D9AA8");
int G_s19b_spark2_m_800D9AA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 2324);
    r[2] = (u)r[3] < (u)5;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d9b28;
    r[2] = (u)r[2] + (int)R_s19b_dword_800DDE94;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d9ae0: goto L800d9ae0; case 0x800d9af0: goto L800d9af0; case 0x800d9b00: goto L800d9b00; case 0x800d9b10: goto L800d9b10; case 0x800d9b20: goto L800d9b20; default: goto out; }
    L800d9ae0:;
     CALL(R_s19b_spark2_m_800D9704);
     goto L800d9b28;
    L800d9af0:;
     CALL(R_s19b_spark2_m_800D97A8);
     goto L800d9b28;
    L800d9b00:;
     CALL(R_s19b_spark2_m_800D985C);
     goto L800d9b28;
    L800d9b10:;
     CALL(R_s19b_spark2_m_800D9910);
     goto L800d9b28;
    L800d9b20:;
     CALL(R_s19b_spark2_m_800D99C4);
    L800d9b28:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
