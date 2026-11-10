extern char R_dword_800AB9D4[] __asm__("dword_800AB9D4");
int G_s17a_800C764C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800C764C");
int G_s17a_800C764C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[4] = *(int *)((u)r[2] + (int)R_dword_800AB9D4);
    r[2] = (u)0 + 12;
    c = ((r[4] == r[2])); r[3] = (u)0 + 24; if (c) goto L800c7670;
    c = ((r[4] == r[3])); r[2] = (u)0 + 1; if (c) goto L800c7674;
    r[2] = (u)0 + -1; goto out;
    L800c7670:;
    r[2] = (u)0 + (u)0;
    L800c7674:;
     goto out;
out:
    RECOMP_RETURN;
}
