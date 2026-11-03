int G_s07b_800C46F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800C46F0");
int G_s07b_800C46F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    c = ((r[6] != 0)); r[2] = (u)0 + (u)0; if (c) goto L800c4708;
     goto out;
    L800c4700:;
    r[2] = (u)0 + 1; goto out;
    L800c4708:;
    r[3] = *(short *)((u)r[4] + 22);
    c = (((int)r[3] <= 0)); r[4] = (u)r[4] + 24; if (c) goto L800c4734;
    L800c4718:;
    r[2] = *(unsigned short *)((u)r[4] + 0);
    c = ((r[2] == r[5])); r[4] = (u)r[4] + 2; if (c) goto L800c4700;
    r[3] = (u)r[3] + -1;
    c = (((int)r[3] > 0));  if (c) goto L800c4718;
    L800c4734:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
