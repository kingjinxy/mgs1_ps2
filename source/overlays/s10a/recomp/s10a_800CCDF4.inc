extern char R_s10a_dat_800E3CE0[] __asm__("s10a_dat_800E3CE0");
extern char R_GM_SeSet[] __asm__("GM_SeSet");
extern char R_s10a_800CAFA8[] __asm__("s10a_800CAFA8");
extern char R_s10a_800CE074[] __asm__("s10a_800CE074");
int G_s10a_800CCDF4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CCDF4");
int G_s10a_800CCDF4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(int *)((u)r[17] + 2856);
    c = ((r[2] != 0)); r[2] = (u)r[2] < (u)20; if (c) goto L800cce58;
    r[5] = (u)0 + (u)0; CALL(R_s10a_800CAFA8);
    r[16] = (u)r[17] + 32;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 83; CALL(R_GM_SeSet);
    r[4] = *(int *)((u)r[17] + 156);
    r[5] = (u)r[16] + (u)0;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s10a_dat_800E3CE0;
    r[7] = (u)0 + (u)0;
    r[4] = (u)r[4] + 624; CALL(R_s10a_800CE074);
    r[2] = *(int *)((u)r[17] + 2856);
    r[2] = (u)r[2] < (u)20;
    L800cce58:;
    c = ((r[2] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800cce68;
    r[2] = (u)0 + 1; goto L800cce80;
    L800cce68:;
    r[3] = *(int *)((u)r[17] + 2872);
    r[4] = *(int *)((u)r[17] + 2856);
    r[3] = r[3] | 32;
    r[4] = (u)r[4] + 1;
    *(int *)((u)r[17] + 2872) = r[3];
    *(int *)((u)r[17] + 2856) = r[4];
    L800cce80:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
