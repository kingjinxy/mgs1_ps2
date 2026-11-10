extern char R_s18a_dat_800C3618[] __asm__("s18a_dat_800C3618");
extern char R_DG_MovePos[] __asm__("DG_MovePos");
extern char R_DG_SetPos[] __asm__("DG_SetPos");
extern char R_NewAnime[] __asm__("NewAnime");
extern char R_ReadRotMatrix[] __asm__("ReadRotMatrix");
int G_s18a_800D1BC4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D1BC4");
int G_s18a_800D1BC4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(88)
    r[29] = (u)r[29] + -88;
    r[2] = (u)0 + 18;
    *(short *)((u)r[29] + 74) = r[2];
    r[2] = (u)0 + 130;
    *(short *)((u)r[29] + 76) = r[2];
    r[2] = (u)r[29] + 24;
    *(int *)((u)r[29] + 80) = r[31];
    *(short *)((u)r[29] + 72) = 0;
    *(short *)((u)r[29] + 24) = 0;
    *(short *)((u)r[2] + 2) = 0;
    *(short *)((u)r[2] + 4) = 0; CALL(R_DG_SetPos);
    r[4] = (u)r[29] + 72; CALL(R_DG_MovePos);
    r[4] = (u)r[29] + 40; CALL(R_ReadRotMatrix);
    r[3] = (u)r[29] + 16;
    r[4] = (u)0 + (u)0;
    r[2] = *(unsigned short *)((u)r[29] + 60);
    r[6] = 0;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = *(unsigned short *)((u)r[29] + 64);
    r[6] = (u)r[6] + (int)R_s18a_dat_800C3618;
    *(short *)((u)r[3] + 2) = r[2];
    r[2] = *(unsigned short *)((u)r[29] + 68);
    r[5] = (u)r[4] + (u)0;
    *(short *)((u)r[3] + 4) = r[2];
    r[2] = (u)0 + 1;
    *(short *)((u)r[29] + 32) = r[2];
    *(short *)((u)r[29] + 34) = 0;
    *(int *)((u)r[6] + 20) = r[3]; CALL(R_NewAnime);
    r[31] = *(int *)((u)r[29] + 80);
    r[29] = (u)r[29] + 88; goto out;
out:
    RECOMP_RETURN;
}
