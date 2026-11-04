extern char R_s15a_800D29AC[] __asm__("s15a_800D29AC");
extern char R_s15a_800D2F78[] __asm__("s15a_800D2F78");
int G_s15a_800D30A8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800D30A8");
int G_s15a_800D30A8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s15a_800D29AC);
    r[3] = *(int *)((u)r[16] + 16464);
    r[2] = (u)0 + 1;
    c = ((r[3] != r[2]));  if (c) goto L800d30d4;
    r[4] = (u)r[16] + (u)0; CALL(R_s15a_800D2F78);
    L800d30d4:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
