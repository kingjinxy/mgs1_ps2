extern char R_s19a_800C7D10[] __asm__("s19a_800C7D10");
int G_s19a_800C7DAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C7DAC");
int G_s19a_800C7DAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[4] = (u)0 + 3; CALL(R_s19a_800C7D10);
    c = ((r[2] != 0));  if (c) goto L800c7dd4;
    r[2] = (u)0 + 130; goto L800c7de4;
    L800c7dd4:;
    c = (((int)r[2] < 0)); r[2] = (int)r[2] < 3; if (c) goto L800c7de8;
    c = ((r[2] == 0)); r[2] = (u)0 + 129; if (c) goto L800c7de8;
    L800c7de4:;
    *(int *)((u)r[16] + 0) = r[2];
    L800c7de8:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
