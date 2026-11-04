extern char R_HZD_QueueDynamicFloor[] __asm__("HZD_QueueDynamicFloor");
extern char R_HZD_QueueDynamicSegment2[] __asm__("HZD_QueueDynamicSegment2");
int G_s11h_800CCC84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800CCC84");
int G_s11h_800CCC84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[20];
    r[20] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 28) = r[19];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16];
    r[19] = *(int *)((u)r[20] + 72);
    r[17] = *(int *)((u)r[5] + 20);
    r[2] = *(short *)((u)r[5] + 2);
    r[16] = *(int *)((u)r[20] + 68);
    c = (((int)r[16] <= 0)); r[18] = (u)r[17] + (u)r[2]; if (c) goto L800cccf4;
    r[5] = (u)r[19] + (u)0;
    L800cccc4:;
    r[19] = (u)r[19] + 16;
    r[2] = *(unsigned char *)((u)r[17] + 0);
    r[17] = (u)r[17] + 1;
    r[6] = *(unsigned char *)((u)r[18] + 0);
    r[18] = (u)r[18] + 1;
    r[16] = (u)r[16] + -1;
    r[4] = *(int *)((u)r[20] + 60);
    r[6] = (u)r[6] << 8;
    r[6] = r[2] | r[6]; CALL(R_HZD_QueueDynamicSegment2);
    c = (((int)r[16] > 0)); r[5] = (u)r[19] + (u)0; if (c) goto L800cccc4;
    L800cccf4:;
    r[16] = *(int *)((u)r[20] + 64);
    r[17] = *(int *)((u)r[20] + 76);
    c = (((int)r[16] <= 0));  if (c) goto L800ccd20;
    L800ccd04:;
    r[4] = *(int *)((u)r[20] + 60);
    r[5] = (u)r[17] + (u)0;
    r[17] = (u)r[17] + 48;
    r[16] = (u)r[16] + -1; CALL(R_HZD_QueueDynamicFloor);
    c = (((int)r[16] > 0));  if (c) goto L800ccd04;
    L800ccd20:;
    r[31] = *(int *)((u)r[29] + 36);
    r[20] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
