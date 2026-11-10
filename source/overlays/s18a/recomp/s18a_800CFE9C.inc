extern char R_s18a_800CDAF8[] __asm__("s18a_800CDAF8");
extern char R_s18a_800CDBB8[] __asm__("s18a_800CDBB8");
extern char R_s18a_800CDC40[] __asm__("s18a_800CDC40");
int G_s18a_800CFE9C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CFE9C");
int G_s18a_800CFE9C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 2404);
    r[2] = (u)0 + 2;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 3; if (c) goto L800cfef0;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800cfecc;
    c = ((r[3] == r[2]));  if (c) goto L800cfee0;
     goto L800cff08;
    L800cfecc:;
    r[2] = (u)0 + 3;
    c = ((r[3] == r[2]));  if (c) goto L800cff00;
     goto L800cff08;
    L800cfee0:;
     CALL(R_s18a_800CDAF8);
     goto L800cff08;
    L800cfef0:;
     CALL(R_s18a_800CDBB8);
     goto L800cff08;
    L800cff00:;
     CALL(R_s18a_800CDC40);
    L800cff08:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
