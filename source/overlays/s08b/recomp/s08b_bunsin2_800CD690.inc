extern char R_GM_SeSetMode[] __asm__("GM_SeSetMode");
int G_s08b_bunsin2_800CD690(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800CD690");
int G_s08b_bunsin2_800CD690(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[7] = (u)0 + 185;
    r[2] = (u)0 + 3;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 6564);
    r[6] = *(short *)((u)r[4] + 390);
    c = ((r[3] == r[2])); r[5] = (u)0 + 186; if (c) goto L800cd6e0;
    r[2] = (int)r[3] < 4;
    c = ((r[2] == 0));  if (c) goto L800cd6cc;
    c = (((int)r[3] <= 0)); r[2] = (u)0 + 9; if (c) goto L800cd760;
     goto L800cd708;
    L800cd6cc:;
    r[2] = (u)0 + 4;
    c = ((r[3] == r[2])); r[2] = (u)0 + 22; if (c) goto L800cd718;
     goto L800cd760;
    L800cd6e0:;
    r[2] = (u)0 + 27;
    c = ((r[6] != r[2])); r[2] = (u)0 + 13; if (c) goto L800cd6f8;
    r[4] = (u)r[4] + 32;
    r[5] = (u)0 + 186; goto L800cd758;
    L800cd6f8:;
    c = ((r[6] != r[2])); r[4] = (u)r[4] + 32; if (c) goto L800cd760;
    r[5] = (u)0 + 185; goto L800cd758;
    L800cd708:;
    c = ((r[6] != r[2])); r[2] = (u)0 + 18; if (c) goto L800cd748;
    r[4] = (u)r[4] + 32; goto L800cd758;
    L800cd718:;
    c = ((r[6] == r[2])); r[2] = (u)0 + 74; if (c) goto L800cd730;
    c = ((r[6] == r[2])); r[2] = (u)0 + 120; if (c) goto L800cd730;
    c = ((r[6] != r[2])); r[2] = (u)0 + 44; if (c) goto L800cd738;
    L800cd730:;
    r[4] = (u)r[4] + 32; goto L800cd758;
    L800cd738:;
    c = ((r[6] == r[2])); r[2] = (u)0 + 90; if (c) goto L800cd750;
    c = ((r[6] == r[2])); r[2] = (u)0 + 142; if (c) goto L800cd750;
    L800cd748:;
    c = ((r[6] != r[2]));  if (c) goto L800cd760;
    L800cd750:;
    r[4] = (u)r[4] + 32;
    r[5] = (u)r[7] + (u)0;
    L800cd758:;
    r[6] = (u)0 + 1; CALL(R_GM_SeSetMode);
    L800cd760:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
