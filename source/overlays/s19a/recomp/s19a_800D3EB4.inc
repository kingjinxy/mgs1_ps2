extern char R_GM_NoisePower[] __asm__("GM_NoisePower");
extern char R_s19a_800D3ACC[] __asm__("s19a_800D3ACC");
extern char R_s19a_800D6620[] __asm__("s19a_800D6620");
int G_s19a_800D3EB4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D3EB4");
int G_s19a_800D3EB4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_GM_NoisePower);
    r[2] = (u)0 + 100;
    c = ((r[3] == r[2])); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800d3f40;
    r[2] = (int)r[3] < 101;
    c = ((r[2] == 0)); r[2] = (u)0 + 5; if (c) goto L800d3ef0;
    c = ((r[3] == r[2])); r[2] = (u)0 + 1; if (c) goto L800d3f0c;
     goto L800d3f40;
    L800d3ef0:;
    r[2] = (u)0 + 200;
    c = ((r[3] == r[2])); r[2] = (u)0 + 255; if (c) goto L800d3f1c;
    c = ((r[3] == r[2]));  if (c) goto L800d3f1c;
     goto L800d3f40;
    L800d3f0c:;
    *(short *)((u)r[16] + 2850) = r[2];
    r[2] = (u)0 + 7;
    *(short *)((u)r[16] + 2852) = r[2]; goto L800d3f5c;
    L800d3f1c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D3ACC);
     CALL(R_s19a_800D6620);
    r[2] = (u)0 + 7;
    *(short *)((u)r[16] + 2850) = r[2];
    r[2] = (u)0 + 12;
    *(short *)((u)r[16] + 2852) = r[2]; goto L800d3f5c;
    L800d3f40:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D3ACC);
    r[2] = (u)0 + 1;
    *(short *)((u)r[16] + 2850) = r[2];
    r[2] = (u)0 + 5;
    *(short *)((u)r[16] + 2852) = r[2];
    *(char *)((u)r[16] + 2968) = 0;
    L800d3f5c:;
    *(int *)((u)r[16] + 2856) = 0;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
