extern char R_s17a_dat_800E5D80[] __asm__("s17a_dat_800E5D80");
extern char R_GM_StreamPlayStop[] __asm__("GM_StreamPlayStop");
extern char R_GM_StreamStatus[] __asm__("GM_StreamStatus");
extern char R_s17a_800D0204[] __asm__("s17a_800D0204");
int G_s17a_800D05B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800D05B0");
int G_s17a_800D05B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    r[3] = 0;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[3] + (int)R_s17a_dat_800E5D80;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[2] = *(int *)((u)r[16] + 40);
    c = ((r[2] != 0)); r[17] = (u)r[4] + (u)0; if (c) goto L800d0624;
    r[2] = *(int *)((u)r[3] + (int)R_s17a_dat_800E5D80);
    r[2] = r[2] & 2;
    c = ((r[2] == 0));  if (c) goto L800d0624;
    *(int *)((u)r[16] + 24) = 0; CALL(R_GM_StreamStatus);
    r[3] = (u)0 + 2;
    c = ((r[2] == r[3])); r[2] = (u)0 + 1; if (c) goto L800d0614;
     CALL(R_GM_StreamPlayStop);
    r[2] = (u)0 + 5;
    *(int *)((u)r[16] + 8) = r[2]; goto L800d0624;
    L800d0614:;
    c = ((r[17] != r[2]));  if (c) goto L800d0624;
     CALL(R_s17a_800D0204);
    L800d0624:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
    r[2] = 0;
    r[3] = (u)r[2] + (int)R_s17a_dat_800E5D80;
    r[2] = *(int *)((u)r[3] + 40);
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800d0654;
    *(int *)((u)r[3] + 40) = r[2];
    L800d0654:;
     goto out;
out:
    RECOMP_RETURN;
}
