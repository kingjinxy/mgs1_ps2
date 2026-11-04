extern char R_s15a_800CB7E4[] __asm__("s15a_800CB7E4");
extern char R_s15a_800CB934[] __asm__("s15a_800CB934");
extern char R_s15a_800CBB68[] __asm__("s15a_800CBB68");
extern char R_s15a_800CBC4C[] __asm__("s15a_800CBC4C");
int G_s15a_800CBDD8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s15a_800CBDD8");
int G_s15a_800CBDD8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 1904);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 2; if (c) goto L800cbe30;
    c = ((r[2] == 0)); r[2] = (u)0 + 2; if (c) goto L800cbe08;
    c = ((r[3] == 0)); r[2] = (u)0 + (u)0; if (c) goto L800cbe20;
     goto L800cbe58;
    L800cbe08:;
    c = ((r[3] == r[2])); r[2] = (u)0 + 3; if (c) goto L800cbe40;
    c = ((r[3] == r[2])); r[2] = (u)0 + (u)0; if (c) goto L800cbe50;
     goto L800cbe58;
    L800cbe20:;
     CALL(R_s15a_800CB7E4);
     goto L800cbe58;
    L800cbe30:;
     CALL(R_s15a_800CB934);
     goto L800cbe58;
    L800cbe40:;
     CALL(R_s15a_800CBB68);
     goto L800cbe58;
    L800cbe50:;
     CALL(R_s15a_800CBC4C);
    L800cbe58:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
