extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_s07b_dword_800E4B78[] __asm__("s07b_dword_800E4B78");
extern char R_s07b_dword_800E4B8C[] __asm__("s07b_dword_800E4B8C");
extern char R_GM_ConfigMotionAdjust[] __asm__("GM_ConfigMotionAdjust");
extern char R_GM_VoxInit[] __asm__("GM_VoxInit");
extern char R_GM_VoxQueueDelay[] __asm__("GM_VoxQueueDelay");
extern char R_GV_RandU[] __asm__("GV_RandU");
extern char R_printf[] __asm__("printf");
int G_s07b_800C52B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800C52B8");
int G_s07b_800C52B8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_GM_VoxInit);
    r[2] = 0;
    r[2] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 22));
    c = ((r[2] == 0));  if (c) goto L800c5390;
    r[4] = (u)r[16] + 156;
    r[5] = (u)r[16] + 1816; CALL(R_GM_ConfigMotionAdjust);
    r[3] = *(unsigned short *)((u)r[16] + 2112);
    r[2] = (u)r[3] < (u)5;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800c5390;
    r[2] = (u)r[2] + (int)R_s07b_dword_800E4B8C;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800c531c: goto L800c531c; case 0x800c5360: goto L800c5360; case 0x800c5374: goto L800c5374; default: goto out; }
    L800c531c:;
    r[4] = (u)0 + 8; CALL(R_GV_RandU);
    r[3] = 0x55550000;
    r[3] = r[3] | 21846;
    mul = (long long)(int)r[2] * (int)r[3]; hi_ = mul >> 32; lo_ = mul;
    r[4] = (int)r[2] >> 31;
    r[6] = hi_;
    r[4] = (u)r[6] - (u)r[4];
    r[3] = (u)r[4] << 1;
    r[3] = (u)r[3] + (u)r[4];
    r[2] = (u)r[2] - (u)r[3];
    r[2] = (u)r[2] + 11;
    r[2] = (u)r[2] << 2;
    r[2] = (u)r[16] + (u)r[2];
    r[4] = *(int *)((u)r[2] + 2276);
     goto L800c5364;
    L800c5360:;
    r[4] = *(int *)((u)r[16] + 2308);
    L800c5364:;
    r[5] = (u)0 + 4; CALL(R_GM_VoxQueueDelay);
     goto L800c5390;
    L800c5374:;
    r[4] = *(int *)((u)r[16] + 2288);
    r[5] = (u)0 + 4; CALL(R_GM_VoxQueueDelay);
    r[4] = 0;
    r[5] = *(int *)((u)r[16] + 2288);
    r[4] = (u)r[4] + (int)R_s07b_dword_800E4B78; CALL(R_printf);
    L800c5390:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
