extern char R_picture_alive[] __asm__("picture_alive");
extern char R_s07b_dword_800C3404[] __asm__("s07b_dword_800C3404");
int G_s07b_800CC6CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CC6CC");
int G_s07b_800CC6CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[3] = (u)0 + -1;
    *(int *)((u)r[2] + ((int)R_s07b_dword_800C3404 + 124)) = r[3];
    r[2] = 0;
    *(int *)((u)r[2] + ((int)R_s07b_dword_800C3404 + 132)) = r[3];
    r[2] = 0;
    *(int *)((u)r[2] + ((int)R_s07b_dword_800C3404 + 128)) = r[3];
    r[2] = 0;
    *(int *)((u)r[2] + ((int)R_s07b_dword_800C3404 + 136)) = r[3];
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_picture_alive) = r[3];
    r[2] = 0;
    *(int *)((u)r[2] + ((int)R_picture_alive + 4)) = r[3]; goto out;
out:
    return r[2];
}
