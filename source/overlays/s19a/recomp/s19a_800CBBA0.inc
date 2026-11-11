int G_s19a_800CBBA0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s19a_800CBBA0");
int G_s19a_800CBBA0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = r[4] & 1;
    c = ((r[2] == 0)); r[2] = r[4] & 2; if (c) goto L800cbbb4;
    r[2] = (u)0 + 2; goto out;
    L800cbbb4:;
    c = ((r[2] == 0)); r[2] = r[4] & 4; if (c) goto L800cbbc4;
    r[2] = (u)0 + 3; goto out;
    L800cbbc4:;
    c = ((r[2] == 0)); r[2] = r[4] & 8; if (c) goto L800cbbd4;
    r[2] = (u)0 + 4; goto out;
    L800cbbd4:;
    c = ((r[2] == 0)); r[2] = r[4] & 16; if (c) goto L800cbbe4;
    r[2] = (u)0 + 5; goto out;
    L800cbbe4:;
    c = ((r[2] == 0)); r[2] = r[4] & 32; if (c) goto L800cbbf4;
    r[2] = (u)0 + 6; goto out;
    L800cbbf4:;
    c = ((r[2] == 0)); r[2] = r[4] & 64; if (c) goto L800cbc04;
    r[2] = (u)0 + 7; goto out;
    L800cbc04:;
    c = ((r[2] == 0)); r[2] = r[4] & 128; if (c) goto L800cbc14;
    r[2] = (u)0 + 8; goto out;
    L800cbc14:;
    c = ((r[2] == 0)); r[2] = r[4] & 256; if (c) goto L800cbc24;
    r[2] = (u)0 + 9; goto out;
    L800cbc24:;
    c = ((r[2] == 0)); r[2] = r[4] & 512; if (c) goto L800cbc34;
    r[2] = (u)0 + 10; goto out;
    L800cbc34:;
    c = ((r[2] == 0)); r[2] = r[4] & 1024; if (c) goto L800cbc44;
    r[2] = (u)0 + 11; goto out;
    L800cbc44:;
    c = ((r[2] == 0)); r[2] = r[4] & 2048; if (c) goto L800cbc54;
    r[2] = (u)0 + 12; goto out;
    L800cbc54:;
    c = ((r[2] != 0)); r[2] = (u)0 + 13; if (c) goto L800cbc70;
    r[3] = r[4] & 4096;
    c = ((r[3] != 0)); r[2] = (u)0 + 14; if (c) goto L800cbc70;
    r[2] = (u)0 + -1; goto out;
    L800cbc70:;
     goto out;
out:
    RECOMP_RETURN;
}
