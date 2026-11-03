extern char R_s10a_800DD9EC[] __asm__("s10a_800DD9EC");
int G_s10a_800DD18C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800DD18C");
int G_s10a_800DD18C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
     CALL(R_s10a_800DD9EC);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
