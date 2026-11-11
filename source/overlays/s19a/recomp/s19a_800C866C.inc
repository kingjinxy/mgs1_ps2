extern char R_HZD_GetAddress[] __asm__("HZD_GetAddress");
extern char R_HZD_ZoneDistance[] __asm__("HZD_ZoneDistance");
int G_s19a_800C866C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C866C");
int G_s19a_800C866C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[6] + (u)0;
    r[6] = (u)0 + -1;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 20) = r[17]; CALL(R_HZD_GetAddress);
    r[17] = (u)r[2] + (u)0;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[18] + (u)0;
    r[6] = (u)0 + -1; CALL(R_HZD_GetAddress);
    r[4] = (u)r[16] + (u)0;
    r[5] = r[17] & 255;
    r[6] = r[2] & 255; CALL(R_HZD_ZoneDistance);
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
