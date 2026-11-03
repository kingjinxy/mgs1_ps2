extern char R_GM_PlayerMap[] __asm__("GM_PlayerMap");
extern char R_GM_SeSet[] __asm__("GM_SeSet");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s10a_800CBD0C[] __asm__("s10a_800CBD0C");
int G_s10a_800CAFA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CAFA8");
int G_s10a_800CAFA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[3] = 0;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 20) = r[17];
    r[2] = *(int *)((u)r[16] + 76);
    r[3] = *(int *)((u)r[3] + (int)R_GM_PlayerMap);
    r[2] = *(int *)((u)r[2] + 0);
    r[2] = r[2] & r[3];
    c = ((r[2] == 0)); r[18] = (u)r[5] + (u)0; if (c) goto L800cb02c;
    r[2] = *(int *)((u)r[16] + 156);
    c = ((r[18] != 0)); r[17] = (u)r[2] + 624; if (c) goto L800caff8;
    r[4] = (u)r[16] + 32;
    r[5] = (u)0 + 83; CALL(R_GM_SeSet);
    L800caff8:;
    r[2] = *(int *)((u)r[16] + 2920);
    c = ((r[2] == 0)); r[4] = (u)r[17] + (u)0; if (c) goto L800cb018;
    r[4] = *(int *)((u)r[16] + 2912);
     CALL(R_GV_DestroyActor);
    r[4] = (u)r[17] + (u)0;
    L800cb018:;
    r[5] = (u)r[18] + (u)0; CALL(R_s10a_800CBD0C);
    *(int *)((u)r[16] + 2912) = r[2];
    r[2] = (u)0 + 30;
    *(int *)((u)r[16] + 2920) = r[2];
    L800cb02c:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
