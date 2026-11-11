extern char R_s19a_dat_800C35B4[] __asm__("s19a_dat_800C35B4");
extern char R_s19a_dat_800C35E0[] __asm__("s19a_dat_800C35E0");
extern char R_GM_ConfigObjectOverride[] __asm__("GM_ConfigObjectOverride");
extern char R_GM_SeSet[] __asm__("GM_SeSet");
int G_s19a_800D0E34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D0E34");
int G_s19a_800D0E34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 32) = r[31];
    c = ((r[17] != 0)); *(short *)((u)r[16] + 2956) = 0; if (c) goto L800d0e7c;
    r[4] = (u)r[16] + 156;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4;
    r[2] = (u)0 + 22;
    *(short *)((u)r[16] + 2274) = r[2];
    r[2] = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s19a_dat_800C35E0);
    r[2] = (u)0 + 1022;
    *(int *)((u)r[29] + 16) = r[2]; CALL(R_GM_ConfigObjectOverride);
    L800d0e7c:;
    r[2] = (u)0 + 60;
    c = ((r[17] != r[2])); r[4] = (u)r[16] + 32; if (c) goto L800d0e90;
    r[5] = (u)0 + 146; CALL(R_GM_SeSet);
    L800d0e90:;
    r[2] = *(short *)((u)r[16] + 184);
    c = ((r[2] != 0)); r[4] = (u)r[16] + 156; if (c) goto L800d0eb4;
    r[2] = *(int *)((u)r[16] + 2872);
    r[2] = r[2] & 128;
    c = ((r[2] != 0));  if (c) goto L800d0ee8;
    L800d0eb4:;
    r[6] = (u)0 + (u)0;
    r[2] = 0;
    *(int *)((u)r[16] + 2884) = 0;
    *(short *)((u)r[16] + 2274) = 0;
    r[5] = *(short *)((u)r[2] + (int)R_s19a_dat_800C35B4);
    r[7] = (u)0 + 4;
    *(int *)((u)r[29] + 16) = 0; CALL(R_GM_ConfigObjectOverride);
    *(int *)((u)r[16] + 2288) = 0;
    *(int *)((u)r[16] + 2296) = 0;
    *(short *)((u)r[16] + 2274) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    L800d0ee8:;
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
