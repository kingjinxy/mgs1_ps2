extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s14e_800CAE24(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CAE24");
int G_s14e_800CAE24(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(short *)((u)r[4] + 2962);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2]));  if (c) goto L800caea8;
    r[2] = (int)r[3] < 2;
    c = ((r[2] == 0)); r[2] = (u)0 + 2; if (c) goto L800cae50;
    c = ((r[3] == 0));  if (c) goto L800cae60;
     goto L800caec8;
    L800cae50:;
    c = ((r[3] == r[2]));  if (c) goto L800caeb8;
     goto L800caec8;
    L800cae60:;
    r[3] = *(short *)((u)r[4] + 2964);
    c = ((r[3] != r[2]));  if (c) goto L800cae98;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 2;
    c = ((r[2] == 0));  if (c) goto L800cae98;
    r[2] = *(short *)((u)r[4] + 2960);
    c = ((r[2] != 0));  if (c) goto L800caec8;
    L800cae98:;
    r[2] = *(int *)((u)r[4] + 2968);
    *(short *)((u)r[4] + 2964) = 0;
    r[2] = (u)r[2] + -4; goto L800caec4;
    L800caea8:;
    r[2] = *(int *)((u)r[4] + 2968);
    *(short *)((u)r[4] + 2964) = r[3];
    r[2] = (u)r[2] + -1; goto L800caec4;
    L800caeb8:;
    r[2] = *(int *)((u)r[4] + 2968);
    *(short *)((u)r[4] + 2964) = r[3];
    r[2] = (u)r[2] + 1;
    L800caec4:;
    *(int *)((u)r[4] + 2968) = r[2];
    L800caec8:;
    r[2] = *(int *)((u)r[4] + 2968);
    c = (((int)r[2] >= 0)); r[2] = (int)r[2] < 256; if (c) goto L800caee0;
    *(int *)((u)r[4] + 2968) = 0; goto out;
    L800caee0:;
    c = ((r[2] != 0)); r[2] = (u)0 + 255; if (c) goto L800caeec;
    *(int *)((u)r[4] + 2968) = r[2];
    L800caeec:;
     goto out;
out:
    RECOMP_RETURN;
}
