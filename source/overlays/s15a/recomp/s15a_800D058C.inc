extern char R_s15a_800CF83C[] __asm__("s15a_800CF83C");
extern char R_s15a_800CF920[] __asm__("s15a_800CF920");
extern char R_s15a_800CFA04[] __asm__("s15a_800CFA04");
extern char R_s15a_800CFD2C[] __asm__("s15a_800CFD2C");
int G_s15a_800D058C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D058C");
int G_s15a_800D058C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[6] + (u)0;
    r[2] = (u)0 + 4;
    c = ((r[17] == r[2])); *(int *)((u)r[29] + 28) = r[31]; if (c) goto L800d0600;
    r[6] = (u)0 + 1; CALL(R_s15a_800CFA04);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)0 + 1;
    r[7] = (u)r[18] + (u)0; CALL(R_s15a_800CFD2C);
    r[3] = *(int *)((u)r[16] + 16464);
    r[2] = (u)0 + 3;
    c = ((r[3] != r[2])); r[4] = (u)r[16] + (u)0; if (c) goto L800d05f4;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)0 + 1; CALL(R_s15a_800CF83C);
     goto L800d0600;
    L800d05f4:;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)0 + 1; CALL(R_s15a_800CF920);
    L800d0600:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
