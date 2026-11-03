extern char R_s08b_dword_800C3448[] __asm__("s08b_dword_800C3448");
extern char R_s08b_bunsin2_800D0330[] __asm__("s08b_bunsin2_800D0330");
extern char R_s08b_bunsin2_800D0410[] __asm__("s08b_bunsin2_800D0410");
extern char R_s08b_bunsin2_800D06A0[] __asm__("s08b_bunsin2_800D06A0");
int G_s08b_bunsin2_800D29DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800D29DC");
int G_s08b_bunsin2_800D29DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[31];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 20) = r[17];
    r[3] = *(int *)((u)r[16] + 6604);
    r[18] = (u)0 + 28;
    c = ((r[3] == r[18])); r[2] = (int)r[3] < 29; if (c) goto L800d2a70;
    c = ((r[2] == 0)); r[2] = (u)0 + 23; if (c) goto L800d2a1c;
    c = ((r[3] == r[2])); r[17] = (u)0 + 1; if (c) goto L800d2a30;
     goto L800d2a9c;
    L800d2a1c:;
    r[2] = (u)0 + 29;
    c = ((r[3] == r[2])); r[2] = (u)0 + 1; if (c) goto L800d2a54;
     goto L800d2a9c;
    L800d2a30:;
    *(int *)((u)r[16] + 6664) = r[17];
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D06A0);
    c = ((r[2] == 0));  if (c) goto L800d2a4c;
    *(int *)((u)r[16] + 6604) = r[18]; goto L800d2a94;
    L800d2a4c:;
    *(int *)((u)r[16] + 6664) = r[17]; goto L800d2a9c;
    L800d2a54:;
    *(int *)((u)r[16] + 6664) = r[2];
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D0330);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d2a9c;
    *(int *)((u)r[2] + (int)R_s08b_dword_800C3448) = 0; goto L800d2a94;
    L800d2a70:;
    r[4] = (u)r[16] + (u)0; CALL(R_s08b_bunsin2_800D0410);
    c = ((r[2] == 0)); r[2] = (u)0 + 8; if (c) goto L800d2a9c;
    *(int *)((u)r[16] + 6600) = r[2];
    r[2] = (u)0 + 38;
    *(int *)((u)r[16] + 6604) = r[2];
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s08b_dword_800C3448) = 0;
    L800d2a94:;
    *(int *)((u)r[16] + 6612) = 0;
    *(int *)((u)r[16] + 6608) = 0;
    L800d2a9c:;
    r[31] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
