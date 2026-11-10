extern char R_GM_PlayerPosition[] __asm__("GM_PlayerPosition");
extern char R_s18a_dat_800E30D4[] __asm__("s18a_dat_800E30D4");
extern char R_s18a_800CC9E4[] __asm__("s18a_800CC9E4");
extern char R_s18a_800CCA88[] __asm__("s18a_800CCA88");
extern char R_s18a_800CCAE0[] __asm__("s18a_800CCAE0");
extern char R_s18a_800CCB38[] __asm__("s18a_800CCB38");
extern char R_s18a_800CCB90[] __asm__("s18a_800CCB90");
extern char R_s18a_800CCBE8[] __asm__("s18a_800CCBE8");
int G_s18a_800CCC0C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CCC0C");
int G_s18a_800CCC0C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    r[4] = (u)r[17] + 32;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16]; CALL(R_s18a_800CC9E4);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_GM_PlayerPosition;
    r[16] = (u)r[2] + (u)0; CALL(R_s18a_800CC9E4);
    r[3] = (u)r[2] + (u)0;
    r[2] = (u)r[16] < (u)5;
    c = ((r[2] == 0)); r[4] = (u)r[3] + (u)0; if (c) goto L800cccc8;
    r[2] = 0;
    r[2] = (u)r[2] + (int)R_s18a_dat_800E30D4;
    r[3] = (u)r[16] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800ccc68: goto L800ccc68; case 0x800ccc7c: goto L800ccc7c; case 0x800ccc90: goto L800ccc90; case 0x800ccca4: goto L800ccca4; case 0x800cccb8: goto L800cccb8; default: goto out; }
    L800ccc68:;
    r[5] = *(int *)((u)r[17] + 2476);
     CALL(R_s18a_800CCA88);
    r[3] = (u)r[2] + (u)0; goto L800cccc8;
    L800ccc7c:;
    r[5] = *(int *)((u)r[17] + 2476);
     CALL(R_s18a_800CCAE0);
    r[3] = (u)r[2] + (u)0; goto L800cccc8;
    L800ccc90:;
    r[5] = *(int *)((u)r[17] + 2476);
     CALL(R_s18a_800CCB38);
    r[3] = (u)r[2] + (u)0; goto L800cccc8;
    L800ccca4:;
    r[5] = *(int *)((u)r[17] + 2476);
     CALL(R_s18a_800CCB90);
    r[3] = (u)r[2] + (u)0; goto L800cccc8;
    L800cccb8:;
    r[5] = *(int *)((u)r[17] + 2476);
     CALL(R_s18a_800CCBE8);
    r[3] = (u)r[2] + (u)0;
    L800cccc8:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[2] = (u)r[3] + (u)0;
    r[29] = (u)r[29] + 32; goto out;
out:
    RECOMP_RETURN;
}
