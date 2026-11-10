extern char R_GM_Camera[] __asm__("GM_Camera");
extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s18a_800D5CE8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D5CE8");
int G_s18a_800D5CE8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(short *)((u)r[4] + 2296);
    r[3] = *(unsigned short *)((u)r[4] + 2296);
    c = ((r[2] == 0));  if (c) goto L800d5d84;
    c = (((int)r[2] <= 0)); r[2] = 0; if (c) goto L800d5d4c;
    r[2] = *(short *)((u)r[2] + ((int)R_GM_Camera + 34));
    c = ((r[2] != 0)); r[2] = (u)r[3] + -1; if (c) goto L800d5d84;
    *(short *)((u)r[4] + 2296) = r[2];
    r[2] = (u)r[2] << 16;
    c = ((r[2] != 0)); r[5] = 0xffff0000; if (c) goto L800d5d84;
    r[5] = r[5] | 32767;
    r[3] = 0;
    r[2] = *(int *)((u)r[3] + (int)R_GM_PlayerStatus);
    r[4] = *(int *)((u)r[4] + 156);
    r[2] = r[2] & r[5];
    *(int *)((u)r[3] + (int)R_GM_PlayerStatus) = r[2];
    r[2] = *(int *)((u)r[4] + 40);
    r[3] = (u)0 + -129;
    r[2] = r[2] & r[3];
    *(int *)((u)r[4] + 40) = r[2]; goto out;
    L800d5d4c:;
    r[2] = *(short *)((u)r[2] + ((int)R_GM_Camera + 34));
    c = ((r[2] == 0)); r[2] = (u)r[3] + 1; if (c) goto L800d5d84;
    *(short *)((u)r[4] + 2296) = r[2];
    r[2] = (u)r[2] << 16;
    c = ((r[2] != 0));  if (c) goto L800d5d84;
    r[3] = *(int *)((u)r[4] + 156);
    r[2] = *(int *)((u)r[3] + 40);
    r[2] = r[2] | 128;
    *(int *)((u)r[3] + 40) = r[2];
    L800d5d84:;
     goto out;
out:
    RECOMP_RETURN;
}
