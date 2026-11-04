int G_s10a_800C4CAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800C4CAC");
int G_s10a_800C4CAC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 4);
    r[3] = *(short *)((u)r[2] + 0);
    r[7] = *(int *)((u)r[2] + 16);
    c = (((int)r[3] <= 0)); r[8] = (u)0 + (u)0; if (c) goto L800c4d7c;
    r[9] = (u)r[3] + (u)0;
    r[4] = (u)r[7] + 12;
    L800c4ccc:;
    r[2] = *(unsigned short *)((u)r[4] + 18);
    c = ((r[2] != r[6]));  if (c) goto L800c4d68;
    r[3] = *(short *)((u)r[5] + 0);
    r[2] = *(short *)((u)r[7] + 0);
    r[2] = (int)r[3] < (int)r[2];
    c = ((r[2] != 0));  if (c) goto L800c4d68;
    r[2] = *(short *)((u)r[4] + -4);
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] != 0));  if (c) goto L800c4d68;
    r[3] = *(short *)((u)r[5] + 4);
    r[2] = *(short *)((u)r[4] + -10);
    r[2] = (int)r[3] < (int)r[2];
    c = ((r[2] != 0));  if (c) goto L800c4d68;
    r[2] = *(short *)((u)r[4] + -2);
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] != 0));  if (c) goto L800c4d68;
    r[3] = *(short *)((u)r[5] + 2);
    r[2] = *(short *)((u)r[4] + -8);
    r[2] = (int)r[3] < (int)r[2];
    c = ((r[2] != 0));  if (c) goto L800c4d68;
    r[2] = *(short *)((u)r[4] + 0);
    r[2] = (int)r[2] < (int)r[3];
    c = ((r[2] != 0)); r[4] = (u)r[4] + 32; if (c) goto L800c4d6c;
    r[2] = (u)0 + 1; goto out;
    L800c4d68:;
    r[4] = (u)r[4] + 32;
    L800c4d6c:;
    r[8] = (u)r[8] + 1;
    r[2] = (int)r[8] < (int)r[9];
    c = ((r[2] != 0)); r[7] = (u)r[7] + 32; if (c) goto L800c4ccc;
    L800c4d7c:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
