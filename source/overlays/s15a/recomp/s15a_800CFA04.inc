extern char R_GM_GetMap[] __asm__("GM_GetMap");
extern char R_HZD_DequeueDynamicFloor[] __asm__("HZD_DequeueDynamicFloor");
extern char R_HZD_DequeueDynamicSegment[] __asm__("HZD_DequeueDynamicSegment");
int G_s15a_800CFA04(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CFA04");
int G_s15a_800CFA04(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 32) = r[20];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 16) = r[16];
    r[4] = *(int *)((u)r[17] + 32);
    r[20] = (u)r[6] + (u)0; CALL(R_GM_GetMap);
    r[16] = (u)r[19] << 7;
    r[16] = (u)r[16] + 13756;
    r[16] = (u)r[17] + (u)r[16];
    r[3] = (u)r[20] << 6;
    r[16] = (u)r[16] + (u)r[3];
    r[18] = *(int *)((u)r[2] + 8);
    r[5] = (u)r[16] + (u)0;
    r[4] = (u)r[18] + (u)0; CALL(R_HZD_DequeueDynamicSegment);
    r[4] = (u)r[18] + (u)0;
    r[5] = (u)r[16] + 16; CALL(R_HZD_DequeueDynamicSegment);
    r[4] = (u)r[18] + (u)0;
    r[5] = (u)r[16] + 32; CALL(R_HZD_DequeueDynamicSegment);
    r[4] = (u)r[18] + (u)0;
    r[5] = (u)r[16] + 48; CALL(R_HZD_DequeueDynamicSegment);
    r[4] = (u)r[18] + (u)0;
    r[2] = (u)r[19] << 1;
    r[2] = (u)r[2] + (u)r[19];
    r[2] = (u)r[2] << 6;
    r[2] = (u)r[2] + 14396;
    r[17] = (u)r[17] + (u)r[2];
    r[2] = (u)r[20] << 1;
    r[2] = (u)r[2] + (u)r[20];
    r[2] = (u)r[2] << 5;
    r[17] = (u)r[17] + (u)r[2];
    r[5] = (u)r[17] + (u)0; CALL(R_HZD_DequeueDynamicFloor);
    r[4] = (u)r[18] + (u)0;
    r[5] = (u)r[17] + 48; CALL(R_HZD_DequeueDynamicFloor);
    r[31] = *(int *)((u)r[29] + 36);
    r[20] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
