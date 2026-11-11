extern char R_s19a_800D092C[] __asm__("s19a_800D092C");
extern char R_s19a_800D1C24[] __asm__("s19a_800D1C24");
extern char R_s19a_800D1C84[] __asm__("s19a_800D1C84");
extern char R_s19a_800D20E8[] __asm__("s19a_800D20E8");
extern char R_s19a_800D213C[] __asm__("s19a_800D213C");
extern char R_s19a_800D220C[] __asm__("s19a_800D220C");
extern char R_s19a_800D649C[] __asm__("s19a_800D649C");
int G_s19a_800D23D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D23D4");
int G_s19a_800D23D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(short *)((u)r[16] + 2272);
    r[2] = (int)r[2] < 49;
    c = ((r[2] == 0));  if (c) goto L800d2428;
     CALL(R_s19a_800D1C84);
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D220C);
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D20E8);
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D213C);
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D649C);
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D1C24);
    L800d2428:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D092C);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
