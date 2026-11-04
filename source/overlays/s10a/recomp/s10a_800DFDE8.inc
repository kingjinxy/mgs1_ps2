extern char R_GV_Malloc[] __asm__("GV_Malloc");
extern char R_s10a_800DF790[] __asm__("s10a_800DF790");
int G_s10a_800DFDE8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800DFDE8");
int G_s10a_800DFDE8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    r[4] = (u)0 + 1168;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_Malloc);
    r[16] = (u)r[2] + (u)0;
    c = ((r[2] != 0)); *(int *)((u)r[17] + 40) = r[2]; if (c) goto L800dfe18;
    *(int *)((u)r[17] + 64) = 0; goto L800dfe6c;
    L800dfe18:;
    r[6] = 0xe1000000;
    r[6] = r[6] | 512;
    r[3] = (u)0 + 1;
    *(char *)((u)r[16] + 3) = r[3];
    r[2] = *(int *)((u)r[17] + 88);
    r[4] = (u)r[17] + (u)0;
    *(char *)((u)r[16] + 11) = r[3];
    r[2] = (u)r[2] << 5;
    r[2] = r[2] & 2559;
    r[2] = r[2] | r[6];
    *(int *)((u)r[16] + 4) = r[2];
    r[2] = *(int *)((u)r[17] + 88);
    r[5] = (u)r[16] + 16;
    r[2] = (u)r[2] << 5;
    r[2] = r[2] & 2559;
    r[2] = r[2] | r[6];
    *(int *)((u)r[16] + 12) = r[2]; CALL(R_s10a_800DF790);
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[16] + 592; CALL(R_s10a_800DF790);
    L800dfe6c:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
