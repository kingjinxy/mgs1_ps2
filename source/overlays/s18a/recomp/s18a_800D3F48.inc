extern char R_GM_PlayerBody[] __asm__("GM_PlayerBody");
extern char R_ratan2[] __asm__("ratan2");
int G_s18a_800D3F48(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D3F48");
int G_s18a_800D3F48(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_GM_PlayerBody);
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 156);
    r[2] = *(int *)((u)r[2] + 0);
    r[5] = *(int *)((u)r[3] + 648);
    r[2] = *(int *)((u)r[2] + 648);
    r[4] = *(int *)((u)r[16] + 3596);
    r[5] = (u)r[2] - (u)r[5]; CALL(R_ratan2);
    r[2] = r[2] & 4095;
    r[3] = (u)r[2] + -1024;
    *(short *)((u)r[16] + 2152) = r[3];
    c = (((int)r[3] >= 0)); *(short *)((u)r[16] + 2184) = r[3]; if (c) goto L800d3f9c;
    r[2] = (u)r[3] << 1;
    r[2] = (u)r[2] + (u)r[3]; goto L800d3fb0;
    L800d3f9c:;
    r[2] = (u)r[3] << 1;
    r[2] = (u)r[2] + (u)r[3];
    r[3] = (u)r[2] >> 31;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (int)r[2] >> 1;
    L800d3fb0:;
    *(short *)((u)r[16] + 2192) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
