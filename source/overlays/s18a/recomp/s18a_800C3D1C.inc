extern char R_DG_FadeScreen[] __asm__("DG_FadeScreen");
extern char R_GM_StreamStatus[] __asm__("GM_StreamStatus");
extern char R_GV_DestroyActor[] __asm__("GV_DestroyActor");
int G_s18a_800C3D1C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800C3D1C");
int G_s18a_800C3D1C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[2] = *(int *)((u)r[16] + 40);
    r[3] = *(int *)((u)r[16] + 44);
    r[2] = (u)r[2] + (u)r[3];
    *(int *)((u)r[16] + 40) = r[2];
    r[2] = (int)r[2] < 257;
    c = ((r[2] != 0)); r[4] = (u)r[3] + (u)0; if (c) goto L800c3d7c;
    r[2] = (u)0 + 255;
    *(int *)((u)r[16] + 40) = r[2]; CALL(R_DG_FadeScreen);
     CALL(R_GM_StreamStatus);
    r[3] = (u)0 + -1;
    c = ((r[2] != r[3]));  if (c) goto L800c3d88;
    r[4] = (u)r[16] + (u)0; CALL(R_GV_DestroyActor);
     goto L800c3d88;
    L800c3d7c:;
    r[4] = *(int *)((u)r[16] + 44);
     CALL(R_DG_FadeScreen);
    L800c3d88:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
