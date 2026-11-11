extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_GM_FreeControl[] __asm__("GM_FreeControl");
extern char R_GM_FreeObject[] __asm__("GM_FreeObject");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_HZD_DequeueDynamicSegment[] __asm__("HZD_DequeueDynamicSegment");
int G_s19a_800D974C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D974C");
int G_s19a_800D974C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    r[4] = (u)r[18] + 48;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GM_FreeControl);
    r[4] = (u)r[18] + 172; CALL(R_GM_FreeObject);
    r[4] = (u)r[18] + 400; CALL(R_GM_FreeObject);
    r[4] = (u)r[18] + 628; CALL(R_GM_FreeObject);
    r[4] = (u)r[18] + 800; CALL(R_GM_FreeObject);
    r[4] = (u)r[18] + 836; CALL(R_GM_FreeObject);
    r[4] = *(int *)((u)r[18] + 32);
    c = ((r[4] == 0));  if (c) goto L800d97ac;
     CALL(R_GV_DestroyActor);
    L800d97ac:;
    r[4] = *(int *)((u)r[18] + 36);
    c = ((r[4] == 0));  if (c) goto L800d97c4;
     CALL(R_GV_DestroyActor);
    L800d97c4:;
    r[4] = 0xff7f0000;
    r[4] = r[4] | 65535;
    r[17] = (u)0 + (u)0;
    r[3] = 0;
    r[2] = *(int *)((u)r[3] + (int)R_GM_PlayerStatus);
    r[16] = (u)0 + 1440;
    r[2] = r[2] & r[4];
    *(int *)((u)r[3] + (int)R_GM_PlayerStatus) = r[2];
    L800d97e4:;
    r[4] = *(int *)((u)r[18] + 1436);
    r[5] = (u)r[18] + (u)r[16];
    r[16] = (u)r[16] + 16;
    r[17] = (u)r[17] + 1; CALL(R_HZD_DequeueDynamicSegment);
    r[2] = (int)r[17] < 8;
    c = ((r[2] != 0));  if (c) goto L800d97e4;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
