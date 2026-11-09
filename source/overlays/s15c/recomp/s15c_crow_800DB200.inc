extern char R_s15c_dword_800E345C[] __asm__("s15c_dword_800E345C");
int G_s15c_crow_800DB200(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15c_crow_800DB200");
int G_s15c_crow_800DB200(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[2] = *(int *)((u)r[4] + 1692);
    r[3] = *(int *)((u)r[4] + 1856);
    r[5] = (u)0 + 1;
    *(int *)((u)r[4] + 2088) = 0;
    r[2] = (u)r[2] + 1;
    c = ((r[3] == r[5])); *(int *)((u)r[4] + 1692) = r[2]; if (c) goto L800db298;
    r[2] = (int)r[3] < 2;
    c = ((r[2] == 0)); r[6] = (u)0 + 2; if (c) goto L800db238;
    c = ((r[3] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800db250;
     goto L800db2dc;
    L800db238:;
    c = ((r[3] == r[6])); r[2] = (u)0 + 3; if (c) goto L800db2b0;
    c = ((r[3] == r[2])); r[2] = (u)0 + (u)0; if (c) goto L800db2c8;
     goto L800db2dc;
    L800db250:;
    r[2] = *(short *)((u)r[4] + 1848);
    c = ((r[2] != r[5])); r[2] = 0; if (c) goto L800db2d8;
    r[3] = *(int *)((u)r[2] + (int)R_s15c_dword_800E345C);
    c = ((r[3] == 0)); r[2] = (u)r[2] + (int)R_s15c_dword_800E345C; if (c) goto L800db2d8;
    r[2] = *(int *)((u)r[2] + 8);
    c = ((r[2] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800db2dc;
    r[2] = (u)0 + 3;
    r[3] = (u)r[2] + (u)0;
    *(int *)((u)r[4] + 1904) = r[3];
    *(int *)((u)r[4] + 1700) = 0;
    *(int *)((u)r[4] + 1692) = 0; goto out;
    L800db298:;
    r[3] = *(short *)((u)r[4] + 1848);
    r[2] = (u)0 + 2;
    c = ((r[3] != r[2])); r[2] = (u)0 + (u)0; if (c) goto L800db2dc;
    r[2] = (u)0 + 1; goto out;
    L800db2b0:;
    r[2] = *(short *)((u)r[4] + 1850);
    c = ((r[2] != r[5])); r[2] = (u)0 + (u)0; if (c) goto L800db2dc;
    r[2] = (u)0 + 2; goto out;
    L800db2c8:;
    r[3] = *(short *)((u)r[4] + 1850);
    c = ((r[3] == r[6])); r[2] = (u)0 + 1; if (c) goto L800db2dc;
    L800db2d8:;
    r[2] = (u)0 + (u)0;
    L800db2dc:;
     goto out;
out:
    RECOMP_RETURN;
}
