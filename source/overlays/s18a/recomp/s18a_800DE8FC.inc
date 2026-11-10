extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_dword_800AB9D4[] __asm__("dword_800AB9D4");
extern char R_GM_SeSet[] __asm__("GM_SeSet");
int G_s18a_800DE8FC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DE8FC");
int G_s18a_800DE8FC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[3] = 0x10000;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[3] = r[3] | 84;
    r[4] = r[2] & r[3];
    r[2] = (u)0 + 16;
    c = ((r[4] != r[2])); *(int *)((u)r[29] + 16) = r[31]; if (c) goto L800de958;
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_dword_800AB9D4);
    r[2] = (u)0 + 8;
    c = ((r[3] != r[2])); r[5] = (u)0 + 169; if (c) goto L800de940;
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_GM_PlayerPosition; goto L800de950;
    L800de940:;
    c = ((r[3] != r[4])); r[4] = 0; if (c) goto L800de958;
    r[4] = (u)r[4] + (int)R_GM_PlayerPosition;
    r[5] = (u)0 + 168;
    L800de950:;
     CALL(R_GM_SeSet);
    L800de958:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
