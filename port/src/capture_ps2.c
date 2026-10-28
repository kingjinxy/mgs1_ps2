/** @brief Frame capture for comparing with DuckStation (tools/port/compare_frames.py). `host:capture.txt`
 * (next to the disc image) lists:
 *  - `replay=N` entries: for each, host:cap/ps1_N_before.bin is loaded into VRAM, ps1_N_gp0.bin's GPU
 *    commands are drawn through the GS renderer, and VRAM is written to host:cap/ps2r_N_vram.bin. The
 *    PS1's exact commands, so differences are the renderer's alone. Runs once, 60 frames after boot (the
 *    GS set up).
 *  - `live=N` entries, with `stage=NAME`: the game's own frame N of that stage (game loop N from the
 *    end of its load, captured at the first DrawOTag of loop N or later, as tools/port/gdb/capture_ps1.py): its ordering table's packets to
 *    host:cap/ps2_N_gp0.bin (u32 word count, then the words) and, at the next DrawOTag, VRAM to
 *    ps2_N_vram.bin. With `ticks` too, the demo stream's clock follows the PS1's (host:cap/ps1_ticks.txt,
 *    from capture_ps1.py): loops count from the PS1's FS_StreamTickStart loop, and FS_StreamGetTick
 *    returns the tick the PS1 had in that loop, so the cutscene's timing is the PS1's.
 * Without the file (or on hardware), nothing happens.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "port/hal_game.h"

#define MAX_REPLAYS 64

extern void GpuGs_Commands(const unsigned int* w, int n); /* HAL ps2/gpu_gs.c */
extern void GpuGs_LoadImage(int x, int y, int w, int h, const unsigned short* src, int stride);
extern void GpuGs_StoreImage(int x, int y, int w, int h, unsigned short* dst);
extern void GpuGs_Flush(void);
extern void GpuGs_Sync(void);

static int   s_Replay[MAX_REPLAYS];
static int   s_ReplayCount;
static int   s_Live[MAX_REPLAYS];
static int   s_LiveCount, s_LiveDone;
static char  s_LiveCaptured[MAX_REPLAYS];
static char  s_Stage[16];
static int   s_Loaded;
static int   s_InStage;    /* the captured stage loading or running */
static int   s_Base;       /* GV_Time at the end of its load (game loops count from there) */
static int   s_BaseSet;
static int   s_Open  = -1; /* live frame whose packets are being written */
static FILE* s_Packets;

#define MAX_TICKS 16384
static int  s_TickStart = -1; /* the PS1's FS_StreamTickStart loop (-1: during the load, no realignment) */
static int* s_Ticks;          /* the PS1's tick per loop (-1: none recorded); NULL: no ticks */
static int  s_Ps1Clock = -1;  /* the PS1's GV_Clock at the load's end */
static int  s_HoldClock;      /* skip GV_Clock's next flip (gvd.c), for the PS1's parity */

static void load_ticks(void)
{
    char  line[64];
    int   frame, tick, i;
    FILE* f = fopen("host:cap/ps1_ticks.txt", "r");
    if (!f || !(s_Ticks = malloc(MAX_TICKS * sizeof(int))))
    {
        printf("capture: no host:cap/ps1_ticks.txt\n");
        if (f)
        {
            fclose(f);
        }
        return;
    }
    for (i = 0; i < MAX_TICKS; i++)
    {
        s_Ticks[i] = -1;
    }
    while (fgets(line, sizeof(line), f))
    {
        if (sscanf(line, "clock %d", &frame) == 1)
        {
            s_Ps1Clock = frame;
        }
        else if (sscanf(line, "start %d", &frame) == 1)
        {
            s_TickStart = frame;
        }
        else if (sscanf(line, "%d %d", &frame, &tick) == 2 && frame >= 0 && frame < MAX_TICKS)
        {
            s_Ticks[frame] = tick;
        }
    }
    fclose(f);
}

