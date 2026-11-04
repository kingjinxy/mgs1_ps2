extern char R_dword_800AB9D4[] __asm__("dword_800AB9D4");
extern char R_s15a_800C57A0[] __asm__("s15a_800C57A0");
int G_s15a_800C57C0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800C57C0");
int G_s15a_800C57C0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
     CALL(R_s15a_800C57A0);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800c57f0;
    r[4] = *(int *)((u)r[2] + (int)R_dword_800AB9D4);
    r[2] = (u)0 + 8;
    c = ((r[4] == r[2])); r[3] = (u)0 + 16; if (c) goto L800c57f8;
    c = ((r[4] == r[3])); r[2] = (u)0 + 1; if (c) goto L800c57fc;
    L800c57f0:;
    r[2] = (u)0 + -1; goto L800c57fc;
    L800c57f8:;
    r[2] = (u)0 + (u)0;
    L800c57fc:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
