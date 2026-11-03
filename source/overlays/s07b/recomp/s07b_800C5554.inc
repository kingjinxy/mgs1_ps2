extern char R_DG_ZeroVector[] __asm__("DG_ZeroVector");
int G_s07b_800C5554(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800C5554");
int G_s07b_800C5554(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = *(unsigned short *)((u)r[4] + 6);
    *(short *)((u)r[4] + 62) = 0;
    *(short *)((u)r[4] + 40) = 0;
    r[2] = r[2] & 65401;
    *(short *)((u)r[4] + 6) = r[2];
    r[2] = 0;
    r[7] = (u)r[2] + (int)R_DG_ZeroVector;
    r[3] = LWL(((u)r[7] + 3), r[3]);
    r[3] = LWR(((u)r[7] + 0), r[3]);
    r[5] = LWL(((u)r[7] + 7), r[5]);
    r[5] = LWR(((u)r[7] + 4), r[5]);
    SWL(((u)r[4] + 47), r[3]);
    SWR(((u)r[4] + 44), r[3]);
    SWL(((u)r[4] + 51), r[5]);
    SWR(((u)r[4] + 48), r[5]);
     goto out;
out:
    RECOMP_RETURN;
}
