extern char R_s14e_dword_800C3350[] __asm__("s14e_dword_800C3350");
extern char R_s14e_dword_800C3360[] __asm__("s14e_dword_800C3360");
extern char R_GM_ConfigObjectOverride[] __asm__("GM_ConfigObjectOverride");
int G_s14e_800C9838(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800C9838");
int G_s14e_800C9838(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[5] + (u)0;
    c = ((r[17] != 0)); *(int *)((u)r[29] + 32) = r[31]; if (c) goto L800c987c;
    r[4] = (u)r[16] + 156;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4;
    r[2] = (u)0 + 9;
    *(short *)((u)r[16] + 2274) = r[2];
    r[2] = 0;
    r[5] = *(short *)((u)r[2] + ((int)R_s14e_dword_800C3360 + 2));
    r[2] = (u)0 + 1022;
    *(int *)((u)r[29] + 16) = r[2]; CALL(R_GM_ConfigObjectOverride);
    L800c987c:;
    r[2] = *(int *)((u)r[16] + 2872);
    r[2] = r[2] & 1;
    c = ((r[2] != 0)); r[2] = (int)r[17] < 4; if (c) goto L800c98c8;
    r[4] = (u)r[16] + 156;
    r[6] = (u)0 + (u)0;
    r[2] = 0;
    *(short *)((u)r[16] + 2274) = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s14e_dword_800C3350);
    r[7] = (u)0 + 4;
    *(int *)((u)r[29] + 16) = 0; CALL(R_GM_ConfigObjectOverride);
    *(int *)((u)r[16] + 2288) = 0;
    *(int *)((u)r[16] + 2296) = 0;
    *(short *)((u)r[16] + 2274) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0; goto L800c98f0;
    L800c98c8:;
    c = ((r[2] == 0)); r[3] = (u)r[17] << 8; if (c) goto L800c98dc;
    r[2] = *(unsigned short *)((u)r[16] + 42);
    r[2] = (u)r[2] - (u)r[3]; goto L800c98e8;
    L800c98dc:;
    r[2] = *(unsigned short *)((u)r[16] + 42);
    r[2] = (u)r[2] + -1024;
    L800c98e8:;
    r[2] = r[2] & 4095;
    *(short *)((u)r[16] + 2956) = r[2];
    L800c98f0:;
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
