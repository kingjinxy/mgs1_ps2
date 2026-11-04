extern char R_DG_PaletteBuffer[] __asm__("DG_PaletteBuffer");
extern char R_s10a_dat_800C3844[] __asm__("s10a_dat_800C3844");
extern char R_DrawSync[] __asm__("DrawSync");
extern char R_LoadImage2[] __asm__("LoadImage2");
extern char R_StoreImage2[] __asm__("StoreImage2");
extern char R_s10a_800E2C5C[] __asm__("s10a_800E2C5C");
int G_s10a_800E2CD4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800E2CD4");
int G_s10a_800E2CD4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(56)
    r[29] = (u)r[29] + -56;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)0 + 15;
    r[2] = 0;
    *(int *)((u)r[29] + 44) = r[23];
    r[23] = (u)r[2] + (u)0;
    *(int *)((u)r[29] + 40) = r[22];
    r[22] = 0;
    *(int *)((u)r[29] + 36) = r[21];
    r[21] = (u)r[22] + (int)R_DG_PaletteBuffer;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s10a_dat_800C3844;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[2] + (u)0;
    r[2] = (u)r[23] + ((int)R_s10a_dat_800C3844 + 8);
    *(int *)((u)r[29] + 32) = r[20];
    r[20] = (u)r[2] + (u)0;
    r[2] = (u)0 + 226;
    *(int *)((u)r[29] + 48) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16];
    *(short *)((u)r[18] + 2) = r[2];
    r[2] = (u)0 + 196;
    *(short *)((u)r[20] + 2) = r[2];
    L800e2d34:;
    r[4] = (u)0 + (u)0; CALL(R_DrawSync);
    r[4] = (u)r[23] + ((int)R_s10a_dat_800C3844 + 8);
    r[5] = (u)r[21] + (u)0; CALL(R_StoreImage2);
    r[4] = (u)0 + (u)0; CALL(R_DrawSync);
    r[16] = (u)r[21] + (u)0;
    r[17] = (u)0 + 512;
    L800e2d58:;
    r[4] = *(unsigned short *)((u)r[16] + 0);
    r[17] = (u)r[17] + -1; CALL(R_s10a_800E2C5C);
    *(short *)((u)r[16] + 0) = r[2];
    c = (((int)r[17] > 0)); r[16] = (u)r[16] + 2; if (c) goto L800e2d58;
    r[4] = (u)r[18] + (u)0;
    r[5] = (u)r[22] + (int)R_DG_PaletteBuffer; CALL(R_LoadImage2);
    r[19] = (u)r[19] + -1;
    r[2] = *(unsigned short *)((u)r[20] + 2);
    r[3] = *(unsigned short *)((u)r[18] + 2);
    r[2] = (u)r[2] + 2;
    r[3] = (u)r[3] + 2;
    *(short *)((u)r[20] + 2) = r[2];
    c = (((int)r[19] > 0)); *(short *)((u)r[18] + 2) = r[3]; if (c) goto L800e2d34;
    r[31] = *(int *)((u)r[29] + 48);
    r[23] = *(int *)((u)r[29] + 44);
    r[22] = *(int *)((u)r[29] + 40);
    r[21] = *(int *)((u)r[29] + 36);
    r[20] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 56; goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800E2DC8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_rc_800E2DC8");
int G_s10a_rc_800E2DC8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
