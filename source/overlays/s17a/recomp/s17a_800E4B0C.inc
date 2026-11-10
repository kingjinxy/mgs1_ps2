int G_s17a_800E4B0C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800E4B0C");
int G_s17a_800E4B0C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[5] - (u)r[4];
    r[5] = r[5] & 4095;
    r[2] = (int)r[5] < 2048;
    c = ((r[2] != 0));  if (c) goto L800e4b24;
    r[5] = (u)r[5] + -4096;
    L800e4b24:;
    r[5] = (u)r[4] + (u)r[5];
    r[2] = (int)r[4] < (int)r[5];
    c = ((r[2] == 0)); r[2] = (u)r[5] + (u)0; if (c) goto L800e4b4c;
    r[4] = (u)r[4] + (u)r[6];
    r[2] = (int)r[4] < (int)r[5];
    c = ((r[2] != 0)); r[2] = (u)r[4] + (u)0; if (c) goto L800e4b60;
    r[2] = (u)r[5] + (u)0; goto out;
    L800e4b4c:;
    r[4] = (u)r[4] - (u)r[6];
    r[3] = (int)r[2] < (int)r[4];
    c = ((r[3] == 0));  if (c) goto L800e4b60;
    r[2] = (u)r[4] + (u)0;
    L800e4b60:;
     goto out;
out:
    RECOMP_RETURN;
}
