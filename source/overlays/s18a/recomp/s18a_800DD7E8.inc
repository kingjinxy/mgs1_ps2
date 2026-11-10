extern char R_s18a_800D5B64[] __asm__("s18a_800D5B64");
extern char R_s18a_800DB6B4[] __asm__("s18a_800DB6B4");
extern char R_s18a_800DB8DC[] __asm__("s18a_800DB8DC");
int G_s18a_800DD7E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DD7E8");
int G_s18a_800DD7E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2212);
    r[2] = *(unsigned short *)((u)r[2] + 4);
    r[2] = r[2] & 128;
    c = ((r[2] == 0)); r[3] = (u)0 + 1; if (c) goto L800dd830;
    r[2] = *(int *)((u)r[16] + 2144);
    r[2] = *(short *)((u)r[2] + 0);
    c = (((int)r[2] <= 0));  if (c) goto L800dd830;
    r[3] = (u)0 + 3;
    L800dd830:;
    r[2] = *(int *)((u)r[16] + 2212);
    *(int *)((u)r[16] + 2140) = r[3];
    r[2] = *(unsigned short *)((u)r[2] + 0);
    r[2] = r[2] & 61440;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800dd88c;
    r[4] = (u)r[16] + (u)0;
    r[3] = (u)r[16] + 2244;
    *(short *)((u)r[16] + 2244) = r[2];
    r[2] = (u)0 + 512;
    *(short *)((u)r[3] + 6) = r[2];
    *(short *)((u)r[3] + 8) = r[2];
    r[2] = (u)0 + 32;
    *(short *)((u)r[3] + 10) = r[2];
    *(short *)((u)r[3] + 12) = r[2];
    *(short *)((u)r[3] + 14) = r[2];
    *(short *)((u)r[3] + 16) = r[2]; CALL(R_s18a_800DB6B4);
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800DB8DC);
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800D5B64);
    L800dd88c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
