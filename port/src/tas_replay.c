/** @brief TAS replay (docs/TAS Testing Plan.md, Phase 3): the pads the PS1 game read, game loop by game loop.
 *
 * MGS_TAS_PADS=<file> (build/link_ps2.py; made by tools/port/tas/trace_to_pads.py from BizHawk's trace) is
 * copied next to the disc image as tas_pads.bin, and Port_TasInit reads it from host: (likewise MGS_TAS_RAW,
 * MGS_TAS_TIME: tas_raw.bin, tas_time.bin) into the heap: embedded, the 5.6 MB of tables pushed the game's
 * .bss past 16 MB (see port/linkfile). mgs_tas_pads holds records of a little-endian u32 GV_Time and the 64 bytes of GV_PadData[0..3] the PS1
 * game had after GV_UpdatePadSystem in that loop, one record each time they change. Port_TasPads (end of
 * libgv/pad.c's GV_UpdatePadSystem) overwrites GV_PadData with the record for the current GV_Time, so the
 * game sees the PS1's pads however the port's pad and timing differ.
 *
 * With MGS_TAS_TIME too, mgs_tas_time holds 24 bytes per loop from GV_Time 0 (little-endian): the
 * tick the PS1's FS_StreamGetTick returned (s32; 0x80000000: no stream), and the PS1's GM_GameStatus,
 * GM_LoadRequest, GV_PassageTime, rand seed and GV_Clock at the end of the loop. The port's timing then follows the
 * PS1's, so the game loops line up:
 *  - streams (cutscenes, codec voice) run on the PS1's clock (Port_TasTick, from capture_ps2.c's
 *    Capture_Tick) and start in the loop the PS1's did, not when the port's CD has the data
 *    (Port_TasStreamMayStart, from Capture_StreamMayStart);
 *  - the game loop runs during loads, and they take a different number of loops here: when a load has
 *    ended (GM_LoadRequest back to 0 at the end of a loop), GV_Time becomes the loop the PS1's matching
 *    load ended in (the same count of load ends since boot), with the PS1's GV_Clock (the double buffer's
 *    parity) and GV_PassageTime there, in Port_TasTrace;
 *  - GV_PassageTime is the PS1's (Port_TasPassageTime, libgv/gvd.c);
 *  - at the end of the loops a load starts and ends in, the rand seed becomes the PS1's: the title runs a
 *    different number of loops before New Game (the boot's wait isn't a stage load), and a load's own
 *    loops call rand.
 *
 * With MGS_TAS_RAW too, mgs_tas_raw holds the PS1's raw mts pads (pad_800C14E0[0..1], 16 bytes) and
 * pad init states (pad_state_800C14F0[0..1], 8 bytes) as records of a u32 GV_Time and the 24 bytes, one each
 * time they change, as at the loop's vertical blank (just before the game reads them). Port_TasRawPads
 * (the end of mts_pad.c's do_control, in the vertical blank interrupt) puts them in place of the port's pads:
 * the readers that bypass GV_PadData (cancel.c's cutscene skip, gamed.c, movie.c) and
 * mts_get_pad_vibration_type (Psycho Mantis, GM_CONFIG_VIBRATION_OFF) then see the PS1's controller.
 *
 * Port_TasTrace (the end of libgv/gvd.c's Act: GV_Time, GV_Clock and GV_PassageTime are the new loop's, the
 * game state the last loop's, which is where BizHawk's trace samples) writes host:tas_trace.log, one line per
 * loop in tools/port/tas/trace.lua's format (the first field is the port's vertical blank count, not a movie
 * frame), for tools/port/tas/compare_trace.py.
 * Without the define both do nothing. */

#include <stdio.h>
#include <string.h>

#ifdef MGS_TAS
#include <stdlib.h>

static unsigned char* mgs_tas_pads; /* NULL: no table (host: file missing) */
static unsigned int   size_mgs_tas_pads;
static unsigned char* mgs_tas_raw;
static unsigned int   size_mgs_tas_raw;
static unsigned char* mgs_tas_time;
static unsigned int   size_mgs_tas_time;

extern int          GV_Time, GV_Clock, GV_PassageTime, GM_GameStatus, GM_AlertMode, GM_LoadRequest;
extern int          DG_UnDrawFrameCount;
extern short        linkvarbuf[96];
extern unsigned char GV_PadData[64], pad_800C14E0[16], GM_PlayerPosition[8];
extern int          GM_PlayerStatus;
extern void*        GM_PlayerControl;
extern char*        GM_GetArea(int flag);
extern int          mts_get_tick_count(void);
extern unsigned int Hal_RandSeed(void);
extern void         srand(unsigned int seed);

