extern char R_blast_data_8009F4B8[] __asm__("blast_data_8009F4B8");
extern char R_NewBlast[] __asm__("NewBlast");
int G_s08b_bunsin2_800D044C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s08b_bunsin2_800D044C");
int G_s08b_bunsin2_800D044C(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(32)
    r[29] = (u)r[29] + -32;
    *(int *)((u)r[29] + 20) = r[17];
    r[17] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 24) = r[31];
    *(int *)((u)r[29] + 16) = r[16];
    r[2] = *(int *)((u)r[17] + 6608);
    r[16] = (u)r[2] + 1;
    r[2] = (u)0 + 1;
    c = ((r[16] != r[2])); *(int *)((u)r[17] + 6608) = r[16]; if (c) goto L800d0488;
    r[2] = (u)0 + 25;
    *(int *)((u)r[17] + 6576) = r[2];
    r[2] = (u)0 + (u)0; goto L800d051c;
    L800d0488:;
    r[2] = (u)0 + 50;
    c = ((r[16] != r[2])); r[2] = (u)0 + 60; if (c) goto L800d04ac;
    r[4] = *(int *)((u)r[17] + 156);
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_blast_data_8009F4B8;
    r[4] = (u)r[4] + 440; CALL(R_NewBlast);
    r[2] = (u)0 + 60;
    L800d04ac:;
    c = ((r[16] != r[2])); r[2] = (u)0 + 65; if (c) goto L800d04cc;
    r[4] = *(int *)((u)r[17] + 156);
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_blast_data_8009F4B8;
    r[4] = (u)r[4] + 716; CALL(R_NewBlast);
    r[2] = (u)0 + 65;
    L800d04cc:;
    c = ((r[16] != r[2])); r[2] = (u)0 + 69; if (c) goto L800d04ec;
    r[4] = *(int *)((u)r[17] + 156);
    r[5] = 0;
    r[5] = (u)r[5] + (int)R_blast_data_8009F4B8;
    r[4] = (u)r[4] + 1176; CALL(R_NewBlast);
    r[2] = (u)0 + 69;
    L800d04ec:;
    c = ((r[16] != r[2])); r[5] = 0; if (c) goto L800d0504;
    r[4] = *(int *)((u)r[17] + 156);
    r[5] = (u)r[5] + (int)R_blast_data_8009F4B8;
    r[4] = (u)r[4] + 164; CALL(R_NewBlast);
    L800d0504:;
    r[2] = *(int *)((u)r[17] + 6608);
    r[2] = (int)r[2] < 301;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800d051c;
    r[2] = *(int *)((u)r[17] + 6568);
    L800d051c:;
    r[31] = *(int *)((u)r[29] + 24);
    r[17] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 32; goto out;
out:
    return r[2];
}
