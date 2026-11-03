extern char R_s10a_dat_800E3824[] __asm__("s10a_dat_800E3824");
extern char R_GM_StreamPlayStart[] __asm__("GM_StreamPlayStart");
extern char R_GM_StreamStatus[] __asm__("GM_StreamStatus");
extern char R_GM_VoxStream[] __asm__("GM_VoxStream");
extern char R_printf[] __asm__("printf");
int G_s10a_800C8D08(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C8D08");
int G_s10a_800C8D08(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = 0;
    r[5] = (u)r[5] + -16;
    r[2] = (u)r[5] << 2;
    r[2] = (u)r[16] + (u)r[2];
    *(int *)((u)r[29] + 20) = r[31];
    r[6] = *(int *)((u)r[2] + 3608);
    r[4] = (u)r[4] + ((int)R_s10a_dat_800E3824 + 32); CALL(R_printf);
     CALL(R_GM_StreamStatus);
    r[3] = (u)0 + -1;
    c = ((r[2] != r[3]));  if (c) goto L800c8d74;
    r[2] = *(int *)((u)r[16] + 3640);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + 3640) = r[2];
    r[2] = (u)r[2] << 2;
    r[2] = (u)r[16] + (u)r[2];
    r[4] = *(int *)((u)r[2] + 3608);
    r[5] = (u)0 + (u)0; CALL(R_GM_VoxStream);
     goto L800c8d7c;
    L800c8d74:;
     CALL(R_GM_StreamPlayStart);
    L800c8d7c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
