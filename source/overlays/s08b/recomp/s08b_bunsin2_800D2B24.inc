extern char R_s08b_dword_800C3448[] __asm__("s08b_dword_800C3448");
extern char R_s08b_bunsin2_800CE2E8[] __asm__("s08b_bunsin2_800CE2E8");
extern char R_s08b_bunsin2_800CFCF8[] __asm__("s08b_bunsin2_800CFCF8");
extern char R_s08b_bunsin2_800CFDE0[] __asm__("s08b_bunsin2_800CFDE0");
extern char R_s08b_bunsin2_800D06A0[] __asm__("s08b_bunsin2_800D06A0");
int G_s08b_bunsin2_800D2B24(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s08b_bunsin2_800D2B24");
int G_s08b_bunsin2_800D2B24(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = r[2] & 1;
    c = ((r[2] == 0)); r[2] = (u)0 + 9; if (c) goto L800d2b3c;
    *(int *)((u)r[16] + 6600) = r[2];
    r[2] = (u)0 + 28; goto L800d2bdc;
    L800d2b3c:;
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s08b_dword_800C3448);
    r[2] = (int)r[2] < 2;
    c = ((r[2] == 0));  if (c) goto L800d2b5c;
    *(int *)((u)r[16] + 6604) = r[17]; goto L800d2be0;
    L800d2b5c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800CE2E8);
    r[2] = (u)0 + 8;
    *(int *)((u)r[16] + 6600) = r[2];
    r[2] = (u)0 + 5; goto L800d2bdc;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D06A0);
    c = ((r[2] == 0)); r[2] = (u)0 + 24; if (c) goto L800d2be8;
    *(int *)((u)r[16] + 6600) = 0; goto L800d2bdc;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800CFDE0);
    c = ((r[2] == 0)); r[2] = (u)0 + 8; if (c) goto L800d2be8;
    *(int *)((u)r[16] + 6600) = r[2];
    r[2] = (u)0 + 38; goto L800d2bdc;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800CFCF8);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d2be8;
    r[2] = *(int *)((u)r[2] + (int)R_s08b_dword_800C3448);
    c = ((r[2] != 0)); r[2] = (u)0 + 8; if (c) goto L800d2bd4;
    *(int *)((u)r[16] + 6600) = r[2];
    r[2] = (u)0 + 38; goto L800d2bdc;
    L800d2bd4:;
    r[2] = (u)0 + 36;
    *(int *)((u)r[16] + 6600) = 0;
    L800d2bdc:;
    *(int *)((u)r[16] + 6604) = r[2];
    L800d2be0:;
    *(int *)((u)r[16] + 6612) = 0;
    *(int *)((u)r[16] + 6608) = 0;
    L800d2be8:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
