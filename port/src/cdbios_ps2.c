/** @brief PS1 disc reads for libfs/cdbios.c (its MGS_PORT branch): the PS1 disc is one file on the DVD
 * (DISC1.BIN, raw 2352-byte sectors from the CHD, build/link_ps2.py), so PS1 sector n (absolute, as the
 * game counts them: LBA + 150) is at byte (n - 150) * 2352 of that file. Reads are asynchronous, in
 * chunks of whole PS1 sectors: MgsCd_Start, then MgsCd_Poll until done, then MgsCd_Sector.
 * PS2 side: compiled against ps2sdk's headers (build/link_ps2.py). */

#include <stdio.h>
#include <kernel.h>
#include <libcdvd.h>

#define PS1_RAW_SECTOR 2352
#define PS1_PREGAP     150 /* the game's sector numbers count from MSF 00:00:00 */
#define DVD_SECTOR     2048
#define CHUNK_MAX      16  /* PS1 sectors per read */
#define BOUNCE_SECTORS ((CHUNK_MAX * PS1_RAW_SECTOR + DVD_SECTOR - 1) / DVD_SECTOR + 1)

static sceCdlFILE    s_Disc;
static int           s_Ready;
static unsigned int  s_DiscSectors; /* PS1 sectors in the file */
static unsigned int  s_Skip;        /* where the chunk's first PS1 sector starts in the bounce buffer */
static unsigned char s_Bounce[BOUNCE_SECTORS * DVD_SECTOR] __attribute__((aligned(64)));

/** Finds the disc file; 1 when it's ready. */
int MgsCd_Init(void)
{
    if (s_Ready)
    {
        return 1;
    }
    sceCdInit(SCECdINIT);
    sceCdMmode(SCECdMmodeDvd);
    if (!sceCdSearchFile(&s_Disc, "\\DISC1.BIN;1"))
    {
        printf("cdbios: DISC1.BIN not found on the disc\n");
        return 0;
    }
    s_DiscSectors = s_Disc.size / PS1_RAW_SECTOR;
    s_Ready       = 1;
    printf("cdbios: DISC1.BIN at DVD sector %u (%u PS1 sectors)\n", s_Disc.lsn, s_DiscSectors);
    return 1;
}

/** Starts reading PS1 sectors [sector, sector + count); returns how many will be read (count is cut to
 * CHUNK_MAX and the end of the disc), 0 if the read didn't start. */
int MgsCd_Start(int sector, int count)
{
    unsigned long long off;
    unsigned int       lba = (unsigned int)(sector - PS1_PREGAP);
    sceCdRMode         mode;

    if (!s_Ready || sector < PS1_PREGAP || lba >= s_DiscSectors)
    {
        printf("cdbios: read of PS1 sector %d (outside the disc)\n", sector);
        return 0;
    }
    if (count > CHUNK_MAX)
    {
        count = CHUNK_MAX;
    }
    if (lba + (unsigned int)count > s_DiscSectors)
    {
        count = (int)(s_DiscSectors - lba);
    }
    off              = (unsigned long long)lba * PS1_RAW_SECTOR;
    s_Skip           = (unsigned int)(off % DVD_SECTOR);
    mode.trycount    = 0;
    mode.spindlctrl  = SCECdSpinNom;
    mode.datapattern = SCECdSecS2048;
    mode.pad         = 0;
    if (!sceCdRead(s_Disc.lsn + (unsigned int)(off / DVD_SECTOR),
                   (s_Skip + (unsigned int)count * PS1_RAW_SECTOR + DVD_SECTOR - 1) / DVD_SECTOR, s_Bounce, &mode))
    {
        return 0;
    }
    return count;
}

/** 1 while the read is in progress, 0 when it's done, -1 on a drive error. */
int MgsCd_Poll(void)
{
    if (sceCdSync(1))
    {
        return 1;
    }
    if (sceCdGetError() != SCECdErNO)
    {
        printf("cdbios: drive error %d\n", sceCdGetError());
        return -1;
    }
    /* The IOP DMAed the sectors behind the EE's data cache (see the HAL's libcd_ps2.c chunk_finish). */
    InvalidDCache(s_Bounce, s_Bounce + sizeof(s_Bounce) - 1);
    return 0;
}

/** The i-th raw sector of the finished read (sync, header, subheader, data). */
const unsigned char* MgsCd_Sector(int i)
{
    return s_Bounce + s_Skip + (unsigned int)i * PS1_RAW_SECTOR;
}

/* PSY-Q libcd: the game's own CdInit calls (main.c, gamed.c) find the disc file; CdReset is called by
 * cdbios's error path only on the PS1 build. */
#undef CdInit
int CdInit(void)
{
    return MgsCd_Init();
}

int CdReset(int mode)
{
    (void)mode;
    return MgsCd_Init();
}
