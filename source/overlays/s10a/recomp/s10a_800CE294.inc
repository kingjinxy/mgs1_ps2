extern char R_s10a_dat_800E49DC[] __asm__("s10a_dat_800E49DC");
int G_s10a_800CE294(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CE294");
int G_s10a_800CE294(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[3] = *(unsigned short *)((u)r[2] + (int)R_s10a_dat_800E49DC);
    c = ((r[3] != r[4])); r[2] = (u)r[2] + (int)R_s10a_dat_800E49DC; if (c) goto L800ce2e8;
    r[3] = *(unsigned short *)((u)r[2] + 2);
    c = ((r[3] == 0)); r[4] = (u)0 + (u)0; if (c) goto L800ce2fc;
    r[7] = (u)r[3] + (u)0;
    r[6] = (u)r[2] + (u)0;
    L800ce2c0:;
    r[3] = (u)r[6] + (u)0;
    r[2] = *(unsigned short *)((u)r[3] + 4);
    c = ((r[2] == r[5])); r[4] = (u)r[4] + 1; if (c) goto L800ce2f0;
    r[2] = (int)r[4] < (int)r[7];
    c = ((r[2] != 0)); r[6] = (u)r[3] + 4; if (c) goto L800ce2c0;
    r[2] = (u)0 + -1; goto out;
    L800ce2e8:;
    r[2] = (u)0 + (u)0; goto out;
    L800ce2f0:;
    r[2] = *(unsigned short *)((u)r[6] + 6);
     goto out;
    L800ce2fc:;
    r[2] = (u)0 + -1;
     goto out;
out:
    return r[2];
}
