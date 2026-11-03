extern char R_ratan2[] __asm__("ratan2");
int G_s10a_800D9B64(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D9B64");
int G_s10a_800D9B64(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    r[3] = *(short *)((u)r[16] + 2444);
    r[2] = *(short *)((u)r[16] + 2440);
    r[4] = *(short *)((u)r[16] + 36);
    r[5] = *(short *)((u)r[16] + 40);
    r[4] = (u)r[2] - (u)r[4];
    r[5] = (u)r[3] - (u)r[5]; CALL(R_ratan2);
    r[4] = r[2] & 4095;
    r[3] = *(int *)((u)r[16] + 2180);
    r[2] = *(short *)((u)r[16] + 36);
    *(short *)((u)r[16] + 114) = r[4];
    r[3] = (u)r[3] << 3;
    r[3] = (u)r[16] + (u)r[3];
    r[3] = *(short *)((u)r[3] + 2184);
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] == 0));  if (c) goto L800d9bd4;
    c = ((r[17] != 0)); r[2] = (u)r[4] + -1024; if (c) goto L800d9be0;
    *(short *)((u)r[16] + 114) = r[2]; goto L800d9be0;
    L800d9bd4:;
    c = ((r[17] != 0)); r[2] = (u)r[4] + 1024; if (c) goto L800d9be0;
    *(short *)((u)r[16] + 114) = r[2];
    L800d9be0:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
