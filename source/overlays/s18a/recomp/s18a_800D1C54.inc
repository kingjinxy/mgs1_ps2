extern char R_s18a_dat_800C3634[] __asm__("s18a_dat_800C3634");
extern char R_NewAnime[] __asm__("NewAnime");
int G_s18a_800D1C54(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D1C54");
int G_s18a_800D1C54(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(88)
    r[29] = (u)r[29] + -88;
    *(int *)((u)r[29] + 80) = r[31];
    r[2] = *(unsigned short *)((u)r[4] + 0);
    r[6] = 0;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 2);
    r[6] = (u)r[6] + (int)R_s18a_dat_800C3634;
    *(short *)((u)r[29] + 18) = r[2];
    r[3] = *(unsigned short *)((u)r[4] + 4);
    r[2] = (u)0 + 18;
    *(short *)((u)r[29] + 74) = r[2];
    r[2] = (u)0 + 130;
    *(short *)((u)r[29] + 76) = r[2];
    r[2] = (u)r[29] + 24;
    r[4] = (u)0 + (u)0;
    r[5] = (u)r[4] + (u)0;
    *(short *)((u)r[29] + 72) = 0;
    *(short *)((u)r[29] + 24) = 0;
    *(short *)((u)r[29] + 20) = r[3];
    *(short *)((u)r[2] + 2) = 0;
    *(short *)((u)r[2] + 4) = 0;
    r[2] = (u)r[29] + 16;
    *(short *)((u)r[29] + 32) = 0;
    *(short *)((u)r[29] + 34) = 0;
    *(int *)((u)r[6] + 20) = r[2]; CALL(R_NewAnime);
    r[31] = *(int *)((u)r[29] + 80);
    r[29] = (u)r[29] + 88; goto out;
out:
    RECOMP_RETURN;
}
