extern char R_s18a_800CC4F0[] __asm__("s18a_800CC4F0");
extern char R_s18a_dat_800C3388[] __asm__("s18a_dat_800C3388");
extern char R_AN_SocomFlash[] __asm__("AN_SocomFlash");
extern char R_DG_MovePos[] __asm__("DG_MovePos");
extern char R_DG_SetPos[] __asm__("DG_SetPos");
extern char R_GM_SeSet[] __asm__("GM_SeSet");
extern char R_ReadRotMatrix[] __asm__("ReadRotMatrix");
extern char R_s18a_800CC6A8[] __asm__("s18a_800CC6A8");
int G_s18a_800CC4F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CC4F0");
int G_s18a_800CC4F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(64)
    r[29] = (u)r[29] + -64;
    *(int *)((u)r[29] + 52) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 56) = r[31];
    *(int *)((u)r[29] + 48) = r[16];
    r[16] = *(int *)((u)r[17] + 156);
    r[16] = (u)r[16] + 440;
    r[4] = (u)r[16] + (u)0; CALL(R_DG_SetPos);
    r[4] = 0;
    r[4] = (u)r[4] + ((int)R_s18a_dat_800C3388 + 12); CALL(R_DG_MovePos);
    r[4] = (u)r[29] + 16; CALL(R_ReadRotMatrix);
    r[4] = (u)r[17] + 32;
    r[5] = (u)0 + 73; CALL(R_GM_SeSet);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[29] + 16;
    r[6] = (u)0 + (u)0; CALL(R_AN_SocomFlash);
    r[4] = (u)r[17] + (u)0;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s18a_800CC4F0; CALL(R_s18a_800CC6A8);
    r[31] = *(int *)((u)r[29] + 56);
    r[17] = *(int *)((u)r[29] + 52);
    r[16] = *(int *)((u)r[29] + 48);
    r[29] = (u)r[29] + 64; goto out;
out:
    RECOMP_RETURN;
}
