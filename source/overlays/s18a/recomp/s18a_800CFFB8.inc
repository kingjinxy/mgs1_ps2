extern char R_s18a_800CD504[] __asm__("s18a_800CD504");
extern char R_s18a_800CDDE0[] __asm__("s18a_800CDDE0");
extern char R_s18a_800CDEFC[] __asm__("s18a_800CDEFC");
int G_s18a_800CFFB8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CFFB8");
int G_s18a_800CFFB8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 2404);
    r[2] = (u)0 + 3;
    c = ((r[3] == r[2])); r[2] = (u)0 + 7; if (c) goto L800cffe8;
    c = ((r[3] == r[2]));  if (c) goto L800cfff8;
     goto L800d0000;
    L800cffe8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CDDE0);
     goto L800d0000;
    L800cfff8:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CDEFC);
    L800d0000:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CD504);
    c = ((r[2] == 0));  if (c) goto L800d0018;
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0;
    L800d0018:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
