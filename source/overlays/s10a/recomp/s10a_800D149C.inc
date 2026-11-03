extern char R_s10a_800D0F5C[] __asm__("s10a_800D0F5C");
extern char R_s10a_800D13B0[] __asm__("s10a_800D13B0");
int G_s10a_800D149C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D149C");
int G_s10a_800D149C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)r[16] + 32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[16] + 108;
    *(int *)((u)r[29] + 24) = r[31];
    r[5] = *(int *)((u)r[16] + 924);
    r[6] = (u)r[17] + (u)0;
    r[5] = (u)r[5] << 3;
    r[5] = (u)r[5] + 940;
    r[5] = (u)r[16] + (u)r[5]; CALL(R_s10a_800D0F5C);
    r[4] = (u)r[16] + 816;
    r[5] = (u)r[17] + (u)0;
    r[6] = (u)r[16] + (u)0; CALL(R_s10a_800D13B0);
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
