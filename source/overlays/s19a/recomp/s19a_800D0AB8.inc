extern char R_s19a_dat_800C35B4[] __asm__("s19a_dat_800C35B4");
extern char R_s19a_dat_800C35C6[] __asm__("s19a_dat_800C35C6");
extern char R_GM_ConfigObjectOverride[] __asm__("GM_ConfigObjectOverride");
int G_s19a_800D0AB8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D0AB8");
int G_s19a_800D0AB8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[5] + (u)0;
    c = ((r[17] != 0)); *(int *)((u)r[29] + 32) = r[31]; if (c) goto L800d0afc;
    r[4] = (u)r[16] + 156;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4;
    r[2] = (u)0 + 9;
    *(short *)((u)r[16] + 2274) = r[2];
    r[2] = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s19a_dat_800C35C6);
    r[2] = (u)0 + 1022;
    *(int *)((u)r[29] + 16) = r[2]; CALL(R_GM_ConfigObjectOverride);
    L800d0afc:;
    r[2] = *(int *)((u)r[16] + 2872);
    r[2] = r[2] & 1;
    c = ((r[2] != 0)); r[2] = (int)r[17] < 4; if (c) goto L800d0b48;
    r[4] = (u)r[16] + 156;
    r[6] = (u)0 + (u)0;
    r[2] = 0;
    *(short *)((u)r[16] + 2274) = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s19a_dat_800C35B4);
    r[7] = (u)0 + 4;
    *(int *)((u)r[29] + 16) = 0; CALL(R_GM_ConfigObjectOverride);
    *(int *)((u)r[16] + 2288) = 0;
    *(int *)((u)r[16] + 2296) = 0;
    *(short *)((u)r[16] + 2274) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0; goto L800d0b70;
    L800d0b48:;
    c = ((r[2] == 0)); r[3] = (u)r[17] << 8; if (c) goto L800d0b5c;
    r[2] = *(unsigned short *)((u)r[16] + 42);
    r[2] = (u)r[2] - (u)r[3]; goto L800d0b68;
    L800d0b5c:;
    r[2] = *(unsigned short *)((u)r[16] + 42);
    r[2] = (u)r[2] + -1024;
    L800d0b68:;
    r[2] = r[2] & 4095;
    *(short *)((u)r[16] + 2952) = r[2];
    L800d0b70:;
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
