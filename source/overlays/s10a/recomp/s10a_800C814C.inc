extern char R_s10a_800C85BC[] __asm__("s10a_800C85BC");
int G_s10a_800C814C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C814C");
int G_s10a_800C814C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 3068);
    r[2] = r[2] & 8191;
    c = ((r[2] != 0)); r[2] = (u)0 + 1; if (c) goto L800c8168;
    r[2] = (u)0 + (u)0; goto out;
    L800c8168:;
    r[3] = 0;
    r[3] = (u)r[3] + (int)R_s10a_800C85BC;
    *(int *)((u)r[4] + 3024) = r[3];
    *(int *)((u)r[4] + 3032) = 0;
    *(short *)((u)r[4] + 112) = 0;
    *(short *)((u)r[4] + 108) = 0; goto out;
out:
    return r[2];
}
