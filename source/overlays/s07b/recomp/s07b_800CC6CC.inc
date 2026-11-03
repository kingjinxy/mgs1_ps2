extern char R_chair_alive[] __asm__("chair_alive");
extern char R_ox_alive[] __asm__("ox_alive");
extern char R_picture_alive[] __asm__("picture_alive");
extern char R_pot_alive[] __asm__("pot_alive");
extern char R_statue_alive[] __asm__("statue_alive");
int G_s07b_800CC6CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CC6CC");
int G_s07b_800CC6CC(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(0)
    r[2] = 0;
    r[3] = (u)0 + -1;
    *(int *)((u)r[2] + (int)R_chair_alive) = r[3];
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_statue_alive) = r[3];
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_pot_alive) = r[3];
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_ox_alive) = r[3];
    r[2] = 0;
    *(int *)((u)r[2] + (int)R_picture_alive) = r[3];
    r[2] = 0;
    *(int *)((u)r[2] + ((int)R_picture_alive + 4)) = r[3]; goto out;
out:
    return r[2];
}
