extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_s07b_dword_800C33D8[] __asm__("s07b_dword_800C33D8");
extern char R_s07b_dword_800E5BB8[] __asm__("s07b_dword_800E5BB8");
extern char R_DG_MovePos[] __asm__("DG_MovePos");
extern char R_DG_SetPos2[] __asm__("DG_SetPos2");
extern char R_GV_SubVec3[] __asm__("GV_SubVec3");
extern char R_GV_VecDir2[] __asm__("GV_VecDir2");
extern char R_ReadRotMatrix[] __asm__("ReadRotMatrix");
extern char R_s07b_800CB224[] __asm__("s07b_800CB224");
extern char R_s07b_800CB6B0[] __asm__("s07b_800CB6B0");
extern char R_s07b_800CB8CC[] __asm__("s07b_800CB8CC");
int G_s07b_800CBC20(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CBC20");
int G_s07b_800CBC20(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(88)
    r[29] = (u)r[29] + -88;
    *(int *)((u)r[29] + 80) = r[18];
    r[18] = (u)r[4] + (u)0;
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_GM_PlayerPosition;
    *(int *)((u)r[29] + 72) = r[16];
    r[16] = 0;
    r[16] = (u)r[16] + (int)R_s07b_dword_800E5BB8;
    r[5] = (u)r[16] + (u)0;
    *(int *)((u)r[29] + 76) = r[17];
    r[17] = (u)r[29] + 48;
    *(int *)((u)r[29] + 84) = r[31];
    r[6] = (u)r[17] + (u)0; CALL(R_GV_SubVec3);
    r[4] = (u)r[17] + (u)0;
    *(short *)((u)r[29] + 60) = 0;
    *(short *)((u)r[29] + 56) = 0; CALL(R_GV_VecDir2);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)r[29] + 56;
    *(short *)((u)r[29] + 58) = r[2]; CALL(R_DG_SetPos2);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s07b_dword_800C33D8; CALL(R_DG_MovePos);
    r[4] = (u)r[29] + 16; CALL(R_ReadRotMatrix);
    r[4] = (u)r[18] + (u)0;
    r[7] = *(unsigned short *)((u)r[29] + 36);
    r[3] = *(unsigned short *)((u)r[29] + 44);
    r[2] = *(unsigned short *)((u)r[29] + 40);
    r[5] = (u)r[7] << 16;
    r[5] = (int)r[5] >> 16;
    r[6] = (u)r[3] << 16;
    r[6] = (int)r[6] >> 16;
    *(short *)((u)r[29] + 64) = r[7];
    r[7] = (u)0 + 96;
    *(short *)((u)r[29] + 66) = r[2];
    *(short *)((u)r[29] + 68) = r[3]; CALL(R_s07b_800CB6B0);
    r[4] = (u)r[18] + (u)0; CALL(R_s07b_800CB8CC);
    r[4] = (u)r[18] + (u)0; CALL(R_s07b_800CB224);
    r[31] = *(int *)((u)r[29] + 84);
    r[18] = *(int *)((u)r[29] + 80);
    r[17] = *(int *)((u)r[29] + 76);
    r[16] = *(int *)((u)r[29] + 72);
    r[29] = (u)r[29] + 88; goto out;
out:
    RECOMP_RETURN;
}
