extern char R_GCL_GetNextInt[] __asm__("GCL_GetNextInt");
extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_s19a_800C401C[] __asm__("s19a_800C401C");
int G_s19a_800C40AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C40AC");
int G_s19a_800C40AC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)0 + 10000;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)0 + -1;
    *(int *)((u)r[29] + 24) = r[31];
    r[4] = (u)0 + 116; CALL(R_GCL_GetOption);
    c = ((r[2] == 0));  if (c) goto L800c40e8;
     CALL(R_GCL_GetNextInt);
    r[3] = (u)r[2] << 4;
    r[3] = (u)r[3] - (u)r[2];
    r[16] = (u)r[3] << 1;
    L800c40e8:;
    r[4] = (u)0 + 112; CALL(R_GCL_GetOption);
    c = ((r[2] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800c4108;
     CALL(R_GCL_GetNextInt);
    r[17] = (u)r[2] + (u)0;
    r[4] = (u)r[16] + (u)0;
    L800c4108:;
    r[5] = (u)r[17] + (u)0; CALL(R_s19a_800C401C);
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
extern char R_GM_PlayerAction[] __asm__("GM_PlayerAction");
extern char R_GM_PlayerControl[] __asm__("GM_PlayerControl");
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_dword_800AB9D4[] __asm__("dword_800AB9D4");
extern char R_GM_SeSetMode[] __asm__("GM_SeSetMode");
int G_s19a_rc_800C4124(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_rc_800C4124");
int G_s19a_rc_800C4124(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[29] = (u)r[29] + -24;
    r[2] = r[2] & 4;
    c = ((r[2] == 0)); *(int *)((u)r[29] + 16) = r[31]; if (c) goto L800c41ac;
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_GM_PlayerAction);
    r[2] = *(int *)((u)r[4] + 32);
    c = ((r[3] != r[2]));  if (c) goto L800c41ac;
    r[2] = *(int *)((u)r[4] + 36);
    r[5] = *(int *)((u)r[4] + 40);
    c = (((int)r[2] <= 0)); r[6] = (u)0 + (u)0; if (c) goto L800c41ac;
    r[7] = 0;
    r[8] = 0;
    L800c416c:;
    r[3] = *(int *)((u)r[5] + 0);
    r[2] = *(int *)((u)r[7] + (int)R_dword_800AB9D4);
    c = ((r[3] != r[2])); r[6] = (u)r[6] + 1; if (c) goto L800c4198;
    r[4] = *(int *)((u)r[8] + (int)R_GM_PlayerControl);
    r[5] = *(int *)((u)r[5] + 4);
    r[6] = (u)0 + 1; CALL(R_GM_SeSetMode);
     goto L800c41ac;
    L800c4198:;
    r[2] = *(int *)((u)r[4] + 36);
    r[2] = (int)r[6] < (int)r[2];
    c = ((r[2] != 0)); r[5] = (u)r[5] + 8; if (c) goto L800c416c;
    L800c41ac:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
