extern char R_s10a_800C7DFC[] __asm__("s10a_800C7DFC");
int G_s10a_800C7E78(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C7E78");
int G_s10a_800C7E78(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(int *)((u)r[4] + 52);
    r[2] = *(int *)((u)r[2] + 0);
    r[16] = r[2] & 3;
    c = ((r[16] == 0));  if (c) goto L800c7ebc;
     CALL(R_s10a_800C7DFC);
    r[3] = (u)r[2] + (u)0;
    c = ((r[3] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800c7ec0;
    r[2] = (u)r[16] + (u)0; goto L800c7ec0;
    L800c7ebc:;
    r[2] = (u)0 + (u)0;
    L800c7ec0:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
