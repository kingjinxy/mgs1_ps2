extern char R_GV_SubVec3[] __asm__("GV_SubVec3");
extern char R_GV_VecDir2[] __asm__("GV_VecDir2");
int G_s07b_800CBAA4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CBAA4");
int G_s07b_800CBAA4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)r[16] + 2724;
    r[5] = (u)r[16] + 32;
    *(int *)((u)r[29] + 28) = r[31];
    r[6] = (u)r[29] + 16; CALL(R_GV_SubVec3);
    r[4] = (u)r[29] + 16; CALL(R_GV_VecDir2);
    r[3] = *(unsigned short *)((u)r[16] + 110);
    r[3] = r[3] & 4095;
    r[2] = (u)r[2] - (u)r[3];
    r[3] = r[2] & 4095;
    r[2] = (int)r[3] < 2048;
    c = ((r[2] == 0)); r[2] = (int)r[3] < 256; if (c) goto L800cbb08;
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800cbb28;
    r[3] = (int)r[3] < 1281;
    c = ((r[3] == 0)); r[2] = (u)0 + 3; if (c) goto L800cbb28;
    r[2] = (u)0 + 4; goto L800cbb28;
    L800cbb08:;
    r[2] = (int)r[3] < 3841;
    c = ((r[2] == 0)); r[3] = (int)r[3] < 2816; if (c) goto L800cbb24;
    c = ((r[3] != 0)); r[2] = (u)0 + 3; if (c) goto L800cbb28;
    r[2] = (u)0 + 2; goto L800cbb28;
    L800cbb24:;
    r[2] = (u)0 + 1;
    L800cbb28:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
