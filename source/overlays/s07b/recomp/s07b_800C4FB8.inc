extern char R_s07b_dword_800C3318[] __asm__("s07b_dword_800C3318");
extern char R_AN_SocomFlash[] __asm__("AN_SocomFlash");
extern char R_DG_MovePos[] __asm__("DG_MovePos");
extern char R_DG_SetPos[] __asm__("DG_SetPos");
extern char R_ReadRotMatrix[] __asm__("ReadRotMatrix");
int G_s07b_800C4FB8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800C4FB8");
int G_s07b_800C4FB8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(56)
    r[29] = (u)r[29] + -56;
    *(int *)((u)r[29] + 52) = r[31];
    *(int *)((u)r[29] + 48) = r[16];
    r[16] = *(int *)((u)r[4] + 156);
    r[16] = (u)r[16] + 440;
    r[4] = (u)r[16] + (u)0; CALL(R_DG_SetPos);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s07b_dword_800C3318; CALL(R_DG_MovePos);
    r[4] = (u)r[29] + 16; CALL(R_ReadRotMatrix);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[29] + 16;
    r[6] = (u)0 + (u)0; CALL(R_AN_SocomFlash);
    r[31] = *(int *)((u)r[29] + 52);
    r[16] = *(int *)((u)r[29] + 48);
    r[29] = (u)r[29] + 56; goto out;
out:
    RECOMP_RETURN;
}
