extern char R_s19a_800D48F0[] __asm__("s19a_800D48F0");
extern char R_s19a_800D65D4[] __asm__("s19a_800D65D4");
int G_s19a_800D5DAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D5DAC");
int G_s19a_800D5DAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(short *)((u)r[16] + 2852);
    r[2] = (u)0 + 23;
    c = ((r[3] != r[2]));  if (c) goto L800d5dec;
     CALL(R_s19a_800D48F0);
    c = ((r[2] == 0)); r[2] = (u)0 + 9; if (c) goto L800d5dec;
    *(short *)((u)r[16] + 2850) = r[2];
    r[2] = (u)0 + 22;
    *(short *)((u)r[16] + 2852) = r[2];
    *(int *)((u)r[16] + 2856) = 0;
    L800d5dec:;
    r[3] = *(unsigned char *)((u)r[16] + 2936);
    r[2] = (u)0 + 255;
    c = ((r[3] != r[2]));  if (c) goto L800d5e28;
    r[2] = *(unsigned char *)((u)r[16] + 2974);
    r[2] = r[2] & 1;
    c = ((r[2] == 0));  if (c) goto L800d5e28;
     CALL(R_s19a_800D65D4);
    r[2] = (u)0 + 7;
    *(short *)((u)r[16] + 2850) = r[2];
    r[2] = (u)0 + 13; goto L800d5e40;
    L800d5e28:;
    r[3] = *(short *)((u)r[16] + 2958);
    r[2] = (u)0 + 2;
    c = ((r[3] != r[2])); r[2] = (u)0 + 9; if (c) goto L800d5e48;
    *(short *)((u)r[16] + 2850) = r[2];
    r[2] = (u)0 + 22;
    L800d5e40:;
    *(short *)((u)r[16] + 2852) = r[2];
    *(int *)((u)r[16] + 2856) = 0;
    L800d5e48:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
