extern char R_DG_PutVector[] __asm__("DG_PutVector");
extern char R_DG_SetPos2[] __asm__("DG_SetPos2");
extern char R_DG_SetTmpLight[] __asm__("DG_SetTmpLight");
extern char R_GV_RandU[] __asm__("GV_RandU");
int G_s15a_800CB24C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CB24C");
int G_s15a_800CB24C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 32) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)0 + 512;
    *(int *)((u)r[29] + 36) = r[17];
    *(int *)((u)r[29] + 40) = r[31];
    r[17] = (u)r[16] + 36; CALL(R_GV_RandU);
    r[4] = (u)0 + 512;
    *(short *)((u)r[29] + 16) = r[2]; CALL(R_GV_RandU);
    r[4] = (u)0 + 256;
    r[2] = (u)r[2] + (u)r[4];
    *(short *)((u)r[29] + 18) = r[2];
    r[2] = (u)0 + 500;
    *(short *)((u)r[29] + 20) = r[2]; CALL(R_GV_RandU);
    r[4] = (u)0 + 256;
    *(short *)((u)r[29] + 24) = r[2]; CALL(R_GV_RandU);
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[16] + 44;
    *(short *)((u)r[29] + 26) = r[2];
    r[2] = (u)0 + 200;
    *(short *)((u)r[29] + 28) = r[2]; CALL(R_DG_SetPos2);
    r[4] = (u)r[29] + 16;
    r[5] = (u)r[4] + (u)0;
    r[6] = (u)0 + 2; CALL(R_DG_PutVector);
    r[4] = (u)r[29] + 16;
    r[5] = (u)0 + 500;
    r[6] = (u)0 + 1000; CALL(R_DG_SetTmpLight);
    r[4] = (u)r[29] + 16;
    r[5] = (u)0 + 500;
    r[6] = (u)r[5] + (u)0; CALL(R_DG_SetTmpLight);
    r[31] = *(int *)((u)r[29] + 40);
    r[17] = *(int *)((u)r[29] + 36);
    r[16] = *(int *)((u)r[29] + 32);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
