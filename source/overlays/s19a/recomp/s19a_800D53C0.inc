extern char R_s19a_dat_800E0CE8[] __asm__("s19a_dat_800E0CE8");
extern char R_s19a_800D3BE4[] __asm__("s19a_800D3BE4");
extern char R_s19a_800D3CCC[] __asm__("s19a_800D3CCC");
extern char R_s19a_800D3CE4[] __asm__("s19a_800D3CE4");
extern char R_s19a_800D3DD8[] __asm__("s19a_800D3DD8");
extern char R_s19a_800D479C[] __asm__("s19a_800D479C");
extern char R_s19a_800D480C[] __asm__("s19a_800D480C");
int G_s19a_800D53C0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800D53C0");
int G_s19a_800D53C0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(short *)((u)r[16] + 2852);
    r[2] = (u)0 + 4;
    c = ((r[3] == r[2])); r[2] = (u)0 + 5; if (c) goto L800d53f0;
    c = ((r[3] == r[2]));  if (c) goto L800d540c;
     goto L800d5458;
    L800d53f0:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D479C);
    c = ((r[2] == 0)); r[2] = (u)0 + 5; if (c) goto L800d5458;
    *(short *)((u)r[16] + 2852) = r[2];
    *(int *)((u)r[16] + 2856) = 0; goto L800d5458;
    L800d540c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D480C);
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d5458;
    r[2] = *(int *)((u)r[2] + (int)R_s19a_dat_800E0CE8);
    c = ((r[2] != 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800d5450;
    r[2] = *(int *)((u)r[16] + 2868);
    r[2] = (u)r[2] + -1;
    *(int *)((u)r[16] + 2868) = r[2]; CALL(R_s19a_800D3BE4);
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D3CCC);
     goto L800d5458;
    L800d5450:;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D3DD8);
    L800d5458:;
    r[2] = *(int *)((u)r[16] + 2964);
    r[2] = (int)r[2] < 2;
    c = ((r[2] != 0));  if (c) goto L800d5474;
    r[4] = (u)r[16] + (u)0; CALL(R_s19a_800D3CE4);
    L800d5474:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
