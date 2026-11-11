extern char R_DG_ZeroMatrix[] __asm__("DG_ZeroMatrix");
extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_DG_MakeObjs[] __asm__("DG_MakeObjs");
extern char R_DG_PutObjs[] __asm__("DG_PutObjs");
extern char R_DG_QueueObjs[] __asm__("DG_QueueObjs");
extern char R_DG_SetPos[] __asm__("DG_SetPos");
int G_s19b_jeep_gls_800CE52C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19b_jeep_gls_800CE52C");
int G_s19b_jeep_gls_800CE52C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    r[5] = (u)r[5] + 72;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] << 3;
    r[16] = (u)r[16] - (u)r[4];
    r[16] = (u)r[16] << 2;
    r[16] = (u)r[16] + (u)r[5];
    r[5] = (u)0 + 87;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[4] = *(int *)((u)r[16] + 0);
    r[6] = (u)0 + (u)0; CALL(R_DG_MakeObjs);
    r[17] = (u)r[2] + (u)0;
    r[7] = (u)r[17] + 72;
    r[2] = *(int *)((u)r[16] + 16);
    r[5] = *(short *)((u)r[17] + 46);
    c = (((int)r[5] <= 0)); r[6] = (u)r[2] + 72; if (c) goto L800ce5b8;
    L800ce57c:;
    r[4] = (u)r[6] + (u)0;
    r[6] = (u)r[4] + 92;
    r[3] = (u)r[7] + (u)0;
    c = ((r[3] == 0)); r[7] = (u)r[3] + 92; if (c) goto L800ce5ac;
    L800ce590:;
    r[2] = *(int *)((u)r[4] + 68);
    *(int *)((u)r[3] + 68) = r[2];
    r[3] = *(int *)((u)r[3] + 72);
    r[4] = *(int *)((u)r[4] + 72);
    c = ((r[3] != 0));  if (c) goto L800ce590;
    L800ce5ac:;
    r[5] = (u)r[5] + -1;
    c = (((int)r[5] > 0));  if (c) goto L800ce57c;
    L800ce5b8:;
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_DG_ZeroMatrix; CALL(R_DG_SetPos);
    r[4] = (u)r[17] + (u)0; CALL(R_DG_PutObjs);
    r[4] = (u)r[17] + (u)0; CALL(R_DG_QueueObjs);
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_GM_CurrentMap);
    r[2] = (u)r[17] + (u)0;
    *(short *)((u)r[2] + 44) = r[3];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
