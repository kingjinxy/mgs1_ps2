extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_GM_PlayerControl[] __asm__("GM_PlayerControl");
extern char R_s07b_800C77A8[] __asm__("s07b_800C77A8");
extern char R_s07b_800C46F0[] __asm__("s07b_800C46F0");
int G_s07b_800C473C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800C473C");
int G_s07b_800C473C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = 0;
    r[4] = (u)r[2] + (int)R_GM_PlayerControl;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s07b_800C77A8;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 2132);
    r[5] = *(unsigned short *)((u)r[16] + 2230);
    c = ((r[3] == r[2])); r[6] = (u)0 + (u)0; if (c) goto L800c4798;
    r[2] = 0;
    r[2] = *(short *)((u)r[2] + ((int)R_GM_Camera + 34));
    c = ((r[2] != 0));  if (c) goto L800c4798;
    r[2] = *(int *)((u)r[16] + 2268);
    r[2] = *(unsigned short *)((u)r[2] + 0);
    r[2] = r[2] & 16384;
    r[6] = (u)0 < (u)r[2];
    L800c4798:;
    r[4] = *(int *)((u)r[4] + 0);
     CALL(R_s07b_800C46F0);
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800c47b4;
    r[2] = (u)0 + (u)0; goto L800c47c4;
    L800c47b4:;
    r[3] = *(int *)((u)r[16] + 2128);
    r[4] = 0x20000;
    r[3] = r[3] | r[4];
    *(int *)((u)r[16] + 2128) = r[3];
    L800c47c4:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
