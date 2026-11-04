extern char R_s10a_dat_800E40BC[] __asm__("s10a_dat_800E40BC");
extern char R_s10a_dat_800E4B10[] __asm__("s10a_dat_800E4B10");
int G_s10a_800D6A34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800D6A34");
int G_s10a_800D6A34(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2624);
    c = (((int)r[2] >= 0));  if (c) goto L800d6a48;
    r[2] = (u)r[2] + 7;
    L800d6a48:;
    r[2] = (int)r[2] >> 3;
    r[2] = (u)r[2] << 3;
    *(int *)((u)r[4] + 2628) = r[2];
    r[2] = 0;
    r[3] = 0;
    r[8] = (u)r[3] + (int)R_s10a_dat_800E40BC;
    r[7] = (u)r[2] + (int)R_s10a_dat_800E4B10;
    r[5] = LWL(((u)r[8] + 3), r[5]);
    r[5] = LWR(((u)r[8] + 0), r[5]);
    r[6] = *(signed char *)((u)r[8] + 4);
    SWL(((u)r[7] + 3), r[5]);
    SWR(((u)r[7] + 0), r[5]);
    *(char *)((u)r[7] + 4) = r[6];
    r[2] = (u)r[2] + (int)R_s10a_dat_800E4B10;
    r[3] = (u)r[4] + 2612;
    *(int *)((u)r[4] + 2612) = r[2];
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
