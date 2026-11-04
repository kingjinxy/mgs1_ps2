extern char R_GM_PlayerAddress[] __asm__("GM_PlayerAddress");
extern char R_GM_PlayerMap[] __asm__("GM_PlayerMap");
extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_s10a_dat_800E4AA0[] __asm__("s10a_dat_800E4AA0");
extern char R_s10a_dat_800E4AA4[] __asm__("s10a_dat_800E4AA4");
extern char R_s10a_dat_800E4AA8[] __asm__("s10a_dat_800E4AA8");
int G_s10a_800CE9E0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800CE9E0");
int G_s10a_800CE9E0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_GM_PlayerAddress);
    r[4] = r[3] & 255;
    r[2] = (int)r[3] >> 8;
    r[2] = r[2] & 255;
    c = ((r[4] != r[2])); r[2] = (u)0 + 255; if (c) goto L800cea4c;
    c = ((r[4] == r[2])); r[2] = 0; if (c) goto L800cea4c;
    *(int *)((u)r[2] + (int)R_s10a_dat_800E4AA0) = r[3];
    r[3] = 0;
    r[2] = 0;
    r[8] = (u)r[2] + (int)R_GM_PlayerPosition;
    r[7] = (u)r[3] + (int)R_s10a_dat_800E4AA8;
    r[5] = LWL(((u)r[8] + 3), r[5]);
    r[5] = LWR(((u)r[8] + 0), r[5]);
    r[6] = LWL(((u)r[8] + 7), r[6]);
    r[6] = LWR(((u)r[8] + 4), r[6]);
    SWL(((u)r[7] + 3), r[5]);
    SWR(((u)r[7] + 0), r[5]);
    SWL(((u)r[7] + 7), r[6]);
    SWR(((u)r[7] + 4), r[6]);
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_GM_PlayerMap);
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s10a_dat_800E4AA4) = r[3];
    L800cea4c:;
     goto out;
out:
    RECOMP_RETURN;
}
