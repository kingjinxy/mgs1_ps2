extern char R_s10a_dat_800E4A94[] __asm__("s10a_dat_800E4A94");
extern char R_s10a_800CE1B8[] __asm__("s10a_800CE1B8");
int G_s10a_800CE744(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CE744");
int G_s10a_800CE744(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[5] + 28);
    r[2] = (u)r[3] - (u)r[4];
    r[2] = (int)r[2] < 5;
    c = ((r[2] != 0)); r[2] = (u)r[3] + -4; if (c) goto L800ce76c;
    *(int *)((u)r[5] + 28) = r[2]; goto L800ce770;
    L800ce76c:;
    *(int *)((u)r[5] + 28) = r[4];
    L800ce770:;
    r[3] = 0;
    r[2] = *(int *)((u)r[5] + 28);
    r[3] = *(int *)((u)r[3] + (int)R_s10a_dat_800E4A94);
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] == 0));  if (c) goto L800ce790;
    *(int *)((u)r[5] + 28) = r[3];
    L800ce790:;
    r[4] = (u)0 + (u)0; CALL(R_s10a_800CE1B8);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
