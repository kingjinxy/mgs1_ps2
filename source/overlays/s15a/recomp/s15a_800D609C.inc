extern char R_s15a_800D5EB0[] __asm__("s15a_800D5EB0");
extern char R_s15a_dat_800D917C[] __asm__("s15a_dat_800D917C");
extern char R_s15a_rc_800D5C5C[] __asm__("s15a_rc_800D5C5C");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_NewActor[] __asm__("GV_NewActor");
extern char R_GV_SetNamedActor[] __asm__("GV_SetNamedActor");
extern char R_s15a_800D53B8[] __asm__("s15a_800D53B8");
extern char R_s15a_800D5EE0[] __asm__("s15a_800D5EE0");
int G_s15a_800D609C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D609C");
int G_s15a_800D609C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    r[4] = (u)0 + 3;
    r[5] = (u)0 + 60;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GV_NewActor);
    r[17] = (u)r[2] + (u)0;
    c = ((r[17] == 0)); r[4] = (u)r[17] + (u)0; if (c) goto L800d6128;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s15a_rc_800D5C5C;
    r[6] = 0;
    r[6] = (u)r[6] + (int)R_s15a_800D5EB0;
    r[7] = 0;
    r[7] = (u)r[7] + ((int)R_s15a_dat_800D917C + 20); CALL(R_GV_SetNamedActor);
    r[4] = (u)0 + 109; CALL(R_s15a_800D53B8);
    r[4] = (u)0 + 115;
    r[16] = (u)r[2] + (u)0; CALL(R_s15a_800D53B8);
    r[4] = (u)r[17] + (u)0;
    r[5] = (u)r[16] + (u)0;
    r[6] = (u)r[2] + (u)0; CALL(R_s15a_800D5EE0);
    c = (((int)r[2] >= 0));  if (c) goto L800d6124;
    r[4] = (u)r[17] + (u)0; CALL(R_GV_DestroyActor);
    r[2] = (u)0 + (u)0; goto L800d612c;
    L800d6124:;
    *(int *)((u)r[17] + 32) = r[18];
    L800d6128:;
    r[2] = (u)r[17] + (u)0;
    L800d612c:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_GV_PassageTime[] __asm__("GV_PassageTime");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_GCL_ExecProc[] __asm__("GCL_ExecProc");
extern char R_GM_SeSet[] __asm__("GM_SeSet");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
int G_s15a_rc_800D6144(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_rc_800D6144");
int G_s15a_rc_800D6144(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_GM_GameStatus);
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[4] = *(int *)((u)r[16] + 52);
    r[3] = r[3] | 32768;
    c = (((int)r[4] > 0)); *(int *)((u)r[2] + (int)R_GM_GameStatus) = r[3]; if (c) goto L800d61b0;
    r[2] = 0;
    r[4] = (u)r[2] + (int)R_linkvarbuf;
    r[2] = *(unsigned short *)((u)r[4] + 24);
    r[3] = *(unsigned short *)((u)r[16] + 40);
    r[2] = (u)r[2] + (u)r[3];
    *(short *)((u)r[4] + 24) = r[2];
    r[2] = (u)r[2] << 16;
    r[3] = *(int *)((u)r[16] + 32);
    r[2] = (int)r[2] >> 16;
    r[3] = (int)r[3] < (int)r[2];
    c = ((r[3] == 0));  if (c) goto L800d61b0;
    r[2] = *(unsigned short *)((u)r[16] + 32);
    *(short *)((u)r[4] + 24) = r[2];
    L800d61b0:;
    r[3] = *(int *)((u)r[16] + 52);
    r[2] = *(int *)((u)r[16] + 36);
    r[2] = (int)r[3] < (int)r[2];
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d61cc;
    *(int *)((u)r[16] + 36) = r[3];
    L800d61cc:;
    r[17] = (u)r[2] + (int)R_linkvarbuf;
    r[2] = *(unsigned short *)((u)r[17] + 22);
    r[3] = *(unsigned short *)((u)r[16] + 36);
    r[2] = (u)r[2] + (u)r[3];
    *(short *)((u)r[17] + 22) = r[2];
    r[2] = *(int *)((u)r[16] + 52);
    r[3] = *(int *)((u)r[16] + 36);
    r[2] = (u)r[2] - (u)r[3];
    *(int *)((u)r[16] + 52) = r[2];
    r[3] = *(short *)((u)r[17] + 22);
    r[2] = *(int *)((u)r[16] + 32);
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] == 0));  if (c) goto L800d6220;
    r[2] = *(unsigned short *)((u)r[16] + 32);
    *(short *)((u)r[17] + 22) = r[2];
    r[3] = *(short *)((u)r[17] + 22);
    L800d6220:;
    r[2] = *(short *)((u)r[17] + 24);
    r[2] = (int)r[2] < (int)r[3];
    r[3] = *(unsigned short *)((u)r[17] + 22);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d623c;
    *(short *)((u)r[17] + 24) = r[3];
    L800d623c:;
    r[3] = *(int *)((u)r[16] + 56);
    r[2] = *(int *)((u)r[2] + (int)R_GV_PassageTime);
    r[3] = (u)r[3] + (u)r[2];
    r[2] = (int)r[3] < 12;
    c = ((r[2] != 0)); *(int *)((u)r[16] + 56) = r[3]; if (c) goto L800d626c;
    r[2] = (u)r[3] + -12;
    *(int *)((u)r[16] + 56) = r[2];
    r[4] = (u)0 + (u)0;
    r[5] = (u)0 + 126; CALL(R_GM_SeSet);
    L800d626c:;
    r[3] = *(short *)((u)r[17] + 24);
    r[2] = *(int *)((u)r[16] + 32);
    c = ((r[3] != r[2]));  if (c) goto L800d62a0;
    r[4] = *(int *)((u)r[16] + 44);
    c = ((r[4] == 0));  if (c) goto L800d6298;
    r[5] = (u)0 + (u)0; CALL(R_GCL_ExecProc);
    L800d6298:;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
    L800d62a0:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
int G_s15a_rc_800D62B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_rc_800D62B4");
int G_s15a_rc_800D62B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[4] = 0xefff0000;
    r[3] = 0;
    r[2] = *(int *)((u)r[3] + (int)R_GM_GameStatus);
    r[4] = r[4] | 32767;
    r[2] = r[2] & r[4];
    *(int *)((u)r[3] + (int)R_GM_GameStatus) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
