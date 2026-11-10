int G_s18a_800DBB78(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s18a_800DBB78");
int G_s18a_800DBB78(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = *(int *)((u)r[4] + 2212);
    r[3] = *(unsigned short *)((u)r[5] + 0);
    r[2] = r[3] & 40960;
    c = ((r[2] == 0)); r[2] = r[3] & 32768; if (c) goto L800dbc94;
    r[6] = *(short *)((u)r[4] + 110);
    c = ((r[2] == 0));  if (c) goto L800dbc18;
    r[2] = *(int *)((u)r[4] + 2020);
    r[2] = r[2] & 16384;
    c = ((r[2] == 0)); r[2] = (u)0 + 80; if (c) goto L800dbbc0;
    r[3] = *(unsigned char *)((u)r[5] + 14);
    r[5] = (u)r[2] - (u)r[3]; goto L800dbbc4;
    L800dbbc0:;
    r[5] = (u)0 + 1;
    L800dbbc4:;
    r[2] = *(int *)((u)r[4] + 2020);
    r[2] = r[2] & 16384;
    c = ((r[2] == 0)); r[3] = (u)0 + 1; if (c) goto L800dbbdc;
    r[3] = (u)0 + 80;
    L800dbbdc:;
    r[2] = r[5] & 255;
    r[2] = (u)r[2] << 1;
    if (r[3]) { lo_ = (int)r[2] / (int)r[3]; hi_ = (int)r[2] % (int)r[3]; }
    c = ((r[3] != 0));  if (c) goto L800dbbf4;
    L800dbbf4:;
    r[1] = (u)0 + -1;
    c = ((r[3] != r[1])); r[1] = 0; if (c) goto L800dbc0c;
    c = ((r[2] != r[1]));  if (c) goto L800dbc0c;
    L800dbc0c:;
    r[2] = lo_;
    r[6] = (u)r[6] + (u)r[2]; goto L800dbc90;
    L800dbc18:;
    r[2] = *(int *)((u)r[4] + 2020);
    r[2] = r[2] & 16384;
    c = ((r[2] == 0));  if (c) goto L800dbc38;
    r[2] = *(unsigned char *)((u)r[5] + 14);
    r[5] = (u)r[2] + 80; goto L800dbc3c;
    L800dbc38:;
    r[5] = (u)0 + 1;
    L800dbc3c:;
    r[2] = *(int *)((u)r[4] + 2020);
    r[2] = r[2] & 16384;
    c = ((r[2] == 0)); r[3] = (u)0 + 1; if (c) goto L800dbc54;
    r[3] = (u)0 + 79;
    L800dbc54:;
    r[2] = r[5] & 255;
    r[2] = (u)r[2] << 1;
    if (r[3]) { lo_ = (int)r[2] / (int)r[3]; hi_ = (int)r[2] % (int)r[3]; }
    c = ((r[3] != 0));  if (c) goto L800dbc6c;
    L800dbc6c:;
    r[1] = (u)0 + -1;
    c = ((r[3] != r[1])); r[1] = 0; if (c) goto L800dbc84;
    c = ((r[2] != r[1]));  if (c) goto L800dbc84;
    L800dbc84:;
    r[2] = lo_;
    r[6] = (u)r[6] - (u)r[2];
    L800dbc90:;
    *(short *)((u)r[4] + 110) = r[6];
    L800dbc94:;
     goto out;
out:
    RECOMP_RETURN;
}
