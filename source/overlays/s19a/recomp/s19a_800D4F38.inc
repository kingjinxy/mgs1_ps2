extern char R_s19a_800D3FC0[] __asm__("s19a_800D3FC0");
extern char R_s19a_800D4060[] __asm__("s19a_800D4060");
int G_s19a_800D4F38(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D4F38");
int G_s19a_800D4F38(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    r[3] = *(short *)((u)r[16] + 2854);
    r[17] = (u)0 + 2;
    c = ((r[3] == r[17])); r[2] = (u)0 + 3; if (c) goto L800d4f6c;
    c = ((r[3] == r[2]));  if (c) goto L800d4f84;
     goto L800d4f9c;
    L800d4f6c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D3FC0);
    c = ((r[2] == 0)); r[2] = (u)0 + 3; if (c) goto L800d4f9c;
    *(short *)((u)r[16] + 2854) = r[2]; goto L800d4f98;
    L800d4f84:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D4060);
    c = ((r[2] == 0));  if (c) goto L800d4f9c;
    *(short *)((u)r[16] + 2854) = r[17];
    L800d4f98:;
    *(int *)((u)r[16] + 2856) = 0;
    L800d4f9c:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
