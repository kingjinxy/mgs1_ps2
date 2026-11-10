extern char R_s18a_dat_800C3A6C[] __asm__("s18a_dat_800C3A6C");
extern char R_s18a_dat_800C3A70[] __asm__("s18a_dat_800C3A70");
extern char R_NewPadVibration[] __asm__("NewPadVibration");
int G_s18a_800D6100(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D6100");
int G_s18a_800D6100(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(unsigned char *)((u)r[16] + 2316);
    c = ((r[2] == 0)); r[4] = 0; if (c) goto L800d613c;
    r[4] = (u)r[4] + (int)R_s18a_dat_800C3A6C;
    r[5] = (u)0 + 1; CALL(R_NewPadVibration);
    r[2] = *(unsigned char *)((u)r[16] + 2316);
    r[2] = (u)r[2] + -1;
    *(char *)((u)r[16] + 2316) = r[2];
    L800d613c:;
    r[2] = *(unsigned char *)((u)r[16] + 2317);
    c = ((r[2] == 0)); r[4] = 0; if (c) goto L800d616c;
    r[4] = (u)r[4] + (int)R_s18a_dat_800C3A70;
    r[5] = (u)0 + 2; CALL(R_NewPadVibration);
    r[2] = *(unsigned char *)((u)r[16] + 2317);
    r[2] = (u)r[2] + -1;
    *(char *)((u)r[16] + 2317) = r[2]; goto L800d6170;
    L800d616c:;
    *(char *)((u)r[16] + 2318) = 0;
    L800d6170:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
