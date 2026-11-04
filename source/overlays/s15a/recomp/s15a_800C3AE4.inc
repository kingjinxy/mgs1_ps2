extern char R_s15a_800C3890[] __asm__("s15a_800C3890");
extern char R_s15a_800C395C[] __asm__("s15a_800C395C");
int G_s15a_800C3AE4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800C3AE4");
int G_s15a_800C3AE4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s15a_800C3890);
    r[2] = *(int *)((u)r[16] + 48);
    c = (((int)r[2] < 0));  if (c) goto L800c3b20;
    c = (((int)r[2] <= 0)); r[2] = (u)r[2] + -1; if (c) goto L800c3b18;
    *(int *)((u)r[16] + 48) = r[2]; goto L800c3b20;
    L800c3b18:;
    r[4] = (u)r[16] + (u)0; CALL(R_s15a_800C395C);
    L800c3b20:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
