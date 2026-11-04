extern char R_s14e_dword_800C38B8[] __asm__("s14e_dword_800C38B8");
extern char R_DG_GetTexture[] __asm__("DG_GetTexture");
int G_s14e_800D9750(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800D9750");
int G_s14e_800D9750(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    r[5] = (u)r[5] << 2;
    r[5] = (u)r[18] + (u)r[5];
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 32) = r[20];
    *(int *)((u)r[29] + 28) = r[19];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16];
    r[19] = *(int *)((u)r[5] + 84);
    c = ((r[19] == 0)); r[2] = (u)0 + 16383; if (c) goto L800d97fc;
    r[3] = *(unsigned short *)((u)r[19] + 14);
    c = ((r[3] != r[2])); r[2] = 0; if (c) goto L800d97fc;
    r[3] = (u)r[2] + (int)R_s14e_dword_800C38B8;
    c = ((r[18] == 0)); r[20] = (u)0 + (u)0; if (c) goto L800d97fc;
    L800d97a4:;
    r[2] = *(int *)((u)r[18] + 64);
    r[16] = *(short *)((u)r[18] + 82);
    r[17] = *(int *)((u)r[2] + 80);
    c = (((int)r[16] <= 0));  if (c) goto L800d97ec;
    L800d97b8:;
    r[2] = *(unsigned short *)((u)r[17] + 0);
    r[4] = r[2] & 65535;
    c = ((r[4] == r[20])); r[17] = (u)r[17] + 2; if (c) goto L800d97d8;
    r[20] = (u)r[2] + (u)0; CALL(R_DG_GetTexture);
    r[3] = (u)r[2] + (u)0;
    L800d97d8:;
    r[2] = *(unsigned short *)((u)r[3] + 6);
    r[16] = (u)r[16] + -1;
    *(short *)((u)r[19] + 14) = r[2];
    c = (((int)r[16] > 0)); r[19] = (u)r[19] + 52; if (c) goto L800d97b8;
    L800d97ec:;
    r[18] = *(int *)((u)r[18] + 72);
    c = ((r[18] != 0));  if (c) goto L800d97a4;
    L800d97fc:;
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
