extern char R_GM_ConfigControlInterp[] __asm__("GM_ConfigControlInterp");
extern char R_s10a_800D1748[] __asm__("s10a_800D1748");
extern char R_s10a_800D188C[] __asm__("s10a_800D188C");
extern char R_s10a_800D19C0[] __asm__("s10a_800D19C0");
extern char R_s10a_800D1A94[] __asm__("s10a_800D1A94");
int G_s10a_800D1DE4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D1DE4");
int G_s10a_800D1DE4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 832);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 2; if (c) goto L800d1e50;
    c = ((r[2] == 0));  if (c) goto L800d1e1c;
    c = ((r[3] == 0)); r[4] = (u)r[16] + 32; if (c) goto L800d1e38;
     goto L800d1e98;
    L800d1e1c:;
    r[2] = (u)0 + 2;
    c = ((r[3] == r[2])); r[2] = (u)0 + 3; if (c) goto L800d1e6c;
    c = ((r[3] == r[2])); r[4] = (u)r[16] + 32; if (c) goto L800d1e88;
     goto L800d1e98;
    L800d1e38:;
    r[5] = (u)0 + 4; CALL(R_GM_ConfigControlInterp);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800D1748);
     goto L800d1e98;
    L800d1e50:;
    r[4] = (u)r[16] + 32;
    r[5] = (u)0 + (u)0; CALL(R_GM_ConfigControlInterp);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800D188C);
     goto L800d1e98;
    L800d1e6c:;
    r[4] = (u)r[16] + 32;
    r[5] = (u)0 + 4; CALL(R_GM_ConfigControlInterp);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800D19C0);
     goto L800d1e98;
    L800d1e88:;
    r[5] = (u)0 + 4; CALL(R_GM_ConfigControlInterp);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800D1A94);
    L800d1e98:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
