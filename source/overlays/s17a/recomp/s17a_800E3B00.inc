extern char R_s17a_dat_800C5694[] __asm__("s17a_dat_800C5694");
extern char R_s17a_dat_800C56B4[] __asm__("s17a_dat_800C56B4");
extern char R_DG_SetPos[] __asm__("DG_SetPos");
extern char R_s17a_800E377C[] __asm__("s17a_800E377C");
extern char R_s17a_800E39FC[] __asm__("s17a_800E39FC");
int G_s17a_800E3B00(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800E3B00");
int G_s17a_800E3B00(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[4] = *(int *)((u)r[17] + 384);
    r[16] = (u)r[5] + (u)0;
    r[4] = (u)r[4] + 808; CALL(R_DG_SetPos);
    r[4] = (int)PSX_ADDR(0x1f800000);
    r[4] = r[4] | 64;
    r[5] = (int)PSX_ADDR(0x1f800000);
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s17a_dat_800C5694;
    r[7] = (u)0 + 4; CALL(R_s17a_800E39FC);
    r[4] = (int)PSX_ADDR(0x1f800000);
    r[4] = r[4] | 64;
    r[5] = (u)r[16] + (u)0;
    r[6] = (u)0 + 4; CALL(R_s17a_800E377C);
    r[4] = *(int *)((u)r[17] + 612);
    r[16] = (u)r[16] + 64;
    r[4] = (u)r[4] + 808; CALL(R_DG_SetPos);
    r[4] = (int)PSX_ADDR(0x1f800000);
    r[4] = r[4] | 64;
    r[5] = (int)PSX_ADDR(0x1f800000);
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s17a_dat_800C56B4;
    r[7] = (u)0 + 4; CALL(R_s17a_800E39FC);
    r[4] = (int)PSX_ADDR(0x1f800000);
    r[4] = r[4] | 64;
    r[5] = (u)r[16] + (u)0;
    r[6] = (u)0 + 4; CALL(R_s17a_800E377C);
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
