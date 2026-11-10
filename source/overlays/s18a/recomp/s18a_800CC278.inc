extern char R_sna_act_helper2_helper2_80033054[] __asm__("sna_act_helper2_helper2_80033054");
int G_s18a_800CC278(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CC278");
int G_s18a_800CC278(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[5] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 16) = r[31];
    r[4] = *(unsigned short *)((u)r[5] + 80);
    r[5] = (u)r[5] + 2084; CALL(R_sna_act_helper2_helper2_80033054);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
