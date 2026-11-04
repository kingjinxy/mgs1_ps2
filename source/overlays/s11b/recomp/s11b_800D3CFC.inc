extern char R_DG_Chanls[] __asm__("DG_Chanls");
extern char R_ratan2[] __asm__("ratan2");
int G_s11b_800D3CFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800D3CFC");
int G_s11b_800D3CFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[2] = 0;
    r[2] = (u)r[2] + ((int)R_DG_Chanls + 492);
    r[2] = (u)r[2] + 48;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[3] = *(unsigned short *)((u)r[2] + 20);
    *(short *)((u)r[4] + 0) = r[3];
    r[3] = *(unsigned short *)((u)r[2] + 24);
    *(short *)((u)r[4] + 2) = r[3];
    r[3] = *(unsigned short *)((u)r[2] + 28);
    r[16] = (u)r[5] + (u)0;
    *(short *)((u)r[4] + 4) = r[3];
    r[4] = *(short *)((u)r[2] + 4);
    r[5] = *(short *)((u)r[2] + 16);
     CALL(R_ratan2);
    *(int *)((u)r[16] + 0) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
