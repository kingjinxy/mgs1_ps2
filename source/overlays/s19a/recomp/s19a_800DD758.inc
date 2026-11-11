extern char R_s19a_dat_800E0E28[] __asm__("s19a_dat_800E0E28");
extern char R_GM_StreamPlayStop[] __asm__("GM_StreamPlayStop");
extern char R_GM_StreamStatus[] __asm__("GM_StreamStatus");
int G_s19a_800DD758(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DD758");
int G_s19a_800DD758(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 24) = r[18];
    r[18] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[5] + (u)0;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_GM_StreamStatus);
    r[17] = 0;
    r[16] = (u)r[17] + (int)R_s19a_dat_800E0E28;
    r[3] = *(int *)((u)r[16] + 40);
    c = ((r[3] != 0)); r[4] = (u)r[2] + (u)0; if (c) goto L800dd7d8;
    r[2] = (u)r[18] << 2;
    r[2] = (u)r[2] + (u)r[16];
    *(int *)((u)r[16] + 28) = r[18];
    r[2] = *(int *)((u)r[2] + 44);
    *(int *)((u)r[16] + 24) = r[19];
    *(int *)((u)r[16] + 32) = r[2];
    r[2] = (u)0 + 2;
    c = ((r[4] == r[2]));  if (c) goto L800dd7c8;
     CALL(R_GM_StreamPlayStop);
    r[2] = (u)0 + 5;
    *(int *)((u)r[16] + 8) = r[2];
    L800dd7c8:;
    r[2] = *(int *)((u)r[17] + (int)R_s19a_dat_800E0E28);
    r[2] = r[2] | 2;
    *(int *)((u)r[17] + (int)R_s19a_dat_800E0E28) = r[2];
    L800dd7d8:;
    r[31] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s19a_dat_800E0E28);
    r[2] = r[2] & 2;
    r[2] = (u)0 < (u)r[2]; goto out;
out:
    RECOMP_RETURN;
}
