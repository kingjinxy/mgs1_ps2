extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_GM_PlayerControl[] __asm__("GM_PlayerControl");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s07b_800C796C[] __asm__("s07b_800C796C");
extern char R_s07b_800C46F0[] __asm__("s07b_800C46F0");
int G_s07b_800C47D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800C47D4");
int G_s07b_800C47D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[2] = 0;
    r[7] = (u)r[2] + (int)R_GM_PlayerControl;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s07b_800C796C;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 2132);
    r[5] = *(unsigned short *)((u)r[4] + 2236);
    c = ((r[3] == r[2])); r[6] = (u)0 + (u)0; if (c) goto L800c4838;
    r[2] = *(int *)((u)r[4] + 2268);
    r[2] = *(unsigned short *)((u)r[2] + 0);
    r[2] = r[2] & 16384;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800c4838;
    r[2] = *(short *)((u)r[2] + ((int)R_GM_Camera + 34));
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800c4838;
    r[2] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 30));
    r[2] = r[2] ^ 17;
    r[6] = (u)r[2] < (u)1;
    L800c4838:;
    r[4] = *(int *)((u)r[7] + 0);
     CALL(R_s07b_800C46F0);
    r[31] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 < (u)r[2];
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
