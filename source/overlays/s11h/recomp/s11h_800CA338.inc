extern char R_GM_FreeObject[] __asm__("GM_FreeObject");
int G_s11h_800CA338(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800CA338");
int G_s11h_800CA338(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[18] + 40;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)0 + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    L800ca358:;
    r[4] = (u)r[17] + (u)0; CALL(R_GM_FreeObject);
    r[16] = (u)r[16] + 1;
    r[2] = (int)r[16] < 15;
    c = ((r[2] != 0)); r[17] = (u)r[17] + 268; if (c) goto L800ca358;
    r[17] = (u)r[18] + 4060;
    r[16] = (u)0 + (u)0;
    L800ca378:;
    r[4] = (u)r[17] + (u)0; CALL(R_GM_FreeObject);
    r[16] = (u)r[16] + 1;
    r[2] = (int)r[16] < 16;
    c = ((r[2] != 0)); r[17] = (u)r[17] + 348; if (c) goto L800ca378;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
