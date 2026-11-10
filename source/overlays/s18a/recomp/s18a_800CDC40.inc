int G_s18a_800CDC40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CDC40");
int G_s18a_800CDC40(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 2476);
    r[5] = *(int *)((u)r[4] + 2480);
    r[3] = (u)0 + 5;
    *(int *)((u)r[4] + 2384) = r[3];
    *(int *)((u)r[4] + 2388) = r[2];
    r[2] = (int)r[5] < 8001;
    c = ((r[2] != 0)); r[2] = (int)r[5] < 3001; if (c) goto L800cdc7c;
    r[2] = (u)0 + 3;
    *(int *)((u)r[4] + 2400) = r[2];
    r[2] = (u)0 + 13;
    L800cdc6c:;
    *(int *)((u)r[4] + 2404) = r[2];
    *(int *)((u)r[4] + 2428) = 0;
    *(int *)((u)r[4] + 2408) = 0; goto out;
    L800cdc7c:;
    c = ((r[2] != 0)); r[2] = (u)0 + 2; if (c) goto L800cdc90;
    *(int *)((u)r[4] + 2400) = r[2];
    r[2] = (u)0 + 8; goto L800cdc6c;
    L800cdc90:;
    r[2] = (int)r[5] < 1500;
    c = ((r[2] == 0)); r[2] = (u)0 + 2; if (c) goto L800cdca8;
    *(int *)((u)r[4] + 2400) = r[2];
    r[2] = (u)0 + 9; goto L800cdc6c;
    L800cdca8:;
    r[3] = *(int *)((u)r[4] + 2408);
    r[2] = (int)r[3] < 6;
    c = ((r[2] != 0)); r[2] = (u)0 + 2; if (c) goto L800cdcc8;
    *(int *)((u)r[4] + 2400) = r[2];
    r[2] = (u)0 + 10; goto L800cdc6c;
    L800cdcc8:;
    r[2] = (u)r[3] + 1;
    *(int *)((u)r[4] + 2408) = r[2]; goto out;
out:
    RECOMP_RETURN;
}
