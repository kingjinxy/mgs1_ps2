extern char R_s10a_dat_800E4560[] __asm__("s10a_dat_800E4560");
int G_s10a_800C7ED0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800C7ED0");
int G_s10a_800C7ED0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[5] = (u)r[2] + (int)R_s10a_dat_800E4560;
    r[2] = *(short *)((u)r[5] + 1024);
    r[3] = *(int *)((u)r[4] + 32);
    r[2] = (u)r[2] << 3;
    r[2] = (u)r[2] + (u)r[5];
    r[6] = LWL(((u)r[3] + 3), r[6]);
    r[6] = LWR(((u)r[3] + 0), r[6]);
    r[7] = LWL(((u)r[3] + 7), r[7]);
    r[7] = LWR(((u)r[3] + 4), r[7]);
    SWL(((u)r[2] + 3), r[6]);
    SWR(((u)r[2] + 0), r[6]);
    SWL(((u)r[2] + 7), r[7]);
    SWR(((u)r[2] + 4), r[7]);
    r[2] = *(short *)((u)r[5] + 1024);
    r[3] = (u)0 + 1;
    r[2] = (u)r[2] << 3;
    r[2] = (u)r[2] + (u)r[5];
    *(short *)((u)r[2] + 6) = r[3];
    r[3] = *(unsigned short *)((u)r[5] + 1026);
    r[2] = *(unsigned short *)((u)r[5] + 1024);
    r[3] = (u)r[3] + 1;
    r[2] = (u)r[2] + 1;
    *(short *)((u)r[5] + 1024) = r[2];
    r[2] = (u)r[2] << 16;
    r[2] = (int)r[2] >> 16;
    r[2] = (int)r[2] < 128;
    c = ((r[2] != 0)); *(short *)((u)r[5] + 1026) = r[3]; if (c) goto L800c7f48;
    *(short *)((u)r[5] + 1024) = 0;
    L800c7f48:;
     goto out;
out:
    RECOMP_RETURN;
}
