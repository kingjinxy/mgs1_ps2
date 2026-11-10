extern char R_GM_StreamPlayStart[] __asm__("GM_StreamPlayStart");
extern char R_GM_StreamStatus[] __asm__("GM_StreamStatus");
extern char R_GM_VoxStream[] __asm__("GM_VoxStream");
extern char R_s18a_800C5200[] __asm__("s18a_800C5200");
int G_s18a_800CD8B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800CD8B4");
int G_s18a_800CD8B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 2476);
    r[3] = *(int *)((u)r[16] + 2408);
    c = ((r[3] != 0)); *(int *)((u)r[16] + 2388) = r[2]; if (c) goto L800cd900;
     CALL(R_GM_StreamStatus);
    r[3] = (u)0 + -1;
    c = ((r[2] != r[3]));  if (c) goto L800cd8f8;
    r[4] = *(int *)((u)r[16] + 2612);
    r[5] = 0x40000000; CALL(R_GM_VoxStream);
    L800cd8f8:;
    r[4] = (u)0 + 2; CALL(R_s18a_800C5200);
    L800cd900:;
    r[3] = *(int *)((u)r[16] + 2408);
    r[2] = (u)0 + 30;
    c = ((r[3] != r[2]));  if (c) goto L800cd918;
     CALL(R_GM_StreamPlayStart);
    L800cd918:;
    r[2] = *(int *)((u)r[16] + 2408);
    r[2] = (int)r[2] < 30;
    c = ((r[2] != 0)); r[2] = (u)0 + 6; if (c) goto L800cd930;
    r[2] = (u)0 + 2;
    L800cd930:;
    *(int *)((u)r[16] + 2384) = r[2];
    r[2] = *(int *)((u)r[16] + 2408);
    r[2] = (int)r[2] < 301;
    c = ((r[2] != 0));  if (c) goto L800cd96c;
     CALL(R_GM_StreamStatus);
    r[3] = (u)0 + -1;
    c = ((r[2] != r[3])); r[2] = (u)0 + 6; if (c) goto L800cd96c;
    *(int *)((u)r[16] + 2404) = r[2];
    *(int *)((u)r[16] + 2428) = 0;
    *(int *)((u)r[16] + 2408) = 0; goto L800cd97c;
    L800cd96c:;
    r[2] = *(int *)((u)r[16] + 2408);
    r[2] = (u)r[2] + 1;
    *(int *)((u)r[16] + 2408) = r[2];
    L800cd97c:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
