extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s07b_dword_800E4B4C[] __asm__("s07b_dword_800E4B4C");
extern char R_s07b_dword_800E4B64[] __asm__("s07b_dword_800E4B64");
extern char R_GV_SendMessage[] __asm__("GV_SendMessage");
extern char R_GV_StrCode[] __asm__("GV_StrCode");
int G_s07b_800C5160(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800C5160");
int G_s07b_800C5160(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(56)
    r[2] = 0;
    r[2] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 22));
    r[29] = (u)r[29] + -56;
    *(int *)((u)r[29] + 40) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 44) = r[17];
    r[17] = (u)r[5] + (u)0;
    c = ((r[2] == 0)); *(int *)((u)r[29] + 48) = r[31]; if (c) goto L800c51c8;
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s07b_dword_800E4B4C; CALL(R_GV_StrCode);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s07b_dword_800E4B64;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = (u)0 + 4;
    *(short *)((u)r[29] + 34) = r[2]; CALL(R_GV_StrCode);
    r[4] = (u)r[29] + 16;
    *(short *)((u)r[29] + 20) = r[2];
    r[2] = 0 | 65535;
    *(short *)((u)r[29] + 24) = r[2];
    r[2] = r[17] | 1024;
    *(short *)((u)r[29] + 22) = r[16];
    *(short *)((u)r[29] + 26) = r[2]; CALL(R_GV_SendMessage);
    L800c51c8:;
    r[31] = *(int *)((u)r[29] + 48);
    r[17] = *(int *)((u)r[29] + 44);
    r[16] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 56; goto out;
out:
    RECOMP_RETURN;
}
