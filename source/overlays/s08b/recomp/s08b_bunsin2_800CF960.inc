extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_Bunsin2_800C8F04[] __asm__("Bunsin2_800C8F04");
int G_s08b_bunsin2_800CF960(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800CF960");
int G_s08b_bunsin2_800CF960(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 6608);
    r[2] = (u)0 + 5;
    c = ((r[3] != r[2])); r[6] = (u)r[16] + 32; if (c) goto L800cf99c;
    r[2] = 0;
    r[4] = *(unsigned short *)((u)r[6] + 48);
    r[5] = *(int *)((u)r[2] + (int)R_GM_CurrentMap);
    r[7] = (u)0 + 2; CALL(R_Bunsin2_800C8F04);
    *(int *)((u)r[16] + 6684) = r[2]; goto L800cf9bc;
    L800cf99c:;
    r[2] = (u)0 + 4;
    c = ((r[3] != r[2])); r[2] = 0; if (c) goto L800cf9bc;
    r[4] = *(unsigned short *)((u)r[6] + 48);
    r[5] = *(int *)((u)r[2] + (int)R_GM_CurrentMap);
    r[7] = (u)0 + 1; CALL(R_Bunsin2_800C8F04);
    *(int *)((u)r[16] + 6680) = r[2];
    L800cf9bc:;
    r[2] = *(int *)((u)r[16] + 6608);
    r[2] = (int)r[2] < 6;
    c = ((r[2] != 0));  if (c) goto L800cf9e4;
    r[2] = *(int *)((u)r[16] + 6592);
    r[2] = r[2] | 4;
    *(int *)((u)r[16] + 6592) = r[2]; goto L800cf9f0;
    L800cf9e4:;
    r[2] = *(int *)((u)r[16] + 6696);
    *(int *)((u)r[16] + 6580) = r[2];
    L800cf9f0:;
    r[2] = *(int *)((u)r[16] + 6608);
    r[2] = (int)r[2] < 21;
    c = ((r[2] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800cfa1c;
    r[3] = *(int *)((u)r[16] + 6608);
    r[4] = (u)0 + 7;
    *(int *)((u)r[16] + 6576) = r[4];
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[16] + 6608) = r[3]; goto L800cfa20;
    L800cfa1c:;
    r[2] = (u)0 + 1;
    L800cfa20:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
