int G_s18a_800D42A8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800D42A8");
int G_s18a_800D42A8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = r[4] & 1;
    c = ((r[2] == 0)); r[2] = r[4] & 2; if (c) goto L800d42bc;
    r[2] = (u)0 + 2; goto out;
    L800d42bc:;
    c = ((r[2] == 0)); r[2] = r[4] & 4; if (c) goto L800d42cc;
    r[2] = (u)0 + 3; goto out;
    L800d42cc:;
    c = ((r[2] == 0)); r[2] = r[4] & 8; if (c) goto L800d42dc;
    r[2] = (u)0 + 4; goto out;
    L800d42dc:;
    c = ((r[2] == 0)); r[2] = r[4] & 16; if (c) goto L800d42ec;
    r[2] = (u)0 + 5; goto out;
    L800d42ec:;
    c = ((r[2] == 0)); r[2] = r[4] & 32; if (c) goto L800d42fc;
    r[2] = (u)0 + 6; goto out;
    L800d42fc:;
    c = ((r[2] == 0)); r[2] = r[4] & 64; if (c) goto L800d430c;
    r[2] = (u)0 + 7; goto out;
    L800d430c:;
    c = ((r[2] == 0)); r[2] = r[4] & 128; if (c) goto L800d431c;
    r[2] = (u)0 + 8; goto out;
    L800d431c:;
    c = ((r[2] == 0)); r[2] = r[4] & 256; if (c) goto L800d432c;
    r[2] = (u)0 + 9; goto out;
    L800d432c:;
    c = ((r[2] == 0)); r[2] = r[4] & 512; if (c) goto L800d433c;
    r[2] = (u)0 + 10; goto out;
    L800d433c:;
    c = ((r[2] == 0)); r[2] = r[4] & 1024; if (c) goto L800d434c;
    r[2] = (u)0 + 11; goto out;
    L800d434c:;
    c = ((r[2] == 0)); r[2] = r[4] & 2048; if (c) goto L800d435c;
    r[2] = (u)0 + 12; goto out;
    L800d435c:;
    c = ((r[2] != 0)); r[2] = (u)0 + 13; if (c) goto L800d4378;
    r[3] = r[4] & 4096;
    c = ((r[3] != 0)); r[2] = (u)0 + 14; if (c) goto L800d4378;
    r[2] = (u)0 + -1; goto out;
    L800d4378:;
     goto out;
out:
    RECOMP_RETURN;
}
