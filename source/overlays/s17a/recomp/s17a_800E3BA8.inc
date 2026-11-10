extern char R_GM_SeSetMode[] __asm__("GM_SeSetMode");
extern char R_GV_RandU[] __asm__("GV_RandU");
int G_s17a_800E3BA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s17a_800E3BA8");
int G_s17a_800E3BA8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 24) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[5] + (u)0;
    r[2] = (u)0 + 2;
    c = ((r[17] != r[2])); *(int *)((u)r[29] + 32) = r[31]; if (c) goto L800e3c40;
    r[2] = *(int *)((u)r[16] + 6528);
    c = ((r[2] == r[17]));  if (c) goto L800e3c40;
    r[2] = *(int *)((u)r[16] + 6508);
    r[2] = (int)r[2] < 3;
    c = ((r[2] != 0));  if (c) goto L800e3c40;
    r[4] = (u)0 + 2; CALL(R_GV_RandU);
    c = ((r[2] == 0)); r[5] = (u)0 + 129; if (c) goto L800e3c00;
    r[5] = (u)0 + 128;
    L800e3c00:;
    r[2] = *(int *)((u)r[16] + 6036);
    r[2] = *(unsigned short *)((u)r[2] + 184);
    *(short *)((u)r[29] + 16) = r[2];
    r[2] = *(int *)((u)r[16] + 6036);
    r[2] = *(unsigned short *)((u)r[2] + 188);
    *(short *)((u)r[29] + 18) = r[2];
    r[2] = *(int *)((u)r[16] + 6036);
    r[4] = (u)r[29] + 16;
    r[2] = *(unsigned short *)((u)r[2] + 192);
    r[6] = (u)0 + 1;
    *(short *)((u)r[29] + 20) = r[2]; CALL(R_GM_SeSetMode);
    L800e3c40:;
    r[2] = *(int *)((u)r[16] + 6536);
    r[4] = (u)0 + 255;
    *(int *)((u)r[16] + 6528) = r[17];
    c = ((r[2] == 0)); *(int *)((u)r[16] + 6532) = r[4]; if (c) goto L800e3c68;
    r[3] = (u)r[17] + (u)0;
    r[2] = (u)0 + 2;
    c = ((r[3] != r[2])); r[2] = (u)0 + 1; if (c) goto L800e3c68;
    *(int *)((u)r[16] + 6528) = r[2];
    L800e3c68:;
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
