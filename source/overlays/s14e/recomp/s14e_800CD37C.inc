extern char R_s14e_dword_800C34D8[] __asm__("s14e_dword_800C34D8");
extern char R_s14e_800CCC8C[] __asm__("s14e_800CCC8C");
int G_s14e_800CD37C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CD37C");
int G_s14e_800CD37C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 2872);
    r[2] = 0x10000;
    r[4] = r[3] | r[2];
    r[3] = *(int *)((u)r[16] + 2856);
    r[2] = (u)0 + 30;
    c = ((r[3] == r[2])); *(int *)((u)r[16] + 2872) = r[4]; if (c) goto L800cd3c0;
    r[2] = *(short *)((u)r[16] + 182);
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800cd400;
     goto L800cd430;
    L800cd3c0:;
    r[2] = 0x100000;
    r[2] = r[4] | r[2];
    r[3] = 0;
    *(int *)((u)r[16] + 2872) = r[2];
    r[2] = *(signed char *)((u)r[16] + 2932);
    r[3] = (u)r[3] + (int)R_s14e_dword_800C34D8;
    r[2] = (u)r[2] << 3;
    r[2] = (u)r[2] + (u)r[3];
    r[6] = LWL(((u)r[2] + 3), r[6]);
    r[6] = LWR(((u)r[2] + 0), r[6]);
    r[7] = LWL(((u)r[2] + 7), r[7]);
    r[7] = LWR(((u)r[2] + 4), r[7]);
    SWL(((u)r[16] + 3079), r[6]);
    SWR(((u)r[16] + 3076), r[6]);
    SWL(((u)r[16] + 3083), r[7]);
    SWR(((u)r[16] + 3080), r[7]);
    L800cd400:;
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_s14e_dword_800C34D8;
    r[2] = *(signed char *)((u)r[16] + 2932);
    r[4] = (u)r[16] + 32;
    r[2] = (u)r[2] << 3;
    r[5] = (u)r[2] + (u)r[5]; CALL(R_s14e_800CCC8C);
    r[3] = *(int *)((u)r[16] + 2856);
    *(short *)((u)r[16] + 2888) = r[2];
    r[2] = (u)0 + (u)0;
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[16] + 2856) = r[3];
    L800cd430:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
