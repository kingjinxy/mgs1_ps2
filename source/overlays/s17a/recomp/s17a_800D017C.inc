extern char R_s17a_dat_800E5D80[] __asm__("s17a_dat_800E5D80");
extern char R_GM_StreamPlayStop[] __asm__("GM_StreamPlayStop");
extern char R_GV_ZeroMemory[] __asm__("GV_ZeroMemory");
int G_s17a_800D017C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800D017C");
int G_s17a_800D017C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = 0;
    r[16] = (u)r[16] + (int)R_s17a_dat_800E5D80;
    r[4] = (u)r[16] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[5] = (u)0 + 176; CALL(R_GV_ZeroMemory);
    r[2] = (u)0 + -1;
    *(int *)((u)r[16] + 20) = r[2];
    *(int *)((u)r[16] + 44) = r[2];
    r[2] = (u)0 + 5;
    *(int *)((u)r[16] + 12) = 0;
    *(int *)((u)r[16] + 16) = 0;
    *(int *)((u)r[16] + 36) = 0;
    *(int *)((u)r[16] + 8) = r[2]; CALL(R_GM_StreamPlayStop);
    r[2] = (u)r[16] + 44;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
