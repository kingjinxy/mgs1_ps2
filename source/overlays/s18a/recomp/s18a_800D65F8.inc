extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_bakudan_count_8009F42C[] __asm__("bakudan_count_8009F42C");
extern char R_s18a_dat_800E434C[] __asm__("s18a_dat_800E434C");
extern char R_s18a_rc_800DCB40[] __asm__("s18a_rc_800DCB40");
extern char R_s18a_800D5A40[] __asm__("s18a_800D5A40");
int G_s18a_800D65F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D65F8");
int G_s18a_800D65F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[3] = *(int *)((u)r[16] + 2148);
    r[2] = (u)0 + 6;
    c = ((r[3] != r[2]));  if (c) goto L800d66bc;
    r[2] = *(int *)((u)r[16] + 2144);
    r[2] = *(short *)((u)r[2] + 0);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d66bc;
    r[2] = *(int *)((u)r[2] + (int)R_bakudan_count_8009F42C);
    r[2] = (int)r[2] < 16;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d66bc;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 16;
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800d6668;
    r[2] = *(unsigned short *)((u)r[2] + (int)R_s18a_dat_800E434C);
    *(short *)((u)r[16] + 110) = r[2];
    L800d6668:;
    r[2] = *(int *)((u)r[16] + 2212);
    r[2] = *(unsigned short *)((u)r[2] + 2);
    r[2] = r[2] & 128;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d66bc;
    r[3] = *(int *)((u)r[16] + 2228);
    r[17] = (u)r[2] + (int)R_s18a_rc_800DCB40;
    c = ((r[3] == r[17]));  if (c) goto L800d66bc;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D5A40);
    c = (((int)r[2] <= 0)); r[2] = (u)0 + 450; if (c) goto L800d66bc;
    r[3] = *(int *)((u)r[16] + 2020);
    *(short *)((u)r[16] + 2304) = r[2];
    *(int *)((u)r[16] + 2228) = r[17];
    *(int *)((u)r[16] + 2232) = 0;
    r[3] = r[3] | 256;
    *(int *)((u)r[16] + 2020) = r[3];
    L800d66bc:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
