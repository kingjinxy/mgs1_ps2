extern char R_s19a_dat_800E0DF4[] __asm__("s19a_dat_800E0DF4");
extern char R_s19a_800D61A4[] __asm__("s19a_800D61A4");
extern char R_s19a_800D62D0[] __asm__("s19a_800D62D0");
extern char R_s19a_800D6388[] __asm__("s19a_800D6388");
int G_s19a_800D649C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D649C");
int G_s19a_800D649C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = (u)0 + -1;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(short *)((u)r[16] + 2848);
    r[4] = (u)0 + 1;
    *(short *)((u)r[16] + 2888) = r[2];
    c = ((r[3] == r[4])); *(int *)((u)r[16] + 2872) = 0; if (c) goto L800d6504;
    r[2] = (int)r[3] < 2;
    c = ((r[2] == 0)); r[2] = (u)0 + 2; if (c) goto L800d64e0;
    c = ((r[3] == 0)); r[2] = 0; if (c) goto L800d64f0;
     goto L800d6528;
    L800d64e0:;
    c = ((r[3] == r[2])); r[2] = 0; if (c) goto L800d6518;
     goto L800d6528;
    L800d64f0:;
    *(short *)((u)r[16] + 2278) = r[4];
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D61A4);
    r[2] = 0; goto L800d6528;
    L800d6504:;
    *(short *)((u)r[16] + 2278) = r[3];
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D62D0);
    r[2] = 0; goto L800d6528;
    L800d6518:;
    *(short *)((u)r[16] + 2278) = 0;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D6388);
    r[2] = 0;
    L800d6528:;
    r[2] = *(int *)((u)r[2] + (int)R_s19a_dat_800E0DF4);
    c = (((int)r[2] <= 0)); r[2] = (u)0 + 255; if (c) goto L800d6540;
    *(int *)((u)r[16] + 2964) = r[2]; goto L800d6548;
    L800d6540:;
    *(int *)((u)r[16] + 2964) = 0;
    *(short *)((u)r[16] + 90) = 0;
    L800d6548:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
