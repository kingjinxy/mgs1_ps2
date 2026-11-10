extern char R_s18a_dat_800E302C[] __asm__("s18a_dat_800E302C");
extern char R_GM_SeSetMode[] __asm__("GM_SeSetMode");
int G_s18a_800CC574(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CC574");
int G_s18a_800CC574(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[4] + 2364);
    r[5] = *(short *)((u)r[4] + 618);
    r[3] = (u)r[2] + -8;
    r[2] = (u)r[3] < (u)6;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800cc650;
    r[2] = (u)r[2] + (int)R_s18a_dat_800E302C;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800cc5b0: goto L800cc5b0; case 0x800cc5c8: goto L800cc5c8; case 0x800cc5dc: goto L800cc5dc; case 0x800cc5fc: goto L800cc5fc; case 0x800cc61c: goto L800cc61c; case 0x800cc650: goto L800cc650; default: goto out; }
    L800cc5b0:;
    r[2] = (u)0 + 16;
    c = ((r[5] != r[2])); r[2] = (u)0 + 8; if (c) goto L800cc63c;
    r[4] = (u)r[4] + 32;
    r[5] = (u)0 + 161; goto L800cc648;
    L800cc5c8:;
    r[2] = (u)0 + 4;
    c = ((r[5] != r[2])); r[4] = (u)r[4] + 32; if (c) goto L800cc650;
    r[5] = (u)0 + 161; goto L800cc648;
    L800cc5dc:;
    r[2] = (u)0 + 8;
    c = ((r[5] == r[2])); r[2] = (u)0 + 13; if (c) goto L800cc5f0;
    c = ((r[5] != r[2])); r[2] = (u)0 + 15; if (c) goto L800cc63c;
    L800cc5f0:;
    r[4] = (u)r[4] + 32;
    r[5] = (u)0 + 161; goto L800cc648;
    L800cc5fc:;
    r[2] = (u)0 + 6;
    c = ((r[5] == r[2])); r[2] = (u)0 + 14; if (c) goto L800cc610;
    c = ((r[5] != r[2])); r[2] = (u)0 + 15; if (c) goto L800cc63c;
    L800cc610:;
    r[4] = (u)r[4] + 32;
    r[5] = (u)0 + 161; goto L800cc648;
    L800cc61c:;
    r[2] = (u)0 + 6;
    c = ((r[5] == r[2])); r[2] = (u)0 + 14; if (c) goto L800cc630;
    c = ((r[5] != r[2])); r[2] = (u)0 + 15; if (c) goto L800cc63c;
    L800cc630:;
    r[4] = (u)r[4] + 32;
    r[5] = (u)0 + 161; goto L800cc648;
    L800cc63c:;
    c = ((r[5] != r[2])); r[4] = (u)r[4] + 32; if (c) goto L800cc650;
    r[5] = (u)0 + 160;
    L800cc648:;
    r[6] = (u)0 + (u)0; CALL(R_GM_SeSetMode);
    L800cc650:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
