extern char R_s18a_800C7584[] __asm__("s18a_800C7584");
extern char R_s18a_800C7878[] __asm__("s18a_800C7878");
int G_s18a_800C7A18(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C7A18");
int G_s18a_800C7A18(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s18a_800C7584);
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800c7a4c;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800C7878);
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800c7a4c;
    r[2] = (u)0 + (u)0; goto L800c7a58;
    L800c7a4c:;
    r[4] = *(int *)((u)r[16] + 2236);
    r[3] = (u)r[2] + (u)0;
    *(short *)((u)r[4] + 0) = r[3];
    L800c7a58:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
