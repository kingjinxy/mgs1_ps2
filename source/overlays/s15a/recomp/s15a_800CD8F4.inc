extern char R_s15a_800CAAA8[] __asm__("s15a_800CAAA8");
extern char R_s15a_800CAEC0[] __asm__("s15a_800CAEC0");
extern char R_s15a_800CCC80[] __asm__("s15a_800CCC80");
extern char R_s15a_800CD108[] __asm__("s15a_800CD108");
extern char R_s15a_800CD5EC[] __asm__("s15a_800CD5EC");
extern char R_s15a_800CD7C8[] __asm__("s15a_800CD7C8");
int G_s15a_800CD8F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CD8F4");
int G_s15a_800CD8F4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 1940);
    r[5] = (u)0 + (u)0;
    *(int *)((u)r[16] + 1944) = r[2]; CALL(R_s15a_800CAEC0);
    r[3] = *(int *)((u)r[16] + 1668);
    *(int *)((u)r[16] + 1940) = r[2];
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 2; if (c) goto L800cd96c;
    c = ((r[2] == 0)); r[2] = (u)0 + 3; if (c) goto L800cd940;
    c = ((r[3] == 0));  if (c) goto L800cd950;
     goto L800cd98c;
    L800cd940:;
    c = ((r[3] == r[2]));  if (c) goto L800cd980;
     goto L800cd98c;
    L800cd950:;
    *(int *)((u)r[16] + 2288) = 0;
    r[4] = (u)r[16] + (u)0; CALL(R_s15a_800CD108);
    r[4] = (u)r[16] + (u)0; CALL(R_s15a_800CAAA8);
     goto L800cd98c;
    L800cd96c:;
    *(int *)((u)r[16] + 2288) = r[3];
    r[4] = (u)r[16] + (u)0; CALL(R_s15a_800CD5EC);
     goto L800cd98c;
    L800cd980:;
    *(int *)((u)r[16] + 2288) = 0;
    r[4] = (u)r[16] + (u)0; CALL(R_s15a_800CD7C8);
    L800cd98c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s15a_800CCC80);
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
