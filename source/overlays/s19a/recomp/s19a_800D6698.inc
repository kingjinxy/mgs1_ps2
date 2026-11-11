extern char R_s19a_dat_800E0D34[] __asm__("s19a_dat_800E0D34");
int G_s19a_800D6698(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D6698");
int G_s19a_800D6698(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[3] = *(unsigned short *)((u)r[2] + (int)R_s19a_dat_800E0D34);
    c = ((r[3] != r[4])); r[2] = (u)r[2] + (int)R_s19a_dat_800E0D34; if (c) goto L800d66ec;
    r[3] = *(unsigned short *)((u)r[2] + 2);
    c = ((r[3] == 0)); r[4] = (u)0 + (u)0; if (c) goto L800d6700;
    r[7] = (u)r[3] + (u)0;
    r[6] = (u)r[2] + (u)0;
    L800d66c4:;
    r[3] = (u)r[6] + (u)0;
    r[2] = *(unsigned short *)((u)r[3] + 4);
    c = ((r[2] == r[5])); r[4] = (u)r[4] + 1; if (c) goto L800d66f4;
    r[2] = (int)r[4] < (int)r[7];
    c = ((r[2] != 0)); r[6] = (u)r[3] + 4; if (c) goto L800d66c4;
    r[2] = (u)0 + -1; goto out;
    L800d66ec:;
    r[2] = (u)0 + (u)0; goto out;
    L800d66f4:;
    r[2] = *(unsigned short *)((u)r[6] + 6);
     goto out;
    L800d6700:;
    r[2] = (u)0 + -1;
     goto out;
out:
    RECOMP_RETURN;
}
