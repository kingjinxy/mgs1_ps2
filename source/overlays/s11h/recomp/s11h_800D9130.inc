extern char R_GV_Malloc[] __asm__("GV_Malloc");
extern char R_s11h_800D8DAC[] __asm__("s11h_800D8DAC");
int G_s11h_800D9130(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800D9130");
int G_s11h_800D9130(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)0 + 224; CALL(R_GV_Malloc);
    c = ((r[2] == 0)); *(int *)((u)r[16] + 32) = r[2]; if (c) goto L800d9164;
    r[4] = (u)r[16] + (u)0; CALL(R_s11h_800D8DAC);
    *(int *)((u)r[16] + 36) = 0;
    r[2] = (u)0 + (u)0; goto L800d9168;
    L800d9164:;
    r[2] = (u)0 + -1;
    L800d9168:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