static void load(void)
{
    char  buf[1024];
    char* p;
    FILE* f;
    if (s_Loaded)
    {
        return;
    }
    s_Loaded = 1;
    if (!(f = fopen("host:capture.txt", "r")))
    {
        return;
    }
    buf[fread(buf, 1, sizeof(buf) - 1, f)] = 0;
    fclose(f);
    for (p = buf; (p = strstr(p, "replay=")) && s_ReplayCount < MAX_REPLAYS;)
    {
        int n = 0;
        for (p += 7; *p >= '0' && *p <= '9'; p++)
        {
            n = n * 10 + (*p - '0');
        }
        s_Replay[s_ReplayCount++] = n;
    }
    for (p = buf; (p = strstr(p, "live=")) && s_LiveCount < MAX_REPLAYS;)
    {
        int n = 0;
        for (p += 5; *p >= '0' && *p <= '9'; p++)
        {
            n = n * 10 + (*p - '0');
        }
        s_Live[s_LiveCount++] = n;
    }
    if (strstr(buf, "ticks"))
    {
        load_ticks();
    }
    if ((p = strstr(buf, "stage=")))
    {
        int i;
        for (p += 6, i = 0; i < (int)sizeof(s_Stage) - 1 && *p > ' '; i++)
        {
            s_Stage[i] = *p++;
        }
    }
}

extern int GV_Time, GV_Clock; /* libgv/gvd.c */

/** Game loops since the end of the captured stage's load (-1: not there). */
static int loop(void)
{
    return s_InStage && s_BaseSet ? GV_Time - s_Base : -1;
}

/** NewLoader (game/loader.c): the captured stage starts loading. */

void Capture_Stage(const char* dir)
{
    load();
    if (s_LiveCount && strcmp(dir, s_Stage) == 0)
    {
        printf("capture: stage %s (GV_Time %d, GV_Clock %d)\n", dir, GV_Time, GV_Clock);
    }
    s_InStage = s_LiveCount && strcmp(dir, s_Stage) == 0;
    s_BaseSet = 0;
}

/** The loader's Die (game/loader.c): loops count from the end of the load. */
void Capture_LoadEnd(void)
{
    if (s_InStage)
    {
        printf("capture: load end (GV_Time %d)\n", GV_Time);
        s_Base    = GV_Time;
        s_BaseSet = 1;
        s_HoldClock = s_Ticks && s_Ps1Clock >= 0 && GV_Clock != s_Ps1Clock;
    }
}

/** FS_StreamTickStart: the loop count becomes the PS1's at its tick start. */
void Capture_TickStart(void)
{
    if (loop() >= 0 && s_TickStart >= 0)
    {
        printf("capture: stream tick start at loop %d, the PS1's at %d\n", loop(), s_TickStart);
        s_Base = GV_Time - s_TickStart;
    }
}

/** gvd.c: whether GV_Clock skips this flip (once, after the load, to match the PS1's double-buffer parity). */
int Capture_HoldClock(void)
{
    if (!s_HoldClock)
    {
        return 0;
    }
    s_HoldClock = 0;
    printf("capture: GV_Clock flip skipped (the PS1's parity)\n");
    return 1;
}

/** strctrl.c: the stream's clock starts at the PS1's loop (the wait for the stream's data is the CD's). */
int Capture_StreamMayStart(void)
{
    return !s_Ticks || !s_InStage || s_TickStart < 0 || loop() >= s_TickStart;
}

/** FS_StreamGetTick: the PS1's tick in this loop, if recorded. */
int Capture_Tick(int* tick)
{
    int n = loop();
    if (!s_Ticks || n < 0 || n >= MAX_TICKS || s_Ticks[n] < 0)
    {
        return 0;
    }
    *tick = s_Ticks[n];
    return 1;
}

/** The first live frame not captured yet that loop `n` has reached (-1: none). */
static int pending(int n)
{
    int i, best = -1;
    for (i = 0; i < s_LiveCount; i++)
    {
        if (!s_LiveCaptured[i] && s_Live[i] <= n && (best < 0 || s_Live[i] < s_Live[best]))
        {
            best = i;
        }
    }
    return best;
}

