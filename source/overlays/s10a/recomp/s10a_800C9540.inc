extern char R_s10a_dat_800E4A9C[] __asm__("s10a_dat_800E4A9C");
extern char R_GM_ConfigControlAttribute[] __asm__("GM_ConfigControlAttribute");
int G_s10a_800C9540(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C9540");
int G_s10a_800C9540(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 3120);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800c9588;
    r[2] = *(int *)((u)r[2] + (int)R_s10a_dat_800E4A9C);
    c = (((int)r[2] <= 0)); r[2] = (u)0 + 1; if (c) goto L800c9588;
    r[4] = (u)r[16] + 32;
    r[5] = (u)0 + 13;
    *(int *)((u)r[16] + 2532) = r[2]; CALL(R_GM_ConfigControlAttribute);
    *(int *)((u)r[16] + 3120) = 0;
    *(int *)((u)r[16] + 2924) = 0;
    L800c9588:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
