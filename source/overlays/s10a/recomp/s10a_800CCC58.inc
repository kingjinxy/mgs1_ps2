extern char R_s10a_800CCF6C[] __asm__("s10a_800CCF6C");
int G_s10a_800CCC58(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CCC58");
int G_s10a_800CCC58(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[5] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[5] + 2884);
    c = ((r[2] == 0)); r[4] = (u)r[5] + (u)0; if (c) goto L800ccc94;
    r[2] = *(int *)((u)r[5] + 2872);
    r[4] = *(int *)((u)r[5] + 2880);
    r[3] = *(int *)((u)r[5] + 2884);
    r[2] = r[2] | r[4];
    r[3] = (u)r[3] + -1;
    *(int *)((u)r[5] + 2872) = r[2];
    *(int *)((u)r[5] + 2884) = r[3];
    r[4] = (u)r[5] + (u)0;
    L800ccc94:;
    r[5] = (u)0 + 350; CALL(R_s10a_800CCF6C);
    r[31] = *(int *)((u)r[29] + 16);
    r[2] = (u)0 < (u)r[2];
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
