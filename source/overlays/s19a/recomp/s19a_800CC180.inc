extern char R_s19a_dat_800C34E8[] __asm__("s19a_dat_800C34E8");
extern char R_GV_RandS[] __asm__("GV_RandS");
extern char R_GV_RandU[] __asm__("GV_RandU");
extern char R_NewAnime[] __asm__("NewAnime");
int G_s19a_800CC180(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CC180");
int G_s19a_800CC180(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 44) = r[31];
    *(int *)((u)r[29] + 40) = r[16];
    r[2] = *(unsigned short *)((u)r[4] + 20);
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 24);
    *(short *)((u)r[29] + 18) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 28);
    r[4] = (u)0 + 16;
    *(short *)((u)r[29] + 20) = r[2]; CALL(R_GV_RandU);
    r[4] = (u)0 + 16;
    *(short *)((u)r[29] + 24) = r[2]; CALL(R_GV_RandS);
    r[4] = (u)0 + 8;
    r[16] = (u)r[29] + 24;
    r[2] = (u)r[2] + 20;
    *(short *)((u)r[16] + 2) = r[2]; CALL(R_GV_RandS);
    r[4] = (u)0 + (u)0;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s19a_dat_800C34E8;
    *(short *)((u)r[16] + 4) = r[2];
    r[2] = (u)r[29] + 16;
    r[5] = (u)r[4] + (u)0;
    *(short *)((u)r[29] + 32) = 0;
    *(short *)((u)r[29] + 34) = 0;
    *(int *)((u)r[6] + 20) = r[2]; CALL(R_NewAnime);
    r[31] = *(int *)((u)r[29] + 44);
    r[16] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
