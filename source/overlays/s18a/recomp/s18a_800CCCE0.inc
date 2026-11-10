extern char R_s18a_dat_800C339C[] __asm__("s18a_dat_800C339C");
extern char R_s18a_dat_800C33DC[] __asm__("s18a_dat_800C33DC");
extern char R_GV_DiffVec3[] __asm__("GV_DiffVec3");
int G_s18a_800CCCE0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CCCE0");
int G_s18a_800CCCE0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] << 4;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = 0;
    r[17] = (u)r[17] + (int)R_s18a_dat_800C339C;
    r[17] = (u)r[16] + (u)r[17];
    r[4] = (u)r[17] + (u)0;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 28) = r[19]; CALL(R_GV_DiffVec3);
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_s18a_dat_800C33DC;
    r[19] = (u)r[16] + (u)r[3];
    r[4] = (u)r[19] + (u)0;
    r[5] = (u)r[18] + (u)0;
    r[16] = (u)r[2] + (u)0; CALL(R_GV_DiffVec3);
    r[16] = (int)r[16] < (int)r[2];
    c = ((r[16] != 0)); r[2] = (u)r[17] + (u)0; if (c) goto L800ccd40;
    r[2] = (u)r[19] + (u)0;
    L800ccd40:;
    r[31] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
