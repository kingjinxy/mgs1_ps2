extern char R_s17a_dat_800C35B4[] __asm__("s17a_dat_800C35B4");
extern char R_NewAnime[] __asm__("NewAnime");
int G_s17a_800D5F8C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800D5F8C");
int G_s17a_800D5F8C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    r[3] = (u)r[29] + 16;
    *(int *)((u)r[29] + 40) = r[31];
    r[2] = *(unsigned short *)((u)r[4] + 20);
    r[6] = 0;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 24);
    r[6] = (u)r[6] + (int)R_s17a_dat_800C35B4;
    *(short *)((u)r[3] + 2) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 28);
    r[4] = (u)0 + (u)0;
    r[5] = (u)r[4] + (u)0;
    *(short *)((u)r[3] + 4) = r[2];
    r[2] = (u)r[29] + 24;
    *(short *)((u)r[29] + 24) = 0;
    *(short *)((u)r[2] + 2) = 0;
    *(short *)((u)r[2] + 4) = 0;
    r[2] = (u)0 + 1;
    *(short *)((u)r[29] + 32) = r[2];
    *(short *)((u)r[29] + 34) = 0;
    *(int *)((u)r[6] + 20) = r[3]; CALL(R_NewAnime);
    r[31] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
