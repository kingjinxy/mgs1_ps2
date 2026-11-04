extern char R_s14e_dword_800DCF40[] __asm__("s14e_dword_800DCF40");
int G_s14e_800CD2B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) __asm__("s14e_800CD2B4");
int G_s14e_800CD2B4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
    RECOMP_ENTRY(0)
    r[5] = (u)r[4] + (u)0;
    r[2] = 0x20000;
    r[3] = *(int *)((u)r[5] + 2872);
    r[4] = *(int *)((u)r[5] + 2856);
    r[3] = r[3] | r[2];
    c = ((r[4] != 0)); *(int *)((u)r[5] + 2872) = r[3]; if (c) goto L800cd2dc;
    r[2] = 0x80000;
    r[2] = r[3] | r[2];
    *(int *)((u)r[5] + 2872) = r[2];
    L800cd2dc:;
    r[2] = *(int *)((u)r[5] + 2856);
    r[2] = (u)r[2] < (u)81;
    c = ((r[2] == 0)); r[2] = (u)0 + 1; if (c) goto L800cd374;
    r[3] = *(unsigned char *)((u)r[5] + 2936);
    r[2] = (u)r[3] < (u)33;
    c = ((r[2] == 0)); r[2] = 0; if (c) goto L800cd360;
    r[2] = (u)r[2] + (int)R_s14e_dword_800DCF40;
    r[3] = (u)r[3] << 2;
    r[3] = (u)r[3] + (u)r[2];
    r[2] = *(int *)((u)r[3] + 0);
    t = r[2];  switch ((u)t) { case 0x800cd320: goto L800cd320; case 0x800cd328: goto L800cd328; case 0x800cd330: goto L800cd330; case 0x800cd338: goto L800cd338; case 0x800cd340: goto L800cd340; case 0x800cd348: goto L800cd348; case 0x800cd350: goto L800cd350; case 0x800cd358: goto L800cd358; case 0x800cd360: goto L800cd360; default: goto out; }
    L800cd320:;
    r[2] = (u)0 + 1536; goto L800cd35c;
    L800cd328:;
    r[2] = (u)0 + 2048; goto L800cd35c;
    L800cd330:;
    r[2] = (u)0 + 2560; goto L800cd35c;
    L800cd338:;
    r[2] = (u)0 + 3072; goto L800cd35c;
    L800cd340:;
    r[2] = (u)0 + 3584; goto L800cd35c;
    L800cd348:;
    *(short *)((u)r[5] + 2888) = 0; goto L800cd360;
    L800cd350:;
    r[2] = (u)0 + 512; goto L800cd35c;
    L800cd358:;
    r[2] = (u)0 + 1024;
    L800cd35c:;
    *(short *)((u)r[5] + 2888) = r[2];
    L800cd360:;
    r[3] = *(int *)((u)r[5] + 2856);
    r[2] = (u)0 + (u)0;
    r[3] = (u)r[3] + 1;
    *(int *)((u)r[5] + 2856) = r[3]; goto out;
    L800cd374:;
     goto out;
out:
    RECOMP_RETURN;
}
