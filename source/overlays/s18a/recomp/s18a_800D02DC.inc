extern char R_s18a_800CD544[] __asm__("s18a_800CD544");
extern char R_s18a_800CE97C[] __asm__("s18a_800CE97C");
extern char R_s18a_800CEA0C[] __asm__("s18a_800CEA0C");
int G_s18a_800D02DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D02DC");
int G_s18a_800D02DC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 2404);
    r[2] = (u)0 + 14;
    c = ((r[3] == r[2])); r[2] = (u)0 + 17; if (c) goto L800d030c;
    c = ((r[3] == r[2]));  if (c) goto L800d031c;
     goto L800d0324;
    L800d030c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CEA0C);
     goto L800d0324;
    L800d031c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CE97C);
    L800d0324:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CD544);
    c = ((r[2] == 0));  if (c) goto L800d033c;
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0;
    L800d033c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
