extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s07b_dword_800E4B4C[] __asm__("s07b_dword_800E4B4C");
extern char R_s07b_dword_800E4B6C[] __asm__("s07b_dword_800E4B6C");
extern char R_GV_SendMessage[] __asm__("GV_SendMessage");
extern char R_GV_StrCode[] __asm__("GV_StrCode");
extern char R_s07b_800C4854[] __asm__("s07b_800C4854");
extern char R_s07b_800C5160[] __asm__("s07b_800C5160");
int G_s07b_800C51DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800C51DC");
int G_s07b_800C51DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(48)
    r[2] = 0;
    r[2] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 22));
    r[29] = (u)r[29] + -48;
    *(int *)((u)r[29] + 40) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[2] == 0)); *(int *)((u)r[29] + 44) = r[31]; if (c) goto L800c52a8;
    r[2] = *(unsigned short *)((u)r[16] + 2112);
    r[2] = (u)r[2] + -2;
    r[2] = (u)r[2] < (u)2;
    c = ((r[2] == 0));  if (c) goto L800c52a8;
    r[4] = (u)0 + (u)0;
    r[5] = (u)0 + 30; CALL(R_s07b_800C5160);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s07b_dword_800E4B4C; CALL(R_GV_StrCode);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s07b_dword_800E4B6C;
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = (u)0 + 7;
    *(short *)((u)r[29] + 34) = r[2]; CALL(R_GV_StrCode);
    *(short *)((u)r[29] + 20) = r[2];
    r[2] = *(unsigned short *)((u)r[16] + 32);
    *(short *)((u)r[29] + 22) = r[2];
    r[2] = *(unsigned short *)((u)r[16] + 34);
    r[4] = (u)r[16] + (u)0;
    *(short *)((u)r[29] + 24) = r[2];
    r[3] = *(unsigned short *)((u)r[16] + 36);
    r[2] = (u)0 + 1500;
    *(short *)((u)r[29] + 28) = r[2];
    r[2] = (u)0 + 1054;
    *(short *)((u)r[29] + 30) = r[2];
    *(short *)((u)r[29] + 26) = r[3]; CALL(R_s07b_800C4854);
    r[2] = *(int *)((u)r[16] + 2168);
    r[2] = (int)r[2] < 1500;
    c = ((r[2] == 0));  if (c) goto L800c5298;
    r[2] = *(unsigned short *)((u)r[16] + 110);
    r[2] = (u)r[2] + 1024; goto L800c529c;
    L800c5298:;
    r[2] = 0 | 65535;
    L800c529c:;
    *(short *)((u)r[29] + 32) = r[2];
    r[4] = (u)r[29] + 16; CALL(R_GV_SendMessage);
    L800c52a8:;
    r[31] = *(int *)((u)r[29] + 44);
    r[16] = *(int *)((u)r[29] + 40);
    r[29] = (u)r[29] + 48; goto out;
out:
    RECOMP_RETURN;
}
