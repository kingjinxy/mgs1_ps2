extern char R_GM_StreamPlayStart[] __asm__("GM_StreamPlayStart");
extern char R_GM_StreamStatus[] __asm__("GM_StreamStatus");
int G_s18a_800CD758(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CD758");
int G_s18a_800CD758(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2476);
    r[4] = *(int *)((u)r[16] + 2408);
    r[3] = (u)0 + 6;
    *(int *)((u)r[16] + 2384) = r[3];
    c = (((int)r[4] <= 0)); *(int *)((u)r[16] + 2388) = r[2]; if (c) goto L800cd79c;
     CALL(R_GM_StreamStatus);
    r[3] = (u)0 + 1;
    c = ((r[2] != r[3]));  if (c) goto L800cd79c;
     CALL(R_GM_StreamPlayStart);
    L800cd79c:;
    r[2] = *(int *)((u)r[16] + 2408);
    r[2] = (int)r[2] < 101;
    c = ((r[2] != 0));  if (c) goto L800cd7d4;
     CALL(R_GM_StreamStatus);
    r[3] = (u)0 + -1;
    c = ((r[2] != r[3])); r[2] = (u)0 + 4; if (c) goto L800cd7d4;
    *(int *)((u)r[16] + 2404) = r[2];
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0; goto L800cd7e4;
    L800cd7d4:;
    r[2] = *(int *)((u)r[16] + 2408);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + 2408) = r[2];
    L800cd7e4:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
