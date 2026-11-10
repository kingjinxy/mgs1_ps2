int G_s17a_800D065C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800D065C");
int G_s17a_800D065C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
extern char R_GM_GameOverTimer[] __asm__("GM_GameOverTimer");
extern char R_GM_StreamPlayStop[] __asm__("GM_StreamPlayStop");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
extern char R_GV_ReceiveMessage[] __asm__("GV_ReceiveMessage");
extern char R_s17a_800D01D4[] __asm__("s17a_800D01D4");
extern char R_s17a_800D0204[] __asm__("s17a_800D0204");
extern char R_s17a_800D0230[] __asm__("s17a_800D0230");
extern char R_s17a_800D04FC[] __asm__("s17a_800D04FC");
int G_s17a_rc_800D0664(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_rc_800D0664");
int G_s17a_rc_800D0664(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_GameOverTimer);
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 32) = r[31];
    c = (((int)r[2] <= 0)); *(int *)((u)r[29] + 24) = r[16]; if (c) goto L800d0690;
    r[2] = (u)0 + 1;
    *(int *)((u)r[17] + 36) = r[2]; goto L800d076c;
    L800d0690:;
    r[4] = *(int *)((u)r[17] + 32);
    r[5] = (u)r[29] + 16; CALL(R_GV_ReceiveMessage);
    r[16] = (u)r[2] + (u)0;
    c = (((int)r[16] <= 0));  if (c) goto L800d0754;
    L800d06a8:;
    r[4] = *(int *)((u)r[29] + 16);
    r[3] = *(unsigned short *)((u)r[4] + 4);
    r[2] = (u)0 + 19213;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 19214; if (c) goto L800d0704;
    c = ((r[2] == 0)); r[2] = (u)0 + 12835; if (c) goto L800d06d8;
    c = ((r[3] == r[2]));  if (c) goto L800d0728;
     goto L800d0740;
    L800d06d8:;
    r[2] = 0 | 33432;
    c = ((r[3] == r[2])); r[2] = 0 | 63465; if (c) goto L800d06f4;
    c = ((r[3] == r[2]));  if (c) goto L800d0718;
     goto L800d0740;
    L800d06f4:;
     CALL(R_s17a_800D01D4);
     goto L800d0740;
    L800d0704:;
    r[4] = *(unsigned short *)((u)r[4] + 6);
    r[5] = (u)0 + 1; CALL(R_s17a_800D04FC);
     goto L800d0740;
    L800d0718:;
     CALL(R_s17a_800D0204);
     goto L800d0740;
    L800d0728:;
     CALL(R_GM_StreamPlayStop);
    r[4] = (u)r[17] + (u)0; CALL(R_GV_DestroyActor);
     goto L800d076c;
    L800d0740:;
    r[2] = *(int *)((u)r[29] + 16);
    r[16] = (u)r[16] + -1;
    r[2] = (u)r[2] + 20;
    c = (((int)r[16] > 0)); *(int *)((u)r[29] + 16) = r[2]; if (c) goto L800d06a8;
    L800d0754:;
    r[2] = *(int *)((u)r[17] + 36);
    c = ((r[2] != 0));  if (c) goto L800d076c;
     CALL(R_s17a_800D0230);
    L800d076c:;
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
