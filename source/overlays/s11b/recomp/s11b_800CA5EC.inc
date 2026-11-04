extern char R_s11b_dat_800C33F4[] __asm__("s11b_dat_800C33F4");
extern char R_s11b_dat_800C3464[] __asm__("s11b_dat_800C3464");
extern char R_NewAnime[] __asm__("NewAnime");
extern char R_memset[] __asm__("memset");
int G_s11b_800CA5EC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800CA5EC");
int G_s11b_800CA5EC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 40) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)r[29] + 16;
    r[5] = (u)0 + (u)0;
    *(int *)((u)r[29] + 44) = r[31];
    r[6] = (u)0 + 20; CALL(R_memset);
    r[2] = 0;
    r[6] = (u)r[2] + (int)R_s11b_dat_800C3464;
    r[4] = (u)0 + (u)0;
    r[5] = (u)r[4] + (u)0;
    r[3] = LWL(((u)r[16] + 3), r[3]);
    r[3] = LWR(((u)r[16] + 0), r[3]);
    r[7] = LWL(((u)r[16] + 7), r[7]);
    r[7] = LWR(((u)r[16] + 4), r[7]);
    SWL(((u)r[29] + 19), r[3]);
    SWR(((u)r[29] + 16), r[3]);
    SWL(((u)r[29] + 23), r[7]);
    SWR(((u)r[29] + 20), r[7]);
    r[16] = (u)r[29] + 16;
    *(int *)((u)r[6] + 20) = r[16]; CALL(R_NewAnime);
    r[2] = 0;
    r[6] = (u)r[2] + (int)R_s11b_dat_800C33F4;
    r[4] = (u)0 + (u)0;
    r[5] = (u)r[4] + (u)0;
    *(int *)((u)r[6] + 20) = r[16]; CALL(R_NewAnime);
    r[31] = *(int *)((u)r[29] + 44);
    r[16] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
