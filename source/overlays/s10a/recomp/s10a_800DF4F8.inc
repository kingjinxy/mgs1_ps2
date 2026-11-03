extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_DG_PutPrim[] __asm__("DG_PutPrim");
extern char R_DG_SetPos[] __asm__("DG_SetPos");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s10a_800DF4B8[] __asm__("s10a_800DF4B8");
int G_s10a_800DF4F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800DF4F8");
int G_s10a_800DF4F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = 0;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 20) = r[17];
    r[3] = *(int *)((u)r[16] + 328);
    r[2] = *(int *)((u)r[16] + 32);
    r[3] = (u)r[3] + -1;
    r[18] = (u)r[3] << 16;
    r[17] = (int)r[18] >> 16;
    *(int *)((u)r[4] + (int)R_GM_CurrentMap) = r[2];
    c = (((int)r[17] > 0)); *(int *)((u)r[16] + 328) = r[3]; if (c) goto L800df544;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
     goto L800df590;
    L800df544:;
    r[4] = (u)r[16] + 296;
    r[2] = (u)0 + 80;
    r[2] = (u)r[2] - (u)r[17];
    r[2] = (u)r[2] << 5;
    *(short *)((u)r[16] + 296) = r[2];
    *(short *)((u)r[16] + 304) = r[2];
    *(short *)((u)r[16] + 312) = r[2]; CALL(R_DG_SetPos);
    r[4] = *(int *)((u)r[16] + 36);
     CALL(R_DG_PutPrim);
    r[7] = (u)r[18] >> 31;
    r[7] = (u)r[17] + (u)r[7];
    r[2] = *(int *)((u)r[16] + 36);
    r[6] = (u)0 + 8;
    r[4] = *(int *)((u)r[2] + 64);
    r[5] = *(int *)((u)r[2] + 68);
    r[7] = (int)r[7] >> 1; CALL(R_s10a_800DF4B8);
    L800df590:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
