extern char R_GV_DiffDirS[] __asm__("GV_DiffDirS");
int G_s19a_800C55A8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C55A8");
int G_s19a_800C55A8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[2] = *(short *)((u)r[16] + 0);
    r[2] = (int)r[2] < 769;
    c = ((r[2] != 0)); r[17] = (u)r[4] + (u)0; if (c) goto L800c55d8;
    r[2] = (u)0 + 768;
    *(short *)((u)r[16] + 0) = r[2];
    L800c55d8:;
    r[4] = *(short *)((u)r[17] + 2);
    r[5] = *(short *)((u)r[16] + 2);
     CALL(R_GV_DiffDirS);
    r[3] = (u)r[2] + (u)0;
    r[2] = (int)r[3] < 1025;
    c = ((r[2] != 0));  if (c) goto L800c5604;
    r[2] = *(unsigned short *)((u)r[17] + 2);
    r[2] = (u)r[2] + 1024; goto L800c561c;
    L800c5604:;
    r[2] = (int)r[3] < -1024;
    c = ((r[2] == 0));  if (c) goto L800c5624;
    r[2] = *(unsigned short *)((u)r[17] + 2);
    r[2] = (u)r[2] + -1024;
    L800c561c:;
    r[2] = r[2] & 4095;
    *(short *)((u)r[16] + 2) = r[2];
    L800c5624:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
