extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_s17a_800DD460[] __asm__("s17a_800DD460");
int G_s17a_800DD06C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800DD06C");
int G_s17a_800DD06C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 76);
    r[4] = *(int *)((u)r[16] + 32);
    r[6] = *(int *)((u)r[2] + 0);
    r[7] = *(int *)((u)r[2] + 4);
    r[8] = *(int *)((u)r[2] + 8);
    r[9] = *(int *)((u)r[2] + 12);
    *(int *)((u)r[16] + 44) = r[6];
    *(int *)((u)r[16] + 48) = r[7];
    *(int *)((u)r[16] + 52) = r[8];
    *(int *)((u)r[16] + 56) = r[9];
    r[6] = *(int *)((u)r[2] + 16);
    r[7] = *(int *)((u)r[2] + 20);
    r[8] = *(int *)((u)r[2] + 24);
    r[9] = *(int *)((u)r[2] + 28);
    *(int *)((u)r[16] + 60) = r[6];
    *(int *)((u)r[16] + 64) = r[7];
    *(int *)((u)r[16] + 68) = r[8];
    *(int *)((u)r[16] + 72) = r[9];
    r[3] = *(int *)((u)r[16] + 100);
    r[2] = 0;
    c = (((int)r[3] <= 0)); *(int *)((u)r[2] + (int)R_GM_CurrentMap) = r[4]; if (c) goto L800dd0e8;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 1; CALL(R_s17a_800DD460);
     goto L800dd118;
    L800dd0e8:;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + (u)0; CALL(R_s17a_800DD460);
    r[2] = *(int *)((u)r[16] + 104);
    c = ((r[2] != 0)); r[2] = (u)r[2] + -1; if (c) goto L800dd114;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
     goto L800dd128;
    L800dd114:;
    *(int *)((u)r[16] + 104) = r[2];
    L800dd118:;
    r[2] = *(int *)((u)r[16] + 100);
    r[2] = (u)r[2] + -1;
    *(int *)((u)r[16] + 100) = r[2];
    L800dd128:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
