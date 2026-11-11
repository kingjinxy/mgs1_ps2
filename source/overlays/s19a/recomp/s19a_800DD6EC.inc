extern char R_s19a_dat_800E0E28[] __asm__("s19a_dat_800E0E28");
extern char R_GM_StreamPlayStop[] __asm__("GM_StreamPlayStop");
extern char R_GM_StreamStatus[] __asm__("GM_StreamStatus");
int G_s19a_800DD6EC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DD6EC");
int G_s19a_800DD6EC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_GM_StreamStatus);
    r[3] = 0;
    r[4] = (u)r[3] + (int)R_s19a_dat_800E0E28;
    r[3] = *(int *)((u)r[4] + 40);
    c = ((r[3] != 0)); r[5] = (u)r[2] + (u)0; if (c) goto L800dd748;
    r[2] = (u)r[16] << 2;
    r[2] = (u)r[2] + (u)r[4];
    *(int *)((u)r[4] + 12) = 0;
    *(int *)((u)r[4] + 16) = r[16];
    r[2] = *(int *)((u)r[2] + 44);
    *(int *)((u)r[4] + 20) = r[2];
    r[2] = (u)0 + 2;
    c = ((r[5] == r[2]));  if (c) goto L800dd748;
     CALL(R_GM_StreamPlayStop);
    L800dd748:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
