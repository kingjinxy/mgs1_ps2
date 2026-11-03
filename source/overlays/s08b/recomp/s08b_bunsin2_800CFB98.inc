extern char R_s08b_dword_800E4340[] __asm__("s08b_dword_800E4340");
extern char R_GV_DirVec2[] __asm__("GV_DirVec2");
int G_s08b_bunsin2_800CFB98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800CFB98");
int G_s08b_bunsin2_800CFB98(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(40)
    r[29] = (u)r[29] + -40;
    *(int *)((u)r[29] + 28) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 32) = r[31];
    *(int *)((u)r[29] + 24) = r[16];
    r[2] = *(int *)((u)r[17] + 6608);
    r[2] = (int)r[2] < 10;
    c = ((r[2] == 0)); r[16] = (u)r[17] + 32; if (c) goto L800cfc20;
    r[3] = *(int *)((u)r[17] + 2008);
    r[2] = (u)0 + 1;
    c = ((r[3] != r[2]));  if (c) goto L800cfbdc;
    r[2] = *(short *)((u)r[16] + 10);
    r[2] = (u)r[2] + 1024; goto L800cfbe8;
    L800cfbdc:;
    r[2] = *(short *)((u)r[16] + 10);
    r[2] = (u)r[2] + -1024;
    L800cfbe8:;
    r[4] = r[2] & 4095;
    r[5] = (u)0 + 100;
    r[6] = (u)r[29] + 16; CALL(R_GV_DirVec2);
    r[2] = *(unsigned short *)((u)r[16] + 0);
    r[3] = *(unsigned short *)((u)r[29] + 16);
    r[2] = (u)r[2] + (u)r[3];
    *(short *)((u)r[16] + 0) = r[2];
    r[2] = *(unsigned short *)((u)r[16] + 4);
    r[3] = *(unsigned short *)((u)r[29] + 20);
    r[2] = (u)r[2] + (u)r[3];
    *(short *)((u)r[16] + 4) = r[2];
    L800cfc20:;
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_s08b_dword_800E4340);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2])); r[2] = (u)0 + (u)0; if (c) goto L800cfc4c;
    r[3] = *(int *)((u)r[17] + 6608);
    r[4] = (u)0 + 7;
    *(int *)((u)r[17] + 6576) = r[4];
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[17] + 6608) = r[3]; goto L800cfc50;
    L800cfc4c:;
    r[2] = (u)0 + 1;
    L800cfc50:;
    r[31] = *(int *)((u)r[29] + 32);
    r[17] = *(int *)((u)r[29] + 28);
    r[16] = *(int *)((u)r[29] + 24);
    r[29] = (u)r[29] + 40; goto out;
out:
    RECOMP_RETURN;
}
