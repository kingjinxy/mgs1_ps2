extern char R_GM_ConfigObjectAction[] __asm__("GM_ConfigObjectAction");
int G_s10a_800DD39C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800DD39C");
int G_s10a_800DD39C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[4] + 1672);
    c = ((r[2] == r[5])); r[2] = (u)0 + 1; if (c) goto L800dd3d0;
    *(int *)((u)r[4] + 1672) = r[5];
    r[4] = (u)r[4] + 160;
    r[6] = (u)0 + (u)0;
    r[7] = (u)0 + 4; CALL(R_GM_ConfigObjectAction);
     goto L800dd3e4;
    L800dd3d0:;
    r[3] = *(short *)((u)r[4] + 186);
    c = ((r[3] != r[2]));  if (c) goto L800dd3e4;
    *(int *)((u)r[4] + 1680) = r[6];
    L800dd3e4:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
