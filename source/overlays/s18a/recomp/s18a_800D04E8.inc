extern char R_s18a_dat_800E31B4[] __asm__("s18a_dat_800E31B4");
extern char R_s18a_800CD504[] __asm__("s18a_800CD504");
extern char R_s18a_800CEAEC[] __asm__("s18a_800CEAEC");
extern char R_s18a_800CED80[] __asm__("s18a_800CED80");
extern char R_s18a_800CEE0C[] __asm__("s18a_800CEE0C");
extern char R_s18a_800CEF70[] __asm__("s18a_800CEF70");
extern char R_s18a_800CF184[] __asm__("s18a_800CF184");
int G_s18a_800D04E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D04E8");
int G_s18a_800D04E8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2404);
    r[3] = (u)r[2] + -8;
    r[2] = (u)r[3] < (u)26;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800d0574;
    r[2] = (u)r[2] + (int)R_s18a_dat_800E31B4;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800d052c: goto L800d052c; case 0x800d053c: goto L800d053c; case 0x800d054c: goto L800d054c; case 0x800d055c: goto L800d055c; case 0x800d056c: goto L800d056c; case 0x800d0574: goto L800d0574; default: goto out; }
    L800d052c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CEAEC);
     goto L800d0574;
    L800d053c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CF184);
     goto L800d0574;
    L800d054c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CEF70);
     goto L800d0574;
    L800d055c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CED80);
     goto L800d0574;
    L800d056c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CEE0C);
    L800d0574:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CD504);
    c = ((r[2] == 0));  if (c) goto L800d058c;
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0;
    L800d058c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
