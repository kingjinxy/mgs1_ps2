extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_d18a_dword_800C3900[] __asm__("d18a_dword_800C3900");
extern char R_d18a_snake18_800CE7BC[] __asm__("d18a_snake18_800CE7BC");
extern char R_d18a_snake18_800D200C[] __asm__("d18a_snake18_800D200C");
extern char R_d18a_snake18_800D20EC[] __asm__("d18a_snake18_800D20EC");
extern char R_d18a_snake18_800CBA64[] __asm__("d18a_snake18_800CBA64");
int G_d18a_snake18_800CEC68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("d18a_snake18_800CEC68");
int G_d18a_snake18_800CEC68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[3] = 0;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_d18a_snake18_800CE7BC;
    r[5] = 0;
    r[4] = *(int *)((u)r[3] + (int)R_GM_PlayerStatus);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[5] + (int)R_d18a_dword_800C3900;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[16] + 2236) = r[2];
    *(int *)((u)r[16] + 2240) = r[2]; CALL(R_d18a_snake18_800CBA64);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800cecb0;
    r[2] = (u)r[2] + (int)R_d18a_snake18_800D20EC; goto L800cecb8;
    L800cecb0:;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_d18a_snake18_800D200C;
    L800cecb8:;
    *(int *)((u)r[16] + 2220) = r[2];
    *(int *)((u)r[16] + 2224) = 0;
    *(short *)((u)r[16] + 2322) = 0;
    *(short *)((u)r[16] + 2320) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
