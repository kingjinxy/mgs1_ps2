extern char R_MENU_DrawBar[] __asm__("MENU_DrawBar");
int G_s10a_800D6950(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D6950");
int G_s10a_800D6950(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 28) = r[17];
    *(int *)((u)r[29] + 24) = r[16];
    r[2] = *(int *)((u)r[18] + 2664);
    c = ((r[2] != 0));  if (c) goto L800d6a1c;
    r[2] = *(int *)((u)r[18] + 2624);
    c = (((int)r[2] >= 0));  if (c) goto L800d698c;
    r[2] = (u)r[2] + 7;
    L800d698c:;
    r[2] = (int)r[2] >> 3;
    r[16] = (u)r[2] << 3;
    c = (((int)r[16] >= 0));  if (c) goto L800d69a0;
    r[16] = (u)0 + (u)0;
    L800d69a0:;
    r[17] = *(int *)((u)r[18] + 2628);
    r[7] = (u)r[16] + (u)0;
    r[2] = (int)r[17] < (int)r[16];
    c = ((r[2] == 0)); r[6] = (u)r[17] + (u)0; if (c) goto L800d69bc;
    r[6] = (u)r[16] + (u)0;
    r[17] = (u)r[16] + (u)0;
    L800d69bc:;
    r[3] = *(int *)((u)r[18] + 2492);
    r[2] = (u)0 + 1;
    c = ((r[3] != r[2])); r[2] = (u)r[18] + 2612; if (c) goto L800d69f0;
    c = ((r[17] != r[16]));  if (c) goto L800d69f0;
    r[3] = *(int *)((u)r[18] + 2640);
    r[2] = (int)r[3] < 30;
    c = ((r[2] == 0)); r[2] = (u)r[3] + 1; if (c) goto L800d6a1c;
    *(int *)((u)r[18] + 2640) = r[2];
    r[2] = (u)r[18] + 2612;
    L800d69f0:;
    *(int *)((u)r[29] + 16) = r[2];
    r[4] = (u)0 + 16;
    r[5] = (u)0 + 28; CALL(R_MENU_DrawBar);
    r[2] = (int)r[16] < (int)r[17];
    c = ((r[2] == 0));  if (c) goto L800d6a1c;
    r[2] = *(int *)((u)r[18] + 2628);
    r[2] = (u)r[2] + -8;
    *(int *)((u)r[18] + 2628) = r[2];
    L800d6a1c:;
    r[31] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
