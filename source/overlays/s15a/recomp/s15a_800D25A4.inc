extern char R_DG_SetPos2[] __asm__("DG_SetPos2");
extern char R_GM_ActObject2[] __asm__("GM_ActObject2");
extern char R_s15a_800CE56C[] __asm__("s15a_800CE56C");
int G_s15a_800D25A4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D25A4");
int G_s15a_800D25A4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[6] + (u)0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[17] << 2;
    r[16] = (u)r[16] + (u)r[17];
    r[16] = (u)r[16] << 3;
    r[16] = (u)r[16] - (u)r[17];
    r[16] = (u)r[16] << 2;
    r[16] = (u)r[16] + 36;
    r[16] = (u)r[18] + (u)r[16];
    r[4] = (u)r[16] + 76;
    r[5] = (u)r[16] + 84;
    *(int *)((u)r[29] + 32) = r[31];
    r[16] = (u)r[16] + 4; CALL(R_DG_SetPos2);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[19] + (u)0;
    r[6] = (u)0 + 71; CALL(R_s15a_800CE56C);
    r[17] = (u)r[17] << 3;
    r[18] = (u)r[18] + (u)r[17];
    r[2] = (u)0 + 1;
    r[4] = (u)r[16] + (u)0;
    *(int *)((u)r[18] + 11268) = r[2]; CALL(R_GM_ActObject2);
    r[31] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
