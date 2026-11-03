extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_GV_Clock[] __asm__("GV_Clock");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s10a_800CF14C[] __asm__("s10a_800CF14C");
extern char R_s10a_800CF2C8[] __asm__("s10a_800CF2C8");
int G_s10a_800CF300(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CF300");
int G_s10a_800CF300(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[3] = 0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[4] = *(int *)((u)r[16] + 680);
    r[2] = *(int *)((u)r[16] + 32);
    r[17] = (u)r[4] + -1;
    *(int *)((u)r[3] + (int)R_GM_CurrentMap) = r[2];
    c = (((int)r[17] > 0)); *(int *)((u)r[16] + 680) = r[17]; if (c) goto L800cf340;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
     goto L800cf374;
    L800cf340:;
    r[4] = (u)r[16] + 40;
    r[5] = (u)r[16] + 168;
    r[6] = (u)0 + 16; CALL(R_s10a_800CF14C);
    r[5] = (u)0 + 16;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GV_Clock);
    r[3] = *(int *)((u)r[16] + 36);
    r[2] = (u)r[2] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[4] = *(int *)((u)r[3] + 64);
    r[6] = (u)r[17] << 4; CALL(R_s10a_800CF2C8);
    L800cf374:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
