extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_s17a_dat_800E574C[] __asm__("s17a_dat_800E574C");
extern char R_DG_GetTexture[] __asm__("DG_GetTexture");
extern char R_DG_MakePrim[] __asm__("DG_MakePrim");
extern char R_DG_QueuePrim[] __asm__("DG_QueuePrim");
extern char R_GV_StrCode[] __asm__("GV_StrCode");
extern char R_s17a_800C8DB0[] __asm__("s17a_800C8DB0");
int G_s17a_800C9D68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800C9D68");
int G_s17a_800C9D68(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[18];
    r[18] = (u)r[4] + (u)0;
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s17a_dat_800E574C;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 28) = r[17];
    *(int *)((u)r[29] + 24) = r[16]; CALL(R_GV_StrCode);
    r[4] = (u)r[2] + (u)0; CALL(R_DG_GetTexture);
    r[17] = (u)r[2] + (u)0;
    c = ((r[17] == 0)); r[4] = (u)0 + 18; if (c) goto L800c9e18;
    *(int *)((u)r[29] + 16) = 0;
    r[5] = (u)0 + 17;
    r[6] = (u)0 + (u)0;
    r[7] = (u)r[18] + 212; CALL(R_DG_MakePrim);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0));  if (c) goto L800c9dd8;
    r[4] = (u)r[16] + (u)0; CALL(R_DG_QueuePrim);
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_CurrentMap);
    *(short *)((u)r[16] + 40) = r[2];
    L800c9dd8:;
    c = ((r[16] == 0)); *(int *)((u)r[18] + 48) = r[16]; if (c) goto L800c9e18;
    r[4] = (u)r[18] + (u)0;
    r[6] = (u)0 + 17;
    r[7] = (u)r[17] + (u)0;
    r[5] = *(int *)((u)r[16] + 64);
    r[2] = (u)0 + 200;
    *(short *)((u)r[16] + 46) = r[2]; CALL(R_s17a_800C8DB0);
    r[4] = (u)r[18] + (u)0;
    r[6] = (u)0 + 17;
    r[5] = *(int *)((u)r[16] + 68);
    r[7] = (u)r[17] + (u)0; CALL(R_s17a_800C8DB0);
    r[2] = (u)0 + (u)0; goto L800c9e1c;
    L800c9e18:;
    r[2] = (u)0 + -1;
    L800c9e1c:;
    r[31] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
