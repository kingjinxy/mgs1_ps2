extern char R_DG_ZeroVector[] __asm__("DG_ZeroVector");
extern char R_s19a_dat_800C3910[] __asm__("s19a_dat_800C3910");
extern char R_GV_RandU[] __asm__("GV_RandU");
extern char R_NewAnime[] __asm__("NewAnime");
int G_s19a_800DC0D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DC0D4");
int G_s19a_800DC0D4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 40) = r[31];
    r[2] = *(unsigned short *)((u)r[4] + 20);
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 24);
    *(short *)((u)r[29] + 18) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 28);
    r[4] = (u)0 + 16;
    *(short *)((u)r[29] + 20) = r[2];
    r[2] = 0;
    r[10] = (u)r[2] + (int)R_DG_ZeroVector;
    r[7] = LWL(((u)r[10] + 3), r[7]);
    r[7] = LWR(((u)r[10] + 0), r[7]);
    r[8] = LWL(((u)r[10] + 7), r[8]);
    r[8] = LWR(((u)r[10] + 4), r[8]);
    SWL(((u)r[29] + 27), r[7]);
    SWR(((u)r[29] + 24), r[7]);
    SWL(((u)r[29] + 31), r[8]);
    SWR(((u)r[29] + 28), r[8]);
    *(short *)((u)r[29] + 32) = 0;
    *(short *)((u)r[29] + 34) = 0; CALL(R_GV_RandU);
    r[3] = (u)r[2] + (u)0;
    r[2] = (int)r[3] < 5;
    c = ((r[2] != 0)); r[2] = (u)0 + 2; if (c) goto L800dc14c;
    *(short *)((u)r[29] + 34) = r[2]; goto L800dc160;
    L800dc14c:;
    c = (((int)r[3] <= 0)); r[2] = (u)0 + 1; if (c) goto L800dc15c;
    *(short *)((u)r[29] + 34) = r[2]; goto L800dc160;
    L800dc15c:;
    *(short *)((u)r[29] + 34) = 0;
    L800dc160:;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s19a_dat_800C3910;
    r[2] = (u)r[29] + 16;
    r[4] = (u)0 + (u)0;
    r[5] = (u)r[4] + (u)0;
    *(int *)((u)r[6] + 20) = r[2]; CALL(R_NewAnime);
    r[31] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
