int G_s10a_800C84E4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C84E4");
int G_s10a_800C84E4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = r[4] & 1;
    c = ((r[2] == 0)); r[2] = r[4] & 2; if (c) goto L800c84f8;
    r[2] = (u)0 + 2; goto out;
    L800c84f8:;
    c = ((r[2] == 0)); r[2] = r[4] & 4; if (c) goto L800c8508;
    r[2] = (u)0 + 3; goto out;
    L800c8508:;
    c = ((r[2] == 0)); r[2] = r[4] & 8; if (c) goto L800c8518;
    r[2] = (u)0 + 4; goto out;
    L800c8518:;
    c = ((r[2] == 0)); r[2] = r[4] & 16; if (c) goto L800c8528;
    r[2] = (u)0 + 5; goto out;
    L800c8528:;
    c = ((r[2] == 0)); r[2] = r[4] & 32; if (c) goto L800c8538;
    r[2] = (u)0 + 6; goto out;
    L800c8538:;
    c = ((r[2] == 0)); r[2] = r[4] & 64; if (c) goto L800c8548;
    r[2] = (u)0 + 7; goto out;
    L800c8548:;
    c = ((r[2] == 0)); r[2] = r[4] & 128; if (c) goto L800c8558;
    r[2] = (u)0 + 8; goto out;
    L800c8558:;
    c = ((r[2] == 0)); r[2] = r[4] & 256; if (c) goto L800c8568;
    r[2] = (u)0 + 9; goto out;
    L800c8568:;
    c = ((r[2] == 0)); r[2] = r[4] & 512; if (c) goto L800c8578;
    r[2] = (u)0 + 10; goto out;
    L800c8578:;
    c = ((r[2] == 0)); r[2] = r[4] & 1024; if (c) goto L800c8588;
    r[2] = (u)0 + 11; goto out;
    L800c8588:;
    c = ((r[2] == 0)); r[2] = r[4] & 2048; if (c) goto L800c8598;
    r[2] = (u)0 + 12; goto out;
    L800c8598:;
    c = ((r[2] != 0)); r[2] = (u)0 + 13; if (c) goto L800c85b4;
    r[3] = r[4] & 4096;
    c = ((r[3] != 0)); r[2] = (u)0 + 14; if (c) goto L800c85b4;
    r[2] = (u)0 + -1; goto out;
    L800c85b4:;
     goto out;
out:
    RECOMP_RETURN;
}
