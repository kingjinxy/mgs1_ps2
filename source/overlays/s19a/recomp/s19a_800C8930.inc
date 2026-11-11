int G_s19a_800C8930(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800C8930");
int G_s19a_800C8930(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(unsigned char *)((u)r[4] + 3124);
    c = ((r[2] == 0)); r[3] = (u)0 + (u)0; if (c) goto L800c8970;
    r[5] = *(short *)((u)r[5] + 22);
    r[6] = (u)r[2] + (u)0;
    r[2] = (u)r[4] + (u)r[3];
    L800c894c:;
    r[2] = *(unsigned char *)((u)r[2] + 3125);
    c = ((r[5] != r[2])); r[3] = (u)r[3] + 1; if (c) goto L800c8964;
    r[2] = (u)0 + 1; goto out;
    L800c8964:;
    r[2] = (int)r[3] < (int)r[6];
    c = ((r[2] != 0)); r[2] = (u)r[4] + (u)r[3]; if (c) goto L800c894c;
    L800c8970:;
    r[2] = (u)0 + (u)0; goto out;
out:
    RECOMP_RETURN;
}
