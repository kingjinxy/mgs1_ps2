extern char R_s18a_800CC2A0[] __asm__("s18a_800CC2A0");
extern char R_s18a_800CC6DC[] __asm__("s18a_800CC6DC");
extern char R_s18a_800CC73C[] __asm__("s18a_800CC73C");
extern char R_s18a_800CC76C[] __asm__("s18a_800CC76C");
extern char R_s18a_800D0D28[] __asm__("s18a_800D0D28");
int G_s18a_800CC7BC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CC7BC");
int G_s18a_800CC7BC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s18a_800CC76C);
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CC73C);
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D0D28);
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CC2A0);
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CC6DC);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
