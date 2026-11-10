extern char R_s18a_800CCD5C[] __asm__("s18a_800CCD5C");
int G_s18a_800CF3B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CF3B0");
int G_s18a_800CF3B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2368);
    c = ((r[2] != 0));  if (c) goto L800cf3e4;
    r[2] = *(int *)((u)r[16] + 2408);
    r[2] = (int)r[2] < 61;
    c = ((r[2] != 0)); r[2] = (u)0 + 4; if (c) goto L800cf43c;
    L800cf3e4:;
    r[3] = *(int *)((u)r[16] + 2460);
    r[2] = (u)0 + 1;
    c = ((r[3] != r[2])); r[2] = (u)0 + 5; if (c) goto L800cf400;
    *(int *)((u)r[16] + 2400) = r[2];
    r[2] = (u)0 + 22; goto L800cf428;
    L800cf400:;
    r[4] = (u)r[16] + 32; CALL(R_s18a_800CCD5C);
    c = ((r[2] == 0)); r[2] = (u)0 + 3; if (c) goto L800cf41c;
    *(int *)((u)r[16] + 2400) = r[2];
    r[2] = (u)0 + 14; goto L800cf428;
    L800cf41c:;
    r[2] = (u)0 + 2;
    *(int *)((u)r[16] + 2400) = r[2];
    r[2] = (u)0 + 9;
    L800cf428:;
    *(int *)((u)r[16] + 2404) = r[2];
    *(int *)((u)r[16] + 2460) = 0;
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0; goto L800cf460;
    L800cf43c:;
    r[3] = *(int *)((u)r[16] + 2488);
    c = ((r[3] != r[2]));  if (c) goto L800cf450;
    *(int *)((u)r[16] + 2460) = 0;
    L800cf450:;
    r[2] = *(int *)((u)r[16] + 2408);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + 2408) = r[2];
    L800cf460:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
