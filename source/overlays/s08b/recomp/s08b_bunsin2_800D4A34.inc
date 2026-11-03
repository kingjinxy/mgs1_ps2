extern char R_s08b_dword_800E3BB0[] __asm__("s08b_dword_800E3BB0");
extern char R_s08b_bunsin2_800D1D44[] __asm__("s08b_bunsin2_800D1D44");
extern char R_s08b_bunsin2_800D2420[] __asm__("s08b_bunsin2_800D2420");
extern char R_s08b_bunsin2_800D2600[] __asm__("s08b_bunsin2_800D2600");
extern char R_s08b_bunsin2_800D3064[] __asm__("s08b_bunsin2_800D3064");
extern char R_s08b_bunsin2_800D3468[] __asm__("s08b_bunsin2_800D3468");
extern char R_s08b_bunsin2_800D3C44[] __asm__("s08b_bunsin2_800D3C44");
extern char R_s08b_bunsin2_800D3CCC[] __asm__("s08b_bunsin2_800D3CCC");
extern char R_s08b_bunsin2_800D43D8[] __asm__("s08b_bunsin2_800D43D8");
int G_s08b_bunsin2_800D4A34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800D4A34");
int G_s08b_bunsin2_800D4A34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 6600);
    r[2] = (u)r[3] < (u)10;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d4ae4;
    r[2] = (u)r[2] + (int)R_s08b_dword_800E3BB0;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d4a6c: goto L800d4a6c; case 0x800d4a7c: goto L800d4a7c; case 0x800d4a8c: goto L800d4a8c; case 0x800d4a9c: goto L800d4a9c; case 0x800d4aac: goto L800d4aac; case 0x800d4abc: goto L800d4abc; case 0x800d4acc: goto L800d4acc; case 0x800d4adc: goto L800d4adc; case 0x800d4ae4: goto L800d4ae4; default: goto out; }
    L800d4a6c:;
     CALL(R_s08b_bunsin2_800D1D44);
     goto L800d4ae4;
    L800d4a7c:;
     CALL(R_s08b_bunsin2_800D3468);
     goto L800d4ae4;
    L800d4a8c:;
     CALL(R_s08b_bunsin2_800D3C44);
     goto L800d4ae4;
    L800d4a9c:;
     CALL(R_s08b_bunsin2_800D3CCC);
     goto L800d4ae4;
    L800d4aac:;
     CALL(R_s08b_bunsin2_800D43D8);
     goto L800d4ae4;
    L800d4abc:;
     CALL(R_s08b_bunsin2_800D2600);
     goto L800d4ae4;
    L800d4acc:;
     CALL(R_s08b_bunsin2_800D2420);
     goto L800d4ae4;
    L800d4adc:;
     CALL(R_s08b_bunsin2_800D3064);
    L800d4ae4:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
