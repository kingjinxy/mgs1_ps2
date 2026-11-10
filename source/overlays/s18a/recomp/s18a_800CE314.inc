extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_dat_800C3498[] __asm__("s18a_dat_800C3498");
int G_s18a_800CE314(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CE314");
int G_s18a_800CE314(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 2476);
    r[2] = (u)0 + 5;
    *(int *)((u)r[4] + 2384) = r[2];
    *(int *)((u)r[4] + 2388) = r[3];
    r[3] = *(int *)((u)r[4] + 2408);
    r[2] = (u)0 + 10;
    c = ((r[3] != r[2])); r[2] = (int)r[3] < 16; if (c) goto L800ce36c;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 96;
    c = ((r[2] == 0)); r[3] = 0; if (c) goto L800ce358;
    r[2] = (u)0 + 1;
    *(int *)((u)r[3] + (int)R_s18a_dat_800C3498) = r[2]; goto L800ce360;
    L800ce358:;
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s18a_dat_800C3498) = 0;
    L800ce360:;
    r[3] = *(int *)((u)r[4] + 2408);
    r[2] = (int)r[3] < 16;
    L800ce36c:;
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800ce3c4;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 64;
    c = ((r[2] != 0)); r[2] = (u)0 + 27; if (c) goto L800ce3b4;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s18a_dat_800C3498);
    c = ((r[2] != 0)); r[2] = (u)0 + 26; if (c) goto L800ce3b4;
    r[2] = *(int *)((u)r[4] + 2480);
    r[2] = (int)r[2] < 1001;
    c = ((r[2] != 0)); r[2] = (u)0 + 28; if (c) goto L800ce3b4;
    r[2] = (u)0 + 25;
    L800ce3b4:;
    *(int *)((u)r[4] + 2404) = r[2];
    *(int *)((u)r[4] + 2428) = 0;
    *(int *)((u)r[4] + 2408) = 0; goto out;
    L800ce3c4:;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 2048;
    c = ((r[2] == 0)); r[2] = (u)r[3] + 1; if (c) goto L800ce3f0;
    r[2] = (u)0 + 16;
    *(int *)((u)r[4] + 2404) = r[2];
    *(int *)((u)r[4] + 2408) = 0;
    *(int *)((u)r[4] + 2428) = 0;
    *(int *)((u)r[4] + 2392) = 0; goto out;
    L800ce3f0:;
    *(int *)((u)r[4] + 2408) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
