extern char R_s19a_dat_800E0230[] __asm__("s19a_dat_800E0230");
extern char R_fprintf[] __asm__("fprintf");
extern char R_s19a_800D68B4[] __asm__("s19a_800D68B4");
int G_s19a_800D6B7C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D6B7C");
int G_s19a_800D6B7C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)0 + 2; CALL(R_s19a_800D68B4);
    r[3] = (u)r[2] + (u)0;
    c = ((r[3] == 0)); r[2] = (u)0 + 1; if (c) goto L800d6bb0;
    c = ((r[3] == r[2]));  if (c) goto L800d6bcc;
     goto L800d6bd0;
    L800d6bb0:;
    r[4] = (u)0 + 1;
    r[5] = 0;
    r[5] = (u)r[5] + ((int)R_s19a_dat_800E0230 + 160); CALL(R_fprintf);
    r[2] = (u)0 + 129;
    *(int *)((u)r[16] + 0) = r[2]; goto L800d6bd0;
    L800d6bcc:;
    *(int *)((u)r[16] + 0) = 0;
    L800d6bd0:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
