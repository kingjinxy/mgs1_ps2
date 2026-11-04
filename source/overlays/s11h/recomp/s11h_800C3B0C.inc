extern char R_s11h_800C38B8[] __asm__("s11h_800C38B8");
extern char R_s11h_800C3984[] __asm__("s11h_800C3984");
int G_s11h_800C3B0C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800C3B0C");
int G_s11h_800C3B0C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s11h_800C38B8);
    r[2] = *(int *)((u)r[16] + 48);
    c = (((int)r[2] < 0));  if (c) goto L800c3b48;
    c = (((int)r[2] <= 0)); r[2] = (u)r[2] + -1; if (c) goto L800c3b40;
    *(int *)((u)r[16] + 48) = r[2]; goto L800c3b48;
    L800c3b40:;
    r[4] = (u)r[16] + (u)0; CALL(R_s11h_800C3984);
    L800c3b48:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
