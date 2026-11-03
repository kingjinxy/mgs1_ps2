extern char R_s10a_800CC584[] __asm__("s10a_800CC584");
int G_s10a_800CC698(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CC698");
int G_s10a_800CC698(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(unsigned char *)((u)r[16] + 2936);
    r[2] = (u)0 + 255;
    c = ((r[3] != r[2])); r[2] = (u)0 + 1; if (c) goto L800cc6d0;
    *(short *)((u)r[16] + 2848) = r[2];
    r[2] = (u)0 + 8;
    *(short *)((u)r[16] + 2850) = r[2];
    r[2] = (u)0 + 14;
    *(short *)((u)r[16] + 2852) = r[2]; goto L800cc6ec;
    L800cc6d0:;
    *(short *)((u)r[16] + 2848) = r[2];
    r[2] = (u)0 + 10;
    *(short *)((u)r[16] + 2850) = r[2];
    r[2] = (u)0 + 23;
    r[4] = (u)r[16] + (u)0;
    *(short *)((u)r[16] + 2852) = r[2]; CALL(R_s10a_800CC584);
    L800cc6ec:;
    r[2] = (u)0 + 1;
    *(int *)((u)r[16] + 2856) = 0;
    *(int *)((u)r[16] + 2876) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
