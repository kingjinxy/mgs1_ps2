extern char R_s19a_800D3A4C[] __asm__("s19a_800D3A4C");
extern char R_s19a_800D3CCC[] __asm__("s19a_800D3CCC");
extern char R_s19a_800D3CE4[] __asm__("s19a_800D3CE4");
extern char R_s19a_800D40E8[] __asm__("s19a_800D40E8");
int G_s19a_800D5030(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D5030");
int G_s19a_800D5030(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(short *)((u)r[16] + 2852);
    r[2] = (u)0 + 3;
    c = ((r[3] != r[2]));  if (c) goto L800d5084;
     CALL(R_s19a_800D40E8);
    c = ((r[2] == 0));  if (c) goto L800d5084;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D3A4C);
    r[2] = *(int *)((u)r[16] + 2536);
    r[4] = (u)r[16] + (u)0;
    r[2] = (u)r[2] + -1;
    *(int *)((u)r[16] + 2868) = r[2]; CALL(R_s19a_800D3CCC);
    r[2] = (u)0 + 1;
    *(int *)((u)r[16] + 2876) = r[2];
    L800d5084:;
    r[2] = *(int *)((u)r[16] + 2964);
    r[2] = (int)r[2] < 2;
    c = ((r[2] != 0));  if (c) goto L800d50a0;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D3CE4);
    L800d50a0:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
