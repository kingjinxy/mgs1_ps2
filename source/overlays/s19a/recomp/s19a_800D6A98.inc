extern char R_s19a_dat_800E0230[] __asm__("s19a_dat_800E0230");
extern char R_fprintf[] __asm__("fprintf");
extern char R_s19a_800D68B4[] __asm__("s19a_800D68B4");
int G_s19a_800D6A98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D6A98");
int G_s19a_800D6A98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)0 + 3; CALL(R_s19a_800D68B4);
    r[3] = (u)r[2] + (u)0;
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 2; if (c) goto L800d6b00;
    c = ((r[2] == 0));  if (c) goto L800d6ad8;
    c = ((r[3] == 0)); r[4] = (u)0 + 1; if (c) goto L800d6aec;
     goto L800d6b18;
    L800d6ad8:;
    r[2] = (u)0 + 2;
    c = ((r[3] == r[2])); r[4] = (u)0 + 1; if (c) goto L800d6b04;
     goto L800d6b18;
    L800d6aec:;
    r[5] = 0;
    r[5] = (u)r[5] + ((int)R_s19a_dat_800E0230 + 120); CALL(R_fprintf);
    r[2] = (u)0 + 130; goto L800d6b14;
    L800d6b00:;
    r[4] = (u)0 + 1;
    L800d6b04:;
    r[5] = 0;
    r[5] = (u)r[5] + ((int)R_s19a_dat_800E0230 + 128); CALL(R_fprintf);
    r[2] = (u)0 + 129;
    L800d6b14:;
    *(int *)((u)r[16] + 0) = r[2];
    L800d6b18:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
