extern char R_s19a_dat_800C34CC[] __asm__("s19a_dat_800C34CC");
extern char R_NewAnime[] __asm__("NewAnime");
int G_s19a_800CC0AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CC0AC");
int G_s19a_800CC0AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    r[3] = (u)0 + 10;
    *(int *)((u)r[29] + 40) = r[31];
    r[2] = *(unsigned short *)((u)r[4] + 20);
    r[6] = 0;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 24);
    r[6] = (u)r[6] + (int)R_s19a_dat_800C34CC;
    *(short *)((u)r[29] + 18) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 28);
    r[4] = (u)0 + (u)0;
    r[5] = (u)r[4] + (u)0;
    *(short *)((u)r[29] + 24) = r[3];
    *(short *)((u)r[29] + 20) = r[2];
    r[2] = (u)r[29] + 24;
    *(short *)((u)r[2] + 2) = r[3];
    *(short *)((u)r[2] + 4) = 0;
    r[2] = (u)r[29] + 16;
    *(short *)((u)r[29] + 32) = 0;
    *(short *)((u)r[29] + 34) = 0;
    *(int *)((u)r[6] + 20) = r[2]; CALL(R_NewAnime);
    r[31] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
