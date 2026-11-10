extern char R_GM_PlayerBody[] __asm__("GM_PlayerBody");
extern char R_GV_DiffDirS[] __asm__("GV_DiffDirS");
extern char R_ratan2[] __asm__("ratan2");
int G_s18a_800C8210(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C8210");
int G_s18a_800C8210(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerBody);
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 156);
    r[2] = *(int *)((u)r[2] + 0);
    r[5] = *(int *)((u)r[3] + 648);
    r[2] = *(int *)((u)r[2] + 648);
    r[4] = *(int *)((u)r[16] + 2480);
    r[5] = (u)r[2] - (u)r[5]; CALL(R_ratan2);
    r[2] = r[2] & 4095;
    r[3] = (u)r[2] + -1024;
    r[2] = (int)r[3] < 513;
    c = ((r[2] != 0)); r[2] = (int)r[3] < -512; if (c) goto L800c8260;
    r[3] = (u)0 + 512; goto L800c826c;
    L800c8260:;
    c = ((r[2] == 0));  if (c) goto L800c826c;
    r[3] = (u)0 + -512;
    L800c826c:;
    r[4] = *(short *)((u)r[16] + 42);
    r[5] = *(int *)((u)r[16] + 2476);
    *(short *)((u)r[16] + 2092) = r[3]; CALL(R_GV_DiffDirS);
    r[3] = (u)r[2] + (u)0;
    r[2] = (u)r[3] + 511;
    r[2] = (u)r[2] < (u)1023;
    c = ((r[2] == 0));  if (c) goto L800c8294;
    *(short *)((u)r[16] + 2094) = r[3];
    L800c8294:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
