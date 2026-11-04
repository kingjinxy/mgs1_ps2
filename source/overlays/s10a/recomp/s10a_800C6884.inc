extern char R_s10a_dat_800E36CC[] __asm__("s10a_dat_800E36CC");
extern char R_GCL_GetOption[] __asm__("GCL_GetOption");
extern char R_fprintf[] __asm__("fprintf");
extern char R_s10a_800C677C[] __asm__("s10a_800C677C");
int G_s10a_800C6884(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800C6884");
int G_s10a_800C6884(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[4] = (u)0 + 114;
    *(int *)((u)r[29] + 20) = r[31];
    *(char *)((u)r[16] + 2700) = 0;
    *(short *)((u)r[16] + 2694) = 0; CALL(R_GCL_GetOption);
    c = ((r[2] == 0)); r[4] = (u)r[2] + (u)0; if (c) goto L800c68d8;
    r[5] = (u)r[16] + 2700; CALL(R_s10a_800C677C);
    r[2] = (int)r[2] < 4;
    c = ((r[2] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800c68dc;
    r[4] = (u)0 + (u)0;
    r[5] = 0;
    r[5] = (u)r[5] + ((int)R_s10a_dat_800E36CC + 60); CALL(R_fprintf);
    r[2] = (u)0 + -1; goto L800c68dc;
    L800c68d8:;
    r[2] = (u)0 + (u)0;
    L800c68dc:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
