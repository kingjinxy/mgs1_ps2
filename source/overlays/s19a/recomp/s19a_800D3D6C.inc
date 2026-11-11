extern char R_s19a_800D3B48[] __asm__("s19a_800D3B48");
extern char R_s19a_800D3B88[] __asm__("s19a_800D3B88");
int G_s19a_800D3D6C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D3D6C");
int G_s19a_800D3D6C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(unsigned char *)((u)r[16] + 2936);
    r[2] = (u)0 + 255;
    c = ((r[3] != r[2]));  if (c) goto L800d3d9c;
     CALL(R_s19a_800D3B48);
    r[2] = (u)0 + 1; goto L800d3da8;
    L800d3d9c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D3B88);
    r[2] = (u)0 + 1;
    L800d3da8:;
    *(short *)((u)r[16] + 2848) = r[2];
    r[2] = (u)0 + 10;
    *(short *)((u)r[16] + 2850) = r[2];
    r[2] = (u)0 + 23;
    *(short *)((u)r[16] + 2852) = r[2];
    r[2] = (u)0 + 1;
    *(int *)((u)r[16] + 2856) = 0;
    *(int *)((u)r[16] + 2876) = r[2];
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
