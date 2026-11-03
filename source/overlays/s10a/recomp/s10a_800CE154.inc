extern char R_s10a_dat_800E4970[] __asm__("s10a_dat_800E4970");
int G_s10a_800CE154(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CE154");
int G_s10a_800CE154(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[5] = (u)0 + (u)0;
    r[6] = (u)0 + 2;
    r[2] = 0;
    r[3] = (u)r[2] + (int)R_s10a_dat_800E4970;
    L800ce164:;
    r[2] = *(int *)((u)r[3] + 156);
    c = ((r[2] != 0)); r[2] = (u)r[5] + (u)0; if (c) goto L800ce180;
    *(int *)((u)r[3] + 156) = r[4];
    *(int *)((u)r[3] + 148) = r[6]; goto out;
    L800ce180:;
    r[5] = (u)r[5] + 1;
    r[2] = (int)r[5] < 8;
    c = ((r[2] != 0)); r[3] = (u)r[3] + 16; if (c) goto L800ce164;
    r[2] = (u)0 + -1; goto out;
out:
    return r[2];
}
