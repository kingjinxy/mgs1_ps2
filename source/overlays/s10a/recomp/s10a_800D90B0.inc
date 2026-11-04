extern char R_s10a_dat_800C372C[] __asm__("s10a_dat_800C372C");
extern char R_DG_MovePos[] __asm__("DG_MovePos");
extern char R_DG_RotatePos[] __asm__("DG_RotatePos");
extern char R_DG_SetPos[] __asm__("DG_SetPos");
extern char R_NewBlood[] __asm__("NewBlood");
extern char R_ReadRotMatrix[] __asm__("ReadRotMatrix");
int G_s10a_800D90B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800D90B0");
int G_s10a_800D90B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(56)
    r[29] = (u)r[29] + -56;
    *(int *)((u)r[29] + 48) = r[16];
    r[16] = (u)r[6] + (u)0;
    r[2] = (u)r[5] << 1;
    r[2] = (u)r[2] + (u)r[5];
    r[2] = (u)r[2] << 3;
    r[2] = (u)r[2] - (u)r[5];
    r[2] = (u)r[2] << 2;
    *(int *)((u)r[29] + 52) = r[31];
    r[4] = *(int *)((u)r[4] + 160);
    r[2] = (u)r[2] + 72;
    r[4] = (u)r[4] + (u)r[2]; CALL(R_DG_SetPos);
    r[4] = 0;
    r[4] = (u)r[4] + ((int)R_s10a_dat_800C372C + 8); CALL(R_DG_MovePos);
    r[4] = 0;
    r[4] = (u)r[4] + ((int)R_s10a_dat_800C372C + 16); CALL(R_DG_RotatePos);
    r[4] = (u)r[29] + 16; CALL(R_ReadRotMatrix);
    r[4] = (u)r[29] + 16;
    r[5] = (u)r[16] + (u)0; CALL(R_NewBlood);
    r[31] = *(int *)((u)r[29] + 52);
    r[16] = *(int *)((u)r[29] + 48);
    r[29] = (u)r[29] + 56; goto out;
out:
    RECOMP_RETURN;
}
