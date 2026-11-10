extern char R_s18a_800CD544[] __asm__("s18a_800CD544");
extern char R_s18a_800CDFCC[] __asm__("s18a_800CDFCC");
extern char R_s18a_800CE0F8[] __asm__("s18a_800CE0F8");
extern char R_s18a_800CE530[] __asm__("s18a_800CE530");
int G_s18a_800D0028(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D0028");
int G_s18a_800D0028(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 2404);
    r[2] = (u)0 + 3;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 4; if (c) goto L800d0074;
    c = ((r[2] == 0)); r[2] = (u)0 + 2; if (c) goto L800d0060;
    c = ((r[3] == r[2]));  if (c) goto L800d0084;
     goto L800d009c;
    L800d0060:;
    r[2] = (u)0 + 16;
    c = ((r[3] == r[2]));  if (c) goto L800d0094;
     goto L800d009c;
    L800d0074:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CDFCC);
     goto L800d009c;
    L800d0084:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CE0F8);
     goto L800d009c;
    L800d0094:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CE530);
    L800d009c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CD544);
    c = ((r[2] == 0));  if (c) goto L800d00b4;
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0;
    L800d00b4:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
