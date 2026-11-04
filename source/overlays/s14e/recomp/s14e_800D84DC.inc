extern char R_DG_SetChanlSystemUnits[] __asm__("DG_SetChanlSystemUnits");
int G_s14e_800D84DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800D84DC");
int G_s14e_800D84DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[5] = *(int *)((u)r[16] + 48);
    r[4] = (u)0 + 1; CALL(R_DG_SetChanlSystemUnits);
    r[5] = *(int *)((u)r[16] + 52);
    r[4] = (u)0 + 2; CALL(R_DG_SetChanlSystemUnits);
    r[5] = *(int *)((u)r[16] + 56);
    r[4] = (u)0 + 3; CALL(R_DG_SetChanlSystemUnits);
    r[5] = *(int *)((u)r[16] + 60);
    r[4] = (u)0 + 6; CALL(R_DG_SetChanlSystemUnits);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
