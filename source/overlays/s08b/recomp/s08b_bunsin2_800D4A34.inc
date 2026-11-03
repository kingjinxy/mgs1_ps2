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
    t = r[2];  switch ((u)t) {  default: goto out; }
     CALL(R_s08b_bunsin2_800D1D44);
     goto L800d4ae4;
     CALL(R_s08b_bunsin2_800D3468);
     goto L800d4ae4;
     CALL(R_s08b_bunsin2_800D3C44);
     goto L800d4ae4;
     CALL(R_s08b_bunsin2_800D3CCC);
     goto L800d4ae4;
     CALL(R_s08b_bunsin2_800D43D8);
     goto L800d4ae4;
     CALL(R_s08b_bunsin2_800D2600);
     goto L800d4ae4;
     CALL(R_s08b_bunsin2_800D2420);
     goto L800d4ae4;
     CALL(R_s08b_bunsin2_800D3064);
    L800d4ae4:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
