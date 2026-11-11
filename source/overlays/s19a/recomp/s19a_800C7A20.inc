extern char R_s19a_dat_800E0438[] __asm__("s19a_dat_800E0438");
extern char R_GM_SeSet2[] __asm__("GM_SeSet2");
int G_s19a_800C7A20(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C7A20");
int G_s19a_800C7A20(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = 0;
    r[3] = *(int *)((u)r[16] + (int)R_s19a_dat_800E0438);
    r[2] = (u)0 + 32;
    c = ((r[3] != r[2])); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800c7a4c;
    r[4] = (u)0 + (u)0;
    r[5] = (u)0 + 63;
    r[6] = (u)0 + 83; CALL(R_GM_SeSet2);
    L800c7a4c:;
    r[2] = *(int *)((u)r[16] + (int)R_s19a_dat_800E0438);
    r[2] = (u)r[2] + -1;
    c = (((int)r[2] >= 0)); *(int *)((u)r[16] + (int)R_s19a_dat_800E0438) = r[2]; if (c) goto L800c7a64;
    *(int *)((u)r[16] + (int)R_s19a_dat_800E0438) = 0;
    L800c7a64:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
