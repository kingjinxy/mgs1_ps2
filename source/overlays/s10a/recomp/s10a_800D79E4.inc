extern char R_GM_AllocTarget[] __asm__("GM_AllocTarget");
extern char R_GM_SetTarget[] __asm__("GM_SetTarget");
int G_s10a_800D79E4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800D79E4");
int G_s10a_800D79E4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[4] + (u)0;
    r[3] = (u)0 + 250;
    r[2] = (u)0 + 1000;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 24) = r[16];
    *(short *)((u)r[29] + 16) = r[3];
    *(short *)((u)r[29] + 18) = r[2];
    *(short *)((u)r[29] + 20) = r[3]; CALL(R_GM_AllocTarget);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); *(int *)((u)r[17] + 1628) = r[16]; if (c) goto L800d7a80;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 16;
    r[6] = (u)0 + 2;
    r[7] = (u)r[29] + (u)r[5]; CALL(R_GM_SetTarget);
    r[2] = *(unsigned short *)((u)r[16] + 0);
    r[2] = r[2] | 512;
    *(short *)((u)r[16] + 0) = r[2]; CALL(R_GM_AllocTarget);
    r[16] = (u)r[2] + (u)0;
    c = ((r[16] == 0)); *(int *)((u)r[17] + 1632) = r[16]; if (c) goto L800d7a80;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 16;
    r[6] = (u)0 + 2;
    r[7] = (u)r[29] + (u)r[5]; CALL(R_GM_SetTarget);
    r[3] = *(unsigned short *)((u)r[16] + 0);
    r[2] = (u)0 + (u)0;
    r[3] = r[3] | 512;
    *(short *)((u)r[16] + 0) = r[3];
    r[3] = (u)0 + 1024;
    *(int *)((u)r[17] + 2624) = r[3]; goto L800d7a84;
    L800d7a80:;
    r[2] = (u)0 + -1;
    L800d7a84:;
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
