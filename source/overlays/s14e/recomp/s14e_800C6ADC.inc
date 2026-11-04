int G_s14e_800C6ADC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800C6ADC");
int G_s14e_800C6ADC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = *(short *)((u)r[4] + 0);
    r[3] = *(short *)((u)r[4] + 2);
    r[2] = *(short *)((u)r[4] + 4);
    c = (((int)r[5] >= 0));  if (c) goto L800c6af4;
    r[5] = (u)0 - (u)r[5];
    L800c6af4:;
    c = (((int)r[3] >= 0));  if (c) goto L800c6b00;
    r[3] = (u)0 - (u)r[3];
    L800c6b00:;
    r[5] = (u)r[5] + (u)r[3];
    c = (((int)r[2] >= 0));  if (c) goto L800c6b10;
    r[2] = (u)0 - (u)r[2];
    L800c6b10:;
    r[2] = (u)r[5] + (u)r[2]; goto out;
out:
    RECOMP_RETURN;
}
