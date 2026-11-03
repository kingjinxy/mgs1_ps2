extern char R_GV_RandU[] __asm__("GV_RandU");
extern char R_s10a_800D0EF8[] __asm__("s10a_800D0EF8");
extern char R_s10a_800D0FD8[] __asm__("s10a_800D0FD8");
extern char R_s10a_800D161C[] __asm__("s10a_800D161C");
int G_s10a_800D19C0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D19C0");
int G_s10a_800D19C0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 836);
    r[2] = (u)0 + 6;
    c = ((r[3] == r[2])); r[2] = (u)0 + 7; if (c) goto L800d19f0;
    c = ((r[3] == r[2]));  if (c) goto L800d19f8;
     goto L800d1a50;
    L800d19f0:;
    *(int *)((u)r[16] + 836) = r[2]; goto L800d1a50;
    L800d19f8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800D161C);
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800d1a50;
    r[3] = *(int *)((u)r[16] + 864);
    c = ((r[3] != r[2])); *(int *)((u)r[16] + 832) = 0; if (c) goto L800d1a30;
    r[4] = (u)0 + 2; CALL(R_GV_RandU);
    c = ((r[2] != 0)); r[2] = (u)0 + 2; if (c) goto L800d1a34;
    r[2] = (u)0 + 3; goto L800d1a34;
    L800d1a30:;
    r[2] = (u)0 + 4;
    L800d1a34:;
    *(int *)((u)r[16] + 836) = r[2];
    *(int *)((u)r[16] + 844) = 0;
    r[4] = (u)r[16] + (u)0;
    r[5] = (u)0 + (u)0;
    r[6] = (u)0 + 255;
    r[7] = (u)r[5] + (u)0; CALL(R_s10a_800D0EF8);
    L800d1a50:;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800D0FD8);
    c = ((r[2] == 0)); r[4] = (u)r[16] + (u)0; if (c) goto L800d1a84;
    r[5] = (u)0 + 255;
    r[6] = (u)0 + (u)0;
    r[7] = (u)r[6] + (u)0;
    r[2] = (u)0 + 1;
    *(int *)((u)r[4] + 832) = r[2];
    r[2] = (u)0 + 5;
    *(int *)((u)r[4] + 836) = r[2];
    *(int *)((u)r[4] + 844) = 0; CALL(R_s10a_800D0EF8);
    L800d1a84:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
