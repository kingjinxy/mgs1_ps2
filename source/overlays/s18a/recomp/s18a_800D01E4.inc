extern char R_s18a_800CD4AC[] __asm__("s18a_800CD4AC");
extern char R_s18a_800CE770[] __asm__("s18a_800CE770");
extern char R_s18a_800CFCB4[] __asm__("s18a_800CFCB4");
int G_s18a_800D01E4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D01E4");
int G_s18a_800D01E4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 2404);
    r[2] = (u)0 + 14;
    c = ((r[3] == r[2])); r[2] = (u)0 + 15; if (c) goto L800d0214;
    c = ((r[3] == r[2]));  if (c) goto L800d0224;
     goto L800d022c;
    L800d0214:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CE770);
     goto L800d022c;
    L800d0224:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CFCB4);
    L800d022c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CD4AC);
    c = ((r[2] == 0));  if (c) goto L800d0244;
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0;
    L800d0244:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
