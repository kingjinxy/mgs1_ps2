extern char R_GM_NoisePower[] __asm__("GM_NoisePower");
extern char R_s19a_dat_800E0530[] __asm__("s19a_dat_800E0530");
int G_s19a_800C8F44(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C8F44");
int G_s19a_800C8F44(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[4] = (u)r[2] + (int)R_s19a_dat_800E0530;
    r[2] = *(short *)((u)r[4] + 386);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800c8f7c;
    r[3] = *(int *)((u)r[2] + (int)R_GM_NoisePower);
    r[2] = (u)0 + 255;
    c = ((r[3] != r[2]));  if (c) goto L800c8f7c;
    r[2] = *(unsigned short *)((u)r[4] + 384);
    *(short *)((u)r[4] + 386) = 0;
    r[2] = (u)r[2] + 1;
    *(short *)((u)r[4] + 384) = r[2];
    L800c8f7c:;
     goto out;
out:
    RECOMP_RETURN;
}
