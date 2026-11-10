extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_GV_PadData[] __asm__("GV_PadData");
extern char R_s18a_800C3F68[] __asm__("s18a_800C3F68");
extern char R_s18a_800C407C[] __asm__("s18a_800C407C");
int G_s18a_800C42AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C42AC");
int G_s18a_800C42AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[3] = 0x8000000;
    r[2] = r[2] & r[3];
    c = ((r[2] == 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800c42dc;
    r[2] = 0;
    r[2] = (u)r[2] + ((int)R_GV_PadData + 16); goto L800c42e4;
    L800c42dc:;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_GV_PadData;
    L800c42e4:;
    *(int *)((u)r[16] + 64) = r[2];
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800C3F68);
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800C407C);
    r[31] = *(int *)((u)r[29] + 20);
    r[2] = 0;
    r[8] = (u)r[2] + (int)R_GM_PlayerPosition;
    r[5] = LWL(((u)r[16] + 43), r[5]);
    r[5] = LWR(((u)r[16] + 40), r[5]);
    r[6] = LWL(((u)r[16] + 47), r[6]);
    r[6] = LWR(((u)r[16] + 44), r[6]);
    SWL(((u)r[8] + 3), r[5]);
    SWR(((u)r[8] + 0), r[5]);
    SWL(((u)r[8] + 7), r[6]);
    SWR(((u)r[8] + 4), r[6]);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s18a_rc_800C4330(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_rc_800C4330");
int G_s18a_rc_800C4330(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[4] = 0xffff0000;
    r[3] = 0;
    r[2] = *(int *)((u)r[3] + (int)R_GM_PlayerStatus);
    r[4] = r[4] | 32767;
    r[2] = r[2] & r[4];
    *(int *)((u)r[3] + (int)R_GM_PlayerStatus) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
