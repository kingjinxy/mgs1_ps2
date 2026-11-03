extern char R_s10a_800CA640[] __asm__("s10a_800CA640");
extern char R_GV_NearExp2[] __asm__("GV_NearExp2");
int G_s10a_800CADC4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CADC4");
int G_s10a_800CADC4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 28) = r[19];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 16) = r[16];
    r[3] = *(int *)((u)r[17] + 2304);
    r[2] = (u)0 + 1;
    *(int *)((u)r[17] + 2896) = 0;
    *(short *)((u)r[17] + 2956) = 0;
    *(short *)((u)r[3] + 0) = r[2];
    r[3] = *(short *)((u)r[17] + 180);
    r[2] = *(int *)((u)r[17] + 2528);
    mul = (long long)(int)r[3] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[19] = (u)r[17] + 2248;
    r[16] = *(int *)((u)r[17] + 2284);
    r[18] = (u)r[17] + 32;
    *(int *)((u)r[17] + 2300) = 0;
    *(int *)((u)r[17] + 2924) = 0;
    r[3] = lo_;
    c = (((int)r[3] >= 0)); *(int *)((u)r[17] + 3124) = 0; if (c) goto L800cae28;
    r[3] = (u)r[3] + 4095;
    L800cae28:;
    r[2] = *(unsigned short *)((u)r[18] + 120);
    r[3] = (int)r[3] >> 12;
    *(short *)((u)r[18] + 50) = r[3];
    r[2] = (u)r[2] + 750;
    *(short *)((u)r[18] + 52) = r[2];
    r[5] = *(int *)((u)r[17] + 2292);
    r[2] = (u)r[5] + 1;
    c = ((r[16] != 0)); *(int *)((u)r[17] + 2292) = r[2]; if (c) goto L800cae5c;
    r[2] = 0;
    r[16] = (u)r[2] + (int)R_s10a_800CA640;
    *(int *)((u)r[17] + 2284) = r[16];
    L800cae5c:;
    t = r[16]; r[4] = (u)r[17] + (u)0; CALL((int (*)())t);
    r[16] = *(int *)((u)r[17] + 2288);
    c = ((r[16] == 0)); r[4] = (u)r[17] + (u)0; if (c) goto L800cae88;
    r[5] = *(int *)((u)r[17] + 2296);
    r[2] = (u)r[5] + 1;
    t = r[16]; *(int *)((u)r[17] + 2296) = r[2]; CALL((int (*)())t);
    L800cae88:;
    r[2] = *(short *)((u)r[19] + 30);
    c = ((r[2] != 0)); r[2] = (u)0 + -1; if (c) goto L800caeb0;
    r[4] = *(short *)((u)r[18] + 54);
    r[5] = *(short *)((u)r[19] + 28);
     CALL(R_GV_NearExp2);
    *(short *)((u)r[18] + 54) = r[2]; goto L800caeb4;
    L800caeb0:;
    *(short *)((u)r[18] + 54) = r[2];
    L800caeb4:;
    r[2] = *(int *)((u)r[17] + 2304);
    r[2] = *(unsigned short *)((u)r[2] + 0);
    r[2] = r[2] & 4;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800caedc;
    r[3] = *(int *)((u)r[17] + 2524);
    *(int *)((u)r[3] + 8) = r[2]; goto L800caee8;
    L800caedc:;
    r[2] = *(int *)((u)r[17] + 2524);
    *(int *)((u)r[2] + 8) = 0;
    L800caee8:;
    r[2] = *(short *)((u)r[19] + 4);
    c = (((int)r[2] >= 0));  if (c) goto L800caf0c;
    r[2] = *(signed char *)((u)r[18] + 87);
    c = ((r[2] == 0));  if (c) goto L800caf0c;
    *(short *)((u)r[19] + 4) = 0;
    L800caf0c:;
    r[2] = *(unsigned short *)((u)r[19] + 4);
    r[2] = (u)r[2] + -16;
    *(short *)((u)r[19] + 4) = r[2];
    *(short *)((u)r[18] + 70) = r[2];
    r[2] = *(int *)((u)r[17] + 2920);
    c = (((int)r[2] <= 0)); r[2] = (u)r[2] + -1; if (c) goto L800caf34;
    *(int *)((u)r[17] + 2920) = r[2];
    L800caf34:;
    r[31] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800CAF50(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800CAF50");
int G_s10a_rc_800CAF50(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800CAF58(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800CAF58");
int G_s10a_rc_800CAF58(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800CAF60(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800CAF60");
int G_s10a_rc_800CAF60(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800CAF68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800CAF68");
int G_s10a_rc_800CAF68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800CAF70(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800CAF70");
int G_s10a_rc_800CAF70(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800CAF78(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800CAF78");
int G_s10a_rc_800CAF78(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800CAF80(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800CAF80");
int G_s10a_rc_800CAF80(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800CAF88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800CAF88");
int G_s10a_rc_800CAF88(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800CAF90(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800CAF90");
int G_s10a_rc_800CAF90(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800CAF98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800CAF98");
int G_s10a_rc_800CAF98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800CAFA0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800CAFA0");
int G_s10a_rc_800CAFA0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
