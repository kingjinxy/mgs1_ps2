extern char R_s19a_dat_800C38E4[] __asm__("s19a_dat_800C38E4");
extern char R_s19a_dat_800C38EC[] __asm__("s19a_dat_800C38EC");
extern char R_DG_SetPos[] __asm__("DG_SetPos");
extern char R_GM_SeSet[] __asm__("GM_SeSet");
extern char R_MulMatrix0[] __asm__("MulMatrix0");
extern char R_NewBullet[] __asm__("NewBullet");
extern char R_RotMatrix[] __asm__("RotMatrix");
extern char R_s19a_800DC0D4[] __asm__("s19a_800DC0D4");
extern char R_s19a_800DF2C8[] __asm__("s19a_800DF2C8");
int G_s19a_800DA8A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DA8A0");
int G_s19a_800DA8A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(72)
    r[29] = (u)r[29] + -72;
    *(int *)((u)r[29] + 64) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s19a_dat_800C38EC;
    *(int *)((u)r[29] + 68) = r[31];
    r[5] = (u)r[29] + 16; CALL(R_RotMatrix);
    r[16] = (u)r[16] + 2276;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[29] + 16;
    r[6] = (u)r[5] + (u)0; CALL(R_MulMatrix0);
    r[4] = (u)r[16] + (u)0; CALL(R_DG_SetPos);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s19a_dat_800C38E4;
    r[5] = (u)r[29] + 36;
    r[6] = (u)r[29] + 56; CALL(R_s19a_800DF2C8);
    r[4] = (u)r[29] + 16;
    r[5] = (u)0 + 1;
    r[6] = (u)r[5] + (u)0;
    r[7] = (u)0 + (u)0; CALL(R_NewBullet);
    r[4] = (u)r[29] + 48;
    r[2] = *(unsigned short *)((u)r[29] + 36);
    r[3] = *(unsigned short *)((u)r[29] + 40);
    r[6] = *(unsigned short *)((u)r[29] + 44);
    r[5] = (u)0 + 46;
    *(short *)((u)r[29] + 48) = r[2];
    *(short *)((u)r[29] + 50) = r[3];
    *(short *)((u)r[29] + 52) = r[6]; CALL(R_GM_SeSet);
    r[4] = (u)r[29] + 16; CALL(R_s19a_800DC0D4);
    r[31] = *(int *)((u)r[29] + 68);
    r[16] = *(int *)((u)r[29] + 64);
    r[29] = (u)r[29] + 72; goto out;
out:
    RECOMP_RETURN;
}
