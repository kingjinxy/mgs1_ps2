extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_s19a_800C5424[] __asm__("s19a_800C5424");
extern char R_s19a_800C55A8[] __asm__("s19a_800C55A8");
int G_s19a_800C569C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C569C");
int G_s19a_800C569C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)r[16] + 32;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_GM_PlayerPosition;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[16] + 108;
    *(int *)((u)r[29] + 24) = r[31];
    r[6] = (u)r[17] + (u)0; CALL(R_s19a_800C5424);
    r[4] = (u)r[16] + 632;
    r[5] = (u)r[17] + (u)0; CALL(R_s19a_800C55A8);
    r[2] = LWL(((u)r[16] + 111), r[2]);
    r[2] = LWR(((u)r[16] + 108), r[2]);
    r[3] = LWL(((u)r[16] + 115), r[3]);
    r[3] = LWR(((u)r[16] + 112), r[3]);
    SWL(((u)r[16] + 43), r[2]);
    SWR(((u)r[16] + 40), r[2]);
    SWL(((u)r[16] + 47), r[3]);
    SWR(((u)r[16] + 44), r[3]);
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
