extern char R_linkvarbuf[] __asm__("linkvarbuf");
int G_s18a_800CFCB4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CFCB4");
int G_s18a_800CFCB4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[3] = *(int *)((u)r[4] + 2476);
    r[2] = (u)0 + 5;
    *(int *)((u)r[4] + 2384) = r[2];
    r[2] = 0;
    *(int *)((u)r[4] + 2388) = r[3];
    r[3] = *(short *)((u)r[2] + ((int)R_linkvarbuf + 2));
    r[2] = (u)0 + 2;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 3; if (c) goto L800cfd0c;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800cfcf0;
    c = ((r[3] == r[2])); r[2] = (u)0 + 15; if (c) goto L800cfd04;
     goto L800cfd1c;
    L800cfcf0:;
    r[2] = (u)0 + 3;
    c = ((r[3] == r[2])); r[2] = (u)0 + 7; if (c) goto L800cfd14;
    r[2] = (u)0 + 15; goto L800cfd1c;
    L800cfd04:;
    r[2] = (u)0 + 10; goto L800cfd1c;
    L800cfd0c:;
    r[2] = (u)0 + 5; goto L800cfd1c;
    L800cfd14:;
    *(int *)((u)r[4] + 2384) = r[2];
    r[2] = (u)0 + 2;
    L800cfd1c:;
    r[3] = *(int *)((u)r[4] + 2408);
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] == 0)); r[2] = (u)r[3] + 1; if (c) goto L800cfd4c;
    r[2] = (u)0 + 2;
    *(int *)((u)r[4] + 2400) = r[2];
    r[2] = (u)0 + 8;
    *(int *)((u)r[4] + 2404) = r[2];
    *(int *)((u)r[4] + 2428) = 0;
    *(int *)((u)r[4] + 2408) = 0; goto out;
    L800cfd4c:;
    *(int *)((u)r[4] + 2408) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
