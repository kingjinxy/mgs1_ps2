extern char R_s08b_dword_800C3610[] __asm__("s08b_dword_800C3610");
extern char R_s08b_dword_800C3614[] __asm__("s08b_dword_800C3614");
extern char R_s08b_dword_800C3618[] __asm__("s08b_dword_800C3618");
extern char R_NewCinemaScreen[] __asm__("NewCinemaScreen");
int G_s08b_bunsin2_800D53E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s08b_bunsin2_800D53E8");
int G_s08b_bunsin2_800D53E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[6] = (u)r[4] + (u)0;
    r[3] = 0;
    r[2] = *(int *)((u)r[3] + (int)R_s08b_dword_800C3610);
    r[4] = (u)r[5] + (u)0;
    c = ((r[2] != 0)); *(int *)((u)r[29] + 16) = r[31]; if (c) goto L800d5424;
    r[2] = (u)0 + 1;
    *(int *)((u)r[3] + (int)R_s08b_dword_800C3610) = r[2];
    r[2] = 0;
    r[5] = (u)r[6] + (u)0;
    *(int *)((u)r[2] + (int)R_s08b_dword_800C3614) = r[4]; CALL(R_NewCinemaScreen);
    r[3] = 0;
    *(int *)((u)r[3] + (int)R_s08b_dword_800C3618) = r[2];
    L800d5424:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
