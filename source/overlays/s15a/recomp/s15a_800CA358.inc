extern char R_s15a_dat_800D8BEC[] __asm__("s15a_dat_800D8BEC");
extern char R_s15a_dat_800D9268[] __asm__("s15a_dat_800D9268");
int G_s15a_800CA358(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CA358");
int G_s15a_800CA358(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2304);
    r[3] = *(int *)((u)r[4] + 1704);
    r[2] = (u)r[2] << 10;
    if (r[3]) { lo_ = (int)r[2] / (int)r[3]; hi_ = (int)r[2] % (int)r[3]; }
    c = ((r[3] != 0));  if (c) goto L800ca374;
    L800ca374:;
    r[1] = (u)0 + -1;
    c = ((r[3] != r[1])); r[1] = 0; if (c) goto L800ca38c;
    c = ((r[2] != r[1]));  if (c) goto L800ca38c;
    L800ca38c:;
    r[3] = lo_;
    c = (((int)r[3] >= 0)); r[2] = (int)r[3] >> 3; if (c) goto L800ca3a4;
    r[3] = (u)r[3] + 7;
    r[2] = (int)r[3] >> 3;
    L800ca3a4:;
    r[2] = (u)r[2] << 3;
    *(int *)((u)r[4] + 2308) = r[2];
    r[2] = 0;
    r[3] = 0;
    r[8] = (u)r[3] + (int)R_s15a_dat_800D8BEC;
    r[7] = (u)r[2] + (int)R_s15a_dat_800D9268;
    r[5] = LWL(((u)r[8] + 3), r[5]);
    r[5] = LWR(((u)r[8] + 0), r[5]);
    r[6] = *(signed char *)((u)r[8] + 4);
    SWL(((u)r[7] + 3), r[5]);
    SWR(((u)r[7] + 0), r[5]);
    *(char *)((u)r[7] + 4) = r[6];
    r[5] = *(signed char *)((u)r[8] + 5);
    *(char *)((u)r[7] + 5) = r[5];
    r[2] = (u)r[2] + (int)R_s15a_dat_800D9268;
    r[3] = (u)r[4] + 2292;
    *(int *)((u)r[4] + 2292) = r[2];
    r[2] = (u)0 + 16;
    *(char *)((u)r[3] + 4) = r[2];
    r[2] = (u)0 + 111;
    *(char *)((u)r[3] + 5) = r[2];
    r[2] = (u)0 + 159;
    *(char *)((u)r[3] + 6) = r[2];
    r[2] = (u)0 + 31;
    *(char *)((u)r[3] + 7) = r[2];
    r[2] = (u)0 + 223;
    *(char *)((u)r[3] + 8) = r[2];
    r[2] = (u)0 + 127;
    *(char *)((u)r[3] + 9) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
