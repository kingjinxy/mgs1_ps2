extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s19a_dat_800E0530[] __asm__("s19a_dat_800E0530");
extern char R_s19a_dat_800E06A4[] __asm__("s19a_dat_800E06A4");
extern char R_GM_SeSetMode[] __asm__("GM_SeSetMode");
extern char R_Port_GameTick[] __asm__("Port_GameTick");
int G_s19a_800C7F2C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C7F2C");
int G_s19a_800C7F2C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[2] = 0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[2] + (int)R_s19a_dat_800E0530;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 368);
    r[2] = (int)r[2] < 6000;
    c = ((r[2] == 0));  if (c) goto L800c7fb4;
     CALL(R_Port_GameTick);
    r[3] = *(int *)((u)r[16] + 372);
    r[2] = (u)r[2] - (u)r[3];
    r[2] = (int)r[2] < 41;
    c = ((r[2] != 0));  if (c) goto L800c7fb4;
    r[2] = *(short *)((u)r[16] + 378);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800c7fa4;
    r[3] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 28));
    r[2] = (u)0 + 9;
    c = ((r[3] == r[2])); r[4] = 0; if (c) goto L800c7fa4;
    r[4] = (u)r[4] + (int)R_GM_PlayerPosition;
    r[5] = (u)0 + 10;
    r[6] = (u)0 + 2; CALL(R_GM_SeSetMode);
    L800c7fa4:;
     CALL(R_Port_GameTick);
    r[3] = 0;
    *(int *)((u)r[3] + (int)R_s19a_dat_800E06A4) = r[2];
    L800c7fb4:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
