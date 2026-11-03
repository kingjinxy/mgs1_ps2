extern char R_s10a_800CADC4[] __asm__("s10a_800CADC4");
extern char R_s10a_800CB3EC[] __asm__("s10a_800CB3EC");
extern char R_s10a_800CB44C[] __asm__("s10a_800CB44C");
extern char R_s10a_800CB8B0[] __asm__("s10a_800CB8B0");
extern char R_s10a_800CB904[] __asm__("s10a_800CB904");
extern char R_s10a_800CB9D4[] __asm__("s10a_800CB9D4");
extern char R_s10a_800CDC74[] __asm__("s10a_800CDC74");
int G_s10a_800CBB9C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CBB9C");
int G_s10a_800CBB9C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(short *)((u)r[16] + 2272);
    r[2] = (int)r[2] < 49;
    c = ((r[2] == 0));  if (c) goto L800cbbf0;
     CALL(R_s10a_800CB44C);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CB9D4);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CB8B0);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CB904);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CDC74);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CB3EC);
    L800cbbf0:;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CADC4);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
