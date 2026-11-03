extern char R_linkvarbuf[] __asm__("linkvarbuf");
extern char R_GV_DestroyOtherActor[] __asm__("GV_DestroyOtherActor");
extern char R_NewSepia_800C5214[] __asm__("NewSepia_800C5214");
int G_s07b_800CB0B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CB0B4");
int G_s07b_800CB0B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    c = ((r[5] == 0)); *(int *)((u)r[29] + 20) = r[31]; if (c) goto L800cb104;
    r[2] = 0;
    r[2] = *(unsigned short *)((u)r[2] + ((int)R_linkvarbuf + 30));
    r[2] = (u)r[2] + -5;
    r[2] = (u)r[2] < (u)2;
    c = ((r[2] != 0));  if (c) goto L800cb120;
    r[2] = *(int *)((u)r[16] + 2096);
    c = ((r[2] != 0));  if (c) goto L800cb120;
     CALL(R_NewSepia_800C5214);
    *(int *)((u)r[16] + 2096) = r[2]; goto L800cb120;
    L800cb104:;
    r[4] = *(int *)((u)r[16] + 2096);
    c = ((r[4] == 0));  if (c) goto L800cb11c;
     CALL(R_GV_DestroyOtherActor);
    L800cb11c:;
    *(int *)((u)r[16] + 2096) = 0;
    L800cb120:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
