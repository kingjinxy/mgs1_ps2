extern char R_s18a_dat_800C3480[] __asm__("s18a_dat_800C3480");
extern char R_s18a_dat_800C3490[] __asm__("s18a_dat_800C3490");
int G_s18a_800CF338(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CF338");
int G_s18a_800CF338(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[2] = *(int *)((u)r[5] + 2368);
    c = ((r[2] != 0)); r[2] = 0; if (c) goto L800cf364;
    r[3] = *(int *)((u)r[5] + 2408);
    r[2] = (int)r[3] < 61;
    c = ((r[2] != 0)); r[2] = (u)r[3] + 1; if (c) goto L800cf3a8;
    r[2] = 0;
    L800cf364:;
    r[3] = *(int *)((u)r[2] + (int)R_s18a_dat_800C3490);
    r[4] = *(int *)((u)r[5] + 2440);
    r[3] = (u)r[3] + 1;
    r[4] = (int)r[4] < 180;
    c = ((r[4] == 0)); *(int *)((u)r[2] + (int)R_s18a_dat_800C3490) = r[3]; if (c) goto L800cf38c;
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s18a_dat_800C3480) = 0;
    r[2] = (u)0 + 2;
    *(int *)((u)r[5] + 2396) = r[2];
    L800cf38c:;
    r[2] = (u)0 + 3;
    *(int *)((u)r[5] + 2400) = r[2];
    r[2] = (u)0 + 14;
    *(int *)((u)r[5] + 2404) = r[2];
    *(int *)((u)r[5] + 2428) = 0;
    *(int *)((u)r[5] + 2408) = 0; goto out;
    L800cf3a8:;
    *(int *)((u)r[5] + 2408) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
