extern char R_s19a_dat_800DF60C[] __asm__("s19a_dat_800DF60C");
extern char R_GM_ConfigObjectLight[] __asm__("GM_ConfigObjectLight");
extern char R_GM_InitObjectNoRots[] __asm__("GM_InitObjectNoRots");
extern char R_GV_StrCode[] __asm__("GV_StrCode");
int G_s19a_800C6454(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C6454");
int G_s19a_800C6454(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s19a_dat_800DF60C;
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 24) = r[31];
    r[17] = (u)r[16] + 192; CALL(R_GV_StrCode);
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[2] + (u)0;
    r[6] = (u)0 + 813;
    r[7] = (u)0 + (u)0; CALL(R_GM_InitObjectNoRots);
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[16] + 244; CALL(R_GM_ConfigObjectLight);
    r[3] = (u)0 + -25;
    *(short *)((u)r[16] + 230) = r[3];
    r[3] = (u)0 + -450;
    *(short *)((u)r[16] + 228) = 0;
    *(short *)((u)r[16] + 232) = r[3];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
