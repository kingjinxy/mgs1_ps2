extern char R_s19a_dat_800E0E28[] __asm__("s19a_dat_800E0E28");
extern char R_GM_StreamPlayStop[] __asm__("GM_StreamPlayStop");
extern char R_GM_StreamStatus[] __asm__("GM_StreamStatus");
extern char R_s19a_800DD460[] __asm__("s19a_800DD460");
int G_s19a_800DD80C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800DD80C");
int G_s19a_800DD80C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    r[3] = 0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[3] + (int)R_s19a_dat_800E0E28;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[2] = *(int *)((u)r[16] + 40);
    c = ((r[2] != 0)); r[17] = (u)r[4] + (u)0; if (c) goto L800dd880;
    r[2] = *(int *)((u)r[3] + (int)R_s19a_dat_800E0E28);
    r[2] = r[2] & 2;
    c = ((r[2] == 0));  if (c) goto L800dd880;
    *(int *)((u)r[16] + 24) = 0; CALL(R_GM_StreamStatus);
    r[3] = (u)0 + 2;
    c = ((r[2] == r[3])); r[2] = (u)0 + 1; if (c) goto L800dd870;
     CALL(R_GM_StreamPlayStop);
    r[2] = (u)0 + 5;
    *(int *)((u)r[16] + 8) = r[2]; goto L800dd880;
    L800dd870:;
    c = ((r[17] != r[2]));  if (c) goto L800dd880;
     CALL(R_s19a_800DD460);
    L800dd880:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
