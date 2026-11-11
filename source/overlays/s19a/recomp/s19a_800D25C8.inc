extern char R_DG_ZeroVector[] __asm__("DG_ZeroVector");
extern char R_s19a_dat_800C3698[] __asm__("s19a_dat_800C3698");
extern char R_NewAnime[] __asm__("NewAnime");
int G_s19a_800D25C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D25C8");
int G_s19a_800D25C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 44) = r[31];
    *(int *)((u)r[29] + 40) = r[16];
    r[3] = LWL(((u)r[4] + 3), r[3]);
    r[3] = LWR(((u)r[4] + 0), r[3]);
    r[7] = LWL(((u)r[4] + 7), r[7]);
    r[7] = LWR(((u)r[4] + 4), r[7]);
    SWL(((u)r[29] + 19), r[3]);
    SWR(((u)r[29] + 16), r[3]);
    SWL(((u)r[29] + 23), r[7]);
    SWR(((u)r[29] + 20), r[7]);
    r[4] = (u)0 + (u)0;
    r[5] = (u)r[4] + (u)0;
    r[16] = 0;
    r[16] = (u)r[16] + (int)R_s19a_dat_800C3698;
    r[6] = (u)r[16] + (u)0;
    r[2] = 0;
    r[9] = (u)r[2] + (int)R_DG_ZeroVector;
    r[3] = LWL(((u)r[9] + 3), r[3]);
    r[3] = LWR(((u)r[9] + 0), r[3]);
    r[7] = LWL(((u)r[9] + 7), r[7]);
    r[7] = LWR(((u)r[9] + 4), r[7]);
    SWL(((u)r[29] + 27), r[3]);
    SWR(((u)r[29] + 24), r[3]);
    SWL(((u)r[29] + 31), r[7]);
    SWR(((u)r[29] + 28), r[7]);
    r[2] = (u)r[29] + 16;
    *(short *)((u)r[29] + 34) = 0;
    *(int *)((u)r[16] + 20) = r[2];
    *(short *)((u)r[29] + 32) = 0; CALL(R_NewAnime);
    r[4] = (u)0 + (u)0;
    r[5] = (u)r[4] + (u)0;
    r[6] = (u)r[16] + (u)0;
    r[2] = (u)0 + 1;
    *(short *)((u)r[29] + 32) = r[2]; CALL(R_NewAnime);
    r[4] = (u)0 + (u)0;
    r[5] = (u)r[4] + (u)0;
    r[6] = (u)r[16] + (u)0;
    r[2] = (u)0 + 2;
    *(short *)((u)r[29] + 32) = r[2]; CALL(R_NewAnime);
    r[31] = *(int *)((u)r[29] + 44);
    r[16] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
