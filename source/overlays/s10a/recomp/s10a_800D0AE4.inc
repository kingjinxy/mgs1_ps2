extern char R_s10a_dat_800E3DA4[] __asm__("s10a_dat_800E3DA4");
extern char R_GM_ConfigObjectJoint[] __asm__("GM_ConfigObjectJoint");
extern char R_GM_ConfigObjectLight[] __asm__("GM_ConfigObjectLight");
extern char R_GM_InitObject[] __asm__("GM_InitObject");
extern char R_GV_StrCode[] __asm__("GV_StrCode");
int G_s10a_800D0AE4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D0AE4");
int G_s10a_800D0AE4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 32) = r[20];
    r[20] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 40) = r[31];
    *(int *)((u)r[29] + 36) = r[21];
    *(int *)((u)r[29] + 28) = r[19];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(int *)((u)r[20] + 36);
    r[18] = (u)0 + (u)0;
    c = (((int)r[2] <= 0)); *(int *)((u)r[20] + 444) = r[6]; if (c) goto L800d0b6c;
    r[21] = 0;
    r[19] = (u)0 + 480;
    L800d0b20:;
    r[4] = (u)r[21] + (int)R_s10a_dat_800E3DA4;
    r[17] = (u)r[20] + (u)r[19]; CALL(R_GV_StrCode);
    r[16] = (u)r[17] + 4;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[2] + (u)0;
    r[6] = (u)0 + 621;
    r[7] = (u)0 + (u)0; CALL(R_GM_InitObject);
    r[4] = (u)r[16] + (u)0; CALL(R_GM_ConfigObjectJoint);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + 232; CALL(R_GM_ConfigObjectLight);
    r[2] = *(int *)((u)r[20] + 36);
    r[18] = (u)r[18] + 1;
    r[2] = (int)r[18] < (int)r[2];
    c = ((r[2] != 0)); r[19] = (u)r[19] + 392; if (c) goto L800d0b20;
    L800d0b6c:;
    r[31] = *(int *)((u)r[29] + 40);
    r[21] = *(int *)((u)r[29] + 36);
    r[20] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 48; goto out;
out:
    return r[2];
}
