extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
int G_s10a_800CB904(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CB904");
int G_s10a_800CB904(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[3] = *(short *)((u)r[4] + 2958);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2]));  if (c) goto L800cb988;
    r[2] = (int)r[3] < 2;
    c = ((r[2] == 0)); r[2] = (u)0 + 2; if (c) goto L800cb930;
    c = ((r[3] == 0));  if (c) goto L800cb940;
     goto L800cb9a8;
    L800cb930:;
    c = ((r[3] == r[2]));  if (c) goto L800cb998;
     goto L800cb9a8;
    L800cb940:;
    r[3] = *(short *)((u)r[4] + 2960);
    c = ((r[3] != r[2]));  if (c) goto L800cb978;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 2;
    c = ((r[2] == 0));  if (c) goto L800cb978;
    r[2] = *(short *)((u)r[4] + 2956);
    c = ((r[2] != 0));  if (c) goto L800cb9a8;
    L800cb978:;
    r[2] = *(int *)((u)r[4] + 2964);
    *(short *)((u)r[4] + 2960) = 0;
    r[2] = (u)r[2] + -4; goto L800cb9a4;
    L800cb988:;
    r[2] = *(int *)((u)r[4] + 2964);
    *(short *)((u)r[4] + 2960) = r[3];
    r[2] = (u)r[2] + -1; goto L800cb9a4;
    L800cb998:;
    r[2] = *(int *)((u)r[4] + 2964);
    *(short *)((u)r[4] + 2960) = r[3];
    r[2] = (u)r[2] + 1;
    L800cb9a4:;
    *(int *)((u)r[4] + 2964) = r[2];
    L800cb9a8:;
    r[2] = *(int *)((u)r[4] + 2964);
    c = (((int)r[2] >= 0)); r[2] = (int)r[2] < 256; if (c) goto L800cb9c0;
    *(int *)((u)r[4] + 2964) = 0; goto out;
    L800cb9c0:;
    c = ((r[2] != 0)); r[2] = (u)0 + 255; if (c) goto L800cb9cc;
    *(int *)((u)r[4] + 2964) = r[2];
    L800cb9cc:;
     goto out;
out:
    return r[2];
}
