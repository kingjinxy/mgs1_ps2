extern char R_s10a_800CC448[] __asm__("s10a_800CC448");
extern char R_s10a_800CC668[] __asm__("s10a_800CC668");
extern char R_s10a_800CC680[] __asm__("s10a_800CC680");
extern char R_s10a_800CC95C[] __asm__("s10a_800CC95C");
int G_s10a_800CD288(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CD288");
int G_s10a_800CD288(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(short *)((u)r[16] + 2852);
    r[2] = (u)0 + 3;
    c = ((r[3] != r[2]));  if (c) goto L800cd2dc;
     CALL(R_s10a_800CC95C);
    c = ((r[2] == 0));  if (c) goto L800cd2dc;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CC448);
    r[2] = *(int *)((u)r[16] + 2536);
    r[4] = (u)r[16] + (u)0;
    r[2] = (u)r[2] + -1;
    *(int *)((u)r[16] + 2868) = r[2]; CALL(R_s10a_800CC668);
    r[2] = (u)0 + 1;
    *(int *)((u)r[16] + 2876) = r[2];
    L800cd2dc:;
    r[2] = *(int *)((u)r[16] + 2964);
    r[2] = (int)r[2] < 2;
    c = ((r[2] != 0));  if (c) goto L800cd2f8;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CC680);
    L800cd2f8:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
