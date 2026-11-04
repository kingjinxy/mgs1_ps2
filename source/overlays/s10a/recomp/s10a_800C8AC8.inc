extern char R_GV_VecDir2[] __asm__("GV_VecDir2");
int G_s10a_800C8AC8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800C8AC8");
int G_s10a_800C8AC8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    r[3] = *(short *)((u)r[16] + 2976);
    r[2] = *(short *)((u)r[16] + 32);
    r[4] = (u)r[3] - (u)r[2];
    *(short *)((u)r[29] + 16) = r[4];
    r[3] = *(short *)((u)r[16] + 2980);
    r[2] = *(short *)((u)r[16] + 36);
    r[6] = (u)0 - (u)r[5];
    r[3] = (u)r[3] - (u)r[2];
    r[2] = (int)r[6] < (int)r[4];
    c = ((r[2] == 0)); *(short *)((u)r[29] + 20) = r[3]; if (c) goto L800c8b24;
    r[2] = (int)r[4] < (int)r[5];
    c = ((r[2] == 0)); r[2] = (int)r[6] < (int)r[3]; if (c) goto L800c8b24;
    c = ((r[2] == 0)); r[2] = (int)r[3] < (int)r[5]; if (c) goto L800c8b24;
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800c8b40;
    L800c8b24:;
    r[4] = (u)r[29] + 16; CALL(R_GV_VecDir2);
    r[3] = *(int *)((u)r[16] + 3100);
    *(short *)((u)r[16] + 3082) = r[2];
    r[2] = (u)0 + (u)0;
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[16] + 3100) = r[3];
    L800c8b40:;
    r[31] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