void HalGame_OnDrawOTag(void)
{
    char  name[64];
    FILE* f;
    int   i;
    if (!s_InStage)
    {
        return;
    }
    if (s_Open >= 0)
    {
        /* The open frame's drawing is done (DrawOTag draws before it returns): its VRAM. */
        static unsigned short band[32 * 1024] __attribute__((aligned(64)));
        int                   row;
        fclose(s_Packets);
        s_Packets = NULL;
        sprintf(name, "host:cap/ps2_%d_vram.bin", s_Open);
        if ((f = fopen(name, "wb")))
        {
            for (row = 0; row < 512; row += 32)
            {
                GpuGs_StoreImage(0, row, 1024, 32, band);
                fwrite(band, 2, 32 * 1024, f);
            }
            fclose(f);
        }
        printf("capture: frame %d\n", s_Open);
        s_Open = -1;
        if (++s_LiveDone == s_LiveCount)
        {
            printf("capture: all frames done\n");
        }
    }
    if ((i = pending(loop())) >= 0)
    {
        s_LiveCaptured[i] = 1;
        sprintf(name, "host:cap/ps2_%d_gp0.bin", s_Live[i]);
        if ((s_Packets = fopen(name, "wb")))
        {
            s_Open = s_Live[i];
        }
        printf("capture: frame %d: loop %d (GV_Clock %d)\n", s_Live[i], loop(), GV_Clock);
    }
}

void HalGame_OnPacket(const unsigned int* words, int count)
{
    if (s_Packets)
    {
        unsigned int n = (unsigned int)count;
        fwrite(&n, 4, 1, s_Packets);
        fwrite(words, 4, (size_t)count, s_Packets);
    }
}

static void* read_file(const char* name, int* size)
{
    FILE* f = fopen(name, "rb");
    void* buf;
    if (!f)
    {
        return NULL;
    }
    fseek(f, 0, SEEK_END);
    *size = (int)ftell(f);
    fseek(f, 0, SEEK_SET);
    buf = memalign(64, (size_t)*size);
    if (buf)
    {
        fread(buf, 1, (size_t)*size, f);
    }
    fclose(f);
    return buf;
}

static void replay(int n)
{
    unsigned short* vram;
    unsigned int*   gp0;
    int             size, gsize, pos, row;
    char            name[64];
    FILE*           f;
    sprintf(name, "host:cap/ps1_%d_before.bin", n);
    vram = read_file(name, &size);
    sprintf(name, "host:cap/ps1_%d_gp0.bin", n);
    gp0 = read_file(name, &gsize);
    if (!vram || !gp0 || size != 1024 * 512 * 2)
    {
        printf("capture: replay %d: capture missing\n", n);
        free(vram);
        free(gp0);
        return;
    }
    GpuGs_LoadImage(0, 0, 1024, 512, vram, 1024);
    for (pos = 0; pos < gsize / 4;)
    {
        int           count = (int)gp0[pos];
        unsigned int* w     = gp0 + pos + 1;
        if (w[0] >> 24 == 0xA0)
        {
            /* LoadImage (the capture's own encoding: A0, y:x, h:w, then the pixels) */
            GpuGs_LoadImage(w[1] & 0xFFFF, w[1] >> 16, w[2] & 0xFFFF, w[2] >> 16, (unsigned short*)(w + 3),
                            w[2] & 0xFFFF);
        }
        else
        {
            GpuGs_Commands(w, count);
        }
        pos += 1 + count;
    }
    GpuGs_Flush();
    GpuGs_Sync();
    sprintf(name, "host:cap/ps2r_%d_vram.bin", n);
    if ((f = fopen(name, "wb")))
    {
        for (row = 0; row < 512; row += 32)
        {
            GpuGs_StoreImage(0, row, 1024, 32, vram + row * 1024);
        }
        fwrite(vram, 2, 1024 * 512, f);
        fclose(f);
    }
    printf("capture: replay %d (%d words)\n", n, gsize / 4);
    free(vram);
    free(gp0);
}

void HalGame_OnPutDispEnv(int x, int y, int w, int h)
{
    static int frames;
    int        i;
    (void)x;
    (void)y;
    (void)w;
    (void)h;
    if (++frames != 60)
    {
        return;
    }
    load();
    if (s_ReplayCount == 0)
    {
        return;
    }
    for (i = 0; i < s_ReplayCount; i++)
    {
        replay(s_Replay[i]);
    }
    printf("capture: all frames done\n");
}
