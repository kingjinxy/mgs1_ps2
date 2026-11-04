extern char R_GM_GameStatus[] __asm__("GM_GameStatus");
extern char R_MENU_DrawBar[] __asm__("MENU_DrawBar");
int G_s11b_800D112C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800D112C");
int G_s11b_800D112C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[18];
    r[18] = (u)r[4] + (u)0;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_GameStatus);
    r[3] = 0x20000;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 28) = r[17];
    r[2] = r[2] & r[3];
    c = ((r[2] != 0)); *(int *)((u)r[29] + 24) = r[16]; if (c) goto L800d11cc;
    r[16] = *(int *)((u)r[18] + 1620);
    c = (((int)r[16] >= 0));  if (c) goto L800d116c;
    r[16] = (u)0 + (u)0;
    L800d116c:;
    r[17] = *(int *)((u)r[18] + 2036);
    r[2] = (int)r[17] < (int)r[16];
    c = ((r[2] == 0)); r[6] = (u)r[17] + (u)0; if (c) goto L800d1188;
    r[6] = (u)r[16] + (u)0;
    r[17] = (u)r[16] + (u)0;
    L800d1188:;
    r[2] = (u)r[18] + 2024;
    *(int *)((u)r[29] + 16) = r[2];
    r[4] = (u)0 + 16;
    r[5] = (u)0 + 28;
    r[7] = (u)r[16] + (u)0; CALL(R_MENU_DrawBar);
    r[2] = (int)r[16] < (int)r[17];
    c = ((r[2] == 0));  if (c) goto L800d11cc;
    r[2] = *(int *)((u)r[18] + 2036);
    r[2] = (u)r[2] + -8;
    *(int *)((u)r[18] + 2036) = r[2];
    r[2] = (int)r[2] < (int)r[16];
    c = ((r[2] == 0));  if (c) goto L800d11cc;
    *(int *)((u)r[18] + 2036) = r[16];
    L800d11cc:;
    r[31] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
