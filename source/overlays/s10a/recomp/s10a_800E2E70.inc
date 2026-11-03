extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_GV_PassageTime[] __asm__("GV_PassageTime");
extern char R_s10a_dat_800C3844[] __asm__("s10a_dat_800C3844");
extern char R_s10a_dat_800E43A4[] __asm__("s10a_dat_800E43A4");
extern char R_GM_SeSetMode[] __asm__("GM_SeSetMode");
extern char R_GM_SeSetSize[] __asm__("GM_SeSetSize");
extern char R_s10a_800E027C[] __asm__("s10a_800E027C");
extern char R_s10a_800E0324[] __asm__("s10a_800E0324");
int G_s10a_800E2E70(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800E2E70");
int G_s10a_800E2E70(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    r[5] = (u)0 + 4;
    r[6] = 0;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 16) = r[16];
    r[4] = *(unsigned short *)((u)r[17] + 36);
    r[3] = *(int *)((u)r[17] + 32);
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_GM_CurrentMap) = r[3];
    r[2] = 0;
    r[18] = *(int *)((u)r[2] + (int)R_GV_PassageTime);
    r[6] = (u)r[6] + ((int)R_s10a_dat_800C3844 + 16); CALL(R_s10a_800E027C);
    r[16] = (u)r[2] + (u)0; CALL(R_s10a_800E0324);
    c = ((r[16] == 0)); r[2] = (u)0 + 1; if (c) goto L800e2ed0;
    c = ((r[16] == r[2]));  if (c) goto L800e2ed8;
     goto L800e2ee8;
    L800e2ed0:;
    *(int *)((u)r[17] + 40) = 0; goto L800e2ee8;
    L800e2ed8:;
    r[2] = *(unsigned short *)((u)r[17] + 60);
    *(int *)((u)r[17] + 40) = r[16];
    *(int *)((u)r[17] + 64) = 0;
    *(short *)((u)r[17] + 62) = r[2];
    L800e2ee8:;
    r[2] = *(int *)((u)r[17] + 40);
    c = ((r[2] == 0));  if (c) goto L800e2ffc;
    r[2] = *(int *)((u)r[17] + 64);
    c = (((int)r[2] > 0)); r[2] = (u)r[2] - (u)r[18]; if (c) goto L800e2ff8;
    r[3] = *(short *)((u)r[17] + 56);
    r[2] = (u)r[3] < (u)5;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800e2f98;
    r[2] = (u)r[2] + (int)R_s10a_dat_800E43A4;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800e2f38: goto L800e2f38; case 0x800e2f50: goto L800e2f50; case 0x800e2f68: goto L800e2f68; case 0x800e2f80: goto L800e2f80; case 0x800e2f98: goto L800e2f98; default: goto out; }
    L800e2f38:;
    r[4] = (u)r[17] + 44;
    r[5] = *(short *)((u)r[17] + 54);
    r[6] = (u)0 + (u)0; CALL(R_GM_SeSetMode);
     goto L800e2fa8;
    L800e2f50:;
    r[4] = (u)r[17] + 44;
    r[5] = *(short *)((u)r[17] + 54);
    r[6] = (u)0 + 3; CALL(R_GM_SeSetMode);
     goto L800e2fa8;
    L800e2f68:;
    r[4] = (u)r[17] + 44;
    r[5] = *(short *)((u)r[17] + 54);
    r[6] = (u)0 + 2; CALL(R_GM_SeSetMode);
     goto L800e2fa8;
    L800e2f80:;
    r[4] = (u)r[17] + 44;
    r[5] = *(short *)((u)r[17] + 54);
    r[6] = (u)0 + 1; CALL(R_GM_SeSetMode);
     goto L800e2fa8;
    L800e2f98:;
    r[5] = *(short *)((u)r[17] + 54);
    r[6] = *(short *)((u)r[17] + 52);
    r[4] = (u)r[17] + 44; CALL(R_GM_SeSetSize);
    L800e2fa8:;
    r[2] = *(short *)((u)r[17] + 60);
    c = (((int)r[2] < 0));  if (c) goto L800e2fdc;
    r[2] = *(unsigned short *)((u)r[17] + 62);
    r[2] = (u)r[2] + -1;
    *(short *)((u)r[17] + 62) = r[2];
    r[2] = (u)r[2] << 16;
    c = ((r[2] != 0));  if (c) goto L800e2fdc;
    *(int *)((u)r[17] + 40) = 0; goto L800e2ffc;
    L800e2fdc:;
    r[2] = *(short *)((u)r[17] + 58);
    r[2] = (u)r[2] << 1;
    *(int *)((u)r[17] + 64) = r[2];
    r[2] = *(int *)((u)r[17] + 64);
    r[2] = (u)r[2] - (u)r[18];
    L800e2ff8:;
    *(int *)((u)r[17] + 64) = r[2];
    L800e2ffc:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800E3014(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800E3014");
int G_s10a_rc_800E3014(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
