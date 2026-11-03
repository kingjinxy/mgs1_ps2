extern char R_s10a_800C7DAC[] __asm__("s10a_800C7DAC");
int G_s10a_800C7DFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C7DFC");
int G_s10a_800C7DFC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    r[5] = 0 | 51845;
    *(int *)((u)r[29] + 20) = r[31];
    *(int *)((u)r[16] + 40) = 0; CALL(R_s10a_800C7DAC);
    c = ((r[2] == 0)); r[2] = (u)0 + 360; if (c) goto L800c7e2c;
    *(int *)((u)r[16] + 44) = r[2];
    r[2] = (u)0 + (u)0; goto L800c7e68;
    L800c7e2c:;
    r[5] = *(int *)((u)r[16] + 44);
    c = (((int)r[5] > 0)); r[2] = (u)0 + 1; if (c) goto L800c7e50;
    r[4] = (u)r[16] + (u)0;
    r[5] = 0 | 56405; CALL(R_s10a_800C7DAC);
     goto L800c7e68;
    L800c7e50:;
    r[3] = (u)0 + 360;
    r[4] = *(int *)((u)r[16] + 44);
    r[3] = (u)r[3] - (u)r[5];
    *(int *)((u)r[16] + 40) = r[3];
    r[4] = (u)r[4] + -1;
    *(int *)((u)r[16] + 44) = r[4];
    L800c7e68:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
