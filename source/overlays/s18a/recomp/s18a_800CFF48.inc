extern char R_s18a_800CD4AC[] __asm__("s18a_800CD4AC");
extern char R_s18a_800CDD28[] __asm__("s18a_800CDD28");
extern char R_s18a_800CDD68[] __asm__("s18a_800CDD68");
int G_s18a_800CFF48(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CFF48");
int G_s18a_800CFF48(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(int *)((u)r[16] + 2404);
    r[2] = (u)0 + 2;
    c = ((r[3] == r[2])); r[2] = (u)0 + 3; if (c) goto L800cff78;
    c = ((r[3] == r[2]));  if (c) goto L800cff88;
     goto L800cff90;
    L800cff78:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CDD28);
     goto L800cff90;
    L800cff88:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CDD68);
    L800cff90:;
    r[4] = (u)r[16] + (u)0; CALL(R_s18a_800CD4AC);
    c = ((r[2] == 0));  if (c) goto L800cffa8;
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0;
    L800cffa8:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
