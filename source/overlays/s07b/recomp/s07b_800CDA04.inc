extern char R_s07b_dword_800E5018[] __asm__("s07b_dword_800E5018");
extern char R_s07b_dword_800E5BC8[] __asm__("s07b_dword_800E5BC8");
int G_s07b_800CDA04(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s07b_800CDA04");
int G_s07b_800CDA04(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2016);
    r[2] = *(short *)((u)r[2] + 38);
    r[3] = 0;
    *(int *)((u)r[4] + 2304) = r[2];
    r[2] = 0;
    r[8] = (u)r[3] + (int)R_s07b_dword_800E5018;
    r[7] = (u)r[2] + (int)R_s07b_dword_800E5BC8;
    r[5] = LWL(((u)r[8] + 3), r[5]);
    r[5] = LWR(((u)r[8] + 0), r[5]);
    r[6] = *(signed char *)((u)r[8] + 4);
    SWL(((u)r[7] + 3), r[5]);
    SWR(((u)r[7] + 0), r[5]);
    *(char *)((u)r[7] + 4) = r[6];
    r[5] = *(signed char *)((u)r[8] + 5);
    r[6] = *(signed char *)((u)r[8] + 6);
    *(char *)((u)r[7] + 5) = r[5];
    *(char *)((u)r[7] + 6) = r[6];
    r[2] = (u)r[2] + (int)R_s07b_dword_800E5BC8;
    *(int *)((u)r[4] + 2292) = r[2];
    r[4] = (u)r[4] + 2292;
    r[2] = (u)0 + 16;
    *(char *)((u)r[4] + 4) = r[2];
    r[2] = (u)0 + 111;
    *(char *)((u)r[4] + 5) = r[2];
    r[2] = (u)0 + 159;
    *(char *)((u)r[4] + 6) = r[2];
    r[2] = (u)0 + 31;
    *(char *)((u)r[4] + 7) = r[2];
    r[2] = (u)0 + 223;
    *(char *)((u)r[4] + 8) = r[2];
    r[2] = (u)0 + 127;
    *(char *)((u)r[4] + 9) = r[2];
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
