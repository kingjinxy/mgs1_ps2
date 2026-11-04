extern char R_GM_FreeControl[] __asm__("GM_FreeControl");
extern char R_GM_FreeObject[] __asm__("GM_FreeObject");
extern char R_GM_FreeTarget[] __asm__("GM_FreeTarget");
int G_s15a_800D4870(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D4870");
int G_s15a_800D4870(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[20];
    r[20] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 28) = r[19];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(int *)((u)r[20] + 36);
    c = (((int)r[2] <= 0)); r[17] = (u)0 + (u)0; if (c) goto L800d48e0;
    r[19] = (u)r[20] + (u)0;
    r[18] = (u)0 + 108;
    r[16] = (u)r[20] + (u)r[18];
    L800d48ac:;
    r[4] = (u)r[16] + 128; CALL(R_GM_FreeObject);
    r[4] = (u)r[16] + 4; CALL(R_GM_FreeControl);
    r[4] = *(int *)((u)r[19] + 108);
    r[19] = (u)r[19] + 972;
    r[18] = (u)r[18] + 972; CALL(R_GM_FreeTarget);
    r[2] = *(int *)((u)r[20] + 36);
    r[17] = (u)r[17] + 1;
    r[2] = (int)r[17] < (int)r[2];
    c = ((r[2] != 0)); r[16] = (u)r[20] + (u)r[18]; if (c) goto L800d48ac;
    L800d48e0:;
    r[31] = *(int *)((u)r[29] + 36);
    r[20] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
