extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_s17a_800D2FC4[] __asm__("s17a_800D2FC4");
int G_s17a_800D2DE0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800D2DE0");
int G_s17a_800D2DE0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
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
    r[8] = *(int *)((u)r[5] + 4);
    r[9] = *(int *)((u)r[5] + 8);
    r[10] = *(int *)((u)r[5] + 12);
    *(int *)((u)r[16] + 44) = r[3];
    *(int *)((u)r[16] + 48) = r[8];
    *(int *)((u)r[16] + 52) = r[9];
    *(int *)((u)r[16] + 56) = r[10];
    r[3] = *(int *)((u)r[5] + 16);
    r[8] = *(int *)((u)r[5] + 20);
    r[9] = *(int *)((u)r[5] + 24);
    r[10] = *(int *)((u)r[5] + 28);
    *(int *)((u)r[16] + 60) = r[3];
    *(int *)((u)r[16] + 64) = r[8];
    *(int *)((u)r[16] + 68) = r[9];
    *(int *)((u)r[16] + 72) = r[10];
    *(int *)((u)r[16] + 80) = r[6];
    *(int *)((u)r[16] + 84) = r[7]; CALL(R_s17a_800D2FC4);
    r[2] = (u)0 + 40;
    *(int *)((u)r[16] + 88) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
