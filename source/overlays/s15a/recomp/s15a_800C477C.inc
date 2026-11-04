extern char R_GM_AlertMode[] __asm__("GM_AlertMode");
extern char R_GM_PlayerBody[] __asm__("GM_PlayerBody");
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_GV_Time[] __asm__("GV_Time");
extern char R_GV_ReceiveMessage[] __asm__("GV_ReceiveMessage");
extern char R_s15a_800C3F68[] __asm__("s15a_800C3F68");
int G_s15a_800C477C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800C477C");
int G_s15a_800C477C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    r[4] = *(unsigned short *)((u)r[16] + 32);
    r[5] = (u)r[29] + 16; CALL(R_GV_ReceiveMessage);
    r[3] = (u)r[2] + (u)0;
    c = (((int)r[3] <= 0));  if (c) goto L800c47e4;
    r[5] = (u)0 + 3538;
    r[4] = (u)0 + 1;
    L800c47ac:;
    r[2] = *(int *)((u)r[29] + 16);
    r[2] = *(unsigned short *)((u)r[2] + 4);
    c = ((r[2] != r[5]));  if (c) goto L800c47cc;
    *(short *)((u)r[16] + 34) = r[4]; goto L800c47d0;
    L800c47cc:;
    *(short *)((u)r[16] + 34) = 0;
    L800c47d0:;
    r[2] = *(int *)((u)r[29] + 16);
    r[3] = (u)r[3] + -1;
    r[2] = (u)r[2] + 20;
    c = (((int)r[3] > 0)); *(int *)((u)r[29] + 16) = r[2]; if (c) goto L800c47ac;
    L800c47e4:;
    r[2] = *(unsigned short *)((u)r[16] + 34);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800c4878;
    r[3] = *(int *)((u)r[2] + (int)R_GM_AlertMode);
    r[2] = (u)0 + 3;
    c = ((r[3] == r[2])); r[2] = 0; if (c) goto L800c4878;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 8211;
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800c4878;
    r[4] = *(int *)((u)r[2] + (int)R_GM_PlayerBody);
    c = ((r[4] == 0)); r[2] = 0; if (c) goto L800c4878;
    r[2] = *(int *)((u)r[2] + (int)R_GV_Time);
    r[3] = *(int *)((u)r[16] + 36);
    if (r[3]) { lo_ = (int)r[2] / (int)r[3]; hi_ = (int)r[2] % (int)r[3]; }
    c = ((r[3] != 0));  if (c) goto L800c4844;
    L800c4844:;
    r[1] = (u)0 + -1;
    c = ((r[3] != r[1])); r[1] = 0; if (c) goto L800c485c;
    c = ((r[2] != r[1]));  if (c) goto L800c485c;
    L800c485c:;
    r[3] = hi_;
    c = ((r[3] != 0));  if (c) goto L800c4878;
    r[4] = *(int *)((u)r[4] + 0);
    r[4] = (u)r[4] + 624; CALL(R_s15a_800C3F68);
    L800c4878:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
int G_s15a_rc_800C4888(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_rc_800C4888");
int G_s15a_rc_800C4888(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
