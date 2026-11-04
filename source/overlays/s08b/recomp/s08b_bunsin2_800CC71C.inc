extern char R_s08b_bunsin2_800C9B38[] __asm__("s08b_bunsin2_800C9B38");
extern char R_s08b_dword_800C33C4[] __asm__("s08b_dword_800C33C4");
extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
extern char R_GM_SeSetMode[] __asm__("GM_SeSetMode");
int G_s08b_bunsin2_800CC71C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s08b_bunsin2_800CC71C");
int G_s08b_bunsin2_800CC71C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[16] + 32;
    c = ((r[5] != 0)); *(int *)((u)r[29] + 24) = r[31]; if (c) goto L800cc7a0;
    r[4] = (u)r[16] + 156;
    r[6] = (u)0 + (u)0;
    r[5] = *(unsigned char *)((u)r[16] + 6957);
    r[2] = *(int *)((u)r[16] + 6628);
    r[3] = (u)0 + 19;
    *(int *)((u)r[16] + 6564) = r[3];
    r[2] = (u)r[2] - (u)r[5];
    *(int *)((u)r[16] + 6628) = r[2];
    r[2] = 0;
    r[5] = *(short *)((u)r[2] + ((int)R_s08b_dword_800C33C4 + 2));
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)0 + 138;
    r[6] = (u)0 + 1; CALL(R_GM_SeSetMode);
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)0 + 52;
    r[6] = (u)0 + 1; CALL(R_GM_SeSetMode);
    r[2] = *(unsigned short *)((u)r[16] + 6696);
    *(short *)((u)r[17] + 10) = r[2];
    r[2] = *(unsigned short *)((u)r[16] + 6696);
    *(short *)((u)r[17] + 78) = r[2];
    L800cc7a0:;
    r[2] = *(short *)((u)r[16] + 182);
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800cc7d8;
    *(int *)((u)r[16] + 6568) = r[2];
    r[2] = (u)0 + 30;
    *(int *)((u)r[16] + 6640) = r[2];
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s08b_bunsin2_800C9B38;
    *(int *)((u)r[16] + 6716) = 0;
    *(int *)((u)r[16] + 6548) = r[2];
    *(int *)((u)r[16] + 6556) = 0;
    *(short *)((u)r[16] + 112) = 0;
    *(short *)((u)r[16] + 108) = 0;
    L800cc7d8:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
