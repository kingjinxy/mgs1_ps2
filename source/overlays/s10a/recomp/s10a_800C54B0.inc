extern char R_s10a_dat_800E3628[] __asm__("s10a_dat_800E3628");
extern char R_GM_FreeObject[] __asm__("GM_FreeObject");
extern char R_printf[] __asm__("printf");
int G_s10a_800C54B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C54B0");
int G_s10a_800C54B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = 0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)r[4] + ((int)R_s10a_dat_800E3628 + 76); CALL(R_printf);
    r[4] = (u)r[16] + 32;
    r[3] = *(int *)((u)r[16] + 32);
    r[2] = (u)0 + 87;
    *(int *)((u)r[3] + 40) = r[2]; CALL(R_GM_FreeObject);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
