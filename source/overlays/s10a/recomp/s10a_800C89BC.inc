extern char R_s10a_800C8828[] __asm__("s10a_800C8828");
extern char R_s10a_800C896C[] __asm__("s10a_800C896C");
extern char R_s10a_800C94A8[] __asm__("s10a_800C94A8");
int G_s10a_800C89BC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C89BC");
int G_s10a_800C89BC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s10a_800C896C);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800C94A8);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800C8828);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
