extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_GM_WhereList[] __asm__("GM_WhereList");
extern char R_dword_800AB9D4[] __asm__("dword_800AB9D4");
extern char R_s10a_800C4EA4[] __asm__("s10a_800C4EA4");
extern char R_s10a_800C4F48[] __asm__("s10a_800C4F48");
int G_s10a_800C4F68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C4F68");
int G_s10a_800C4F68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
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
    r[17] = (u)r[4] + (u)0; CALL(R_s10a_800C4F48);
    c = ((r[2] == 0)); r[6] = 0; if (c) goto L800c4fb4;
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[16] + (u)0;
    r[6] = (u)r[6] + (int)R_GM_PlayerPosition; CALL(R_s10a_800C4EA4);
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800c4fbc;
    L800c4fb4:;
    r[2] = (u)0 + (u)0; goto L800c4fdc;
    L800c4fbc:;
    r[3] = *(int *)((u)r[2] + (int)R_dword_800AB9D4);
    r[2] = (u)0 + 2;
    c = ((r[3] == r[2])); r[2] = r[3] ^ 10; if (c) goto L800c4fd8;
    r[2] = (u)r[2] < (u)1;
    r[2] = (u)r[2] << 1; goto L800c4fdc;
    L800c4fd8:;
    r[2] = (u)0 + 1;
    L800c4fdc:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
