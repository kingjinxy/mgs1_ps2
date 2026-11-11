extern char R_s19a_800CC36C[] __asm__("s19a_800CC36C");
int G_s19a_800CC984(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CC984");
int G_s19a_800CC984(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s19a_800CC36C);
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800cc9b0;
    r[3] = *(int *)((u)r[16] + 3100);
    r[2] = (u)0 + (u)0;
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[16] + 3100) = r[3];
    L800cc9b0:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
