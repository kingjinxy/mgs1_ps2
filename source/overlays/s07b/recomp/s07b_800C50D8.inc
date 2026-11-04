extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s07b_dword_800E4B4C[] __asm__("s07b_dword_800E4B4C");
extern char R_s07b_dword_800E4B58[] __asm__("s07b_dword_800E4B58");
extern char R_GV_SendMessage[] __asm__("GV_SendMessage");
extern char R_GV_StrCode[] __asm__("GV_StrCode");
int G_s07b_800C50D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800C50D8");
int G_s07b_800C50D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[2] = 0;
    r[2] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 22));
    r[29] = (u)r[29] + -48;
    c = ((r[2] == 0)); *(int *)((u)r[29] + 40) = r[31]; if (c) goto L800c5150;
    r[2] = *(unsigned short *)((u)r[4] + 2112);
    r[2] = (u)r[2] + -2;
    r[2] = (u)r[2] < (u)2;
    c = ((r[2] == 0)); r[4] = 0; if (c) goto L800c5150;
    r[4] = (u)r[4] + (int)R_s07b_dword_800E4B4C; CALL(R_GV_StrCode);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s07b_dword_800E4B58;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = (u)0 + 6;
    *(short *)((u)r[29] + 34) = r[2]; CALL(R_GV_StrCode);
    r[4] = (u)r[29] + 16;
    *(short *)((u)r[29] + 20) = r[2];
    r[2] = 0 | 65535;
    *(short *)((u)r[29] + 24) = r[2];
    *(short *)((u)r[29] + 26) = r[2];
    r[2] = (u)0 + 1;
    *(short *)((u)r[29] + 28) = r[2];
    r[2] = (u)0 + 1394;
    *(short *)((u)r[29] + 22) = 0;
    *(short *)((u)r[29] + 30) = r[2]; CALL(R_GV_SendMessage);
    L800c5150:;
    r[31] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
