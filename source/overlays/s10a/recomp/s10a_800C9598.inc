extern char R_DG_FreeObjsPacket[] __asm__("DG_FreeObjsPacket");
int G_s10a_800C9598(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C9598");
int G_s10a_800C9598(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    r[5] = (u)0 + (u)0; CALL(R_DG_FreeObjsPacket);
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + 1; CALL(R_DG_FreeObjsPacket);
    r[5] = (u)0 + (u)0;
    r[4] = (u)r[17] + (u)0;
    r[3] = (u)0 + 32;
    *(int *)((u)r[16] + 36) = r[17];
    r[16] = (u)r[16] + 154;
    L800c95d8:;
    r[2] = (u)r[17] + (u)r[3];
    *(int *)((u)r[16] + -18) = r[2];
    r[2] = *(unsigned short *)((u)r[4] + 36);
    r[4] = (u)r[4] + 88;
    r[3] = (u)r[3] + 88;
    r[5] = (u)r[5] + 1;
    *(short *)((u)r[16] + 0) = r[2];
    r[2] = (int)r[5] < 16;
    c = ((r[2] != 0)); r[16] = (u)r[16] + 92; if (c) goto L800c95d8;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
