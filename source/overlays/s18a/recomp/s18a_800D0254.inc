extern char R_s18a_800CE858[] __asm__("s18a_800CE858");
extern char R_s18a_800CE93C[] __asm__("s18a_800CE93C");
int G_s18a_800D0254(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D0254");
int G_s18a_800D0254(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 2404);
    r[2] = (u)0 + 14;
    c = ((r[3] == r[2])); r[2] = (u)0 + 17; if (c) goto L800d0284;
    c = ((r[3] == r[2]));  if (c) goto L800d0294;
     goto L800d029c;
    L800d0284:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CE858);
     goto L800d029c;
    L800d0294:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CE93C);
    L800d029c:;
    r[3] = *(int *)((u)r[16] + 2488);
    r[2] = (u)0 + 3;
    c = ((r[3] == r[2])); r[2] = (u)0 + 36; if (c) goto L800d02b4;
    c = ((r[3] != r[2]));  if (c) goto L800d02cc;
    L800d02b4:;
    r[2] = (u)0 + 4;
    *(int *)((u)r[16] + 2400) = r[2];
    r[2] = (u)0 + 29;
    *(int *)((u)r[16] + 2404) = r[2];
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0;
    L800d02cc:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
