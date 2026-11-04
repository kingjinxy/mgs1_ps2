extern char R_s14e_800C96AC[] __asm__("s14e_800C96AC");
extern char R_s14e_800CA90C[] __asm__("s14e_800CA90C");
extern char R_s14e_800CA96C[] __asm__("s14e_800CA96C");
extern char R_s14e_800CADD0[] __asm__("s14e_800CADD0");
extern char R_s14e_800CAE24[] __asm__("s14e_800CAE24");
extern char R_s14e_800CAEF4[] __asm__("s14e_800CAEF4");
extern char R_s14e_800CDC08[] __asm__("s14e_800CDC08");
int G_s14e_800CB0BC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CB0BC");
int G_s14e_800CB0BC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(short *)((u)r[16] + 2272);
    r[2] = (int)r[2] < 49;
    c = ((r[2] == 0));  if (c) goto L800cb110;
     CALL(R_s14e_800CA96C);
    r[4] = (u)r[16] + (u)0; CALL(R_s14e_800CAEF4);
    r[4] = (u)r[16] + (u)0; CALL(R_s14e_800CADD0);
    r[4] = (u)r[16] + (u)0; CALL(R_s14e_800CAE24);
    r[4] = (u)r[16] + (u)0; CALL(R_s14e_800CDC08);
    r[4] = (u)r[16] + (u)0; CALL(R_s14e_800CA90C);
    L800cb110:;
    r[4] = (u)r[16] + (u)0; CALL(R_s14e_800C96AC);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
