int G_s10a_800C3AB4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800C3AB4");
int G_s10a_800C3AB4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[4] = *(int *)((u)r[4] + 52);
    r[3] = *(unsigned char *)((u)r[4] + 0);
    r[2] = (u)0 + 80;
    c = ((r[3] != r[2])); r[6] = (u)r[2] + (u)0; if (c) goto L800c3af8;
    L800c3acc:;
    r[2] = *(unsigned char *)((u)r[4] + 1);
    c = ((r[2] == r[5])); r[2] = (u)r[4] + 3; if (c) goto L800c3b00;
    r[2] = *(unsigned char *)((u)r[4] + 2);
    r[2] = (u)r[4] + (u)r[2];
    r[3] = *(unsigned char *)((u)r[2] + 2);
    c = ((r[3] == r[6])); r[4] = (u)r[2] + 2; if (c) goto L800c3acc;
    L800c3af8:;
    r[2] = (u)0 + (u)0; goto out;
    L800c3b00:;
     goto out;
out:
    RECOMP_RETURN;
}
