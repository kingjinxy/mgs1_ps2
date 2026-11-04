extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_MENU_DrawBar2[] __asm__("MENU_DrawBar2");
int G_s10a_800DC70C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800DC70C");
int G_s10a_800DC70C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 32) = r[18];
    r[18] = (u)r[4] + (u)0;
    r[2] = 0;
    r[6] = (u)r[2] + (int)R_linkvarbuf;
    *(int *)((u)r[29] + 36) = r[31];
    *(int *)((u)r[29] + 28) = r[17];
    *(int *)((u)r[29] + 24) = r[16];
    r[3] = *(short *)((u)r[6] + 24);
    r[2] = *(int *)((u)r[18] + 1956);
    mul = (long long)(int)r[3] * (int)r[2]; hi_ = mul >> 32; lo_ = mul;
    r[2] = lo_;
    c = (((int)r[2] >= 0));  if (c) goto L800dc74c;
    r[2] = (u)r[2] + 255;
    L800dc74c:;
    r[2] = (int)r[2] >> 8;
    c = (((int)r[2] >= 0)); *(int *)((u)r[18] + 1952) = r[2]; if (c) goto L800dc75c;
    r[2] = (u)r[2] + 7;
    L800dc75c:;
    r[2] = (int)r[2] >> 3;
    r[16] = (u)r[2] << 3;
    c = (((int)r[16] >= 0));  if (c) goto L800dc770;
    r[16] = (u)0 + (u)0;
    L800dc770:;
    r[17] = *(int *)((u)r[18] + 1948);
    r[2] = (int)r[17] < (int)r[16];
    c = ((r[2] == 0)); r[2] = (u)r[18] + 1936; if (c) goto L800dc788;
    r[17] = (u)r[16] + (u)0;
    L800dc788:;
    r[4] = (u)0 + 40;
    r[5] = (u)r[17] + (u)0;
    *(int *)((u)r[29] + 16) = r[2];
    r[7] = *(short *)((u)r[6] + 24);
    r[6] = (u)r[16] + (u)0; CALL(R_MENU_DrawBar2);
    r[2] = (int)r[16] < (int)r[17];
    c = ((r[2] == 0));  if (c) goto L800dc7bc;
    r[2] = *(int *)((u)r[18] + 1948);
    r[2] = (u)r[2] + -8;
    *(int *)((u)r[18] + 1948) = r[2];
    L800dc7bc:;
    r[31] = *(int *)((u)r[29] + 36);
    r[18] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
