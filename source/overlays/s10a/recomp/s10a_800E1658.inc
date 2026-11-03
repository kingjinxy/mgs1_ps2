extern char R_DG_Chanls[] __asm__("DG_Chanls");
extern char R_GV_Clock[] __asm__("GV_Clock");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s10a_800E11C0[] __asm__("s10a_800E11C0");
int G_s10a_800E1658(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800E1658");
int G_s10a_800E1658(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    r[3] = 0;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GV_Clock);
    r[3] = (u)r[3] + ((int)R_DG_Chanls + 492);
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = *(int *)((u)r[17] + 32);
    r[2] = (u)r[2] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[4] = *(int *)((u)r[3] + 492);
    r[5] = (u)r[16] + (u)0; CALL(R_s10a_800E11C0);
    r[3] = *(int *)((u)r[16] + 112);
    r[2] = (u)0 + 4;
    c = ((r[3] != r[2]));  if (c) goto L800e16ac;
    r[4] = (u)r[17] + (u)0; CALL(R_GV_DestroyActor);
    L800e16ac:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
