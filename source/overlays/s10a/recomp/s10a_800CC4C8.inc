extern char R_GM_NoisePosition[] __asm__("GM_NoisePosition");
extern char R_GM_WhereList[] __asm__("GM_WhereList");
extern char R_s10a_dat_800E4AA4[] __asm__("s10a_dat_800E4AA4");
extern char R_HZD_GetAddress[] __asm__("HZD_GetAddress");
int G_s10a_800CC4C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CC4C8");
int G_s10a_800CC4C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_WhereList);
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = 0;
    *(int *)((u)r[29] + 24) = r[31];
    r[2] = *(int *)((u)r[2] + 44);
    r[5] = (u)r[17] + (int)R_GM_NoisePosition;
    r[4] = *(int *)((u)r[2] + 8);
    r[6] = (u)0 + -1; CALL(R_HZD_GetAddress);
    r[3] = 0;
    r[3] = *(int *)((u)r[3] + (int)R_s10a_dat_800E4AA4);
    *(int *)((u)r[16] + 3056) = r[2];
    r[10] = (u)r[17] + (int)R_GM_NoisePosition;
    r[7] = LWL(((u)r[10] + 3), r[7]);
    r[7] = LWR(((u)r[10] + 0), r[7]);
    r[8] = LWL(((u)r[10] + 7), r[8]);
    r[8] = LWR(((u)r[10] + 4), r[8]);
    SWL(((u)r[16] + 3039), r[7]);
    SWR(((u)r[16] + 3036), r[7]);
    SWL(((u)r[16] + 3043), r[8]);
    SWR(((u)r[16] + 3040), r[8]);
    *(int *)((u)r[16] + 3060) = r[3];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
