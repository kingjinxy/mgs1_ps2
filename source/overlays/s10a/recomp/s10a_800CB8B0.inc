extern char R_s10a_dat_800E4990[] __asm__("s10a_dat_800E4990");
extern char R_s10a_800CB478[] __asm__("s10a_800CB478");
extern char R_s10a_800CB55C[] __asm__("s10a_800CB55C");
extern char R_s10a_800CB6DC[] __asm__("s10a_800CB6DC");
extern char R_s10a_800CB804[] __asm__("s10a_800CB804");
int G_s10a_800CB8B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s10a_800CB8B0");
int G_s10a_800CB8B0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    *(int *)((u)r[29] + 16) = r[16];
    r[16] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 20) = r[31];
    *(char *)((u)r[16] + 2974) = 0; CALL(R_s10a_800CB55C);
    r[2] = 0;
    r[3] = *(int *)((u)r[2] + (int)R_s10a_dat_800E4990);
    r[2] = (u)0 + 1;
    c = ((r[3] == r[2]));  if (c) goto L800cb8f4;
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CB478);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CB6DC);
    r[4] = (u)r[16] + (u)0; CALL(R_s10a_800CB804);
    L800cb8f4:;
    r[31] = *(int *)((u)r[29] + 20);
    r[16] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
