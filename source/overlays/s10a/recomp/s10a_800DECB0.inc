extern char R_DG_ZeroMatrix[] __asm__("DG_ZeroMatrix");
extern char R_GM_CurrentMap[] __asm__("GM_CurrentMap");
extern char R_s10a_800DEFCC[] __asm__("s10a_800DEFCC");
extern char R_s10a_800DF6FC[] __asm__("s10a_800DF6FC");
int G_s10a_800DECB0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800DECB0");
int G_s10a_800DECB0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(72)
    r[29] = (u)r[29] + -72;
    *(int *)((u)r[29] + 60) = r[19];
    r[19] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 64) = r[31];
    *(int *)((u)r[29] + 56) = r[18];
    *(int *)((u)r[29] + 52) = r[17];
    *(int *)((u)r[29] + 48) = r[16];
    r[2] = *(int *)((u)r[19] + 32);
    r[3] = 0;
    *(int *)((u)r[3] + (int)R_GM_CurrentMap) = r[2]; CALL(R_s10a_800DEFCC);
    r[2] = *(short *)((u)r[19] + 128);
    c = (((int)r[2] <= 0)); r[18] = (u)0 + (u)0; if (c) goto L800dee10;
    r[16] = (u)r[19] + 48;
    L800decf0:;
    r[2] = *(short *)((u)r[16] + -6);
    r[17] = *(int *)((u)r[16] + -4);
    c = ((r[2] != 0));  if (c) goto L800ded80;
    r[2] = 0;
    r[9] = (u)r[2] + (int)R_DG_ZeroMatrix;
    r[6] = *(int *)((u)r[9] + 0);
    r[7] = *(int *)((u)r[9] + 4);
    r[8] = *(int *)((u)r[9] + 8);
    *(int *)((u)r[29] + 16) = r[6];
    *(int *)((u)r[29] + 20) = r[7];
    *(int *)((u)r[29] + 24) = r[8];
    r[6] = *(int *)((u)r[9] + 12);
    r[7] = *(int *)((u)r[9] + 16);
    r[8] = *(int *)((u)r[9] + 20);
    *(int *)((u)r[29] + 28) = r[6];
    *(int *)((u)r[29] + 32) = r[7];
    *(int *)((u)r[29] + 36) = r[8];
    r[6] = *(int *)((u)r[9] + 24);
    r[7] = *(int *)((u)r[9] + 28);
    *(int *)((u)r[29] + 40) = r[6];
    *(int *)((u)r[29] + 44) = r[7];
    r[2] = *(short *)((u)r[17] + 0);
    *(int *)((u)r[29] + 36) = r[2];
    r[2] = *(short *)((u)r[19] + 132);
    *(int *)((u)r[29] + 40) = r[2];
    r[2] = *(short *)((u)r[17] + 4);
    *(int *)((u)r[29] + 44) = r[2];
    r[5] = *(short *)((u)r[19] + 134);
    r[4] = (u)r[29] + 16; CALL(R_s10a_800DF6FC);
    r[2] = (u)0 + 30; goto L800dedd8;
    L800ded80:;
    r[2] = (int)r[2] < 9;
    c = ((r[2] != 0));  if (c) goto L800dedcc;
    r[3] = *(short *)((u)r[16] + 0);
    r[2] = *(short *)((u)r[17] + 0);
    c = ((r[3] != r[2])); r[2] = (u)0 + 8; if (c) goto L800dedc8;
    r[3] = *(short *)((u)r[16] + 2);
    r[2] = *(short *)((u)r[17] + 2);
    c = ((r[3] != r[2])); r[2] = (u)0 + 8; if (c) goto L800dedc8;
    r[3] = *(short *)((u)r[16] + 4);
    r[2] = *(short *)((u)r[17] + 4);
    c = ((r[3] == r[2])); r[2] = (u)0 + 8; if (c) goto L800dedcc;
    L800dedc8:;
    *(short *)((u)r[19] + 130) = r[2];
    L800dedcc:;
    r[2] = *(unsigned short *)((u)r[16] + -6);
    r[2] = (u)r[2] + -1;
    L800dedd8:;
    *(short *)((u)r[16] + -6) = r[2];
    r[6] = LWL(((u)r[17] + 3), r[6]);
    r[6] = LWR(((u)r[17] + 0), r[6]);
    r[7] = LWL(((u)r[17] + 7), r[7]);
    r[7] = LWR(((u)r[17] + 4), r[7]);
    SWL(((u)r[16] + 3), r[6]);
    SWR(((u)r[16] + 0), r[6]);
    SWL(((u)r[16] + 7), r[7]);
    SWR(((u)r[16] + 4), r[7]);
    r[2] = *(short *)((u)r[19] + 128);
    r[18] = (u)r[18] + 1;
    r[2] = (int)r[18] < (int)r[2];
    c = ((r[2] != 0)); r[16] = (u)r[16] + 16; if (c) goto L800decf0;
    L800dee10:;
    r[31] = *(int *)((u)r[29] + 64);
    r[19] = *(int *)((u)r[29] + 60);
    r[18] = *(int *)((u)r[29] + 56);
    r[17] = *(int *)((u)r[29] + 52);
    r[16] = *(int *)((u)r[29] + 48);
    r[29] = (u)r[29] + 72; goto out;
out:
    RECOMP_RETURN;
}
int G_s10a_rc_800DEE2C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_rc_800DEE2C");
int G_s10a_rc_800DEE2C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
     goto out;
out:
    RECOMP_RETURN;
}
