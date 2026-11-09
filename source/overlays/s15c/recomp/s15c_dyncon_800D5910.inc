int G_s15c_dyncon_800D5910(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15c_dyncon_800D5910");
int G_s15c_dyncon_800D5910(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = (u)r[6] << 1;
    r[2] = (u)r[2] + (u)r[6];
    r[5] = (u)r[5] + (u)r[2];
    r[5] = (u)r[5] << 2;
    r[2] = (u)r[5] << 2;
    r[3] = (u)r[4] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 15548);
    r[2] = (int)r[2] < 6;
    c = ((r[2] != 0)); r[2] = (u)r[5] + 1; if (c) goto L800d5948;
    r[2] = (u)0 + 5;
    *(int *)((u)r[3] + 15548) = r[2];
    r[2] = (u)r[5] + 1;
    L800d5948:;
    r[2] = (u)r[2] << 2;
    r[3] = (u)r[4] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 15548);
    r[2] = (int)r[2] < 6;
    c = ((r[2] != 0)); r[2] = (u)r[5] + 2; if (c) goto L800d5970;
    r[2] = (u)0 + 5;
    *(int *)((u)r[3] + 15548) = r[2];
    r[2] = (u)r[5] + 2;
    L800d5970:;
    r[2] = (u)r[2] << 2;
    r[3] = (u)r[4] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 15548);
    r[2] = (int)r[2] < 6;
    c = ((r[2] != 0)); r[2] = (u)r[5] + 3; if (c) goto L800d5998;
    r[2] = (u)0 + 5;
    *(int *)((u)r[3] + 15548) = r[2];
    r[2] = (u)r[5] + 3;
    L800d5998:;
    r[2] = (u)r[2] << 2;
    r[4] = (u)r[4] + (u)r[2];
    r[2] = *(int *)((u)r[4] + 15548);
    r[2] = (int)r[2] < 6;
    c = ((r[2] != 0)); r[2] = (u)0 + 5; if (c) goto L800d59b8;
    *(int *)((u)r[4] + 15548) = r[2];
    L800d59b8:;
     goto out;
out:
    RECOMP_RETURN;
}
