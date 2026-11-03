extern char R_s07b_800CAD54[] __asm__("s07b_800CAD54");
int G_s07b_800CBF00(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CBF00");
int G_s07b_800CBF00(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    r[2] = *(int *)((u)r[29] + 56);
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[7] + (u)0;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[6] + (u)0;
    c = ((r[2] == 0)); *(int *)((u)r[29] + 32) = r[31]; if (c) goto L800cbf4c;
    r[2] = *(unsigned char *)((u)r[16] + 0);
    c = ((r[2] != 0)); r[2] = (u)r[2] + 1; if (c) goto L800cbf4c;
    *(char *)((u)r[16] + 0) = r[2];
    r[5] = (u)0 + 132; CALL(R_s07b_800CAD54);
    L800cbf4c:;
    r[2] = *(int *)((u)r[17] + 0);
    c = ((r[2] == 0));  if (c) goto L800cbf60;
    *(int *)((u)r[17] + 0) = 0;
    L800cbf60:;
    r[2] = *(unsigned char *)((u)r[16] + 0);
    c = ((r[2] == 0)); r[2] = (u)r[2] + 1; if (c) goto L800cbf94;
    *(char *)((u)r[16] + 0) = r[2];
    r[2] = r[2] & 255;
    r[3] = r[18] & 255;
    c = ((r[2] != r[3])); r[2] = (u)0 + 1; if (c) goto L800cbf94;
    *(int *)((u)r[17] + 0) = r[2];
    r[2] = (u)0 + 8;
    *(char *)((u)r[16] + 0) = 0;
    *(char *)((u)r[19] + 2659) = r[2];
    L800cbf94:;
    r[31] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    return r[2];
}
