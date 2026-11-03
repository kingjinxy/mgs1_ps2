extern char R_s10a_800E2C5C[] __asm__("s10a_800E2C5C");
extern char R_s10a_800E2CD4[] __asm__("s10a_800E2CD4");
extern char R_DG_SetExtPaletteMakeFunc[] __asm__("DG_SetExtPaletteMakeFunc");
int G_s10a_800E2DD0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800E2DD0");
int G_s10a_800E2DD0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[4] = 0;
    r[5] = 0;
    r[4] = (u)r[4] + (int)R_s10a_800E2CD4;
    *(int *)((u)r[29] + 16) = r[31];
    r[5] = (u)r[5] + (int)R_s10a_800E2C5C; CALL(R_DG_SetExtPaletteMakeFunc);
    r[31] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
