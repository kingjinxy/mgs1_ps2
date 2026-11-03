extern char R_s07b_dword_800E4F5C[] __asm__("s07b_dword_800E4F5C");
extern char R_s07b_dword_800E4F70[] __asm__("s07b_dword_800E4F70");
extern char R_printf[] __asm__("printf");
extern char R_s07b_800CB068[] __asm__("s07b_800CB068");
extern char R_s07b_800CB0B4[] __asm__("s07b_800CB0B4");
int G_s07b_800CB130(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) __asm__("s07b_800CB130");
int G_s07b_800CB130(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    RECOMP_ENTRY(24)
    r[29] = (u)r[29] + -24;
    r[5] = (u)r[4] + (u)0;
    *(int *)((u)r[29] + 16) = r[31];
    r[2] = *(int *)((u)r[5] + 2148);
    c = ((r[2] == 0));  if (c) goto L800cb214;
    c = (((int)r[2] <= 0));  if (c) goto L800cb1c0;
    r[2] = (u)r[2] + -1;
    c = ((r[2] != 0)); *(int *)((u)r[5] + 2148) = r[2]; if (c) goto L800cb214;
    r[2] = *(int *)((u)r[5] + 2124);
    r[2] = r[2] & 1;
    c = ((r[2] != 0));  if (c) goto L800cb214;
    r[2] = *(int *)((u)r[5] + 2128);
    r[2] = r[2] & 1;
    c = ((r[2] != 0));  if (c) goto L800cb1a0;
    r[2] = *(int *)((u)r[5] + 156);
    r[3] = *(int *)((u)r[2] + 40);
    r[4] = (u)0 + -129;
    r[3] = r[3] & r[4];
    *(int *)((u)r[2] + 40) = r[3];
    L800cb1a0:;
    r[4] = (u)r[5] + (u)0;
    r[5] = (u)0 + (u)0; CALL(R_s07b_800CB0B4);
    r[4] = (u)0 + (u)0; CALL(R_s07b_800CB068);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s07b_dword_800E4F5C; goto L800cb20c;
    L800cb1c0:;
    r[2] = (u)r[2] + 1;
    c = ((r[2] != 0)); *(int *)((u)r[5] + 2148) = r[2]; if (c) goto L800cb214;
    r[2] = *(int *)((u)r[5] + 2124);
    r[2] = r[2] & 1;
    c = ((r[2] == 0)); r[4] = (u)r[5] + (u)0; if (c) goto L800cb214;
    r[2] = *(int *)((u)r[5] + 156);
    r[3] = *(int *)((u)r[2] + 40);
    r[5] = (u)0 + 1;
    r[3] = r[3] | 128;
    *(int *)((u)r[2] + 40) = r[3]; CALL(R_s07b_800CB0B4);
    r[4] = (u)0 + 1; CALL(R_s07b_800CB068);
    r[4] = 0;
    r[4] = (u)r[4] + (int)R_s07b_dword_800E4F70;
    L800cb20c:;
     CALL(R_printf);
    L800cb214:;
    r[31] = *(int *)((u)r[29] + 16);
    r[29] = (u)r[29] + 24; goto out;
out:
    RECOMP_RETURN;
}
