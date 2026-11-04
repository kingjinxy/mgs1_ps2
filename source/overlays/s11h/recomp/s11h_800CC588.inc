extern char R_s11h_800CC414[] __asm__("s11h_800CC414");
extern char R_s11h_800CC48C[] __asm__("s11h_800CC48C");
extern char R_DG_SetExtPaletteMakeFunc[] __asm__("DG_SetExtPaletteMakeFunc");
int G_s11h_800CC588(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800CC588");
int G_s11h_800CC588(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[4] = 0;
    r[5] = 0;
    r[4] = (u)r[4] + (int)R_s11h_800CC48C;
    *(int *)((u)r[29] + 16) = r[31];
    r[5] = (u)r[5] + (int)R_s11h_800CC414; CALL(R_DG_SetExtPaletteMakeFunc);
    r[31] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
