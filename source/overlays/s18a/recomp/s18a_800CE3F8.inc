extern char R_GM_PlayerStatus[] __asm__("GM_PlayerStatus");
extern char R_s18a_dat_800C349C[] __asm__("s18a_dat_800C349C");
int G_s18a_800CE3F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CE3F8");
int G_s18a_800CE3F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 2476);
    r[2] = (u)0 + 5;
    *(int *)((u)r[4] + 2384) = r[2];
    *(int *)((u)r[4] + 2388) = r[3];
    r[3] = *(int *)((u)r[4] + 2408);
    r[2] = (u)0 + 3;
    c = ((r[3] != r[2])); r[2] = (int)r[3] < 9; if (c) goto L800ce450;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 96;
    c = ((r[2] == 0)); r[3] = 0; if (c) goto L800ce43c;
    r[2] = (u)0 + 1;
    *(int *)((u)r[3] + (int)R_s18a_dat_800C349C) = r[2]; goto L800ce444;
    L800ce43c:;
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s18a_dat_800C349C) = 0;
    L800ce444:;
    r[3] = *(int *)((u)r[4] + 2408);
    r[2] = (int)r[3] < 9;
    L800ce450:;
    c = ((r[2] != 0)); r[2] = (u)r[3] + 1; if (c) goto L800ce4c4;
    r[2] = *(int *)((u)r[4] + 2480);
    r[2] = (int)r[2] < 2000;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800ce49c;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 64;
    c = ((r[2] != 0)); r[2] = (u)0 + 27; if (c) goto L800ce4b0;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s18a_dat_800C349C);
    c = ((r[2] != 0)); r[2] = (u)0 + 26; if (c) goto L800ce4b0;
    r[2] = (u)0 + 22; goto L800ce4b0;
    L800ce49c:;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerStatus);
    r[2] = r[2] & 96;
    c = ((r[2] != 0)); r[2] = (u)0 + 20; if (c) goto L800ce4b4;
    L800ce4b0:;
    *(int *)((u)r[4] + 2404) = r[2];
    L800ce4b4:;
    *(int *)((u)r[4] + 2428) = 0;
    *(int *)((u)r[4] + 2408) = 0;
    *(int *)((u)r[4] + 2432) = 0; goto out;
    L800ce4c4:;
    *(int *)((u)r[4] + 2408) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
