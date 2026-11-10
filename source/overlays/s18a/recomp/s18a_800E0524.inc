extern char R_s18a_dat_800C3CBC[] __asm__("s18a_dat_800C3CBC");
extern char R_GV_RandU[] __asm__("GV_RandU");
extern char R_NewAnime[] __asm__("NewAnime");
int G_s18a_800E0524(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800E0524");
int G_s18a_800E0524(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 40) = r[31];
    r[7] = LWL(((u)r[4] + 3), r[7]);
    r[7] = LWR(((u)r[4] + 0), r[7]);
    r[8] = LWL(((u)r[4] + 7), r[8]);
    r[8] = LWR(((u)r[4] + 4), r[8]);
    SWL(((u)r[29] + 19), r[7]);
    SWR(((u)r[29] + 16), r[7]);
    SWL(((u)r[29] + 23), r[8]);
    SWR(((u)r[29] + 20), r[8]);
    r[4] = (u)0 + 128;
    *(short *)((u)r[29] + 24) = 0; CALL(R_GV_RandU);
    r[4] = (u)0 + (u)0;
    r[3] = (u)r[29] + 24;
    r[2] = (u)r[2] + 64;
    *(short *)((u)r[3] + 2) = r[2];
    r[2] = (u)0 + 1;
    *(short *)((u)r[3] + 4) = 0;
    *(short *)((u)r[29] + 32) = r[2];
    r[2] = (u)r[29] + 16;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s18a_dat_800C3CBC;
    r[5] = (u)r[4] + (u)0;
    *(short *)((u)r[29] + 34) = 0;
    *(int *)((u)r[6] + 20) = r[2]; CALL(R_NewAnime);
    r[31] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
