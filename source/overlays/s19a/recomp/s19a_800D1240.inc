extern char R_s19a_dat_800C3628[] __asm__("s19a_dat_800C3628");
extern char R_DG_MovePos[] __asm__("DG_MovePos");
extern char R_DG_SetPos[] __asm__("DG_SetPos");
extern char R_ReadRotMatrix[] __asm__("ReadRotMatrix");
extern char R_s19a_800CC180[] __asm__("s19a_800CC180");
int G_s19a_800D1240(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D1240");
int G_s19a_800D1240(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(56)
    r[29] = (u)r[29] + -56;
    *(int *)((u)r[29] + 48) = r[31];
    r[4] = *(int *)((u)r[4] + 156);
    r[4] = (u)r[4] + 624; CALL(R_DG_SetPos);
    r[4] = 0;
    r[4] = (u)r[4] + ((int)R_s19a_dat_800C3628 + 8); CALL(R_DG_MovePos);
    r[4] = (u)r[29] + 16; CALL(R_ReadRotMatrix);
    r[4] = (u)r[29] + 16; CALL(R_s19a_800CC180);
    r[31] = *(int *)((u)r[29] + 48);
    r[29] = (u)r[29] + 56; goto out;
out:
    RECOMP_RETURN;
}
