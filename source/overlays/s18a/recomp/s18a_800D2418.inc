extern char R_DG_GetLightMatrix2[] __asm__("DG_GetLightMatrix2");
extern char R_GM_ActControl[] __asm__("GM_ActControl");
extern char R_GM_ActObject2[] __asm__("GM_ActObject2");
extern char R_GM_CheckMessage[] __asm__("GM_CheckMessage");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s18a_800D2388[] __asm__("s18a_800D2388");
extern char R_s18a_800D4780[] __asm__("s18a_800D4780");
int G_s18a_800D2418(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D2418");
int G_s18a_800D2418(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[16] + 32;
    *(int *)((u)r[29] + 24) = r[31];
    r[5] = *(unsigned short *)((u)r[17] + 48);
    r[6] = (u)0 + 12835; CALL(R_GM_CheckMessage);
    c = ((r[2] != 0));  if (c) goto L800d2488;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D2388);
    r[4] = (u)r[17] + (u)0; CALL(R_GM_ActControl);
    r[4] = (u)r[16] + 156; CALL(R_GM_ActObject2);
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D4780);
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[16] + 2296; CALL(R_DG_GetLightMatrix2);
    r[4] = (u)r[16] + (u)0;
    r[5] = *(unsigned short *)((u)r[17] + 48);
    r[6] = (u)0 + 12835; CALL(R_GM_CheckMessage);
    c = ((r[2] == 0));  if (c) goto L800d2490;
    L800d2488:;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    L800d2490:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
