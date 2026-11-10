int G_s18a_800D54E0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D54E0");
int G_s18a_800D54E0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    c = (((int)r[5] >= 0)); r[2] = (u)r[5] - (u)r[4]; if (c) goto L800d54f0;
    r[2] = (u)0 + (u)0; goto out;
    L800d54f0:;
    r[3] = r[2] & 4095;
    r[2] = (int)r[3] < 2048;
    c = ((r[2] == 0)); r[2] = (int)r[3] < 256; if (c) goto L800d5520;
    c = ((r[2] == 0)); r[3] = (int)r[3] < 1281; if (c) goto L800d5510;
    r[2] = (u)0 + 1; goto out;
    L800d5510:;
    c = ((r[3] == 0)); r[2] = (u)0 + 3; if (c) goto L800d5540;
    r[2] = (u)0 + 4; goto out;
    L800d5520:;
    r[2] = (int)r[3] < 3841;
    c = ((r[2] == 0)); r[3] = (int)r[3] < 2816; if (c) goto L800d553c;
    c = ((r[3] != 0)); r[2] = (u)0 + 3; if (c) goto L800d5540;
    r[2] = (u)0 + 2; goto out;
    L800d553c:;
    r[2] = (u)0 + 1;
    L800d5540:;
     goto out;
out:
    RECOMP_RETURN;
}
