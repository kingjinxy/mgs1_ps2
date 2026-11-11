extern char R_s19a_800D3A84[] __asm__("s19a_800D3A84");
extern char R_s19a_800D3FC0[] __asm__("s19a_800D3FC0");
extern char R_s19a_800D48F0[] __asm__("s19a_800D48F0");
int G_s19a_800D4FB4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D4FB4");
int G_s19a_800D4FB4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(short *)((u)r[16] + 2854);
    c = ((r[3] == 0)); r[2] = (u)0 + 2; if (c) goto L800d5004;
    c = ((r[3] != r[2]));  if (c) goto L800d501c;
     CALL(R_s19a_800D3FC0);
    c = ((r[2] == 0));  if (c) goto L800d501c;
    r[4] = (u)r[16] + (u)0;
    *(short *)((u)r[16] + 2854) = 0;
    *(int *)((u)r[4] + 2856) = 0; CALL(R_s19a_800D3A84);
     goto L800d501c;
    L800d5004:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D48F0);
    c = ((r[2] == 0)); r[2] = (u)0 + 2; if (c) goto L800d501c;
    *(short *)((u)r[16] + 2854) = r[2];
    *(int *)((u)r[16] + 2856) = 0;
    L800d501c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 + (u)0;
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
