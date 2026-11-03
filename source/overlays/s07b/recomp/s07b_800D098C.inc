extern char R_GM_GameOverTimer[] __asm__("GM_GameOverTimer");
extern char R_s07b_800CDBA4[] __asm__("s07b_800CDBA4");
extern char R_s07b_800CF6F0[] __asm__("s07b_800CF6F0");
extern char R_s07b_dword_800E5BB0[] __asm__("s07b_dword_800E5BB0");
extern char R_s07b_800CB2A4[] __asm__("s07b_800CB2A4");
extern char R_s07b_800CC89C[] __asm__("s07b_800CC89C");
int G_s07b_800D098C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800D098C");
int G_s07b_800D098C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800d09c8;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s07b_800CDBA4;
    r[5] = (u)0 + 1;
    *(int *)((u)r[16] + 2132) = r[2];
    *(int *)((u)r[16] + 2136) = 0;
    *(short *)((u)r[16] + 2662) = 0;
    *(short *)((u)r[16] + 2660) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0; CALL(R_s07b_800CC89C);
    L800d09c8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s07b_800CB2A4);
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s07b_dword_800E5BB0);
    r[2] = *(int *)((u)r[2] + 0);
    r[3] = (u)0 + 4096;
    r[2] = r[2] & 4104;
    c = ((r[2] != r[3])); r[2] = 0; if (c) goto L800d0a3c;
    r[2] = *(int *)((u)r[2] + (int)R_GM_GameOverTimer);
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800d0a3c;
    *(short *)((u)r[16] + 2118) = r[2];
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s07b_800CF6F0;
    *(int *)((u)r[16] + 2132) = r[2];
    r[2] = *(int *)((u)r[16] + 2124);
    r[3] = *(int *)((u)r[16] + 2128);
    *(int *)((u)r[16] + 2136) = 0;
    *(short *)((u)r[16] + 2662) = 0;
    *(short *)((u)r[16] + 2660) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    r[2] = r[2] | 16;
    r[3] = r[3] | 16;
    *(int *)((u)r[16] + 2124) = r[2];
    *(int *)((u)r[16] + 2128) = r[3];
    L800d0a3c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
