extern char R_s11h_800CAC78[] __asm__("s11h_800CAC78");
int G_s11h_800CACBC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800CACBC");
int G_s11h_800CACBC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[4] = r[4] & 255;
    *(int *)((u)r[29] + 16) = r[31];
    r[5] = (u)0 + (u)0; CALL(R_s11h_800CAC78);
    r[31] = *(int *)((u)r[29] + 16);
    r[2] = r[2] & 65535;
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
