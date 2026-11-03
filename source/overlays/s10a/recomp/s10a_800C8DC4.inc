extern char R_GV_ReceiveMessage[] __asm__("GV_ReceiveMessage");
int G_s10a_800C8DC4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C8DC4");
int G_s10a_800C8DC4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[17] + 32;
    *(int *)((u)r[29] + 24) = r[31];
    r[4] = *(unsigned short *)((u)r[16] + 48);
    r[5] = (u)r[17] + 124; CALL(R_GV_ReceiveMessage);
    r[3] = (u)r[2] << 24;
    r[6] = *(int *)((u)r[16] + 92);
    r[3] = (int)r[3] >> 24;
    c = (((int)r[3] <= 0)); *(char *)((u)r[16] + 86) = r[2]; if (c) goto L800c8e1c;
    r[4] = *(short *)((u)r[17] + 3086);
    L800c8e00:;
    r[2] = *(unsigned short *)((u)r[6] + 4);
    c = ((r[2] == r[4])); r[2] = (u)0 + 1; if (c) goto L800c8e20;
    r[3] = (u)r[3] + -1;
    c = (((int)r[3] > 0)); r[6] = (u)r[6] + 20; if (c) goto L800c8e00;
    L800c8e1c:;
    r[2] = (u)0 + (u)0;
    L800c8e20:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
