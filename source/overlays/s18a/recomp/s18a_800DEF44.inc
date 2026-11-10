extern char R_GM_PlayerBody[] __asm__("GM_PlayerBody");
extern char R_GM_PlayerControl[] __asm__("GM_PlayerControl");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_DG_DequeuePrim[] __asm__("DG_DequeuePrim");
extern char R_DG_FreePrim[] __asm__("DG_FreePrim");
extern char R_GM_FreeControl[] __asm__("GM_FreeControl");
extern char R_GM_FreeObject[] __asm__("GM_FreeObject");
extern char R_GM_FreeTarget[] __asm__("GM_FreeTarget");
extern char R_GV_DestroyOtherActor[] __asm__("GV_DestroyOtherActor");
int G_s18a_800DEF44(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DEF44");
int G_s18a_800DEF44(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 28) = r[19];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 16) = r[16];
    r[4] = *(int *)((u)r[17] + 2012);
    r[18] = (u)r[17] + 32; CALL(R_GV_DestroyOtherActor);
    r[4] = (u)r[18] + (u)0; CALL(R_GM_FreeControl);
    r[19] = (u)r[17] + 156;
    r[4] = (u)r[19] + (u)0; CALL(R_GM_FreeObject);
    r[4] = *(int *)((u)r[17] + 2024);
     CALL(R_GM_FreeTarget);
    r[16] = *(int *)((u)r[17] + 2164);
    c = ((r[16] == 0)); r[5] = 0; if (c) goto L800defb0;
    r[4] = (u)r[16] + (u)0; CALL(R_DG_DequeuePrim);
    r[4] = (u)r[16] + (u)0; CALL(R_DG_FreePrim);
    r[5] = 0;
    L800defb0:;
    r[2] = *(unsigned short *)((u)r[17] + 2302);
    r[4] = *(int *)((u)r[5] + (int)R_GM_PlayerControl);
    r[3] = 0;
    c = ((r[4] != r[18])); *(short *)((u)r[3] + ((int)R_linkvarbuf + 32)) = r[2]; if (c) goto L800defc8;
    *(int *)((u)r[5] + (int)R_GM_PlayerControl) = 0;
    L800defc8:;
    r[3] = 0;
    r[2] = *(int *)((u)r[3] + (int)R_GM_PlayerBody);
    c = ((r[2] != r[19]));  if (c) goto L800defe0;
    *(int *)((u)r[3] + (int)R_GM_PlayerBody) = 0;
    L800defe0:;
    r[31] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
