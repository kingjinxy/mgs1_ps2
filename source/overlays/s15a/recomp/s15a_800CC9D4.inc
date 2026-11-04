extern char R_s15a_dat_800C34B0[] __asm__("s15a_dat_800C34B0");
extern char R_s15a_dat_800C34E0[] __asm__("s15a_dat_800C34E0");
extern char R_DG_MovePos[] __asm__("DG_MovePos");
extern char R_DG_RotatePos[] __asm__("DG_RotatePos");
extern char R_DG_SetPos[] __asm__("DG_SetPos");
extern char R_GV_RandS[] __asm__("GV_RandS");
extern char R_NewBlood[] __asm__("NewBlood");
extern char R_ReadRotMatrix[] __asm__("ReadRotMatrix");
int G_s15a_800CC9D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CC9D4");
int G_s15a_800CC9D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(64)
    r[29] = (u)r[29] + -64;
    *(int *)((u)r[29] + 52) = r[17];
    r[17] = (u)r[6] + (u)0;
    r[2] = (u)r[5] << 1;
    r[2] = (u)r[2] + (u)r[5];
    r[2] = (u)r[2] << 3;
    r[2] = (u)r[2] - (u)r[5];
    r[2] = (u)r[2] << 2;
    *(int *)((u)r[29] + 56) = r[31];
    *(int *)((u)r[29] + 48) = r[16];
    r[4] = *(int *)((u)r[4] + 160);
    r[2] = (u)r[2] + 72;
    r[4] = (u)r[4] + (u)r[2]; CALL(R_DG_SetPos);
    r[4] = 0;
    r[4] = (u)r[4] + ((int)R_s15a_dat_800C34B0 + 40); CALL(R_DG_MovePos);
    r[4] = (u)0 + 128; CALL(R_GV_RandS);
    r[16] = 0;
    r[3] = *(unsigned short *)((u)r[16] + (int)R_s15a_dat_800C34E0);
    r[4] = (u)0 + 128;
    r[3] = (u)r[3] + (u)r[2];
    *(short *)((u)r[16] + (int)R_s15a_dat_800C34E0) = r[3];
    r[16] = (u)r[16] + (int)R_s15a_dat_800C34E0; CALL(R_GV_RandS);
    r[3] = *(unsigned short *)((u)r[16] + 2);
    r[4] = (u)0 + 512;
    r[3] = (u)r[3] + (u)r[2];
    *(short *)((u)r[16] + 2) = r[3]; CALL(R_GV_RandS);
    r[3] = *(unsigned short *)((u)r[16] + 4);
    r[4] = (u)r[16] + (u)0;
    r[3] = (u)r[3] + (u)r[2];
    *(short *)((u)r[4] + 4) = r[3]; CALL(R_DG_RotatePos);
    r[4] = (u)r[29] + 16; CALL(R_ReadRotMatrix);
    r[4] = (u)r[29] + 16;
    r[5] = (u)r[17] + (u)0; CALL(R_NewBlood);
    r[31] = *(int *)((u)r[29] + 56);
    r[17] = *(int *)((u)r[29] + 52);
    r[16] = *(int *)((u)r[29] + 48);
    r[29] = (u)r[29] + 64; goto out;
out:
    RECOMP_RETURN;
}
