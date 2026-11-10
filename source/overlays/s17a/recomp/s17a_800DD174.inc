extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_s17a_800DD39C[] __asm__("s17a_800DD39C");
int G_s17a_800DD174(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800DD174");
int G_s17a_800DD174(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_CurrentMap);
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[16] + 76) = r[5];
    *(int *)((u)r[16] + 32) = r[2];
    r[3] = *(int *)((u)r[5] + 0);
    r[7] = *(int *)((u)r[5] + 4);
    r[8] = *(int *)((u)r[5] + 8);
    r[9] = *(int *)((u)r[5] + 12);
    *(int *)((u)r[16] + 44) = r[3];
    *(int *)((u)r[16] + 48) = r[7];
    *(int *)((u)r[16] + 52) = r[8];
    *(int *)((u)r[16] + 56) = r[9];
    r[3] = *(int *)((u)r[5] + 16);
    r[7] = *(int *)((u)r[5] + 20);
    r[8] = *(int *)((u)r[5] + 24);
    r[9] = *(int *)((u)r[5] + 28);
    *(int *)((u)r[16] + 60) = r[3];
    *(int *)((u)r[16] + 64) = r[7];
    *(int *)((u)r[16] + 68) = r[8];
    *(int *)((u)r[16] + 72) = r[9];
    *(int *)((u)r[16] + 100) = r[6]; CALL(R_s17a_800DD39C);
    r[2] = (u)0 + 13;
    *(int *)((u)r[16] + 104) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
