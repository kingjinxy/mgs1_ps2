extern char R_s10a_800E0144[] __asm__("s10a_800E0144");
extern char R_s10a_800E024C[] __asm__("s10a_800E024C");
int G_s10a_800E301C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800E301C");
int G_s10a_800E301C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)0 + 112;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[16] + 36) = r[5];
    r[5] = (u)r[16] + 44;
    *(int *)((u)r[16] + 32) = r[6]; CALL(R_s10a_800E024C);
    r[4] = (u)0 + 114; CALL(R_s10a_800E0144);
    r[4] = (u)0 + 110;
    *(short *)((u)r[16] + 52) = r[2]; CALL(R_s10a_800E0144);
    r[4] = (u)0 + 116;
    *(short *)((u)r[16] + 54) = r[2]; CALL(R_s10a_800E0144);
    r[4] = (u)0 + 105;
    *(short *)((u)r[16] + 56) = r[2]; CALL(R_s10a_800E0144);
    r[4] = (u)0 + 99;
    *(short *)((u)r[16] + 58) = r[2]; CALL(R_s10a_800E0144);
    r[4] = (u)0 + 115;
    *(short *)((u)r[16] + 60) = r[2]; CALL(R_s10a_800E0144);
    *(int *)((u)r[16] + 40) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
