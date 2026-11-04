extern char R_HZD_InsideZone[] __asm__("HZD_InsideZone");
extern char R_s10a_800CC544[] __asm__("s10a_800CC544");
extern char R_s10a_800CC584[] __asm__("s10a_800CC584");
int G_s10a_800CC774(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800CC774");
int G_s10a_800CC774(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(unsigned char *)((u)r[16] + 2936);
    r[2] = (u)0 + 255;
    c = ((r[3] == r[2])); r[6] = (u)r[3] + (u)0; if (c) goto L800cc7c8;
    r[2] = *(int *)((u)r[16] + 76);
    r[4] = *(int *)((u)r[2] + 8);
    r[5] = (u)r[16] + 32; CALL(R_HZD_InsideZone);
    c = ((r[2] != 0));  if (c) goto L800cc7dc;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CC584);
    r[2] = (u)0 + 2;
    *(short *)((u)r[16] + 2848) = r[2];
    r[2] = (u)0 + 11; goto L800cc818;
    L800cc7c8:;
    r[2] = *(int *)((u)r[16] + 3064);
    r[2] = (int)r[2] < 7000;
    c = ((r[2] != 0));  if (c) goto L800cc804;
    L800cc7dc:;
    r[2] = (u)0 + 2;
    r[3] = (u)0 + 13;
    *(short *)((u)r[16] + 2850) = r[3];
    r[3] = (u)0 + 24;
    *(short *)((u)r[16] + 2848) = r[2];
    *(short *)((u)r[16] + 2852) = r[3];
    *(short *)((u)r[16] + 2854) = r[2];
    *(int *)((u)r[16] + 2856) = 0;
    *(int *)((u)r[16] + 2876) = 0; goto L800cc828;
    L800cc804:;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CC544);
    r[2] = (u)0 + 2;
    *(short *)((u)r[16] + 2848) = r[2];
    r[2] = (u)0 + 12;
    L800cc818:;
    *(short *)((u)r[16] + 2850) = r[2];
    r[2] = (u)0 + 1;
    *(int *)((u)r[16] + 2856) = 0;
    *(int *)((u)r[16] + 2876) = r[2];
    L800cc828:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
