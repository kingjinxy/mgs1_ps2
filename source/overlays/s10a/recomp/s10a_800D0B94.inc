extern char R_GM_FreeObject[] __asm__("GM_FreeObject");
extern char R_GM_FreeTarget[] __asm__("GM_FreeTarget");
int G_s10a_800D0B94(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800D0B94");
int G_s10a_800D0B94(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 28) = r[19];
    r[19] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 20) = r[17];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(int *)((u)r[19] + 36);
    c = (((int)r[2] <= 0)); r[17] = (u)0 + (u)0; if (c) goto L800d0c08;
    r[16] = (u)r[19] + (u)0;
    r[18] = (u)0 + 480;
    L800d0bc8:;
    r[4] = (u)r[19] + (u)r[18];
    r[4] = (u)r[4] + 4; CALL(R_GM_FreeObject);
    r[2] = *(int *)((u)r[16] + 776);
    c = ((r[2] == 0));  if (c) goto L800d0bf0;
    r[4] = *(int *)((u)r[16] + 480);
     CALL(R_GM_FreeTarget);
    L800d0bf0:;
    r[16] = (u)r[16] + 392;
    r[2] = *(int *)((u)r[19] + 36);
    r[17] = (u)r[17] + 1;
    r[2] = (int)r[17] < (int)r[2];
    c = ((r[2] != 0)); r[18] = (u)r[18] + 392; if (c) goto L800d0bc8;
    L800d0c08:;
    r[31] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