#define RECORD 68
#define NO_TICK 0x80000000u
#define STATE_VOX_STREAM 0x20

#define TIME_RECORD 24
#define MAX_LOADS 4096

/** A host: file into the heap (NULL if missing). */
static unsigned char* load(const char* name, unsigned int* size)
{
    FILE*          f = fopen(name, "rb");
    unsigned char* data;
    long           n;
    if (!f)
    {
        printf("tas: no %s\n", name);
        return 0;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    data = malloc(n > 0 ? n : 1);
    if (!data || fread(data, 1, n, f) != (size_t)n)
    {
        printf("tas: reading %s failed\n", name);
        free(data);
        fclose(f);
        return 0;
    }
    fclose(f);
    *size = (unsigned int)n;
    return data;
}

static unsigned int read_u32(const unsigned char* p)
{
    return p[0] | p[1] << 8 | p[2] << 16 | (unsigned int)p[3] << 24;
}

static void hex(FILE* f, const void* data, int n)
{
    static const char digits[] = "0123456789abcdef";
    const unsigned char* p = data;
    char buf[512];
    int  i;
    for (i = 0; i < n; i++)
    {
        buf[i * 2]     = digits[p[i] >> 4];
        buf[i * 2 + 1] = digits[p[i] & 15];
    }
    buf[n * 2] = ' ';
    fwrite(buf, 1, n * 2 + 1, f);
}
#endif

#ifdef MGS_TAS
static int s_LoadEnded; /* a load started or ended in this loop: the seed becomes the PS1's at its end */

/** The PS1's record for loop `time`, or NULL without one. */
static const unsigned char* time_record_at(int time)
{
    if (!mgs_tas_time || time < 0 || (unsigned int)time >= size_mgs_tas_time / TIME_RECORD)
    {
        return 0;
    }
    return mgs_tas_time + time * TIME_RECORD;
}

static const unsigned char* time_record(void)
{
    return time_record_at(GV_Time);
}
#endif

int Port_TasTick(int* tick)
{
#ifdef MGS_TAS
    const unsigned char* r = time_record();
    if (!r || read_u32(r) == NO_TICK)
    {
        return 0;
    }
    *tick = (int)read_u32(r);
    return 1;
#else
    (void)tick;
    return 0;
#endif
}

/** -1: no TAS timing (the caller decides); 0/1: whether the PS1 had started its stream by this loop. */
int Port_TasStreamMayStart(void)
{
#ifdef MGS_TAS
    const unsigned char* r = time_record();
    if (!mgs_tas_time)
    {
        return -1;
    }
    return r && (read_u32(r + 4) & STATE_VOX_STREAM) ? 1 : 0;
#else
    return -1;
#endif
}

/** loader.c's NewLoader and Die: a load starts or has ended. */
void Port_TasLoadEnd(void)
{
#ifdef MGS_TAS
    s_LoadEnded = 1;
#endif
}

/** gvd.c, after GV_PassageTime is measured: the PS1's. */
void Port_TasPassageTime(void)
{
#ifdef MGS_TAS
    const unsigned char* r = time_record();
    if (r)
    {
        GV_PassageTime = (int)read_u32(r + 12);
    }
#endif
}

/** mts_pad.c's do_control (vertical blank interrupt: no C library calls). */
void Port_TasRawPads(void* pads, void* states)
{
#ifdef MGS_TAS
    static unsigned int  next;
    unsigned int         count, time = (unsigned int)GV_Time, i;
    const unsigned char* r;
    if (!mgs_tas_raw || (count = size_mgs_tas_raw / 28) == 0 || time < read_u32(mgs_tas_raw))
    {
        return;
    }
    while (next + 1 < count && read_u32(mgs_tas_raw + (next + 1) * 28) <= time)
    {
        next++;
    }
    while (next > 0 && read_u32(mgs_tas_raw + next * 28) > time)
    {
        next--;
    }
    r = mgs_tas_raw + next * 28 + 4;
    for (i = 0; i < 16; i++)
    {
        ((unsigned char*)pads)[i] = r[i];
    }
    for (i = 0; i < 8; i++)
    {
        ((unsigned char*)states)[i] = r[16 + i];
    }
#else
    (void)pads, (void)states;
#endif
}

void Port_TasPads(void)
{
#ifdef MGS_TAS
    static unsigned int next;
    unsigned int        count = size_mgs_tas_pads / RECORD, time = (unsigned int)GV_Time;
    if (!mgs_tas_pads || count == 0 || time < read_u32(mgs_tas_pads))
    {
        return;
    }
    while (next + 1 < count && read_u32(mgs_tas_pads + (next + 1) * RECORD) <= time)
    {
        next++;
    }
    while (next > 0 && read_u32(mgs_tas_pads + next * RECORD) > time)
    {
        next--;
    }
    memcpy(GV_PadData, mgs_tas_pads + next * RECORD + 4, 64);
#endif
}

#ifdef MGS_TAS
static FILE* s_Trace;
static int   s_Ps1Loads;
static int   s_Ps1LoadEnd[MAX_LOADS]; /* the PS1's load ends: the loops whose line has GM_LoadRequest back to 0 */
#endif

/** HalGame_Init, before the game starts: the file and the table scan here, not in a game loop (a few
 * milliseconds after the GV_Clock flip let the HAL draw an ordering table not yet built: TLB misses in
 * DrawOTagImpl). */
void Port_TasInit(void)
{
#ifdef MGS_TAS
    int t, prev = 0, n;
    mgs_tas_pads = load("host:tas_pads.bin", &size_mgs_tas_pads);
    mgs_tas_raw  = load("host:tas_raw.bin", &size_mgs_tas_raw);
    mgs_tas_time = load("host:tas_time.bin", &size_mgs_tas_time);
    n            = mgs_tas_time ? (int)(size_mgs_tas_time / TIME_RECORD) : 0;
    for (t = 0; t < n && s_Ps1Loads < MAX_LOADS; t++)
    {
        int request = (int)read_u32(mgs_tas_time + t * TIME_RECORD + 8);
        if (prev && !request)
        {
            s_Ps1LoadEnd[s_Ps1Loads++] = t;
        }
        prev = request;
    }
    s_Trace = fopen("host:tas_trace.log", "w");
    printf("tas: replay, %d PS1 load ends, trace %s\n", s_Ps1Loads, s_Trace ? "host:tas_trace.log" : "unavailable");
#endif
}

void Port_TasTrace(void)
{
#ifdef MGS_TAS
    static int           loads, prev_request, traced = -1;
    FILE*                f = s_Trace;
    const char*          stage;
    const unsigned char* r;
    if (GV_Time == traced)
    {
        return; /* once per loop */
    }
    if (prev_request && !GM_LoadRequest && loads < s_Ps1Loads)
    {
        if (GV_Time != s_Ps1LoadEnd[loads])
        {
            printf("tas: load end %d at loop %d, the PS1's at %d\n", loads, GV_Time, s_Ps1LoadEnd[loads]);
            GV_Time = s_Ps1LoadEnd[loads];
        }
        if ((r = time_record()) != 0)
        {
            GV_PassageTime = (int)read_u32(r + 12);
            GV_Clock       = (int)read_u32(r + 20);
        }
        loads++;
        s_LoadEnded = 1;
    }
    prev_request = GM_LoadRequest;
    r            = time_record();
    if (s_LoadEnded && r)
    {
        srand(read_u32(r + 16));
    }
    s_LoadEnded = 0;
    traced      = GV_Time;
    if (!f)
    {
        return;
    }
    stage = GM_GetArea(0);
    fprintf(f, "%d %d %d %d %08x %08x %.8s ", mts_get_tick_count(), GV_Time, GV_Clock, GV_PassageTime,
            GM_GameStatus, Hal_RandSeed(), stage && stage[0] ? stage : "-");
    hex(f, GV_PadData, 64);
    hex(f, pad_800C14E0, 16);
    hex(f, GM_PlayerPosition, 8);
    fprintf(f, "%d %d %d ", GM_AlertMode, GM_LoadRequest, DG_UnDrawFrameCount);
    hex(f, linkvarbuf, 192);
    /* trace_debug.lua's fields: the 4 BizHawk-only ones (stream clock, pad states) as "-", then
       GM_PlayerStatus and Snake's CONTROL (124 bytes) */
    fprintf(f, "- - - - %08x ", GM_PlayerStatus);
    if (GM_PlayerControl)
    {
        hex(f, GM_PlayerControl, 124);
    }
    else
    {
        fputs("- ", f);
    }
    fputc('\n', f);
    if ((GV_Time & 63) == 0)
    {
        fflush(f);
    }
#endif
}
