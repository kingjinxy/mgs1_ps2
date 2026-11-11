extern char R_s19a_dat_800C3628[] __asm__("s19a_dat_800C3628");
extern char R_DG_MovePos[] __asm__("DG_MovePos");
extern char R_DG_RotatePos[] __asm__("DG_RotatePos");
extern char R_DG_SetPos[] __asm__("DG_SetPos");
extern char R_ReadRotMatrix[] __asm__("ReadRotMatrix");
extern char R_s19a_800D2544[] __asm__("s19a_800D2544");
int G_s19a_800D15D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D15D4");
int G_s19a_800D15D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(64)
    r[29] = (u)r[29] + -64;
    *(int *)((u)r[29] + 56) = r[31];
    r[4] = *(int *)((u)r[4] + 156);
    r[4] = (u)r[4] + 164; CALL(R_DG_SetPos);
    r[4] = 0;
    r[4] = (u)r[4] + ((int)R_s19a_dat_800C3628 + 32); CALL(R_DG_MovePos);
    r[4] = 0;
    r[4] = (u)r[4] + ((int)R_s19a_dat_800C3628 + 40); CALL(R_DG_RotatePos);
    r[4] = (u)r[29] + 16; CALL(R_ReadRotMatrix);
    r[2] = *(unsigned short *)((u)r[29] + 36);
    r[3] = *(unsigned short *)((u)r[29] + 40);
    r[5] = *(unsigned short *)((u)r[29] + 44);
    r[4] = (u)r[29] + 48;
    *(short *)((u)r[29] + 48) = r[2];
    *(short *)((u)r[29] + 50) = r[3];
    *(short *)((u)r[29] + 52) = r[5]; CALL(R_s19a_800D2544);
    r[31] = *(int *)((u)r[29] + 56);
    r[29] = (u)r[29] + 64; goto out;
out:
    RECOMP_RETURN;
}
