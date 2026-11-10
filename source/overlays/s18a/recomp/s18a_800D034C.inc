extern char R_s18a_800CEB78[] __asm__("s18a_800CEB78");
extern char R_s18a_800CEE58[] __asm__("s18a_800CEE58");
extern char R_s18a_800CF090[] __asm__("s18a_800CF090");
int G_s18a_800D034C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D034C");
int G_s18a_800D034C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 2404);
    r[2] = (u)0 + 9;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 10; if (c) goto L800d03a8;
    c = ((r[2] == 0)); r[2] = (u)0 + 8; if (c) goto L800d037c;
    c = ((r[3] == r[2]));  if (c) goto L800d0398;
     goto L800d03b0;
    L800d037c:;
    r[2] = (u)0 + 10;
    c = ((r[3] != r[2]));  if (c) goto L800d03b0;
     CALL(R_s18a_800CEB78);
     goto L800d03b0;
    L800d0398:;
     CALL(R_s18a_800CEE58);
     goto L800d03b0;
    L800d03a8:;
     CALL(R_s18a_800CF090);
    L800d03b0:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
