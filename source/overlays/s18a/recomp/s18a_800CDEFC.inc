extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_800CCA20[] __asm__("s18a_800CCA20");
int G_s18a_800CDEFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CDEFC");
int G_s18a_800CDEFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = *(int *)((u)r[16] + 2476);
    r[3] = *(int *)((u)r[16] + 2480);
    r[2] = (u)0 + 8;
    *(int *)((u)r[16] + 2384) = r[2];
    r[3] = (int)r[3] < 1000;
    c = ((r[3] == 0)); *(int *)((u)r[16] + 2388) = r[4]; if (c) goto L800cdf54;
    r[4] = *(int *)((u)r[16] + 2464);
    r[5] = *(int *)((u)r[16] + 2476);
    r[2] = (u)0 + 2;
    *(int *)((u)r[16] + 2400) = r[2]; CALL(R_s18a_800CCA20);
    c = ((r[2] != 0)); r[2] = (u)0 + 11; if (c) goto L800cdf48;
    r[2] = (u)0 + 10;
    L800cdf48:;
    *(int *)((u)r[16] + 2404) = r[2];
    *(int *)((u)r[16] + 2408) = 0; goto L800cdfbc;
    L800cdf54:;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 2048;
    c = ((r[2] == 0)); r[2] = (u)0 + 2; if (c) goto L800cdf88;
    *(int *)((u)r[16] + 2400) = r[2];
    r[2] = (u)0 + 33;
    *(int *)((u)r[16] + 2404) = r[2];
    *(int *)((u)r[16] + 2408) = 0;
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2392) = 0; goto L800cdfbc;
    L800cdf88:;
    r[3] = *(int *)((u)r[16] + 2408);
    r[2] = (int)r[3] < 91;
    c = ((r[2] != 0)); r[2] = (u)r[3] + 1; if (c) goto L800cdfb8;
    r[2] = (u)0 + 3;
    *(int *)((u)r[16] + 2400) = r[2];
    r[2] = (u)0 + 14;
    *(int *)((u)r[16] + 2404) = r[2];
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0; goto L800cdfbc;
    L800cdfb8:;
    *(int *)((u)r[16] + 2408) = r[2];
    L800cdfbc:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
