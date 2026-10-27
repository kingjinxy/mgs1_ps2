#include "mgstype.h"
#include "mts/mts.h"

#include "game.h"
#include "charadef.h"
#include "libgcl/libgcl.h"

extern CHARA MainCharacterEntries[];    /* in main.c */
extern CHARA _StageCharacterEntries[];  /* only visible when built-in */

// force gp usage
void *SECTION(".sbss") StageCharacterEntries;

void GM_InitChara(void)
{
#ifdef DEV_EXE
    StageCharacterEntries = &_StageCharacterEntries[0];
#else
    extern void *mts_get_bss_tail(void);
    StageCharacterEntries = mts_get_bss_tail();
#endif
}

#ifdef MGS_PORT
#include <stdio.h>

/* PS2 port: the overlays are linked in (build/overlays_ps2.py), so the stage's CHARA table is the linked
 * one of that stage, not the copy of its binary at StageCharacterEntries (which still receives the read:
 * libfs/cdstage.c). Port_Stages: generated, by stage name. */
extern struct
{
    const char *name;
    CHARA      *charas;
} Port_Stages[];

static CHARA  port_no_charas[1];
static CHARA *port_stage_charas = port_no_charas;

/* The overlay loader (GM_LoadInitBin): id's low 16 bits are the stage name's GV_StrCode. */
void Port_SetStage(int id)
{
    int i;

    for (i = 0; Port_Stages[i].name; i++)
    {
        if ((GV_StrCode(Port_Stages[i].name) & 0xFFFF) == (id & 0xFFFF))
        {
            printf("port: stage %s\n", Port_Stages[i].name);
            port_stage_charas = Port_Stages[i].charas;
            return;
        }
    }

    printf("port: stage binary %X is not linked in\n", id);
    port_stage_charas = port_no_charas;
}
#endif

void GM_ResetChara(void)
{
#ifdef MGS_PORT
    port_stage_charas = port_no_charas;
#elif !defined(DEV_EXE)
    CHARA *chara;

    chara = (CHARA *)StageCharacterEntries;
    // overwrite the first entry with the end-of-table marker
    *((int *)&chara->func) = 0;
    *((int *)&chara->class_id) = 0;
#endif
}

void *GM_GetChara(unsigned char *script)
{
    return GM_GetCharaID(GCL_StrToInt(script));
}

void *GM_GetCharaID(int chara_id)
{
    CHARA *chara;
    int    i;

    for (i = 0; i < 2; i++)
    {
        // First, search the built-in charas
        chara = &MainCharacterEntries[0];
        if (i != 0)
        {
            // chara_id wasn't found in the main binary's built-ins,
            // so now we'll search the stage overlay's chara table.
#ifdef MGS_PORT
            chara = port_stage_charas;
#else
            chara = (CHARA *)StageCharacterEntries;
#endif
        }

        for (; chara->func != NULL; chara++)
        {
            if (chara->class_id == chara_id)
            {
                return chara->func;
            }
        }
    }

    return NULL;
}
