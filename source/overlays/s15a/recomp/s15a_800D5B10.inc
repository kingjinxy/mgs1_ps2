extern char R_DG_ZeroMatrix[] __asm__("DG_ZeroMatrix");
extern char R_DG_SetPos[] __asm__("DG_SetPos");
extern char R_s15a_800D5AF0[] __asm__("s15a_800D5AF0");
int G_s15a_800D5B10(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D5B10");
int G_s15a_800D5B10(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    r[4] = 0;
    *(int *)((u)r[29] + 24) = r[31];
    r[4] = (u)r[4] + (int)R_DG_ZeroMatrix; CALL(R_DG_SetPos);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0; CALL(R_s15a_800D5AF0);
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
