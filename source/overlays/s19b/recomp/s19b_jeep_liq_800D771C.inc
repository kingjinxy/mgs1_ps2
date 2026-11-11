extern char R_GV_NearSpeed[] __asm__("GV_NearSpeed");
extern char R_s19b_jeep_mrl_800D399C[] __asm__("s19b_jeep_mrl_800D399C");
int G_s19b_jeep_liq_800D771C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19b_jeep_liq_800D771C");
int G_s19b_jeep_liq_800D771C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 24) = r[31];
    r[16] = (u)r[6] - (u)r[5]; CALL(R_s19b_jeep_mrl_800D399C);
    c = (((int)r[16] < 0)); r[5] = (u)r[2] + (u)0; if (c) goto L800d7788;
    r[2] = (int)r[16] < 3001;
    c = ((r[2] != 0)); r[2] = (int)r[16] < 751; if (c) goto L800d775c;
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[5] + 100;
    r[6] = (u)0 + 15; goto L800d77cc;
    L800d775c:;
    c = ((r[2] != 0)); r[2] = (int)r[16] < 94; if (c) goto L800d7774;
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[5] + 50;
    r[6] = (u)0 + 8; goto L800d77cc;
    L800d7774:;
    c = ((r[2] != 0)); r[2] = (u)r[17] + (u)0; if (c) goto L800d77dc;
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[5] + 15; goto L800d77c8;
    L800d7788:;
    r[2] = (int)r[16] < -3000;
    c = ((r[2] == 0)); r[4] = (u)r[17] + (u)0; if (c) goto L800d77a0;
    r[5] = (u)r[5] + -100;
    r[6] = (u)0 + 15; goto L800d77cc;
    L800d77a0:;
    r[2] = (int)r[16] < -750;
    c = ((r[2] == 0)); r[6] = (u)0 + 8; if (c) goto L800d77b8;
    r[5] = (u)r[5] + -50;
     goto L800d77cc;
    L800d77b8:;
    r[2] = (int)r[16] < -93;
    c = ((r[2] == 0)); r[4] = (u)r[17] + (u)0; if (c) goto L800d77d8;
    r[5] = (u)r[5] + -15;
    L800d77c8:;
    r[6] = (u)0 + 3;
    L800d77cc:;
     CALL(R_GV_NearSpeed);
    r[17] = (u)r[2] + (u)0;
    L800d77d8:;
    r[2] = (u)r[17] + (u)0;
    L800d77dc:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
