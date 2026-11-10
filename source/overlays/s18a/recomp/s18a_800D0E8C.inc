extern char R_s18a_dat_800C34A0[] __asm__("s18a_dat_800C34A0");
extern char R_s18a_dat_800C34A4[] __asm__("s18a_dat_800C34A4");
extern char R_s18a_dat_800C34A8[] __asm__("s18a_dat_800C34A8");
extern char R_s18a_800E24B8[] __asm__("s18a_800E24B8");
int G_s18a_800D0E8C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D0E8C");
int G_s18a_800D0E8C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[2] = 0;
    r[2] = *(int *)((u)r[2] + (int)R_s18a_dat_800C34A4);
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 20) = r[17];
    c = ((r[2] == 0)); *(int *)((u)r[29] + 16) = r[16]; if (c) goto L800d0edc;
    r[17] = 0;
    r[2] = *(int *)((u)r[17] + (int)R_s18a_dat_800C34A0);
    c = ((r[2] == 0)); r[16] = 0; if (c) goto L800d0edc;
    r[4] = *(int *)((u)r[16] + (int)R_s18a_dat_800C34A8);
    c = ((r[4] == 0));  if (c) goto L800d0edc;
     CALL(R_s18a_800E24B8);
    *(int *)((u)r[16] + (int)R_s18a_dat_800C34A8) = 0;
    *(int *)((u)r[17] + (int)R_s18a_dat_800C34A0) = 0;
    L800d0edc:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
    r[3] = 0;
    r[2] = *(int *)((u)r[3] + (int)R_s18a_dat_800C34A4);
    c = ((r[2] == 0)); r[2] = (u)r[2] + -1; if (c) goto L800d0f1c;
    c = ((r[2] != 0)); *(int *)((u)r[3] + (int)R_s18a_dat_800C34A4) = r[2]; if (c) goto L800d0f1c;
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s18a_dat_800C34A8) = 0;
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_s18a_dat_800C34A0) = 0;
    L800d0f1c:;
     goto out;
out:
    RECOMP_RETURN;
}
