extern char R_s10a_dat_800E3D18[] __asm__("s10a_dat_800E3D18");
extern char R_s10a_dat_800E4970[] __asm__("s10a_dat_800E4970");
extern char R_fprintf[] __asm__("fprintf");
extern char R_s10a_800CD308[] __asm__("s10a_800CD308");
int G_s10a_800CD460(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CD460");
int G_s10a_800CD460(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    r[2] = 0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[2] + (int)R_s10a_dat_800E4970;
    *(int *)((u)r[29] + 24) = r[31];
    r[3] = *(unsigned char *)((u)r[17] + 2938);
    r[2] = *(int *)((u)r[16] + 36);
    c = ((r[3] != r[2])); r[4] = (u)0 + 1; if (c) goto L800cd498;
    r[2] = (u)0 + (u)0; goto L800cd4b8;
    L800cd498:;
    r[5] = 0;
    r[5] = (u)r[5] + ((int)R_s10a_dat_800E3D18 + 16); CALL(R_fprintf);
    r[2] = *(unsigned char *)((u)r[16] + 36);
    r[4] = (u)r[17] + (u)0;
    *(char *)((u)r[4] + 2938) = r[2]; CALL(R_s10a_800CD308);
    r[2] = (u)0 + 1;
    L800cd4b8:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
