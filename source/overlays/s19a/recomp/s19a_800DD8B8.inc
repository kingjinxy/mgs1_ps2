int G_s19a_800DD8B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DD8B8");
int G_s19a_800DD8B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
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
extern char R_s19a_800DD430[] __asm__("s19a_800DD430");
extern char R_s19a_800DD460[] __asm__("s19a_800DD460");
extern char R_s19a_800DD48C[] __asm__("s19a_800DD48C");
extern char R_s19a_800DD758[] __asm__("s19a_800DD758");
int G_s19a_rc_800DD8C0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_rc_800DD8C0");
int G_s19a_rc_800DD8C0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_GameOverTimer);
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 32) = r[31];
    c = (((int)r[2] <= 0)); *(int *)((u)r[29] + 24) = r[16]; if (c) goto L800dd8ec;
    r[2] = (u)0 + 1;
    *(int *)((u)r[17] + 36) = r[2]; goto L800dd9c8;
    L800dd8ec:;
    r[4] = *(int *)((u)r[17] + 32);
    r[5] = (u)r[29] + 16; CALL(R_GV_ReceiveMessage);
    r[16] = (u)r[2] + (u)0;
    c = (((int)r[16] <= 0));  if (c) goto L800dd9b0;
    L800dd904:;
    r[4] = *(int *)((u)r[29] + 16);
    r[3] = *(unsigned short *)((u)r[4] + 4);
    r[2] = (u)0 + 19213;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 19214; if (c) goto L800dd960;
    c = ((r[2] == 0)); r[2] = (u)0 + 12835; if (c) goto L800dd934;
    c = ((r[3] == r[2]));  if (c) goto L800dd984;
     goto L800dd99c;
    L800dd934:;
    r[2] = 0 | 33432;
    c = ((r[3] == r[2])); r[2] = 0 | 63465; if (c) goto L800dd950;
    c = ((r[3] == r[2]));  if (c) goto L800dd974;
     goto L800dd99c;
    L800dd950:;
     CALL(R_s19a_800DD430);
     goto L800dd99c;
    L800dd960:;
    r[4] = *(unsigned short *)((u)r[4] + 6);
    r[5] = (u)0 + 1; CALL(R_s19a_800DD758);
     goto L800dd99c;
    L800dd974:;
     CALL(R_s19a_800DD460);
     goto L800dd99c;
    L800dd984:;
     CALL(R_GM_StreamPlayStop);
    r[4] = (u)r[17] + (u)0; CALL(R_GV_DestroyActor);
     goto L800dd9c8;
    L800dd99c:;
    r[2] = *(int *)((u)r[29] + 16);
    r[16] = (u)r[16] + -1;
    r[2] = (u)r[2] + 20;
    c = (((int)r[16] > 0)); *(int *)((u)r[29] + 16) = r[2]; if (c) goto L800dd904;
    L800dd9b0:;
    r[2] = *(int *)((u)r[17] + 36);
    c = ((r[2] != 0));  if (c) goto L800dd9c8;
     CALL(R_s19a_800DD48C);
    L800dd9c8:;
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
