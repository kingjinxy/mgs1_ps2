extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_s17a_dat_800E57A8[] __asm__("s17a_dat_800E57A8");
extern char R_AN_Blast_Mini[] __asm__("AN_Blast_Mini");
extern char R_AN_Blast_Minimini[] __asm__("AN_Blast_Minimini");
extern char R_AN_Blast_Single[] __asm__("AN_Blast_Single");
extern char R_AN_Blast_high[] __asm__("AN_Blast_high");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_RandS[] __asm__("GV_RandS");
extern char R_GV_RandU[] __asm__("GV_RandU");
int G_s17a_800CB074(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800CB074");
int G_s17a_800CB074(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
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
    c = ((r[3] != 0));  if (c) goto L800cb0c8;
    L800cb0c8:;
    r[1] = (u)0 + -1;
    c = ((r[3] != r[1])); r[1] = 0; if (c) goto L800cb0e0;
    c = ((r[5] != r[1]));  if (c) goto L800cb0e0;
    L800cb0e0:;
    r[3] = lo_;
    r[4] = *(int *)((u)r[16] + 52);
    mul = (long long)(int)r[2] * (int)r[4]; hi_ = mul >> 32; lo_ = mul;
    r[2] = *(unsigned short *)((u)r[16] + 36);
    r[5] = lo_;
    c = (((int)r[5] >= 0)); r[3] = (u)r[2] + (u)r[3]; if (c) goto L800cb104;
    r[5] = (u)r[5] + 32767;
    L800cb104:;
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
    c = ((r[3] != 0));  if (c) goto L800cb148;
    L800cb148:;
    r[1] = (u)0 + -1;
    c = ((r[3] != r[1])); r[1] = 0; if (c) goto L800cb160;
    c = ((r[5] != r[1]));  if (c) goto L800cb160;
    L800cb160:;
    r[3] = lo_;
    r[4] = *(int *)((u)r[16] + 52);
    mul = (long long)(int)r[2] * (int)r[4]; hi_ = mul >> 32; lo_ = mul;
    r[2] = *(unsigned short *)((u)r[16] + 38);
    r[5] = lo_;
    c = (((int)r[5] >= 0)); r[3] = (u)r[2] + (u)r[3]; if (c) goto L800cb184;
    r[5] = (u)r[5] + 32767;
    L800cb184:;
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
    c = ((r[3] != 0));  if (c) goto L800cb1c8;
    L800cb1c8:;
    r[1] = (u)0 + -1;
    c = ((r[3] != r[1])); r[1] = 0; if (c) goto L800cb1e0;
    c = ((r[5] != r[1]));  if (c) goto L800cb1e0;
    L800cb1e0:;
    r[3] = lo_;
    r[4] = *(int *)((u)r[16] + 52);
    mul = (long long)(int)r[2] * (int)r[4]; hi_ = mul >> 32; lo_ = mul;
    r[2] = *(unsigned short *)((u)r[16] + 40);
    r[4] = lo_;
    c = (((int)r[4] >= 0)); r[3] = (u)r[2] + (u)r[3]; if (c) goto L800cb204;
    r[4] = (u)r[4] + 32767;
    L800cb204:;
    r[2] = (int)r[4] >> 15;
    r[2] = (u)r[3] + (u)r[2];
    *(short *)((u)r[29] + 20) = r[2];
    r[3] = *(int *)((u)r[16] + 56);
    r[2] = (u)r[3] < (u)6;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800cb298;
    r[2] = (u)r[2] + (int)R_s17a_dat_800E57A8;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800cb240: goto L800cb240; case 0x800cb250: goto L800cb250; case 0x800cb260: goto L800cb260; case 0x800cb270: goto L800cb270; case 0x800cb280: goto L800cb280; case 0x800cb290: goto L800cb290; default: goto out; }
    L800cb240:;
    r[4] = (u)r[29] + 16; CALL(R_AN_Blast_high);
     goto L800cb298;
    L800cb250:;
    r[4] = (u)0 + 2; CALL(R_GV_RandU);
    c = ((r[2] == 0));  if (c) goto L800cb280;
    L800cb260:;
    r[4] = (u)r[29] + 16; CALL(R_AN_Blast_Single);
     goto L800cb298;
    L800cb270:;
    r[4] = (u)0 + 2; CALL(R_GV_RandU);
    c = ((r[2] == 0));  if (c) goto L800cb290;
    L800cb280:;
    r[4] = (u)r[29] + 16; CALL(R_AN_Blast_Mini);
     goto L800cb298;
    L800cb290:;
    r[4] = (u)r[29] + 16; CALL(R_AN_Blast_Minimini);
    L800cb298:;
    r[2] = *(int *)((u)r[16] + 60);
    r[2] = (u)r[2] + -1;
    c = (((int)r[2] >= 0)); *(int *)((u)r[16] + 60) = r[2]; if (c) goto L800cb2b4;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    L800cb2b4:;
    r[2] = *(int *)((u)r[16] + 68);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + 68) = r[2];
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
int G_s17a_rc_800CB2D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_rc_800CB2D4");
int G_s17a_rc_800CB2D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
