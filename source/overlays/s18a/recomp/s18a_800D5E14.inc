extern char R_s18a_dat_800E4348[] __asm__("s18a_dat_800E4348");
extern char R_GV_DiffDirS[] __asm__("GV_DiffDirS");
extern char R_GV_NearPhase[] __asm__("GV_NearPhase");
extern char R_GV_NearSpeed[] __asm__("GV_NearSpeed");
int G_s18a_800D5E14(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D5E14");
int G_s18a_800D5E14(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = 0;
    r[5] = *(int *)((u)r[17] + (int)R_s18a_dat_800E4348);
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    c = (((int)r[5] < 0)); *(int *)((u)r[29] + 16) = r[16]; if (c) goto L800d5e6c;
    r[16] = *(short *)((u)r[18] + 110);
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DiffDirS);
    c = ((r[2] == 0));  if (c) goto L800d5e6c;
    r[5] = *(int *)((u)r[17] + (int)R_s18a_dat_800E4348);
    r[4] = (u)r[16] + (u)0; CALL(R_GV_NearPhase);
    r[4] = (u)r[2] + (u)0;
    r[5] = *(int *)((u)r[17] + (int)R_s18a_dat_800E4348);
    r[6] = (u)0 + 64; CALL(R_GV_NearSpeed);
    *(short *)((u)r[18] + 110) = r[2];
    L800d5e6c:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
