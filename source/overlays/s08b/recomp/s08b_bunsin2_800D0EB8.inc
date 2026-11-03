extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_linkvarbuf[] __asm__("linkvarbuf");
int G_s08b_bunsin2_800D0EB8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800D0EB8");
int G_s08b_bunsin2_800D0EB8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 6696);
    r[2] = (u)0 + 8;
    *(int *)((u)r[4] + 6576) = r[2];
    r[2] = 0;
    *(int *)((u)r[4] + 6580) = r[3];
    r[3] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 2));
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); r[5] = (u)0 + 15; if (c) goto L800d0ef4;
    c = (((int)r[3] <= 0)); r[5] = (u)0 + 30; if (c) goto L800d0ef4;
    r[2] = (int)r[3] < 4;
    c = ((r[2] == 0));  if (c) goto L800d0ef4;
    r[5] = (u)0 + 5;
    L800d0ef4:;
    r[2] = *(int *)((u)r[4] + 6608);
    r[2] = (int)r[5] < (int)r[2];
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d0f30;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 512;
    c = ((r[2] != 0)); r[2] = (u)0 + 5; if (c) goto L800d0f30;
    *(int *)((u)r[4] + 6600) = r[2];
    r[2] = (u)0 + 24;
    L800d0f24:;
    *(int *)((u)r[4] + 6604) = r[2];
    *(int *)((u)r[4] + 6608) = 0; goto out;
    L800d0f30:;
    r[3] = *(int *)((u)r[4] + 6608);
    r[2] = (int)r[3] < 61;
    c = ((r[2] != 0)); r[2] = (u)r[3] + 1; if (c) goto L800d0f4c;
    r[2] = (u)0 + 19; goto L800d0f24;
    L800d0f4c:;
    *(int *)((u)r[4] + 6608) = r[2]; goto out;
out:
    return r[2];
}
