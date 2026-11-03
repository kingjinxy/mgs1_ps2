extern char R_s10a_800C3B40[] __asm__("s10a_800C3B40");
extern char R_s10a_800C3C0C[] __asm__("s10a_800C3C0C");
int G_s10a_800C3D94(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C3D94");
int G_s10a_800C3D94(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    *(int *)((u)r[29] + 20) = r[31];
    r[16] = (u)r[4] + (u)0; CALL(R_s10a_800C3B40);
    r[2] = *(int *)((u)r[16] + 48);
    c = (((int)r[2] < 0));  if (c) goto L800c3dd0;
    c = (((int)r[2] <= 0)); r[2] = (u)r[2] + -1; if (c) goto L800c3dc8;
    *(int *)((u)r[16] + 48) = r[2]; goto L800c3dd0;
    L800c3dc8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800C3C0C);
    L800c3dd0:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
