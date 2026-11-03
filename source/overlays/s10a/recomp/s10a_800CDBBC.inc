extern char R_s10a_dat_800E4990[] __asm__("s10a_dat_800E4990");
extern char R_s10a_800CC774[] __asm__("s10a_800CC774");
extern char R_s10a_800CD674[] __asm__("s10a_800CD674");
extern char R_s10a_800CD76C[] __asm__("s10a_800CD76C");
extern char R_s10a_800CD970[] __asm__("s10a_800CD970");
extern char R_s10a_800CDA68[] __asm__("s10a_800CDA68");
int G_s10a_800CDBBC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CDBBC");
int G_s10a_800CDBBC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(short *)((u)r[16] + 2850);
    r[2] = (u)0 + 8;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 9; if (c) goto L800cdc10;
    c = ((r[2] == 0)); r[2] = (u)0 + 7; if (c) goto L800cdbf4;
    c = ((r[3] == r[2])); r[2] = 0; if (c) goto L800cdc40;
     goto L800cdc4c;
    L800cdbf4:;
    r[2] = (u)0 + 9;
    c = ((r[3] == r[2])); r[2] = (u)0 + 10; if (c) goto L800cdc20;
    c = ((r[3] == r[2])); r[2] = 0; if (c) goto L800cdc30;
     goto L800cdc4c;
    L800cdc10:;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CD970);
    r[2] = 0; goto L800cdc4c;
    L800cdc20:;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CD76C);
    r[2] = 0; goto L800cdc4c;
    L800cdc30:;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CDA68);
    r[2] = 0; goto L800cdc4c;
    L800cdc40:;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CD674);
    r[2] = 0;
    L800cdc4c:;
    r[3] = *(int *)((u)r[2] + (int)R_s10a_dat_800E4990);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2]));  if (c) goto L800cdc64;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CC774);
    L800cdc64:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
