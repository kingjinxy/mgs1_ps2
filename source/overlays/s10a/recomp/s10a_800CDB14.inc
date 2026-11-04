extern char R_s10a_dat_800E4990[] __asm__("s10a_dat_800E4990");
extern char R_s10a_800CC708[] __asm__("s10a_800CC708");
extern char R_s10a_800CD288[] __asm__("s10a_800CD288");
extern char R_s10a_800CD4CC[] __asm__("s10a_800CD4CC");
extern char R_s10a_800CD674[] __asm__("s10a_800CD674");
int G_s10a_800CDB14(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s10a_800CDB14");
int G_s10a_800CDB14(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    r[3] = *(short *)((u)r[16] + 2850);
    r[2] = (u)0 + 6;
    c = ((r[3] == r[2])); r[2] = (int)r[3] < 7; if (c) goto L800cdb5c;
    c = ((r[2] == 0)); r[2] = (u)0 + 7; if (c) goto L800cdb4c;
    c = ((r[3] == 0)); r[2] = 0; if (c) goto L800cdb6c;
     goto L800cdb94;
    L800cdb4c:;
    c = ((r[3] == r[2])); r[2] = 0; if (c) goto L800cdb7c;
     goto L800cdb94;
    L800cdb5c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CD288);
    r[2] = 0; goto L800cdb94;
    L800cdb6c:;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CD4CC);
    r[2] = 0; goto L800cdb94;
    L800cdb7c:;
    r[2] = *(unsigned short *)((u)r[16] + 90);
    r[4] = (u)r[16] + (u)0;
    r[2] = r[2] | 4096;
    *(short *)((u)r[16] + 90) = r[2]; CALL(R_s10a_800CD674);
    r[2] = 0;
    L800cdb94:;
    r[2] = *(int *)((u)r[2] + (int)R_s10a_dat_800E4990);
    c = ((r[2] == 0));  if (c) goto L800cdbac;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CC708);
    L800cdbac:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
