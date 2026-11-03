int G_s10a_800E354C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800E354C");
int G_s10a_800E354C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(unsigned char *)((u)r[4] + 3);
    r[3] = *(unsigned char *)((u)r[5] + 3);
    r[2] = (u)r[2] + (u)r[3];
    r[3] = (u)r[2] + 1;
    r[2] = (int)r[3] < 17;
    c = ((r[2] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800e3578;
    *(char *)((u)r[4] + 3) = r[3];
    *(int *)((u)r[5] + 0) = 0; goto L800e357c;
    L800e3578:;
    r[2] = (u)0 + -1;
    L800e357c:;
     goto out;
out:
    RECOMP_RETURN;
}
