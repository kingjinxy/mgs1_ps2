extern char R_s07b_dword_800E4FA8[] __asm__("s07b_dword_800E4FA8");
extern char R_GV_SendMessage[] __asm__("GV_SendMessage");
extern char R_GV_StrCode[] __asm__("GV_StrCode");
int G_s07b_800CC514(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CC514");
int G_s07b_800CC514(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(56)
    r[29] = (u)r[29] + -56;
    *(int *)((u)r[29] + 40) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 44) = r[17];
    r[17] = (u)r[5] + (u)0;
    r[4] = 0;
    *(int *)((u)r[29] + 48) = r[31];
    r[4] = (u)r[4] + (int)R_s07b_dword_800E4FA8; CALL(R_GV_StrCode);
    r[4] = (u)r[29] + 16;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = (u)0 + 4;
    *(short *)((u)r[29] + 34) = r[2];
    r[2] = (u)0 + 12856;
    *(short *)((u)r[29] + 20) = r[2];
    r[2] = 0 | 65535;
    *(short *)((u)r[29] + 22) = r[16];
    *(short *)((u)r[29] + 24) = r[2];
    *(short *)((u)r[29] + 26) = r[17]; CALL(R_GV_SendMessage);
    r[31] = *(int *)((u)r[29] + 48);
    r[17] = *(int *)((u)r[29] + 44);
    r[16] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 56; goto out;
out:
    return r[2];
}
