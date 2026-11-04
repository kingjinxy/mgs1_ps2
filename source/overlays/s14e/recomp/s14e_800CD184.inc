extern char R_HZD_GetAddress[] __asm__("HZD_GetAddress");
extern char R_HZD_ReachTo[] __asm__("HZD_ReachTo");
extern char R_s14e_800CCB60[] __asm__("s14e_800CCB60");
extern char R_s14e_800CD0FC[] __asm__("s14e_800CD0FC");
int G_s14e_800CD184(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CD184");
int G_s14e_800CD184(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s14e_800CCB60);
    r[4] = *(int *)((u)r[16] + 76);
    r[2] = *(int *)((u)r[16] + 3064);
    r[3] = *(int *)((u)r[4] + 0);
    c = ((r[3] != r[2])); r[2] = (u)0 + -1; if (c) goto L800cd208;
    r[2] = *(int *)((u)r[16] + 2856);
    r[2] = r[2] & 16;
    c = ((r[2] == 0)); r[5] = (u)r[16] + 32; if (c) goto L800cd1fc;
    r[4] = *(int *)((u)r[4] + 8);
    r[6] = (u)0 + -1; CALL(R_HZD_GetAddress);
    r[6] = *(int *)((u)r[16] + 3060);
    r[3] = *(int *)((u)r[16] + 76);
    *(int *)((u)r[16] + 3084) = r[2];
    r[4] = *(int *)((u)r[3] + 8);
    r[5] = (u)r[2] + (u)0; CALL(R_HZD_ReachTo);
    r[2] = (int)r[2] < 2;
    c = ((r[2] != 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800cd200;
    r[2] = (u)0 + -1; goto L800cd208;
    L800cd1fc:;
    r[4] = (u)r[16] + (u)0;
    L800cd200:;
    r[5] = (u)0 + 1500; CALL(R_s14e_800CD0FC);
    L800cd208:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
