extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s17a_800C89AC[] __asm__("s17a_800C89AC");
extern char R_s17a_800C89E8[] __asm__("s17a_800C89E8");
int G_s17a_800C8B98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800C8B98");
int G_s17a_800C8B98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[4] + (u)0;
    r[2] = 0;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[6] + (u)0;
    r[3] = *(int *)((u)r[29] + 56);
    r[2] = *(int *)((u)r[2] + (int)R_GM_CurrentMap);
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[17] + 124) = r[2];
    *(int *)((u)r[29] + 16) = r[3]; CALL(R_s17a_800C89AC);
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[16] + (u)0; CALL(R_s17a_800C89E8);
    r[3] = (u)0 + -1;
    c = ((r[2] != r[3]));  if (c) goto L800c8be8;
    r[4] = (u)r[17] + (u)0; CALL(R_GV_DestroyActor);
    L800c8be8:;
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
