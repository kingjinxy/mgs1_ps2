extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s19a_800D213C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D213C");
int G_s19a_800D213C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(short *)((u)r[4] + 2958);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2]));  if (c) goto L800d21c0;
    r[2] = (int)r[3] < 2;
    c = ((r[2] == 0)); r[2] = (u)0 + 2; if (c) goto L800d2168;
    c = ((r[3] == 0));  if (c) goto L800d2178;
     goto L800d21e0;
    L800d2168:;
    c = ((r[3] == r[2]));  if (c) goto L800d21d0;
     goto L800d21e0;
    L800d2178:;
    r[3] = *(short *)((u)r[4] + 2960);
    c = ((r[3] != r[2]));  if (c) goto L800d21b0;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 2;
    c = ((r[2] == 0));  if (c) goto L800d21b0;
    r[2] = *(short *)((u)r[4] + 2956);
    c = ((r[2] != 0));  if (c) goto L800d21e0;
    L800d21b0:;
    r[2] = *(int *)((u)r[4] + 2964);
    *(short *)((u)r[4] + 2960) = 0;
    r[2] = (u)r[2] + -4; goto L800d21dc;
    L800d21c0:;
    r[2] = *(int *)((u)r[4] + 2964);
    *(short *)((u)r[4] + 2960) = r[3];
    r[2] = (u)r[2] + -1; goto L800d21dc;
    L800d21d0:;
    r[2] = *(int *)((u)r[4] + 2964);
    *(short *)((u)r[4] + 2960) = r[3];
    r[2] = (u)r[2] + 1;
    L800d21dc:;
    *(int *)((u)r[4] + 2964) = r[2];
    L800d21e0:;
    r[2] = *(int *)((u)r[4] + 2964);
    c = (((int)r[2] >= 0)); r[2] = (int)r[2] < 256; if (c) goto L800d21f8;
    *(int *)((u)r[4] + 2964) = 0; goto out;
    L800d21f8:;
    c = ((r[2] != 0)); r[2] = (u)0 + 255; if (c) goto L800d2204;
    *(int *)((u)r[4] + 2964) = r[2];
    L800d2204:;
     goto out;
out:
    RECOMP_RETURN;
}
