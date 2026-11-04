extern char R_dword_800AB9D4[] __asm__("dword_800AB9D4");
extern char R_s11b_800C68C8[] __asm__("s11b_800C68C8");
int G_s11b_800C68E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11b_800C68E8");
int G_s11b_800C68E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
     CALL(R_s11b_800C68C8);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800c6918;
    r[4] = *(int *)((u)r[2] + (int)R_dword_800AB9D4);
    r[2] = (u)0 + 8;
    c = ((r[4] == r[2])); r[3] = (u)0 + 16; if (c) goto L800c6920;
    c = ((r[4] == r[3])); r[2] = (u)0 + 1; if (c) goto L800c6924;
    L800c6918:;
    r[2] = (u)0 + -1; goto L800c6924;
    L800c6920:;
    r[2] = (u)0 + (u)0;
    L800c6924:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
