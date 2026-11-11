extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_GM_WhereList[] __asm__("GM_WhereList");
extern char R_dword_800AB9D4[] __asm__("dword_800AB9D4");
extern char R_s19a_800D2FA8[] __asm__("s19a_800D2FA8");
extern char R_s19a_800D304C[] __asm__("s19a_800D304C");
int G_s19a_800D306C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D306C");
int G_s19a_800D306C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_WhereList);
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(int *)((u)r[2] + 44);
    r[16] = *(int *)((u)r[2] + 8);
    r[17] = (u)r[4] + (u)0; CALL(R_s19a_800D304C);
    c = ((r[2] == 0)); r[6] = 0; if (c) goto L800d30b8;
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[16] + (u)0;
    r[6] = (u)r[6] + (int)R_GM_PlayerPosition; CALL(R_s19a_800D2FA8);
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800d30c0;
    L800d30b8:;
    r[2] = (u)0 + (u)0; goto L800d30e0;
    L800d30c0:;
    r[3] = *(int *)((u)r[2] + (int)R_dword_800AB9D4);
    r[2] = (u)0 + 2;
    c = ((r[3] == r[2])); r[2] = r[3] ^ 10; if (c) goto L800d30dc;
    r[2] = (u)r[2] < (u)1;
    r[2] = (u)r[2] << 1; goto L800d30e0;
    L800d30dc:;
    r[2] = (u)0 + 1;
    L800d30e0:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
