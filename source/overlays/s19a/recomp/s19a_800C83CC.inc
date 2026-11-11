extern char R_s19a_dat_800E06BC[] __asm__("s19a_dat_800E06BC");
extern char R_s19a_800C7814[] __asm__("s19a_800C7814");
int G_s19a_800C83CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C83CC");
int G_s19a_800C83CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[5] + 20);
    r[2] = (u)r[3] - (u)r[4];
    r[2] = (int)r[2] < 5;
    c = ((r[2] != 0)); r[2] = (u)r[3] + -4; if (c) goto L800c83f4;
    *(int *)((u)r[5] + 20) = r[2]; goto L800c83f8;
    L800c83f4:;
    *(int *)((u)r[5] + 20) = r[4];
    L800c83f8:;
    r[3] = 0;
    r[2] = *(int *)((u)r[5] + 20);
    r[3] = *(int *)((u)r[3] + (int)R_s19a_dat_800E06BC);
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] == 0));  if (c) goto L800c8418;
    *(int *)((u)r[5] + 20) = r[3];
    L800c8418:;
    r[4] = (u)0 + (u)0; CALL(R_s19a_800C7814);
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
