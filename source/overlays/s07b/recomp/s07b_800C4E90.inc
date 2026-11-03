extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_GV_DiffDirS[] __asm__("GV_DiffDirS");
extern char R_GV_NearExp8[] __asm__("GV_NearExp8");
extern char R_GV_SubVec3[] __asm__("GV_SubVec3");
extern char R_GV_VecDir2[] __asm__("GV_VecDir2");
extern char R_s07b_800C5B14[] __asm__("s07b_800C5B14");
int G_s07b_800C4E90(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800C4E90");
int G_s07b_800C4E90(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_GM_PlayerPosition;
    r[5] = (u)r[16] + 32;
    *(int *)((u)r[29] + 28) = r[31];
    r[6] = (u)r[29] + 16; CALL(R_GV_SubVec3);
    r[4] = (u)r[29] + 16; CALL(R_GV_VecDir2);
    r[3] = *(int *)((u)r[16] + 156);
    r[3] = *(int *)((u)r[3] + 60);
    c = ((r[3] != 0)); r[6] = r[2] & 4095; if (c) goto L800c4ee8;
    r[2] = (u)0 + 8;
    *(short *)((u)r[16] + 1866) = 0;
    *(short *)((u)r[16] + 110) = r[6];
    *(char *)((u)r[16] + 116) = r[2]; goto L800c4f40;
    L800c4ee8:;
    r[5] = *(short *)((u)r[16] + 42);
    r[4] = (u)r[6] + (u)0; CALL(R_GV_DiffDirS);
    r[6] = (u)r[2] + (u)0;
    r[2] = (u)r[6] + 767;
    r[2] = (u)r[2] < (u)1535;
    c = ((r[2] == 0)); r[4] = (u)r[29] + 16; if (c) goto L800c4f1c;
    r[4] = *(short *)((u)r[16] + 1866);
    r[5] = (u)0 - (u)r[6]; CALL(R_GV_NearExp8);
    *(short *)((u)r[16] + 1866) = r[2]; goto L800c4f34;
    L800c4f1c:;
    *(short *)((u)r[16] + 1866) = 0; CALL(R_GV_VecDir2);
    r[2] = r[2] & 4095;
    *(short *)((u)r[16] + 110) = r[2];
    r[2] = (u)0 + 8;
    *(char *)((u)r[16] + 116) = r[2];
    L800c4f34:;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + (u)0; CALL(R_s07b_800C5B14);
    L800c4f40:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
