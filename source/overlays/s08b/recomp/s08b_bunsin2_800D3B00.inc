extern char R_s08b_bunsin2_800CDFA0[] __asm__("s08b_bunsin2_800CDFA0");
extern char R_s08b_bunsin2_800CFC90[] __asm__("s08b_bunsin2_800CFC90");
extern char R_s08b_bunsin2_800D072C[] __asm__("s08b_bunsin2_800D072C");
extern char R_s08b_bunsin2_800D0784[] __asm__("s08b_bunsin2_800D0784");
int G_s08b_bunsin2_800D3B00(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800D3B00");
int G_s08b_bunsin2_800D3B00(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[3] = *(int *)((u)r[16] + 6604);
    r[17] = (u)0 + 8;
    c = ((r[3] == r[17])); r[2] = (int)r[3] < 9; if (c) goto L800d3b50;
    c = ((r[2] == 0)); r[2] = (u)0 + 3; if (c) goto L800d3b3c;
    c = ((r[3] == r[2]));  if (c) goto L800d3ba8;
     goto L800d3bc0;
    L800d3b3c:;
    r[2] = (u)0 + 9;
    c = ((r[3] == r[2]));  if (c) goto L800d3b98;
     goto L800d3bc0;
    L800d3b50:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D072C);
    r[3] = (u)r[2] + (u)0;
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); r[2] = (u)0 + 2; if (c) goto L800d3b78;
    c = ((r[3] == r[2]));  if (c) goto L800d3b84;
     goto L800d3bc0;
    L800d3b78:;
    r[2] = (u)0 + 9;
    *(int *)((u)r[16] + 6604) = r[2]; goto L800d3bbc;
    L800d3b84:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800CDFA0);
    r[2] = (u)0 + 3;
    *(int *)((u)r[16] + 6604) = r[2]; goto L800d3bbc;
    L800d3b98:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D0784);
     goto L800d3bb0;
    L800d3ba8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800CFC90);
    L800d3bb0:;
    c = ((r[2] == 0));  if (c) goto L800d3bc0;
    *(int *)((u)r[16] + 6604) = r[17];
    L800d3bbc:;
    *(int *)((u)r[16] + 6608) = 0;
    L800d3bc0:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
