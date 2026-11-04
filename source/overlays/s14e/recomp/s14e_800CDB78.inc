extern char R_s14e_dword_800DD008[] __asm__("s14e_dword_800DD008");
extern char R_s14e_800CD734[] __asm__("s14e_800CD734");
extern char R_s14e_800CD764[] __asm__("s14e_800CD764");
extern char R_s14e_800CD858[] __asm__("s14e_800CD858");
extern char R_s14e_800CD9DC[] __asm__("s14e_800CD9DC");
extern char R_s14e_800CDADC[] __asm__("s14e_800CDADC");
int G_s14e_800CDB78(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CDB78");
int G_s14e_800CDB78(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(short *)((u)r[4] + 2850);
    r[2] = (u)r[3] < (u)5;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800cdbf8;
    r[2] = (u)r[2] + (int)R_s14e_dword_800DD008;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800cdbb0: goto L800cdbb0; case 0x800cdbc0: goto L800cdbc0; case 0x800cdbd0: goto L800cdbd0; case 0x800cdbe0: goto L800cdbe0; case 0x800cdbf0: goto L800cdbf0; default: goto out; }
    L800cdbb0:;
     CALL(R_s14e_800CD734);
     goto L800cdbf8;
    L800cdbc0:;
     CALL(R_s14e_800CD9DC);
     goto L800cdbf8;
    L800cdbd0:;
     CALL(R_s14e_800CD858);
     goto L800cdbf8;
    L800cdbe0:;
     CALL(R_s14e_800CDADC);
     goto L800cdbf8;
    L800cdbf0:;
     CALL(R_s14e_800CD764);
    L800cdbf8:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
