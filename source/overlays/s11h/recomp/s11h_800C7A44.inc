extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_s11h_dat_800DAA94[] __asm__("s11h_dat_800DAA94");
extern char R_AN_Blast_Mini[] __asm__("AN_Blast_Mini");
extern char R_AN_Blast_Minimini[] __asm__("AN_Blast_Minimini");
extern char R_AN_Blast_Single[] __asm__("AN_Blast_Single");
extern char R_AN_Blast_high[] __asm__("AN_Blast_high");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_RandS[] __asm__("GV_RandS");
extern char R_GV_RandU[] __asm__("GV_RandU");
int G_s11h_800C7A44(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800C7A44");
int G_s11h_800C7A44(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = 0 | 32768;
    *(int *)((u)r[29] + 28) = r[31];
    r[3] = *(int *)((u)r[16] + 32);
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_GM_CurrentMap) = r[3]; CALL(R_GV_RandS);
    r[3] = *(short *)((u)r[16] + 44);
    r[4] = *(short *)((u)r[16] + 36);
    r[5] = *(int *)((u)r[16] + 68);
    r[3] = (u)r[3] - (u)r[4];
    mul = (long long)(int)r[3] * (int)r[5]; hi_ = mul >> 32; lo_ = mul;
    r[5] = lo_;
    r[3] = *(int *)((u)r[16] + 64);
    if (r[3]) { lo_ = (int)r[5] / (int)r[3]; hi_ = (int)r[5] % (int)r[3]; }
    c = ((r[3] != 0));  if (c) goto L800c7a98;
    L800c7a98:;
    r[1] = (u)0 + -1;
    c = ((r[3] != r[1])); r[1] = 0; if (c) goto L800c7ab0;
    c = ((r[5] != r[1]));  if (c) goto L800c7ab0;
    L800c7ab0:;
    r[3] = lo_;
    r[4] = *(int *)((u)r[16] + 52);
    mul = (long long)(int)r[2] * (int)r[4]; hi_ = mul >> 32; lo_ = mul;
    r[2] = *(unsigned short *)((u)r[16] + 36);
    r[5] = lo_;
    c = (((int)r[5] >= 0)); r[3] = (u)r[2] + (u)r[3]; if (c) goto L800c7ad4;
    r[5] = (u)r[5] + 32767;
    L800c7ad4:;
    r[4] = 0 | 32768;
    r[2] = (int)r[5] >> 15;
    r[2] = (u)r[3] + (u)r[2];
    *(short *)((u)r[29] + 16) = r[2]; CALL(R_GV_RandS);
    r[3] = *(short *)((u)r[16] + 46);
    r[4] = *(short *)((u)r[16] + 38);
    r[5] = *(int *)((u)r[16] + 68);
    r[3] = (u)r[3] - (u)r[4];
    mul = (long long)(int)r[3] * (int)r[5]; hi_ = mul >> 32; lo_ = mul;
    r[5] = lo_;
    r[3] = *(int *)((u)r[16] + 64);
    if (r[3]) { lo_ = (int)r[5] / (int)r[3]; hi_ = (int)r[5] % (int)r[3]; }
    c = ((r[3] != 0));  if (c) goto L800c7b18;
    L800c7b18:;
    r[1] = (u)0 + -1;
    c = ((r[3] != r[1])); r[1] = 0; if (c) goto L800c7b30;
    c = ((r[5] != r[1]));  if (c) goto L800c7b30;
    L800c7b30:;
    r[3] = lo_;
    r[4] = *(int *)((u)r[16] + 52);
    mul = (long long)(int)r[2] * (int)r[4]; hi_ = mul >> 32; lo_ = mul;
    r[2] = *(unsigned short *)((u)r[16] + 38);
    r[5] = lo_;
    c = (((int)r[5] >= 0)); r[3] = (u)r[2] + (u)r[3]; if (c) goto L800c7b54;
    r[5] = (u)r[5] + 32767;
    L800c7b54:;
    r[4] = 0 | 32768;
    r[2] = (int)r[5] >> 15;
    r[2] = (u)r[3] + (u)r[2];
    *(short *)((u)r[29] + 18) = r[2]; CALL(R_GV_RandS);
    r[3] = *(short *)((u)r[16] + 48);
    r[4] = *(short *)((u)r[16] + 40);
    r[5] = *(int *)((u)r[16] + 68);
    r[3] = (u)r[3] - (u)r[4];
    mul = (long long)(int)r[3] * (int)r[5]; hi_ = mul >> 32; lo_ = mul;
    r[5] = lo_;
    r[3] = *(int *)((u)r[16] + 64);
    if (r[3]) { lo_ = (int)r[5] / (int)r[3]; hi_ = (int)r[5] % (int)r[3]; }
    c = ((r[3] != 0));  if (c) goto L800c7b98;
    L800c7b98:;
    r[1] = (u)0 + -1;
    c = ((r[3] != r[1])); r[1] = 0; if (c) goto L800c7bb0;
    c = ((r[5] != r[1]));  if (c) goto L800c7bb0;
    L800c7bb0:;
    r[3] = lo_;
    r[4] = *(int *)((u)r[16] + 52);
    mul = (long long)(int)r[2] * (int)r[4]; hi_ = mul >> 32; lo_ = mul;
    r[2] = *(unsigned short *)((u)r[16] + 40);
    r[4] = lo_;
    c = (((int)r[4] >= 0)); r[3] = (u)r[2] + (u)r[3]; if (c) goto L800c7bd4;
    r[4] = (u)r[4] + 32767;
    L800c7bd4:;
    r[2] = (int)r[4] >> 15;
    r[2] = (u)r[3] + (u)r[2];
    *(short *)((u)r[29] + 20) = r[2];
    r[3] = *(int *)((u)r[16] + 56);
    r[2] = (u)r[3] < (u)6;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800c7c68;
    r[2] = (u)r[2] + (int)R_s11h_dat_800DAA94;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800c7c10: goto L800c7c10; case 0x800c7c20: goto L800c7c20; case 0x800c7c30: goto L800c7c30; case 0x800c7c40: goto L800c7c40; case 0x800c7c50: goto L800c7c50; case 0x800c7c60: goto L800c7c60; default: goto out; }
    L800c7c10:;
    r[4] = (u)r[29] + 16; CALL(R_AN_Blast_high);
     goto L800c7c68;
    L800c7c20:;
    r[4] = (u)0 + 2; CALL(R_GV_RandU);
    c = ((r[2] == 0));  if (c) goto L800c7c50;
    L800c7c30:;
    r[4] = (u)r[29] + 16; CALL(R_AN_Blast_Single);
     goto L800c7c68;
    L800c7c40:;
    r[4] = (u)0 + 2; CALL(R_GV_RandU);
    c = ((r[2] == 0));  if (c) goto L800c7c60;
    L800c7c50:;
    r[4] = (u)r[29] + 16; CALL(R_AN_Blast_Mini);
     goto L800c7c68;
    L800c7c60:;
    r[4] = (u)r[29] + 16; CALL(R_AN_Blast_Minimini);
    L800c7c68:;
    r[2] = *(int *)((u)r[16] + 60);
    r[2] = (u)r[2] + -1;
    c = (((int)r[2] >= 0)); *(int *)((u)r[16] + 60) = r[2]; if (c) goto L800c7c84;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    L800c7c84:;
    r[2] = *(int *)((u)r[16] + 68);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + 68) = r[2];
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
int G_s11h_rc_800C7CA4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_rc_800C7CA4");
int G_s11h_rc_800C7CA4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
