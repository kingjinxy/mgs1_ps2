extern char R_GM_NoisePower[] __asm__("GM_NoisePower");
extern char R_s19a_800D3ACC[] __asm__("s19a_800D3ACC");
extern char R_s19a_800D3BE4[] __asm__("s19a_800D3BE4");
extern char R_s19a_800D3CCC[] __asm__("s19a_800D3CCC");
extern char R_s19a_800D3CE4[] __asm__("s19a_800D3CE4");
extern char R_s19a_800D6620[] __asm__("s19a_800D6620");
int G_s19a_800D555C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D555C");
int G_s19a_800D555C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[16] + 2868);
    r[4] = (u)r[16] + (u)0;
    r[2] = (u)r[2] + -1;
    *(int *)((u)r[16] + 2868) = r[2]; CALL(R_s19a_800D3BE4);
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D3CCC);
    r[2] = *(int *)((u)r[16] + 2964);
    r[2] = (int)r[2] < 2;
    c = ((r[2] == 0)); r[3] = 0x120000; if (c) goto L800d55a4;
    r[2] = *(int *)((u)r[16] + 2972);
    r[2] = r[2] & r[3];
    c = ((r[2] == 0));  if (c) goto L800d55b4;
    L800d55a4:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D3CE4);
     goto L800d5610;
    L800d55b4:;
    r[2] = *(unsigned char *)((u)r[16] + 2974);
    r[2] = r[2] & 1;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d5610;
    r[3] = *(int *)((u)r[2] + (int)R_GM_NoisePower);
    r[2] = (u)0 + 100;
    c = ((r[3] == r[2])); r[2] = (u)0 + 255; if (c) goto L800d5604;
    c = ((r[3] != r[2]));  if (c) goto L800d5604;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D3ACC);
     CALL(R_s19a_800D6620);
    r[2] = (u)0 + 7;
    *(short *)((u)r[16] + 2850) = r[2];
    r[2] = (u)0 + 12;
    *(short *)((u)r[16] + 2852) = r[2]; goto L800d560c;
    L800d5604:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D3CE4);
    L800d560c:;
    *(int *)((u)r[16] + 2856) = 0;
    L800d5610:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
