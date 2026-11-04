extern char R_DG_Chanls[] __asm__("DG_Chanls");
extern char R_GV_Clock[] __asm__("GV_Clock");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s10a_800E11C0[] __asm__("s10a_800E11C0");
int G_s10a_800E13BC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800E13BC");
int G_s10a_800E13BC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 32) = r[20];
    r[20] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[2] = 0;
    r[3] = 0;
    r[2] = (u)r[2] + ((int)R_DG_Chanls + 492);
    *(int *)((u)r[29] + 40) = r[31];
    *(int *)((u)r[29] + 36) = r[21];
    *(int *)((u)r[29] + 28) = r[19];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = *(int *)((u)r[20] + 32);
    r[3] = *(int *)((u)r[3] + (int)R_GV_Clock);
    r[17] = *(int *)((u)r[20] + 36);
    r[3] = (u)r[3] << 2;
    r[2] = (u)r[2] + (u)r[3];
    r[19] = *(int *)((u)r[2] + 492);
    c = (((int)r[17] <= 0)); r[18] = (u)0 + (u)0; if (c) goto L800e143c;
    r[21] = (u)0 + 4;
    L800e1410:;
    r[4] = (u)r[19] + (u)0;
    r[5] = (u)r[16] + (u)0; CALL(R_s10a_800E11C0);
    r[2] = *(int *)((u)r[16] + 112);
    c = ((r[2] != r[21]));  if (c) goto L800e1430;
    r[18] = (u)r[18] + 1;
    L800e1430:;
    r[17] = (u)r[17] + -1;
    c = (((int)r[17] > 0)); r[16] = (u)r[16] + 132; if (c) goto L800e1410;
    L800e143c:;
    r[2] = *(int *)((u)r[20] + 36);
    c = ((r[18] != r[2]));  if (c) goto L800e1454;
    r[4] = (u)r[20] + (u)0; CALL(R_GV_DestroyActor);
    L800e1454:;
    r[31] = *(int *)((u)r[29] + 40);
    r[21] = *(int *)((u)r[29] + 36);
    r[20] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
