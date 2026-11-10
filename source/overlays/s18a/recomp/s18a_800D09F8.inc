extern char R_s18a_800CFDDC[] __asm__("s18a_800CFDDC");
extern char R_s18a_800CFE9C[] __asm__("s18a_800CFE9C");
extern char R_s18a_800D01B4[] __asm__("s18a_800D01B4");
extern char R_s18a_800D034C[] __asm__("s18a_800D034C");
int G_s18a_800D09F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D09F8");
int G_s18a_800D09F8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 2400);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 2; if (c) goto L800d0a54;
    c = ((r[2] == 0));  if (c) goto L800d0a28;
    c = ((r[3] == 0));  if (c) goto L800d0a44;
     goto L800d0a7c;
    L800d0a28:;
    r[2] = (u)0 + 2;
    c = ((r[3] == r[2])); r[2] = (u)0 + 3; if (c) goto L800d0a64;
    c = ((r[3] == r[2]));  if (c) goto L800d0a74;
     goto L800d0a7c;
    L800d0a44:;
     CALL(R_s18a_800CFDDC);
     goto L800d0a7c;
    L800d0a54:;
     CALL(R_s18a_800CFE9C);
     goto L800d0a7c;
    L800d0a64:;
     CALL(R_s18a_800D034C);
     goto L800d0a7c;
    L800d0a74:;
     CALL(R_s18a_800D01B4);
    L800d0a7c:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
