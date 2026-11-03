extern char R_GM_SeSet[] __asm__("GM_SeSet");
int G_s10a_800CB044(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CB044");
int G_s10a_800CB044(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(signed char *)((u)r[4] + 2932);
    r[7] = *(short *)((u)r[4] + 2272);
    r[6] = *(short *)((u)r[4] + 402);
    c = (((int)r[3] >= 0)); r[2] = (u)r[3] + (u)0; if (c) goto L800cb064;
    r[2] = (u)r[3] + 3;
    L800cb064:;
    r[2] = (int)r[2] >> 2;
    r[2] = (u)r[2] << 2;
    r[2] = (u)r[3] - (u)r[2];
    r[2] = (u)r[2] << 24;
    r[2] = (int)r[2] >> 23;
    r[3] = (u)r[2] + 160;
    r[5] = (u)r[2] + 161;
    r[2] = (u)0 + 1;
    c = ((r[7] != r[2])); r[2] = (u)0 + 2; if (c) goto L800cb0a0;
    r[2] = (u)0 + 22;
    c = ((r[6] != r[2])); r[2] = (u)0 + 11; if (c) goto L800cb0b8;
    r[4] = (u)r[4] + 32; goto L800cb0c4;
    L800cb0a0:;
    c = ((r[7] != r[2])); r[2] = (u)0 + 16; if (c) goto L800cb0cc;
    c = ((r[6] != r[2])); r[2] = (u)0 + 8; if (c) goto L800cb0b8;
    r[4] = (u)r[4] + 32; goto L800cb0c4;
    L800cb0b8:;
    c = ((r[6] != r[2])); r[4] = (u)r[4] + 32; if (c) goto L800cb0cc;
    r[5] = (u)r[3] + (u)0;
    L800cb0c4:;
     CALL(R_GM_SeSet);
    L800cb0cc:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    return r[2];
}
