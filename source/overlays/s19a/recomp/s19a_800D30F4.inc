extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_s19a_dat_800E0B38[] __asm__("s19a_dat_800E0B38");
int G_s19a_800D30F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D30F4");
int G_s19a_800D30F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[4] = (u)r[2] + (int)R_s19a_dat_800E0B38;
    r[2] = *(short *)((u)r[4] + 384);
    r[3] = 0;
    r[2] = (u)r[2] << 3;
    r[2] = (u)r[2] + (u)r[4];
    r[8] = (u)r[3] + (int)R_GM_PlayerPosition;
    r[5] = LWL(((u)r[8] + 3), r[5]);
    r[5] = LWR(((u)r[8] + 0), r[5]);
    r[6] = LWL(((u)r[8] + 7), r[6]);
    r[6] = LWR(((u)r[8] + 4), r[6]);
    SWL(((u)r[2] + 3), r[5]);
    SWR(((u)r[2] + 0), r[5]);
    SWL(((u)r[2] + 7), r[6]);
    SWR(((u)r[2] + 4), r[6]);
    r[2] = *(short *)((u)r[4] + 384);
    r[3] = (u)0 + 1;
    r[2] = (u)r[2] << 3;
    r[2] = (u)r[2] + (u)r[4];
    *(short *)((u)r[2] + 6) = r[3];
    r[3] = *(unsigned short *)((u)r[4] + 386);
    r[2] = *(unsigned short *)((u)r[4] + 384);
    r[3] = (u)r[3] + 1;
    r[2] = (u)r[2] + 1;
    *(short *)((u)r[4] + 384) = r[2];
    r[2] = (u)r[2] << 16;
    r[2] = (int)r[2] >> 16;
    r[2] = (int)r[2] < 48;
    c = ((r[2] != 0)); *(short *)((u)r[4] + 386) = r[3]; if (c) goto L800d3170;
    *(short *)((u)r[4] + 384) = 0;
    L800d3170:;
     goto out;
out:
    RECOMP_RETURN;
}
