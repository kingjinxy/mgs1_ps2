extern char R_s14e_800DA3B4[] __asm__("s14e_800DA3B4");
extern char R_s14e_800DA460[] __asm__("s14e_800DA460");
extern char R_s14e_800DA50C[] __asm__("s14e_800DA50C");
int G_s14e_800DA674(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800DA674");
int G_s14e_800DA674(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    r[5] = (u)r[5] << 2;
    r[5] = (u)r[17] + (u)r[5];
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 28) = r[19];
    *(int *)((u)r[29] + 24) = r[18];
    *(int *)((u)r[29] + 16) = r[16];
    r[18] = *(int *)((u)r[5] + 84);
    c = ((r[17] == 0)); r[19] = 0x10000; if (c) goto L800da704;
    L800da6a4:;
    r[16] = *(int *)((u)r[17] + 64);
    r[4] = (u)r[16] + (u)0; CALL(R_s14e_800DA3B4);
    r[2] = *(int *)((u)r[16] + 0);
    r[2] = r[2] & r[19];
    c = ((r[2] != 0));  if (c) goto L800da6dc;
    r[4] = *(int *)((u)r[16] + 72);
    r[6] = *(short *)((u)r[17] + 82);
    r[5] = (u)r[18] + (u)0; CALL(R_s14e_800DA460);
    r[18] = (u)r[2] + (u)0; goto L800da6f4;
    L800da6dc:;
    r[4] = *(int *)((u)r[16] + 72);
    r[6] = *(short *)((u)r[17] + 82);
    r[7] = *(int *)((u)r[16] + 60);
    r[5] = (u)r[18] + (u)0; CALL(R_s14e_800DA50C);
    r[18] = (u)r[2] + (u)0;
    L800da6f4:;
    r[17] = *(int *)((u)r[17] + 72);
    c = ((r[17] != 0));  if (c) goto L800da6a4;
    L800da704:;
    r[31] = *(int *)((u)r[29] + 32);
    r[19] = *(int *)((u)r[29] + 28);
    r[18] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
