extern char R_GV_SubVec3[] __asm__("GV_SubVec3");
extern char R_GV_VecLen3[] __asm__("GV_VecLen3");
extern char R_ratan2[] __asm__("ratan2");
int G_s10a_800CF5A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CF5A0");
int G_s10a_800CF5A0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    r[2] = (u)r[4] + (u)0;
    r[4] = (u)r[5] + (u)0;
    r[5] = (u)r[2] + (u)0;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[6] + (u)0;
    r[6] = (u)r[29] + 16;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 28) = r[17]; CALL(R_GV_SubVec3);
    r[4] = *(short *)((u)r[29] + 16);
    r[5] = *(short *)((u)r[29] + 20);
     CALL(R_ratan2);
    r[2] = r[2] & 4095;
    *(short *)((u)r[16] + 2) = r[2];
    r[17] = *(short *)((u)r[29] + 18);
    r[4] = (u)r[29] + 16;
    *(short *)((u)r[29] + 18) = 0; CALL(R_GV_VecLen3);
    r[4] = (u)r[2] + (u)0;
    r[5] = (u)r[17] + (u)0; CALL(R_ratan2);
    r[2] = r[2] & 4095;
    r[2] = (u)r[2] + -1024;
    *(short *)((u)r[16] + 0) = r[2];
    *(short *)((u)r[16] + 4) = 0;
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
