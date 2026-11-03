extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_DG_MakePrim[] __asm__("DG_MakePrim");
extern char R_DG_QueuePrim[] __asm__("DG_QueuePrim");
extern char R_s10a_800CC25C[] __asm__("s10a_800CC25C");
int G_s10a_800CC2FC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CC2FC");
int G_s10a_800CC2FC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 32) = r[18];
    r[18] = (u)r[5] + (u)0;
    r[4] = (u)0 + (u)0;
    r[5] = (u)0 + 8;
    r[6] = (u)r[4] + (u)0;
    r[7] = (u)r[17] + 36;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 24) = r[16];
    *(int *)((u)r[29] + 16) = 0; CALL(R_DG_MakePrim);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0));  if (c) goto L800cc354;
    r[4] = (u)r[16] + (u)0; CALL(R_DG_QueuePrim);
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_CurrentMap);
    *(short *)((u)r[16] + 40) = r[2];
    L800cc354:;
    c = ((r[16] == 0)); *(int *)((u)r[17] + 32) = r[16]; if (c) goto L800cc37c;
    r[4] = *(int *)((u)r[16] + 64);
    r[5] = (u)r[18] + (u)0; CALL(R_s10a_800CC25C);
    r[4] = *(int *)((u)r[16] + 68);
    r[5] = (u)r[18] + (u)0; CALL(R_s10a_800CC25C);
    r[2] = (u)0 + (u)0; goto L800cc380;
    L800cc37c:;
    r[2] = (u)0 + -1;
    L800cc380:;
    r[31] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
