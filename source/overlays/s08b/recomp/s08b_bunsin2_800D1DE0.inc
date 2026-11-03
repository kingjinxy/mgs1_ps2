extern char R_s08b_dword_800E39E8[] __asm__("s08b_dword_800E39E8");
extern char R_s08b_bunsin2_800CF54C[] __asm__("s08b_bunsin2_800CF54C");
extern char R_s08b_bunsin2_800CF958[] __asm__("s08b_bunsin2_800CF958");
extern char R_s08b_bunsin2_800CFCF8[] __asm__("s08b_bunsin2_800CFCF8");
extern char R_s08b_bunsin2_800D0004[] __asm__("s08b_bunsin2_800D0004");
extern char R_s08b_bunsin2_800D0D80[] __asm__("s08b_bunsin2_800D0D80");
extern char R_s08b_bunsin2_800D1588[] __asm__("s08b_bunsin2_800D1588");
int G_s08b_bunsin2_800D1DE0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800D1DE0");
int G_s08b_bunsin2_800D1DE0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 6604);
    r[2] = (u)r[3] < (u)37;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d1eb8;
    r[2] = (u)r[2] + (int)R_s08b_dword_800E39E8;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) {  default: goto out; }
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800CF958);
    c = ((r[2] == 0)); r[2] = (u)0 + 7; if (c) goto L800d1eb8;
    *(int *)((u)r[16] + 6600) = r[2]; goto L800d1ea8;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D0D80);
     goto L800d1eb8;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D1588);
    c = ((r[2] == 0)); r[2] = (u)0 + 24; if (c) goto L800d1e60;
    *(int *)((u)r[16] + 6604) = r[2];
    *(int *)((u)r[16] + 6608) = 0;
    L800d1e60:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800CF54C);
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800d1eb8;
    *(int *)((u)r[16] + 6608) = 0;
    *(int *)((u)r[16] + 6612) = 0;
    *(int *)((u)r[16] + 6584) = r[2]; goto L800d1eb8;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D0004);
    c = ((r[2] == 0)); r[2] = (u)0 + 24; if (c) goto L800d1eb8;
    *(int *)((u)r[16] + 6604) = r[2]; goto L800d1eb4;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800CFCF8);
    c = ((r[2] == 0));  if (c) goto L800d1eb8;
    L800d1ea8:;
    r[2] = (u)0 + 24;
    *(int *)((u)r[16] + 6604) = r[2];
    *(int *)((u)r[16] + 6612) = 0;
    L800d1eb4:;
    *(int *)((u)r[16] + 6608) = 0;
    L800d1eb8:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
