extern char R_s17a_dat_800C5420[] __asm__("s17a_dat_800C5420");
extern char R_DG_MovePos[] __asm__("DG_MovePos");
extern char R_DG_SetPos[] __asm__("DG_SetPos");
extern char R_ReadRotMatrix[] __asm__("ReadRotMatrix");
extern char R_SetRotMatrix[] __asm__("SetRotMatrix");
extern char R_s17a_800E4BA8[] __asm__("s17a_800E4BA8");
extern char R_s17a_800E4F38[] __asm__("s17a_800E4F38");
int G_s17a_800E2AF8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800E2AF8");
int G_s17a_800E2AF8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(56)
    r[29] = (u)r[29] + -56;
    *(int *)((u)r[29] + 48) = r[16];
    *(int *)((u)r[29] + 52) = r[31];
    r[16] = (u)r[5] + (u)0; CALL(R_DG_SetPos);
    r[4] = 0;
    r[4] = (u)r[4] + ((int)R_s17a_dat_800C5420 + 8); CALL(R_DG_MovePos);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s17a_dat_800C5420;
    r[5] = (u)r[29] + 16; CALL(R_s17a_800E4F38);
    r[4] = (u)r[29] + 16;
    r[5] = (u)r[16] + (u)0; CALL(R_s17a_800E4BA8);
    r[4] = (u)r[16] + (u)0; CALL(R_SetRotMatrix);
    r[4] = (u)r[16] + (u)0; CALL(R_ReadRotMatrix);
    r[31] = *(int *)((u)r[29] + 52);
    r[16] = *(int *)((u)r[29] + 48);
    r[29] = (u)r[29] + 56; goto out;
out:
    RECOMP_RETURN;
}
