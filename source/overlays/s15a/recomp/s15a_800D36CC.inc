extern char R_DG_ZeroVector[] __asm__("DG_ZeroVector");
extern char R_DG_PutVector[] __asm__("DG_PutVector");
extern char R_DG_SetPos2[] __asm__("DG_SetPos2");
extern char R_GV_AddVec3[] __asm__("GV_AddVec3");
extern char R_s15a_800D33D0[] __asm__("s15a_800D33D0");
int G_s15a_800D36CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D36CC");
int G_s15a_800D36CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[16] + 4;
    r[4] = (u)r[18] + (u)0;
    r[5] = (u)r[16] + 900;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[16] + 80;
    *(int *)((u)r[29] + 28) = r[31];
    r[6] = (u)r[17] + (u)0; CALL(R_s15a_800D33D0);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_DG_ZeroVector;
    r[5] = (u)r[17] + (u)0; CALL(R_DG_SetPos2);
    r[4] = (u)r[16] + 924;
    r[16] = (u)r[16] + 932;
    r[5] = (u)r[16] + (u)0;
    r[6] = (u)0 + 1; CALL(R_DG_PutVector);
    r[4] = (u)r[18] + (u)0;
    r[5] = (u)r[16] + (u)0;
    r[6] = (u)r[4] + (u)0; CALL(R_GV_AddVec3);
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
