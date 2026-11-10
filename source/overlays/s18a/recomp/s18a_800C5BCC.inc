int G_s18a_800C5BCC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C5BCC");
int G_s18a_800C5BCC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = *(short *)((u)r[4] + 4);
    r[3] = *(short *)((u)r[4] + 0);
    r[2] = (int)r[5] < 4751;
    c = ((r[2] != 0)); r[2] = (int)r[5] < -1250; if (c) goto L800c5be8;
    r[2] = (u)0 + (u)0; goto out;
    L800c5be8:;
    c = ((r[2] == 0)); r[2] = (int)r[3] < -750; if (c) goto L800c5bf8;
    r[2] = (u)0 + 4; goto out;
    L800c5bf8:;
    c = ((r[2] == 0)); r[2] = (int)r[3] < 1250; if (c) goto L800c5c08;
    r[2] = (u)0 + 3; goto out;
    L800c5c08:;
    c = ((r[2] == 0)); r[2] = (int)r[3] < 2500; if (c) goto L800c5c18;
    r[2] = (u)0 + 2; goto out;
    L800c5c18:;
    c = ((r[2] == 0)); r[2] = (int)r[3] < 3250; if (c) goto L800c5c28;
    r[2] = (u)0 + 1; goto out;
    L800c5c28:;
    c = ((r[2] != 0)); r[2] = (u)0 + 7; if (c) goto L800c5c44;
    r[3] = (int)r[3] < 5500;
    c = ((r[3] != 0)); r[2] = (u)0 + 6; if (c) goto L800c5c44;
    r[2] = (u)0 + 5; goto out;
    L800c5c44:;
     goto out;
out:
    RECOMP_RETURN;
}
