extern char R_s10a_800CF674[] __asm__("s10a_800CF674");
extern char R_s10a_800CF88C[] __asm__("s10a_800CF88C");
extern char R_s10a_800CFD40[] __asm__("s10a_800CFD40");
extern char R_s10a_800CFE20[] __asm__("s10a_800CFE20");
int G_s10a_800D0230(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800D0230");
int G_s10a_800D0230(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[31];
    r[3] = *(int *)((u)r[4] + 440);
    r[2] = (u)r[3] << 1;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (u)r[2] << 4;
    r[2] = (u)r[2] + (u)r[3];
    r[2] = (u)r[2] << 3;
    r[2] = (u)r[4] + (u)r[2];
    r[3] = *(int *)((u)r[2] + 868);
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[2] + 868) = r[3];
    r[3] = *(int *)((u)r[2] + 860);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 2; if (c) goto L800d02bc;
    c = ((r[2] == 0));  if (c) goto L800d0290;
    c = ((r[3] == 0));  if (c) goto L800d02ac;
     goto L800d02e4;
    L800d0290:;
    r[2] = (u)0 + 2;
    c = ((r[3] == r[2])); r[2] = (u)0 + 3; if (c) goto L800d02cc;
    c = ((r[3] == r[2]));  if (c) goto L800d02dc;
     goto L800d02e4;
    L800d02ac:;
     CALL(R_s10a_800CF674);
     goto L800d02e4;
    L800d02bc:;
     CALL(R_s10a_800CF88C);
     goto L800d02e4;
    L800d02cc:;
     CALL(R_s10a_800CFD40);
     goto L800d02e4;
    L800d02dc:;
     CALL(R_s10a_800CFE20);
    L800d02e4:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
