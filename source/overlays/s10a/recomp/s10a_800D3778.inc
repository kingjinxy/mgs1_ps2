extern char R_DG_ZeroVector[] __asm__("DG_ZeroVector");
extern char R_s10a_dat_800C370C[] __asm__("s10a_dat_800C370C");
extern char R_GV_RandU[] __asm__("GV_RandU");
extern char R_NewAnime[] __asm__("NewAnime");
int G_s10a_800D3778(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D3778");
int G_s10a_800D3778(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
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
    r[4] = (u)0 + 1024;
    r[2] = 0;
    r[10] = (u)r[2] + (int)R_DG_ZeroVector;
    r[7] = LWL(((u)r[10] + 3), r[7]);
    r[7] = LWR(((u)r[10] + 0), r[7]);
    r[8] = LWL(((u)r[10] + 7), r[8]);
    r[8] = LWR(((u)r[10] + 4), r[8]);
    SWL(((u)r[29] + 27), r[7]);
    SWR(((u)r[29] + 24), r[7]);
    SWL(((u)r[29] + 31), r[8]);
    SWR(((u)r[29] + 28), r[8]);
    *(short *)((u)r[29] + 32) = r[5]; CALL(R_GV_RandU);
    r[3] = 0x88880000;
    r[3] = r[3] | 34953;
    mul = (long long)(int)r[2] * (int)r[3]; hi_ = mul >> 32; lo_ = mul;
    r[4] = (u)0 + (u)0;
    r[3] = (u)r[29] + 16;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s10a_dat_800C370C;
    *(int *)((u)r[6] + 20) = r[3];
    r[3] = (int)r[2] >> 31;
    r[7] = hi_;
    r[5] = (u)r[7] + (u)r[2];
    r[5] = (int)r[5] >> 4;
    r[5] = (u)r[5] - (u)r[3];
    r[3] = (u)r[5] << 4;
    r[3] = (u)r[3] - (u)r[5];
    r[3] = (u)r[3] << 1;
    r[2] = (u)r[2] - (u)r[3];
    r[5] = (u)r[4] + (u)0;
    *(short *)((u)r[29] + 34) = r[2]; CALL(R_NewAnime);
    r[31] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    return r[2];
}
