extern char R_d18a_dword_800DA628[] __asm__("d18a_dword_800DA628");
int G_d18a_snake18_800CC3C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("d18a_snake18_800CC3C8");
int G_d18a_snake18_800CC3C8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)r[4] < (u)8;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800cc408;
    r[2] = (u)r[2] + (int)R_d18a_dword_800DA628;
    r[3] = (u)r[4] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800cc3f0: goto L800cc3f0; case 0x800cc3f8: goto L800cc3f8; case 0x800cc400: goto L800cc400; default: goto out; }
    L800cc3f0:;
    r[2] = (u)0 + (u)0; goto out;
    L800cc3f8:;
    r[2] = (u)0 + 1; goto out;
    L800cc400:;
    r[2] = (u)0 + 2; goto out;
    L800cc408:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
