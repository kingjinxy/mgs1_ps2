extern char R_GV_NearExp2[] __asm__("GV_NearExp2");
int G_s10a_800DD0FC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800DD0FC");
int G_s10a_800DD0FC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    r[2] = (u)0 + 21;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[3] = *(int *)((u)r[17] + 1628);
    r[16] = (u)r[17] + 36;
    *(short *)((u)r[3] + 0) = r[2];
    r[2] = *(unsigned short *)((u)r[17] + 184);
    r[4] = *(short *)((u)r[16] + 54);
    r[5] = (u)0 + 450;
    *(short *)((u)r[16] + 50) = r[2]; CALL(R_GV_NearExp2);
    *(short *)((u)r[16] + 54) = r[2];
    r[2] = *(int *)((u)r[17] + 1676);
    c = (((int)r[2] >= 0)); r[2] = (u)r[2] + -16; if (c) goto L800dd168;
    r[2] = *(signed char *)((u)r[16] + 87);
    c = ((r[2] == 0));  if (c) goto L800dd15c;
    *(int *)((u)r[17] + 1676) = 0;
    L800dd15c:;
    r[2] = *(int *)((u)r[17] + 1676);
    r[2] = (u)r[2] + -16;
    L800dd168:;
    *(int *)((u)r[17] + 1676) = r[2];
    r[2] = *(unsigned short *)((u)r[17] + 1676);
    *(short *)((u)r[16] + 70) = r[2];
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
