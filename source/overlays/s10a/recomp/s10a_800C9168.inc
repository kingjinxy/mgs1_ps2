extern char R_s10a_800C8B50[] __asm__("s10a_800C8B50");
int G_s10a_800C9168(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C9168");
int G_s10a_800C9168(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s10a_800C8B50);
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800c9194;
    r[3] = *(int *)((u)r[16] + 3100);
    r[2] = (u)0 + (u)0;
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[16] + 3100) = r[3];
    L800c9194:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
