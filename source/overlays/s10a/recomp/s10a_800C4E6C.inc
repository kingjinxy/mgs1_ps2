extern char R_s10a_dat_800E455A[] __asm__("s10a_dat_800E455A");
extern char R_s10a_800C4D84[] __asm__("s10a_800C4D84");
int G_s10a_800C4E6C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C4E6C");
int G_s10a_800C4E6C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[2] = 0;
    r[2] = *(short *)((u)r[2] + (int)R_s10a_dat_800E455A);
    r[29] = (u)r[29] + -24;
    c = (((int)r[2] <= 0)); *(int *)((u)r[29] + 16) = r[31]; if (c) goto L800c4e90;
     CALL(R_s10a_800C4D84);
     goto L800c4e94;
    L800c4e90:;
    r[2] = (u)0 + (u)0;
    L800c4e94:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
