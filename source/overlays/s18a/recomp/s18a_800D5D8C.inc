extern char R_GM_SnakeCamera[] __asm__("GM_SnakeCamera");
extern char R_DG_MatrixRotZYX[] __asm__("DG_MatrixRotZYX");
extern char R_DG_TransposeMatrix[] __asm__("DG_TransposeMatrix");
extern char R_MulMatrix0[] __asm__("MulMatrix0");
extern char R_ReadRotMatrix[] __asm__("ReadRotMatrix");
extern char R_SetRotMatrix[] __asm__("SetRotMatrix");
int G_s18a_800D5D8C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D5D8C");
int G_s18a_800D5D8C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(104)
    r[29] = (u)r[29] + -104;
    *(int *)((u)r[29] + 96) = r[31];
    *(int *)((u)r[29] + 92) = r[17];
    *(int *)((u)r[29] + 88) = r[16];
    r[17] = *(int *)((u)r[4] + 156);
    r[4] = (u)r[29] + 16;
    r[17] = (u)r[17] + 624; CALL(R_ReadRotMatrix);
    r[4] = (u)r[29] + 16;
    r[16] = (u)r[29] + 48;
    r[5] = (u)r[16] + (u)0; CALL(R_DG_TransposeMatrix);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)r[16] + (u)0; CALL(R_MulMatrix0);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[29] + 80; CALL(R_DG_MatrixRotZYX);
    r[4] = (u)r[29] + 16; CALL(R_SetRotMatrix);
    r[3] = *(short *)((u)r[29] + 80);
    c = (((int)r[3] >= 0));  if (c) goto L800d5df4;
    r[3] = (u)r[3] + 15;
    L800d5df4:;
    r[3] = r[3] & 65520;
    r[31] = *(int *)((u)r[29] + 96);
    r[17] = *(int *)((u)r[29] + 92);
    r[16] = *(int *)((u)r[29] + 88);
    r[2] = 0;
    *(short *)((u)r[2] + ((int)R_GM_SnakeCamera + 40)) = r[3];
    r[29] = (u)r[29] + 104; goto out;
out:
    RECOMP_RETURN;
}
