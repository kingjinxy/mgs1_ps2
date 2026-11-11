extern char R_s19a_dat_800E0DEC[] __asm__("s19a_dat_800E0DEC");
extern char R_s19a_800D65BC[] __asm__("s19a_800D65BC");
int G_s19a_800D6FFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D6FFC");
int G_s19a_800D6FFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[5] + 28);
    r[2] = (u)r[3] - (u)r[4];
    r[2] = (int)r[2] < 5;
    c = ((r[2] != 0)); r[2] = (u)r[3] + -4; if (c) goto L800d7024;
    *(int *)((u)r[5] + 28) = r[2]; goto L800d7028;
    L800d7024:;
    *(int *)((u)r[5] + 28) = r[4];
    L800d7028:;
    r[3] = 0;
    r[2] = *(int *)((u)r[5] + 28);
    r[3] = *(int *)((u)r[3] + (int)R_s19a_dat_800E0DEC);
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] == 0));  if (c) goto L800d7048;
    *(int *)((u)r[5] + 28) = r[3];
    L800d7048:;
    r[4] = (u)0 + (u)0; CALL(R_s19a_800D65BC);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
