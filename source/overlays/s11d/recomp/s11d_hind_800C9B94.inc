extern char R_GV_DiffDirS[] __asm__("GV_DiffDirS");
int G_s11d_hind_800C9B94(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11d_hind_800C9B94");
int G_s11d_hind_800C9B94(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[16] + 32;
    *(int *)((u)r[29] + 24) = r[31];
    r[4] = *(short *)((u)r[17] + 78);
    r[5] = *(short *)((u)r[17] + 10);
     CALL(R_GV_DiffDirS);
    c = ((r[2] != 0));  if (c) goto L800c9bec;
    r[3] = *(int *)((u)r[16] + 2404);
    r[2] = (int)r[3] < -4;
    c = ((r[2] != 0)); r[2] = (u)r[3] + 4; if (c) goto L800c9c50;
    r[2] = (int)r[3] < 5;
    c = ((r[2] == 0)); r[2] = (u)r[3] + -4; if (c) goto L800c9c50;
    *(int *)((u)r[16] + 2404) = 0; goto L800c9c54;
    L800c9bec:;
    c = (((int)r[2] <= 0));  if (c) goto L800c9c24;
    r[2] = *(short *)((u)r[16] + 498);
    r[4] = *(int *)((u)r[16] + 2404);
    r[3] = (u)r[2] - (u)r[4];
    r[2] = (int)r[3] < -16;
    c = ((r[2] != 0)); r[2] = (u)r[4] + -16; if (c) goto L800c9c50;
    r[2] = (int)r[3] < 17;
    c = ((r[2] != 0)); r[2] = (u)r[4] + (u)r[3]; if (c) goto L800c9c50;
    r[2] = (u)r[4] + 16; goto L800c9c50;
    L800c9c24:;
    r[2] = *(short *)((u)r[16] + 498);
    r[4] = *(int *)((u)r[16] + 2404);
    r[2] = (u)0 - (u)r[2];
    r[3] = (u)r[2] - (u)r[4];
    r[2] = (int)r[3] < -16;
    c = ((r[2] != 0)); r[2] = (u)r[4] + -16; if (c) goto L800c9c50;
    r[2] = (int)r[3] < 17;
    c = ((r[2] != 0)); r[2] = (u)r[4] + (u)r[3]; if (c) goto L800c9c50;
    r[2] = (u)r[4] + 16;
    L800c9c50:;
    *(int *)((u)r[16] + 2404) = r[2];
    L800c9c54:;
    r[2] = *(unsigned short *)((u)r[17] + 80);
    r[3] = *(unsigned short *)((u)r[16] + 2404);
    r[2] = (u)r[2] + (u)r[3];
    *(short *)((u)r[17] + 80) = r[2];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
