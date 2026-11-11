extern char R_s19a_800D4124[] __asm__("s19a_800D4124");
int G_s19a_800D48F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D48F0");
int G_s19a_800D48F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2856);
    r[2] = r[2] & 31;
    c = ((r[2] != 0)); r[2] = (u)0 + -1; if (c) goto L800d4920;
    *(int *)((u)r[16] + 3080) = r[2];
    *(int *)((u)r[16] + 3052) = r[2]; CALL(R_s19a_800D4124);
    L800d4920:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D4124);
    *(short *)((u)r[16] + 2888) = r[2];
    r[2] = (u)r[2] << 16;
    c = (((int)r[2] < 0)); r[2] = (u)0 + (u)0; if (c) goto L800d494c;
    r[3] = *(int *)((u)r[16] + 2856);
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[16] + 2856) = r[3]; goto L800d4950;
    L800d494c:;
    r[2] = (u)0 + 1;
    L800d4950:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
