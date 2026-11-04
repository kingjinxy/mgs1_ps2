int G_s11h_800CC000(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s11h_800CC000");
int G_s11h_800CC000(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = r[4] & 32767;
    c = ((r[2] != 0)); r[3] = (u)r[4] + (u)0; if (c) goto L800cc014;
    r[2] = r[3] & 65535; goto out;
    L800cc014:;
    r[3] = r[4] & 31;
    r[2] = r[4] & 992;
    r[2] = (u)r[2] >> 5;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = r[4] & 31744;
    r[2] = (u)r[2] >> 10;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = (u)r[3] << 2;
    r[2] = (u)r[2] + (u)r[3];
    r[3] = (u)r[2] << 4;
    r[2] = (u)r[2] + (u)r[3];
    r[4] = r[4] & 32768;
    r[2] = (u)r[2] >> 9;
    r[3] = (u)r[2] << 5;
    r[3] = r[2] | r[3];
    r[2] = (u)r[2] << 10;
    r[3] = r[3] | r[2];
    r[3] = r[3] | r[4];
    c = ((r[3] != 0));  if (c) goto L800cc068;
    r[3] = 0 | 32768;
    L800cc068:;
    r[2] = r[3] & 65535; goto out;
out:
    RECOMP_RETURN;
}
