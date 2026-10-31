#include "ps1align.h"
#include "zako.h"

#include <stdio.h>
#include "mgstype.h"
#include "game/game.h"
#include "game/item.h"
#include "libdg/libdg.h"
#include "libgcl/libgcl.h"
#include "okajima/blood.h"
#include "mts/mts.h" // for fprintf

extern int s03d_dword_800C39B0;
extern int s03d_dword_800C39B8;
extern int s03d_dword_800C39C0;
extern int s03d_dword_800C39C8;
extern int s03d_dword_800C3A90[];
extern int s03d_dword_800C3A64;
extern int s03d_dword_800C3A6C;
extern int s03d_dword_800C3A84;
extern int s03d_dword_800C3A88;
extern int s03d_dword_800C3A74;
extern int s03d_dword_800C3A7C;
extern short s03d_word_800C39F0[2];
extern int s03d_dword_800C39F4;
extern short s03d_word_800C3A00[2];
extern int s03d_dword_800C3A04;
extern int s03d_dword_800C3A08;
extern int s03d_dword_800C3A0C;
extern int s03d_dword_800C39E0;
extern int s03d_dword_800C39FC;
extern short s03d_word_800C3A38[2];
extern short s03d_word_800C3A3C[2];
extern short s03d_word_800C39E8[2];
extern short s03d_word_800C39EC[2];
extern int s03d_dword_800DC310;
extern SVECTOR s03d_dword_800C3B88;
extern int s03d_dword_800C3A5C;
extern short s03d_word_800C3A10[20];
extern const SVECTOR s03d_dword_800DB548;
extern const SVECTOR s03d_dword_800DB550;
extern const SVECTOR s03d_dword_800DB558;

extern int s03d_dword_800DC2F8;
extern int s03d_dword_800DC2F4;

void AN_Fog(SVECTOR *svec);

void s03d_800D01C4(struct _Work *work, int arg);
void s03d_800D0324(struct _Work *work, int arg);
void s03d_800CF68C(struct _Work *work, int arg);
void s03d_800CE12C(struct _Work *work, int arg);
void s03d_800CF548(struct _Work *work, int arg);
void s03d_800CEE3C(struct _Work *work, int arg);
void s03d_800CF194(struct _Work *work, int arg);
void Zako_800D0BEC(Work *work, int type);
void Zako_800D0B18(Work *work, int index, int count);
void Zako_800D0B88(Work *work);
int  s03d_800CDE1C(Work *work);
void s03d_800CE720(struct _Work *work, int arg);
int  Zako_800D0EF0(Work *work, int index);
void s03d_800CDB5C(Work *work);
int  s03d_800CC4EC(Work *work, int arg);
void s03d_800CC984(Work *work);
int  s03d_800CD61C(Work *work);
int  s03d_800CD75C(Work *work);
int  s03d_800CD984(Work *work);
void s03d_800D041C(Work *work);
void s03d_800D14AC(Work *work);
void s03d_800CFB04(Work *work, int arg);

static inline void SetAction(Work *work, int action, int interp)
{
    work->field_8E0 = action;
    GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[action], 0, interp);
}

static inline void SetMode(Work *work, void (*fn)(Work *, int))
{
    work->field_8E8 = fn;
    work->field_8F0 = 0;
    work->control.turn.vz = 0;
    work->control.turn.vx = 0;
    GM_ConfigMotionAdjust(&work->body, 0);
}

static inline void SetMode2(Work *work, void (*fn)(Work *, int))
{
    if (!work->field_8EC)
    {
        work->field_8EC = (int)fn;
        work->field_8F4 = 0;
    }

    work->control.turn.vz = 0;
    work->control.turn.vx = 0;
    GM_ConfigMotionAdjust(&work->body, 0);
}

static inline void SetModeFields(Work *work, void (*fn)(Work *, int))
{
    work->field_8E8 = fn;
    work->field_8F0 = 0;
    work->control.turn.vz = 0;
    work->control.turn.vx = 0;
}

void s03d_800D13F8(Work *work);
void s03d_800D3B5C(Work *work);
void s03d_800D153C(Work *work);
void ZakoCom_800D4050(int idx);

void Zako_800CCAB0(DG_OBJS *objs, DG_DEF *def)
{
    DG_OBJ *obj;
    int i;

    DG_FreeObjsPacket(objs, 0);
    DG_FreeObjsPacket(objs, 1);

    objs->def = def;
    obj = objs->objs;
    for (i = 0; i < 16; i++)
    {
        obj->model = &def->models[i];
        obj->n_packs = def->models[i].n_faces;
        obj++;
    }
}

void s03d_800CCB2C(Work *work)
{
    if (work->field_B00 != 0)
    {
        if ( GM_GameStatus & STATE_CAM_CHANGE || GM_Camera.first_person )
        {
            if (work->lod != 1)
            {
                work->lod = 1;
                Zako_800CCAB0(work->body.objs, work->models[1]);
            }
        }
        else
        {
            if (work->lod != 0)
            {
                work->lod = 0;
                Zako_800CCAB0(work->body.objs, work->models[0]);
            }
        }

        DG_VisibleObjs(work->body.objs);
        DG_VisibleObjs(work->weapon.objs);
        *work->enable_shadow = 1;
        *work->enable_glight = 1;
    }
    else
    {
        DG_InvisibleObjs(work->body.objs);
        DG_InvisibleObjs(work->weapon.objs);
        *work->enable_shadow = 0;
        *work->enable_glight = 0;
    }
}

void s03d_800CCC54(Work *work)
{
    CONTROL *control;

    control = &work->control;

    GM_ActControl(control);
    GM_ActObject2(&work->body);

    DG_GetLightMatrix2(&control->mov, work->light);

    s03d_800D153C(work);
    GM_MoveTarget(work->field_8FC, &control->mov);

    if (s03d_dword_800DC2F8 == 13 && ZAKOCOM_MGR->entries[work->param.fAF8].field_4 == 1)
    {
        GV_DestroyActor(work);
    }

    s03d_800CCB2C(work);
}

void Zako_800CCCF4(Work *work)
{
    TARGET *t = work->field_8FC;
    int     b14 = work->param.life;
    int     b16 = work->param.faint;

    GM_SetTarget(t, 0x9E, 2, (SVECTOR *)&s03d_dword_800C39B0);
    GM_SetPowerTarget(t, 1, -1, b14, b16, (SVECTOR *)&s03d_dword_800C39B8);
    GM_SetCaptureTarget(t, -1, b16, NULL, NULL);
    GM_SetC4Target(t, &work->body.objs->objs[1].world);
    GM_SetTarget(&work->field_900, 4, 1, (SVECTOR *)&s03d_dword_800C39C0);
    GM_SetPowerTarget(&work->field_900, 7, 5, 0, 3, (SVECTOR *)&s03d_dword_800C39C8);
}
void Zako_800CCDE0(Work *work)
{
    short *p = (short *)&work->field_8C8;

    GV_ZeroMemory(p, 0x20);
    work->field_8C8 = 0;
    p[0x0D] = 0x1C2;
    p[0x0E] = 1;
    work->field_8E8 = 0;
    work->field_8EC = 0;
    work->field_8F0 = 0;
    work->field_8F4 = 0;
}

extern const char s03d_dword_800DB3C4[]; /* "ippanhei" */
extern const char s03d_dword_800DB3D0[]; /* "enemy" */
extern const char s03d_dword_800DB3D8[]; /* "famas" */
void *NewShadow2(CONTROL *control, OBJECT *parent, SVECTOR indices, int **enabled);
void *NewGunLight(MATRIX *world, int **pvisible);
int   Zako_800D0EF0(Work *work, int index);

int s03d_800CCE3C(Work *work, int name, int where)
{
    SVECTOR  indices;
    CONTROL *control;
    OBJECT  *body;
    OBJECT  *weapon;
    int      i;

    control = &work->control;
    if (GM_InitControl(control, name, where) < 0)
    {
        return -1;
    }

    GM_ConfigControlString(control, GCL_GetOption('p'), GCL_GetOption('d'));
    GM_ConfigControlAttribute(control, RADAR_VISIBLE | RADAR_SIGHT);
    GM_ConfigControlInterp(control, 4);

    body = &work->body;
    weapon = &work->weapon;

    GM_InitObject(body, GV_StrCode((char *)s03d_dword_800DB3C4), 0x32D, GV_StrCode((char *)s03d_dword_800DB3D0));
    GM_ConfigObjectJoint(body);
    GM_ConfigMotionControl(body, &work->m_ctrl, GV_StrCode((char *)s03d_dword_800DB3D0), work->m_segs1, work->m_segs2,
                           control, work->rots);
    GM_ConfigObjectLight(body, work->light);

    work->models[1] = work->body.objs->def;
    work->models[0] = GV_GetCache(GV_CacheID(3127, 'k'));
    work->lod = 1;

    work->hom = GM_SetHomingTarget(&work->body.objs->objs[6].world, control);

    GM_InitObject(weapon, GV_StrCode((char *)s03d_dword_800DB3D8), 109, 0);
    GM_ConfigObjectLight(weapon, work->light);
    GM_ConfigObjectRoot(weapon, body, 4);

    for (i = 0; i < 0; i++)
    {
    }

    indices.vx = 0;
    indices.vy = 6;
    indices.vz = 12;
    indices.pad = 15;
    work->shadow = NewShadow2(control, body, indices, &work->enable_shadow);
    work->glight = NewGunLight(&body->objs->objs[4].world, &work->enable_glight);

    Zako_800D0EF0(work, 0);
    Zako_800CCDE0(work);
    return 0;
}

void s03d_800CD054(Work *work)
{
    ZakoCom_800D4050(work->param.fAF8);
    GM_FreeControl(&work->control);
    GM_FreeObject(&work->body);
    GM_FreeObject(&work->weapon);
    GM_FreeTarget(work->field_8FC);
    GV_DestroyActor(work->glight);
    GV_DestroyActor(work->shadow);
    GM_ResetHomingTarget(work->hom);
}

int s03d_800CD0C8(Work *work)
{
    PARAM   *param;
    HZD_PAT *patrol;
    HZD_PTP *points;
    int      i;

    param = &work->param;

    patrol = work->control.map->hzd->def->routes;
    patrol += param->roots[param->c_root];

    work->n_nodes = patrol->n_points;

    if (work->n_nodes <= 0)
    {
        return -1;
    }

    points = patrol->points;
    for (i = 0; i < work->n_nodes; i++)
    {
        work->nodes[i].vx = points->x;
        work->nodes[i].vy = points->y;
        work->nodes[i].vz = points->z;
        work->nodes[i].pad = points->command;
        points++;
    }
    return 0;
}

int Zako_800CD16C(char *opt, char *out)
{
    int count = 0;
    char *str;

    while ((str = GCL_NextStr()) != NULL)
    {
        *out++ = GCL_StrToInt(str);
        count++;
    }
    return count;
}

extern const char s03d_dword_800DB3E0[]; /* "Err not enough work !!\n" */
extern const char s03d_dword_800DB3F8[]; /* "Err Err Err Change Root Num Over !!\n" */
extern const char s03d_dword_800DB420[]; /* "Err Err Err Change Defend Num Over !!\n" */
extern const char s03d_dword_800DB448[]; /* "Life=%d Faint=%d Blood=%c Area=%c \n" */
extern const char s03d_dword_800DB46C[]; /* "watchar.c : action point Err\n" */
extern int        s03d_dword_800C39A8;
extern int        GM_CurrentMap;
int  ZakoCom_800D3FF4(Work *work);
int  ZakoCom_800D4038(void);

void s03d_800CD1C4(Work *work, int name, int where)
{
    char *opt;
    int   addr, i;

    s03d_800CCE3C(work, name, where);

    work->param.fAF8 = ZakoCom_800D3FF4(work);
    if (work->param.fAF8 < 0)
    {
        fprintf(0, (char *)s03d_dword_800DB3E0);
    }

    work->field_B04 = ZakoCom_800D4038();

    work->param.roots[0] = 0;
    work->param.c_root = 0;
    opt = GCL_GetOption('r');
    if (opt)
    {
        if (Zako_800CD16C(opt, work->param.roots) >= 4)
        {
            fprintf(0, (char *)s03d_dword_800DB3F8);
        }
    }

    switch (work->param.fAF8)
    {
    case 0:
        work->field_B64 = 3000;
        break;
    case 1:
        work->field_B64 = 4000;
        break;
    case 2:
        work->field_B64 = 7000;
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        work->field_B64 = 8000;
        break;
    }

    work->param.life = 192;
    opt = GCL_GetOption('l');
    if (opt)
    {
        work->param.life = GCL_StrToInt(opt);
    }

    work->param.faint = 255;
    opt = GCL_GetOption('f');
    if (opt)
    {
        work->param.faint = GCL_StrToInt(opt);
    }

    work->param.field_B18 = 40;
    opt = GCL_GetOption('z');
    if (opt)
    {
        work->param.field_B18 = GCL_StrToInt(opt);
    }

    work->param.fAF9 = 'A';
    opt = GCL_GetOption('b');
    if (opt)
    {
        work->param.fAF9 = GCL_StrToInt(opt);
    }

    work->param.defends[work->param.c_root] = 255;
    opt = GCL_GetOption('n');
    if (opt)
    {
        if (Zako_800CD16C(opt, work->param.defends) >= 4)
        {
            fprintf(0, (char *)s03d_dword_800DB420);
        }
    }

    work->param.fAFA = 'A';
    opt = GCL_GetOption('a');
    if (opt)
    {
        work->param.fAFA = GCL_StrToInt(opt);
    }

    if (work->param.fAFA == 'S')
    {
        Zako_800D0EF0(work, 1);
    }

    fprintf(0, (char *)s03d_dword_800DB448, work->param.life, work->param.faint, work->param.fAF9, work->param.fAFA);

    if (s03d_800CD0C8(work) < 0)
    {
        fprintf(1, (char *)s03d_dword_800DB46C);
    }

    work->field_8FC = GM_AllocTarget();
    if (work->field_8FC)
    {
        Zako_800CCCF4(work);
    }

    work->field_AC8 = 0;
    work->field_ACA = 0;
    work->field_ACC = 0;
    work->field_ACE = 0;
    work->field_AD0 = 0;
    work->field_AD4 = 0;

    work->field_B48 = work->nodes[0];
    work->field_B5C = HZD_GetAddress(work->control.map->hzd, &work->field_B48, -1);
    work->field_B22 = 512;
    work->field_B24 = 4000;
    work->field_B28 = 0;
    work->field_B20 = 0;
    work->field_AE8 = 0;
    work->field_AE4 = 0;
    work->field_B60 = GM_CurrentMap;
    work->field_B34 = *(SVECTOR *)&s03d_dword_800C39A8;
    work->field_AF0 = 0;
    work->control.mov = work->nodes[0];
    work->field_AF6 = 0;
    work->field_AF8 = 0;
    work->field_B00 = 1;
    work->field_BA0 = 0;

    for (i = 0; i < 8; i++)
    {
        work->field_B2C[i] = 0;
    }

    work->field_B33 = 0x17;
    ((signed char *)work->field_B2C)[4] = -1;

    GM_ConfigControlRadarparam(&work->control, 0, 512, 4000, 0);

    work->field_B40 = work->nodes[0];
    work->field_B54 = GM_CurrentMap;

    addr = HZD_GetAddress(work->control.map->hzd, &work->control.mov, -1);
    work->field_B50 = addr;
    work->field_B74 = addr;
    work->field_B58 = addr;
    work->field_B80 = work->field_B40;
}

/* rodata after this function's jump table (0x800DB48C), from overlay2.c */
const char s03d_dword_800DB4AC[] STR_PIECE = {'z', 'a', 'k', 'o'};
const char s03d_dword_800DB4B0[] STR_PIECE = {'.', 'c', 0x0, 0x8f};
const char s03d_dword_800DB4B4[] STR_PIECE = {' ', 'm', 'e', 'r'};
const char s03d_dword_800DB4B8[] STR_PIECE = {'y', 'l', ' ', 'K'};
const char s03d_dword_800DB4BC[] STR_PIECE = {'I', 'L', 'L', 'E'};
const char s03d_dword_800DB4C0[] STR_PIECE = {'D', ' ', '!', '!'};
const char s03d_dword_800DB4C4[] STR_PIECE = {'!', ' ', '\n', 0x0};
const char s03d_dword_800DB4C8[] STR_PIECE = {' ', 'S', 'N', 'A'};
const char s03d_dword_800DB4CC[] STR_PIECE = {'K', 'E', ' ', 'K'};
const char s03d_dword_800DB4D0[] STR_PIECE = {'I', 'L', 'L', 'E'};
const char s03d_dword_800DB4D4[] STR_PIECE = {'D', ' ', '!', '!'};
const char s03d_dword_800DB4D8[] STR_PIECE = {'!', ' ', '\n', 0x0};

void *NewZako_800CD5A0(int name, int where)
{
    Work *work;

    work = GV_NewActor(4, sizeof(Work));
    if (work != NULL)
    {
        GV_SetNamedActor(&work->actor, (GV_ACTFUNC)s03d_800CCC54, (GV_ACTFUNC)s03d_800CD054,
                         (char *)s03d_dword_800DB4AC);
        s03d_800CD1C4(work, name, where);
    }

    return (void *)work;
}

int s03d_800CD61C(Work *work)
{
    TARGET *t = work->field_8FC;

    if (t->damaged & TARGET_CAPTURE)
    {
        if (t->a_mode == 0x24)
        {
            work->field_8E8 = s03d_800CEE3C;
            work->field_8F0 = 0;
            work->control.turn.vz = 0;
            work->control.turn.vx = 0;
            GM_ConfigMotionAdjust(&work->body, 0);
            t->damaged = 0;
        }
        else
        {
            work->field_8E8 = s03d_800CF194;
            work->field_8F0 = 0;
            work->control.turn.vz = 0;
            work->control.turn.vx = 0;
            GM_ConfigMotionAdjust(&work->body, 0);
            t->damaged = 0;
        }
        return 1;
    }
    return 0;
}
int Zako_800CD6A8(Work *work)
{
    TARGET *t = work->field_8FC;

    if (t->damaged & 4)
    {
        if (t->a_mode == 1)
        {
            t->force = DG_ZeroVector;
            if (t->vital <= 0)
            {
                return 1;
            }
        }
        t->damage = 0;
        t->damaged = 0;
    }
    return 0;
}
int Zako_800CD720(SVECTOR *vec)
{
    int x = vec->vx;
    int y = vec->vy;
    int z = vec->vz;

    return ABS(x) + ABS(y) + ABS(z);
}
extern const char s03d_dword_800DB4B4[];
extern const char s03d_dword_800DB4C8[];
int  Zako_800CD720(SVECTOR *vec);
void s03d_800CFA04(Work *work, int arg);
void s03d_800CF4D4(Work *work, int arg);

int s03d_800CD75C(Work *work)
{
    short   val;
    TARGET *target;

    target = work->field_8FC;
    if (!(target->damaged & TARGET_POWER))
    {
        return 0;
    }

    val = target->a_mode - 1;
    switch (val)
    {
    case 2:
        target->force = DG_ZeroVector;
        if (target->faint <= 0)
        {
            work->field_8DC = 1;
            SetMode(work, s03d_800CFB04);
        }
        else
        {
            SetMode(work, s03d_800CFA04);
        }
        break;
    case 3:
        work->field_8DC = 0;
        SetMode(work, s03d_800CFB04);
        break;
    case 0:
        target->force = DG_ZeroVector;
        if (target->vital <= 0)
        {
            if (target->vital != work->field_BA2 - 64)
            {
                work->field_BA0 = 1;
                printf((char *)s03d_dword_800DB4B4);
            }
            else
            {
                printf((char *)s03d_dword_800DB4C8);
            }
            work->field_8DC = 1;
            SetMode(work, s03d_800CFB04);
        }
        else
        {
            SetMode(work, s03d_800CFA04);
        }
        break;
    case 1:
        if (Zako_800CD720(&target->force) < 100)
        {
            work->field_8DC = 3;
        }
        else
        {
            work->field_8DC = 2;
        }
        SetMode(work, s03d_800CFB04);
        break;
    case 4:
        work->field_8DC = 3;
        SetMode(work, s03d_800CFB04);
        break;
    case 7:
        SetMode(work, s03d_800CF4D4);
        break;
    case 8:
        SetMode(work, s03d_800CF548);
        break;
    }

    target->damage = 0;
    target->damaged = 0;
    return 1;
}

/* rodata after this function's jump table (0x800DB4DC), from overlay2.c */
const char    s03d_dword_800DB500[36] = "aaa reset wait zone id = %d z=%d\n";
const char    s03d_dword_800DB524[36] = "bbb reset fight zone id = %d z=%d\n";
const SVECTOR s03d_dword_800DB548 = {-200, 1000, 600, 0};
const SVECTOR s03d_dword_800DB550 = {5, 0, 100, 0};
const SVECTOR s03d_dword_800DB558 = {400, 1000, 400, 0};
const int     s03d_dword_800DB560 = 0;
int s03d_800CD984(Work *work)
{
    if (work->control.mov.vx < 0x1194)
    {
        return 0;
    }
    if (work->control.mov.vz >= 0xBB9 || !(GM_GameStatus & 2))
    {
        return 0;
    }

    work->field_8E8 = s03d_800CF548;
    work->field_8F0 = 0;
    work->control.turn.vz = 0;
    work->control.turn.vx = 0;
    GM_ConfigMotionAdjust(&work->body, 0);
    return 1;
}
int Zako_800CDA04(Work *work)
{
    int a = s03d_800CD61C(work);
    int b = s03d_800CD75C(work);
    int c = s03d_800CD984(work);

    if (a | b | c)
    {
        work->field_8FC->class = 1;
        return 1;
    }
    return 0;
}
void Zako_800CDA70(Work *work)
{
    TARGET *t = work->field_8FC;
    int     b14 = work->param.life;
    int     b16 = work->param.faint;

    GM_SetTarget(t, 0x9E, 2, (SVECTOR *)&s03d_dword_800C39B0);
    GM_SetPowerTarget(t, 1, -1, b14, b16, (SVECTOR *)&s03d_dword_800C39B8);
    GM_SetCaptureTarget(t, -1, b16, NULL, NULL);
    GM_SetC4Target(t, &work->body.objs->objs[1].world);
    GM_SetTarget(&work->field_900, 4, 1, (SVECTOR *)&s03d_dword_800C39C0);
    GM_SetPowerTarget(&work->field_900, 7, 5, 0, 3, (SVECTOR *)&s03d_dword_800C39C8);
}
extern const char s03d_dword_800DB500[]; /* "aaa reset wait zone id = %d z=%d\n" */
extern const char s03d_dword_800DB524[]; /* "bbb reset fight zone id = %d z=%d\n" */
int ZakoCom_800D4038(void);

void s03d_800CDB5C(Work *work)
{
    CONTROL *control;
    HZD_ZON *zone;
    int      z;
    short    zz;

    control = &work->control;

    work->field_B04 = ZakoCom_800D4038();
    work->field_B00 = 1;
    GM_ConfigControlAttribute(control, RADAR_VISIBLE | RADAR_SIGHT | RADAR_ALL_MAP);
    Zako_800CDA70(work);

    if (s03d_dword_800DC2F8 < 4)
    {
        z = work->param.fAF8 * 2 + 25;
        printf((char *)s03d_dword_800DB500, work->param.fAF8, z);
    }
    else
    {
        z = ZAKOCOM_MGR->field_38[work->param.fAF8 % 2];
        printf((char *)s03d_dword_800DB524, work->param.fAF8, z);
    }

    zone = &control->map->hzd->def->zones[z];
    control->mov.vx = zone->x;
    control->mov.vy = zone->y + 1000;
    zz = zone->z;
    control->mov.vz = zz;

    if (work->param.fAF8 == 2)
    {
        control->mov.vz = zz + 500;
    }

    control->map = GM_GetMap(work->field_B54);

    work->field_AC8 = 0;
    work->field_ACA = 0;
    work->field_ACC = 0;
    work->field_ACE = 0;
    work->field_AD0 = 0;
    work->field_AD4 = work->n_nodes - 1;
    work->field_B5C = work->field_B50;
    work->field_B48 = work->field_B40;
    work->field_B22 = 512;
    work->field_B24 = 4000;
    work->field_B28 = 0;
    work->field_B20 = 0;
    work->field_AE8 = 0;
    work->field_ADC = 1;
    work->field_BA0 = 0;
    work->field_B60 = work->field_B54;
    work->field_B80 = work->field_B40;
    work->field_B58 = work->field_B74 = work->field_B50;
}
int Zako_800CDD40(int from, int to)
{
    int dir;

    if (to < 0)
    {
        return 0;
    }
    if (from < 0)
    {
        return 0;
    }
    dir = GV_DiffDirS(from, to);
    if ((unsigned int)(dir + 0x380) >= 0x701)
    {
        return 0;
    }
    if (dir >= 0)
    {
        return 1;
    }
    return 2;
}
void Zako_800CDD94(Work *work)
{
    int diff;
    int v;

    diff = GM_PlayerBody->objs->objs[6].world.t[1] -
           work->body.objs->objs[6].world.t[1];
    v = GV_NearExp8(work->adjust[2].vx, (ratan2(work->field_B90, diff) & 0xFFF) - 0x400);
    work->adjust[2].vx = v;
    work->adjust[6].vx = v;
    if (v < 0)
    {
        work->adjust[7].vx = v * 3;
    }
    else
    {
        work->adjust[7].vx = v * 3 / 2;
    }
}
int s03d_800CDE1C(Work *work)
{
    TARGET *target;
    SVECTOR svec;
    SVECTOR rp_shift;
    SVECTOR force;
    SVECTOR size;

    rp_shift = s03d_dword_800DB548;
    force    = s03d_dword_800DB550;
    size     = s03d_dword_800DB558;

    target = (TARGET *)((char *)work + 0x948);
    GM_SetTarget(target, 4, ENEMY_SIDE, &size);
    DG_SetPos2(&work->control.mov, &work->control.rot);
    DG_RotVector(&force, &svec, 1);
    GM_SetPowerTarget(target, POWER_ONCE, 2, 32, 1, &svec);
    DG_PutVector(&rp_shift, &target->center, 1);
    return GM_PowerTarget(target);
}
void Zako_800CDF2C(Work *work)
{
    TARGET *t = &work->field_900;

    GM_SetPowerTarget(t, 7, 5, 0, 3, (SVECTOR *)&s03d_dword_800C39C8);
    GM_MoveTarget(t, &work->control.mov);
    GM_PowerTarget(t);
}
void s03d_800D05DC(Work *work, int arg);
void s03d_800D0698(Work *work, int arg);
void s03d_800D0754(Work *work, int arg);
void s03d_800D07DC(Work *work, int arg);
void s03d_800D085C(Work *work, int arg);
void s03d_800D08DC(Work *work, int arg);
void s03d_800D0958(Work *work, int arg);
void s03d_800D09D8(Work *work, int arg);
void s03d_800CE5B4(Work *work, int arg);
void s03d_800CE644(Work *work, int arg);

int s03d_800CDF94(Work *work)
{
    int press;

    press = work->field_AD8;

    if (press & 0x1)
    {
        SetMode2(work, s03d_800D05DC);
        return 0;
    }

    if (press & 0x2)
    {
        SetMode2(work, s03d_800D0698);
        return 0;
    }

    if (press & 0x4)
    {
        SetMode2(work, s03d_800D0754);
        return 0;
    }

    if (press & 0x40)
    {
        SetMode2(work, s03d_800D07DC);
        return 0;
    }

    if (press & 0x80)
    {
        SetMode2(work, s03d_800D085C);
        return 0;
    }

    if (press & 0x400)
    {
        SetMode2(work, s03d_800D08DC);
        return 0;
    }

    if (press & 0x800)
    {
        SetMode2(work, s03d_800D0958);
        return 0;
    }

    if (press & 0x200)
    {
        SetMode2(work, s03d_800D09D8);
        return 0;
    }

    if (press & 0x100)
    {
        SetMode(work, s03d_800CE5B4);
        return 1;
    }

    if (press & 0x20)
    {
        SetMode(work, s03d_800CE644);
        return 1;
    }

    if (press & 0x30000)
    {
        SetMode(work, s03d_800CE720);
        work->adjust[2].vx = 0;
        return 1;
    }

    return 0;
}
int  s03d_800CDF94(Work *work);
void s03d_800CE318(Work *work, int arg);

void s03d_800CE12C(Work *work, int arg)
{
    work->field_8FC->class |= 0x9E;

    if (ZAKOCOM_MGR->field_1C == 0)
    {
        work->field_8FC->class |= TARGET_C4;
    }

    work->field_B24 = 4000;

    if (arg == 0)
    {
        SetAction(work, 0, 4);
    }

    if (Zako_800CDA04(work) || s03d_800CDF94(work))
    {
        GM_ConfigObjectOverride(&work->body, ((short *)&s03d_dword_800C39E0)[0], 0, 4, 0);
        work->field_8EC = 0;
        work->field_8F4 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        return;
    }

    if (work->field_AE6 >= 0)
    {
        if (GV_DiffDirAbs(work->control.rot.vy, work->field_AE6) < 0x100)
        {
            if (work->field_ADC & 0x1)
            {
                work->field_8E0 = 2;
                GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[2], 0, 4);
            }
            else
            {
                work->field_8E0 = 1;
                GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[1], 0, 4);
            }

            work->field_8E8 = s03d_800CE318;
            work->field_8F0 = 0;
            work->control.turn.vz = 0;
            work->control.turn.vx = 0;
            GM_ConfigMotionAdjust(&work->body, 0);
        }
        else
        {
            work->control.turn.vy = work->field_AE6;
        }
    }

    work->field_B20 = GV_NearExp4P((short)work->field_B20, work->control.rot.vy);
}
void s03d_800CE2C0(Work *work, int arg1)
{
    int dir = GV_DiffDirS(arg1, work->control.rot.vy);

    if (dir > 128)
    {
        dir = 128;
    }
    else if (dir < -128)
    {
        dir = -128;
    }

    work->control.turn.vz = dir;
}
void s03d_800CE318(Work *work, int arg)
{
    CONTROL *ctrl;
    SVECTOR *vecs;
    int      dir, motion, touches, touch, touch2, size;

    work->field_8FC->class |= 0x9E;

    if (ZAKOCOM_MGR->field_1C == 0)
    {
        work->field_8FC->class |= TARGET_C4;
    }

    work->field_B24 = 4000;

    if (Zako_800CDA04(work) || s03d_800CDF94(work))
    {
        GM_ConfigObjectOverride(&work->body, ((short *)&s03d_dword_800C39E0)[0], 0, 4, 0);
        work->field_8EC = 0;
        work->field_8F4 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        return;
    }

    ctrl = &work->control;
    vecs = ctrl->vecs;
    dir = work->field_AE6;
    motion = work->field_8E0;
    touch = -1;

    if ((work->field_ADC & 1) && motion != 2)
    {
        SetAction(work, 2, 4);
    }

    if (dir < 0)
    {
        SetMode(work, s03d_800CE12C);
        GM_ConfigObjectOverride(&work->body, ((short *)&s03d_dword_800C39E0)[0], 0, 4, 0);
        work->field_8EC = 0;
        work->field_8F4 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        return;
    }

    touches = ctrl->n_touches;

    if (touches > 0)
    {
        touch = GV_VecDir2(vecs);
        if (touches > 1)
        {
            touch2 = GV_VecDir2(&ctrl->vecs[1]);
            if (GV_DiffDirAbs(dir, touch2) < GV_DiffDirAbs(dir, touch))
            {
                touch = touch2;
            }
        }
    }

    if (dir < 0)
    {
        SetMode(work, s03d_800CE12C);
        GM_ConfigObjectOverride(&work->body, ((short *)&s03d_dword_800C39E0)[0], 0, 4, 0);
        work->field_8EC = 0;
        work->field_8F4 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        return;
    }

    switch (Zako_800CDD40(dir, touch))
    {
    case 1:
        dir = (touch - 1024) & 4095;
        break;
    case 2:
        dir = (touch + 1024) & 4095;
        break;
    }

    if (work->body.objs->bound_mode == 0)
    {
        ctrl->rot.vy = dir;
    }
    ctrl->turn.vy = dir;

    size = 0;
    if (motion == 1)
    {
        size = 50;
    }
    else if (motion == 2)
    {
        size = 100;
    }

    ctrl->step.vx = size * rsin(dir) / 4096;
    ctrl->step.vz = size * rcos(dir) / 4096;

    s03d_800CE2C0(work, dir);
    work->field_B20 = GV_NearExp4P((short)work->field_B20, work->control.rot.vy);
}
void s03d_800CE5B4(Work *work, int arg)
{
    if (arg == 0)
    {
        work->field_8DC = 3;
        work->field_8E0 = 0x1F;
        GM_ConfigObjectAction(&work->body, s03d_word_800C3A10[7], 0, 4);
    }
    if (Zako_800CDA04(work) == 0 && work->body.is_end)
    {
        work->field_AE0 = 0;
        work->field_8E8 = s03d_800CF68C;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        GM_ConfigMotionAdjust(&work->body, NULL);
    }
}
void s03d_800CE644(Work *work, int arg)
{
    CONTROL *control = &work->control;
    work->field_8FC->class |= 0x9E;
    work->field_B24 = 0xFA0;
    if (arg == 0)
    {
        work->field_8E0 = 0x10;
        GM_ConfigObjectAction(&work->body, s03d_word_800C3A00[0], 0, 4);
    }
    if (Zako_800CDA04(work))
    {
        return;
    }
    if (work->body.is_end || !(work->field_AD8 & 0x20))
    {
        work->field_8E8 = s03d_800CE12C;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        GM_ConfigMotionAdjust(&work->body, NULL);
    }
    else
    {
        short vy = work->field_B94;
        control->step.vx = 0;
        control->step.vz = 0;
        control->turn.vy = vy;
    }
}
void s03d_800CE8F4(Work *work, int arg);
void s03d_800CE9E8(Work *work, int arg);
void s03d_800CEB38(Work *work, int arg);
void s03d_800CECBC(Work *work, int arg);

void s03d_800CE720(Work *work, int arg)
{
    int press;

    work->field_8FC->class |= 0x9E;
    work->field_B24 = 4000;

    press = work->field_AD8;

    if (arg == 0)
    {
        if (press & 0x10000)
        {
            SetAction(work, 3, 4);
        }
        else
        {
            SetAction(work, 5, 4);
        }

        GM_ConfigMotionAdjust(&work->body, work->adjust);
    }

    if (work->param.fAF8 != 1 || !(GV_Time & 0x100))
    {
        Zako_800CDD94(work);
    }

    if (Zako_800CDA04(work))
    {
        return;
    }

    if (!(press & 0x30000))
    {
        SetMode(work, s03d_800CE12C);
        return;
    }

    if (press & 0x40000)
    {
        SetModeFields(work, s03d_800CE8F4);
        return;
    }

    if (press & 0x80000)
    {
        SetModeFields(work, s03d_800CE9E8);
        return;
    }

    if (press & 0x100000)
    {
        SetModeFields(work, s03d_800CEB38);
        return;
    }

    if (press & 0x200000)
    {
        SetModeFields(work, s03d_800CECBC);
        return;
    }

    if (work->param.fAF8 != 1 || !(GV_Time & 0x100))
    {
        if (work->field_AE6 >= 0)
        {
            work->control.turn.vy = work->field_AE6;
        }
    }
    else
    {
        work->control.turn.vy = work->field_B98;
    }

    work->field_B20 = work->control.rot.vy;
}
void s03d_800CE8F4(Work *work, int arg)
{
    work->field_8FC->class |= 0x9E;
    work->field_B24 = 0xFA0;
    if (arg == 0)
    {
        if (work->field_AD8 & 0x10000)
        {
            work->field_8E0 = 4;
            GM_ConfigObjectAction(&work->body, s03d_word_800C39E8[0], 0, 0);
        }
        else
        {
            work->field_8E0 = 6;
            GM_ConfigObjectAction(&work->body, s03d_word_800C39EC[0], 0, 0);
        }
        Zako_800D0EF0(work, 3);
        GM_ConfigMotionAdjust(&work->body, work->adjust);
    }
    if (work->param.fAF8 != 1 || !(GV_Time & 0x100))
    {
        Zako_800CDD94(work);
    }
    if (!Zako_800CDA04(work))
    {
        work->field_8E8 = s03d_800CE720;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
    }
}
void s03d_800CE9E8(Work *work, int arg)
{
    SVECTOR *rot;
    work->field_8FC->class |= 0x9E;
    work->field_B24 = 0xFA0;
    if (arg == 0)
    {
        GM_ConfigMotionAdjust(&work->body, work->adjust);
    }
    rot = &work->control.rot;
    if (arg == 1 || arg == 7)
    {
        rot->vy = (*(unsigned short *)&rot->vy - 0x100) & 0xFFF;
    }
    if (arg == 3 || arg == 5)
    {
        rot->vy = (*(unsigned short *)&rot->vy + 0x100) & 0xFFF;
    }
    if (arg == 2 || arg == 4 || arg == 6)
    {
        work->field_8E0 = 6;
        GM_ConfigObjectAction(&work->body, s03d_word_800C39EC[0], 0, 0);
        Zako_800D0EF0(work, 3);
    }
    Zako_800CDD94(work);
    if (!Zako_800CDA04(work))
    {
        if (work->body.is_end)
        {
            work->field_8E8 = s03d_800CE720;
            work->field_8F0 = 0;
            work->control.turn.vz = 0;
            work->control.turn.vx = 0;
            GM_ConfigMotionAdjust(&work->body, NULL);
        }
        work->control.rot.vy = rot->vy;
    }
}
extern SVECTOR s03d_dword_800C3A44;
extern SVECTOR s03d_dword_800C3A4C;
extern SVECTOR s03d_dword_800C3A54;
void *NewTenage3(SVECTOR *pos, SVECTOR *step, int fuse_time, int type, int model, int do_sound, int player_side);

void s03d_800CEB38(Work *work, int arg)
{
    SVECTOR *pos;
    SVECTOR *step;
    SVECTOR  out;
    SVECTOR  rot;
    SVECTOR  diff;
    int      dist;

    if (arg == 0)
    {
        SetAction(work, 7, 4);
    }

    if (arg == 17)
    {
        GM_SeSet(&work->control.mov, SE_PINNUKI);
    }

    if (arg == 45)
    {
        if (work->param.fAF8 == 2)
        {
            pos = &s03d_dword_800C3A44;
        }
        else
        {
            pos = &s03d_dword_800C3A4C;
        }

        dist = GV_DiffVec3(pos, &work->field_B68);
        step = &s03d_dword_800C3A54;
        step->vz = dist / 8;

        GV_SubVec3(&work->field_B68, pos, &diff);
        rot.vx = 0;
        rot.vy = GV_VecDir2(&diff);
        rot.vz = 0;

        DG_SetPos2(pos, &rot);
        DG_RotVector(step, &out, 1);
        NewTenage3(pos, &out, 60, 0, 15240, 0, 0);
    }

    if (Zako_800CDA04(work))
    {
        return;
    }

    if (work->body.is_end)
    {
        SetMode(work, s03d_800CE720);
    }

    work->control.turn.vy = work->field_AE6;
}
void s03d_800CECBC(Work *work, int arg)
{
    work->field_8FC->class |= 0x9E;
    work->field_B24 = 0xFA0;
    if (arg == 0)
    {
        work->field_8E0 = 8;
        GM_ConfigObjectAction(&work->body, s03d_word_800C39F0[0], 0, 0);
    }
    if (arg == 3 && s03d_800CDE1C(work))
    {
        GM_SeSet(&work->control.mov, 0x25);
    }
    work->control.turn.vy = work->field_B94;
    if (Zako_800CDA04(work))
    {
        return;
    }
    if (work->body.is_end)
    {
        work->field_8E8 = s03d_800CE720;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        GM_ConfigMotionAdjust(&work->body, NULL);
    }
}
void s03d_800CED94(Work *work, int arg)
{
    work->field_B24 = 0;
    if (arg == 0)
    {
        work->field_8E0 = 0x13;
        GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C3A04)[1], 0, 4);
    }
    if (Zako_800CDA04(work))
    {
        return;
    }
    work->field_8FC->class |= 0x9E;
    if (work->body.is_end)
    {
        work->field_8F8 = 1;
        work->field_8E8 = s03d_800CE12C;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        GM_ConfigMotionAdjust(&work->body, NULL);
    }
}
void s03d_800CEE3C(Work *work, int arg)
{
    TARGET  *target;
    CONTROL *control;

    target = work->field_8FC;
    control = &work->control;

    work->field_8E4 = 0;

    if (arg == 0)
    {
        work->field_8DC = 6;
        work->field_8E0 = 27;
        GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[27], 0, 4);
    }

    if (arg - 8 < 10u)
    {
        Zako_800CDF2C(work);
    }

    if (work->field_8E0 == 27)
    {
        if (arg == 22)
        {
            if (control->mov.vy - control->levels[0] < 2000)
            {
                GM_SeSet(&control->mov, SE_V_ENE_PUNCHED);
                GM_SeSet(&control->mov, SE_HIT_FLOOR);
                Zako_800D0B18(work, 6, 0);
                GM_SetNoise(100, 4, &work->control.mov);
            }
            else if (control->mov.vy - control->levels[0] > 4000)
            {
                work->field_8FC->vital = 0;
                GM_SeSet(&control->mov, SE_V_ENE_THROWN);
            }
        }

        if (work->body.is_end)
        {
            if (control->grounded == 0)
            {
                work->field_8E0 = 36;
                GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[36], 0, 4);
            }
            else
            {
                work->field_8E8 = s03d_800CF68C;
                work->field_8F0 = 0;
                work->control.turn.vz = 0;
                work->control.turn.vx = 0;
                GM_ConfigMotionAdjust(&work->body, 0);
            }
        }
    }
    else if (control->grounded)
    {
        GM_SeSet(&control->mov, SE_V_ENE_PUNCHED);
        GM_SeSet(&control->mov, SE_HIT_FLOOR);
        GM_SetNoise(100, 4, &work->control.mov);
        Zako_800D0B18(work, 6, 1);

        if (work->field_8FC->vital <= 0)
        {
            work->field_8E8 = s03d_800D01C4;
            work->field_8F0 = 0;
            work->control.turn.vz = 0;
            work->control.turn.vx = 0;
            GM_ConfigMotionAdjust(&work->body, 0);
        }
        else
        {
            work->field_8E8 = s03d_800CF68C;
            work->field_8F0 = 0;
            work->control.turn.vz = 0;
            work->control.turn.vx = 0;
            GM_ConfigMotionAdjust(&work->body, 0);
        }
    }

    if (arg < 24)
    {
        control->turn = *target->field_1C;
    }

    if (arg < 22)
    {
        work->control.hzd_height = -32767;
    }
}
void s03d_800CF114(Work *work)
{
    SVECTOR vec;

    work->control.turn = GM_PlayerControl->rot;
    DG_SetPos2(&GM_PlayerPosition, &GM_PlayerControl->rot);
    DG_PutVector((SVECTOR *)&s03d_dword_800C3A5C, &vec, 1);
    GV_SubVec3(&vec, &work->control.mov, &work->control.step);
}
void s03d_800CFB04(Work *work, int arg);

void s03d_800CF194(Work *work, int arg)
{
    TARGET *target;
    int     motion;
    int     a_mode;

    target = work->field_8FC;
    motion = work->field_8E0;

    work->field_8E4 = 0;

    if (arg == 0)
    {
        work->field_AF6 = target->faint;
        GM_SeSet(&work->control.mov, SE_V_ENE_GRABBED);
    }

    if (work->field_AF6 != target->faint)
    {
        GM_SeSet(&work->control.mov, SE_V_ENE_GRABBED);
        work->field_AF6 = target->faint;
    }

    if (target->damaged & TARGET_POWER)
    {
        Zako_800D0B18(work, 5, 0);
        GM_SeSet(&work->control.mov, SE_V_ENE_GRABBED);

        target->force = DG_ZeroVector;
        target->damage = 0;
        target->damaged = 0;

        if (target->vital <= 0)
        {
            a_mode = target->a_mode;
            if (a_mode == 1)
            {
                work->field_BA0 = a_mode;
            }

            work->field_8DC = 5;
            target->side = ENEMY_SIDE;
            work->field_8E8 = s03d_800CFB04;
            work->field_8F0 = 0;
            work->control.turn.vz = 0;
            work->control.turn.vx = 0;
            GM_ConfigMotionAdjust(&work->body, 0);
            target->captured = 0;
        }
    }

    switch (GM_PlayerAction)
    {
    case 7:
    case 13:
        if (motion != 23 && motion != 44)
        {
            target->side = NO_SIDE;
            work->field_8E0 = 23;
            GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[23], 0, 4);
            work->field_AF8 = 0;
        }

        if (work->field_AF8 == 50 && target->faint > 0)
        {
            work->field_8E0 = 44;
            GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[44], 0, 4);
        }

        if (motion == 44 && !(work->field_AF8 & 7))
        {
            s03d_dword_800DC2F4 = 4;
        }

        work->control.turn = GM_PlayerControl->rot;
        s03d_800CF114(work);
        work->field_AF8++;
        break;

    case 38:
        if (motion != 24)
        {
            target->side = NO_SIDE;
            work->field_8E0 = 24;
            GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[24], 0, 4);
        }

        work->control.turn = GM_PlayerControl->rot;
        s03d_800CF114(work);
        break;

    case 39:
        work->field_8DC = 4;
        target->side = ENEMY_SIDE;
        target->vital = 0;
        work->field_8E8 = s03d_800CFB04;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        GM_ConfigMotionAdjust(&work->body, 0);
        return;

    default:
        work->field_8DC = 5;
        target->side = ENEMY_SIDE;
        work->field_8E8 = s03d_800CFB04;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        GM_ConfigMotionAdjust(&work->body, 0);
        return;
    }

    if (work->field_B90 > 800)
    {
        target->captured = 0;
    }

    work->field_8FC->class |= TARGET_POWER | TARGET_SEEK;
}
void s03d_800CF4D4(Work *work, int arg)
{
    if (arg == 0)
    {
        work->field_8E0 = 0x22;
        GM_ConfigObjectAction(&work->body, s03d_word_800C3A10[10], 0, 4);
    }
    if (work->body.is_end)
    {
        work->field_8E8 = s03d_800D01C4;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        GM_ConfigMotionAdjust(&work->body, NULL);
    }
}
void s03d_800CF548(Work *work, int arg)
{
    SVECTOR *pos = &work->control.mov;
    int phase;
    work->field_8E4 = 0;
    work->field_B24 = 0;
    if (arg == 0)
    {
        work->field_8E0 = 0x1C;
        GM_ConfigObjectAction(&work->body, s03d_word_800C3A10[4], 0, 4);
        work->field_8FC->faint = 0;
    }
    if (Zako_800CDA04(work))
    {
        return;
    }
    phase = 0xA;
    if (arg == phase)
    {
        work->field_8DC = 1;
        work->field_8E0 = 0x21;
        GM_ConfigObjectAction(&work->body, s03d_word_800C3A10[9], 0, 4);
    }
    else
    {
        work->field_8FC->class |= 0x9E;
    }
    if (arg == phase + 0x18)
    {
        GM_SeSet(pos, 0x51);
    }
    if (arg == phase + 0x2E)
    {
        GM_SeSet(pos, 0x33);
    }
    if (arg >= phase + 0x32 && work->body.is_end)
    {
        work->field_8E8 = s03d_800CF68C;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        GM_ConfigMotionAdjust(&work->body, NULL);
    }
}
void s03d_800CF844(Work *work, int arg);
void s03d_800CF90C(Work *work, int arg);

void s03d_800CF68C(Work *work, int arg)
{
    int x;

    if (arg == 0)
    {
        if (work->field_8DC < 3)
        {
            if (work->field_8DC == 1)
            {
                work->field_8E0 = 37;
                GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[37], 0, 4);
            }
            else
            {
                work->field_8E0 = 35;
                GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[35], 0, 4);
            }
        }
        else
        {
            work->field_8E0 = 36;
            GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[36], 0, 4);
        }

        if (work->field_8FC->faint <= 0)
        {
            x = work->control.mov.vx % 90;
        }
        else
        {
            x = work->control.mov.vx % 30;
        }

        x = (x < 0) ? -x : x;
        work->field_AF6 = x + 10;
    }

    if (Zako_800CD6A8(work))
    {
        work->field_8E8 = s03d_800CF844;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        GM_ConfigMotionAdjust(&work->body, 0);
    }
    else if (work->field_AF6 < arg)
    {
        if (work->field_8FC->faint <= 0)
        {
            work->field_8FC->faint = work->param.faint;
        }

        work->field_8E8 = s03d_800CF90C;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        GM_ConfigMotionAdjust(&work->body, 0);
    }
}
void s03d_800CF844(Work *work, int arg)
{
    if (arg == 0)
    {
        if (work->field_8DC < 3)
        {
            work->field_8E0 = 0x2A;
            GM_ConfigObjectAction(&work->body, s03d_word_800C3A10[18], 0, 4);
        }
        else
        {
            work->field_8E0 = 0x2B;
            GM_ConfigObjectAction(&work->body, s03d_word_800C3A10[19], 0, 4);
        }
        GM_SeSet(&work->control.mov, 0x36);
    }
    if (arg == 4)
    {
        Zako_800D0BEC(work, 0);
    }
    if (work->body.is_end)
    {
        work->field_8E8 = s03d_800D01C4;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        GM_ConfigMotionAdjust(&work->body, NULL);
    }
}
void s03d_800CF90C(Work *work, int arg)
{
    work->field_8E4 = 0;
    if (arg == 0)
    {
        if (work->field_8DC < 3)
        {
            if (work->field_AF6 >= 0x96)
            {
                work->field_8E0 = 0x28;
                GM_ConfigObjectAction(&work->body, s03d_word_800C3A10[16], 0, 4);
            }
            else
            {
                work->field_8E0 = 0x26;
                GM_ConfigObjectAction(&work->body, s03d_word_800C3A10[14], 0, 4);
            }
        }
        else
        {
            if (work->field_AF6 >= 0x96)
            {
                work->field_8E0 = 0x29;
                GM_ConfigObjectAction(&work->body, s03d_word_800C3A10[17], 0, 4);
            }
            else
            {
                work->field_8E0 = 0x27;
                GM_ConfigObjectAction(&work->body, s03d_word_800C3A10[15], 0, 4);
            }
        }
    }
    if (work->body.is_end)
    {
        work->field_8E8 = s03d_800CE12C;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        GM_ConfigMotionAdjust(&work->body, NULL);
    }
}
void s03d_800CFA04(Work *work, int arg)
{
    TARGET *t;
    work->field_8E4 = 0;
    work->field_8FC->class |= 0x9E;
    work->field_B24 = 0xFA0;
    if (Zako_800CDA04(work))
    {
        return;
    }
    t = work->field_8FC;
    if (arg == 0)
    {
        work->field_8E0 = 0xF;
        GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39FC)[1], 0, 4);
        GM_SeSet(&work->control.mov, 0x8D);
        if (t->a_mode == 3)
        {
            GM_SeSet(&work->control.mov, 0x34);
            Zako_800D0B88(work);
        }
        else
        {
            Zako_800D0B18(work, 5, 0);
        }
    }
    if (work->body.is_end)
    {
        work->field_8E8 = s03d_800CE12C;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        GM_ConfigMotionAdjust(&work->body, NULL);
    }
}
void s03d_800CFFF0(Work *work, int arg);

void s03d_800CFB04(Work *work, int arg)
{
    int     *unk;
    CONTROL *ctrl;

    unk = &work->field_8C8;
    work->control.step = work->field_8FC->force;

    ctrl = &work->control;
    if (unk[5] != 1)
    {
        work->field_8E4 = 0;
    }

    if (arg == 0)
    {
        switch (unk[5])
        {
        case 0:
            GM_SeSet(&ctrl->mov, SE_PUNCH_HIT);
            work->field_8E0 = 30;
            GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[30], 0, 4);
            GM_SeSet(&ctrl->mov, SE_V_ENE_PUNCHED);
            Zako_800D0B18(work, 5, 0);
            work->field_AF6 = 17;
            break;
        case 1:
            work->field_8E0 = 33;
            GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[33], 0, 4);
            if (work->field_8FC->vital <= 0)
            {
                if (GM_Weapon == WP_Rifle)
                {
                    Zako_800D0B18(work, 6, 2);
                }
                else
                {
                    Zako_800D0B18(work, 6, 1);
                }
            }
            else
            {
                Zako_800D0B18(work, 5, 0);
            }
            GM_SeSet(&ctrl->mov, SE_V_ENE_PUNCHED);
            work->field_AF6 = 46;
            break;
        case 3:
            GM_SeSet(&ctrl->mov, SE_ENEMY_DAMAGE);
            work->field_8E0 = 31;
            GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[31], 0, 4);
            Zako_800D0B18(work, 5, 0);
            work->field_AF6 = 17;
            break;
        case 2:
            GM_SeSet(&ctrl->mov, SE_V_ENE_THROWN);
            work->field_8E0 = 32;
            GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[32], 0, 4);
            Zako_800D0B18(work, 5, 0);
            work->field_AF6 = 22;
            break;
        case 4:
            GM_SeSet(&ctrl->mov, SE_V_ENE_SNAPPED);
            work->field_8E0 = 25;
            GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[25], 0, 4);
            work->field_AF6 = 67;
            break;
        case 5:
            work->field_8E0 = 26;
            GM_ConfigObjectAction(&work->body, ((short *)&s03d_dword_800C39E0)[26], 0, 4);
            work->field_AF6 = 15;
            break;
        }
    }

    switch (unk[5])
    {
    case 0:
        if (arg < 12)
        {
            ctrl->turn.vy += 170;
        }

        if (arg - 1 < 5u)
        {
            Zako_800CDF2C(work);
        }

        if (arg < 20)
        {
            work->control.hzd_height = -32767;
        }
        break;
    case 1:
        if (arg == 24)
        {
            GM_SeSet(&ctrl->mov, SE_ENEMY_COLLAPSE);
        }
        break;
    case 3:
        if (arg - 1 < 14u)
        {
            Zako_800CDF2C(work);
        }
        if (arg < 15)
        {
            ctrl->hzd_height = -32767;
        }
        break;
    case 2:
        if (arg - 1 < 29u)
        {
            Zako_800CDF2C(work);
        }
        if (arg < 20)
        {
            ctrl->hzd_height = -32767;
        }
        break;
    case 4:
    case 5:
        break;
    }

    if (arg > 16 && ctrl->grounded)
    {
        ctrl->step = DG_ZeroVector;
    }

    if (arg == work->field_AF6)
    {
        if (ctrl->mov.vy - ctrl->levels[0] < 2000)
        {
            GM_SeSet(&ctrl->mov, SE_HIT_FLOOR);
            GM_SetNoise(100, 4, &ctrl->mov);
            Zako_800D0B18(work, 6, 0);
        }
        else if (ctrl->mov.vy - ctrl->levels[0] > 4000)
        {
            work->field_8FC->vital = 0;
            work->field_8E8 = s03d_800CFFF0;
            work->field_8F0 = 0;
            work->control.turn.vz = 0;
            work->control.turn.vx = 0;
            GM_ConfigMotionAdjust(&work->body, 0);
            return;
        }
    }

    if (work->body.is_end)
    {
        work->field_8E4 = 1;
        work->field_8FC->force = DG_ZeroVector;
        if (work->field_8FC->vital <= 0)
        {
            work->field_8E8 = s03d_800D01C4;
            work->field_8F0 = 0;
            work->control.turn.vz = 0;
            work->control.turn.vx = 0;
            GM_ConfigMotionAdjust(&work->body, 0);
        }
        else
        {
            work->field_8E8 = s03d_800CF68C;
            work->field_8F0 = 0;
            work->control.turn.vz = 0;
            work->control.turn.vx = 0;
            GM_ConfigMotionAdjust(&work->body, 0);
        }
    }
}
void s03d_800CFFF0(Work *work, int arg)
{
    CONTROL *ctrl = &work->control;

    work->field_8E4 = 0;
    ctrl->step = work->field_8FC->force;
    if (arg == 0 && work->field_8DC != 2)
    {
        GM_SeSet(&ctrl->mov, SE_V_ENE_THROWN);
    }
    if (arg > 16 && ctrl->grounded)
    {
        ctrl->step = DG_ZeroVector;
    }
    if (work->field_8E0 < 35)
    {
        if (work->body.is_end)
        {
            if (work->field_8DC < 3)
            {
                if (work->field_8DC == 1)
                {
                    work->field_8E0 = 37;
                    GM_ConfigObjectAction(&work->body, s03d_word_800C3A10[13], 0, 4);
                }
                else
                {
                    work->field_8E0 = 35;
                    GM_ConfigObjectAction(&work->body, s03d_word_800C3A10[11], 0, 4);
                }
            }
            else
            {
                work->field_8E0 = 36;
                GM_ConfigObjectAction(&work->body, s03d_word_800C3A10[12], 0, 4);
            }
        }
    }
    else if (ctrl->grounded)
    {
        work->field_8E4 = 1;
        work->field_8FC->force = DG_ZeroVector;
        GM_SeSet(&ctrl->mov, SE_HIT_FLOOR);
        Zako_800D0B18(work, 6, 1);
        work->field_8E8 = s03d_800D01C4;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        GM_ConfigMotionAdjust(&work->body, NULL);
    }
}
void s03d_800D01C4(Work *work, int arg)
{
    if (arg == 0)
    {
        if (work->field_8DC < 3)
        {
            if (work->field_8DC == 1)
            {
                work->field_8E0 = 0x2F;
                GM_ConfigObjectAction(&work->body, s03d_word_800C3A3C[1], 0, 4);
            }
            else
            {
                work->field_8E0 = 0x2D;
                GM_ConfigObjectAction(&work->body, s03d_word_800C3A38[1], 0, 4);
            }
        }
        else
        {
            work->field_8E0 = 0x2E;
            GM_ConfigObjectAction(&work->body, s03d_word_800C3A3C[0], 0, 4);
        }
        GM_ConfigControlAttribute(&work->control, 0);
        work->field_B28 = 0;
    }
    if (arg == 4)
    {
        int b04 = work->field_B04;

        printf("n_dead = %d \n", b04);
        if (b04 == 6 || b04 == 0xA || b04 == 0xE)
        {
            Zako_800D0BEC(work, 2);
        }
        if (b04 == 8 || b04 == 0xC)
        {
            Zako_800D0BEC(work, 0);
        }
    }
    if (arg & 2)
    {
        work->field_B00 = 0;
    }
    else
    {
        work->field_B00 = 1;
    }
    if (arg >= 9)
    {
        work->field_8E8 = s03d_800D0324;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        GM_ConfigMotionAdjust(&work->body, NULL);
    }
}

const char s03d_dword_800DB5A4[] STR_PIECE = {'F', 'A', '-', 'M'};
const char s03d_dword_800DB5A8[] STR_PIECE = {'A', 'S', '/', 'B'};
const char s03d_dword_800DB5AC[] STR_PIECE = {'U', 'L', 'L', 'E'};
const char s03d_dword_800DB5B0[] STR_PIECE = {'T', ' ', '*', ' '};
const char s03d_dword_800DB5B4[] STR_PIECE = {'2', '5', 0x0, 0x0};

const char s03d_dword_800DB5B8[] STR_PIECE = {'S', 'O', 'C', 'O'};
const char s03d_dword_800DB5BC[] STR_PIECE = {'M', '/', 'B', 'U'};
const char s03d_dword_800DB5C0[] STR_PIECE = {'L', 'L', 'E', 'T'};
const char s03d_dword_800DB5C4[] STR_PIECE = {' ', '*', ' ', '1'};
const char s03d_dword_800DB5C8[] STR_PIECE = {'2', 0x0, 0x0, 0x0};

const char s03d_dword_800DB5CC[] STR_PIECE = {'R', 'A', 'T', 'I'};
const char s03d_dword_800DB5D0[] STR_PIECE = {'O', 'N', 0x0, 0x0};

const char s03d_dword_800DB5D4[] STR_PIECE = {'n', 'o', 'i', 's'};
const char s03d_dword_800DB5D8[] STR_PIECE = {'e', ' ', 'd', 'i'};
const char s03d_dword_800DB5DC[] STR_PIECE = {'s', ' ', ' ', '='};
const char s03d_dword_800DB5E0[] STR_PIECE = {'%', 'd', ',', '\n'};
const char s03d_dword_800DB5E4[] STR_PIECE = {0x0, 0x0, 0x0, 0x0};

const char s03d_dword_800DB5E8[] STR_PIECE = {' ', 'A', 's', 'i'};
const char s03d_dword_800DB5EC[] STR_PIECE = {'a', 't', 'o', ' '};
const char s03d_dword_800DB5F0[] STR_PIECE = {'m', 'i', 'k', 'k'};
const char s03d_dword_800DB5F4[] STR_PIECE = {'e', '!', '!', ' '};
const char s03d_dword_800DB5F8[] STR_PIECE = {'[', '%', 'd', ']'};
const char s03d_dword_800DB5FC[] STR_PIECE = {'\n', 0x0, 0xa9, ','};


void s03d_800D0324(Work *work, int arg)
{
    if (arg == 0)
    {
        int *base = &s03d_dword_800DC310;
        work->field_B00 = 0;
        work->control.mov = s03d_dword_800C3B88;
        base[work->param.fAF8 * 4 + 0x90 / 4] = 1;
        if (work->field_BA0 == 0)
        {
            unsigned short *lv = (unsigned short *)linkvarbuf;
            lv[0x4F]++;
        }
    }
    {
        int *base = &s03d_dword_800DC310;
        if (base[work->param.fAF8 * 4 + 0x90 / 4] != 2)
        {
            return;
        }
        s03d_800CDB5C(work);
        work->field_8E8 = s03d_800CE12C;
        work->field_8F0 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
        GM_ConfigMotionAdjust(&work->body, NULL);
    }
}
int Zako_800D0408(Work *work)
{
    return work->control.mov.vx >= 0x1195;
}
void s03d_800D041C(Work *work)
{
    short   *act;
    CONTROL *control;
    void   (*action)(Work *, int);
    int      time;

    act = (short *)&work->field_8C8;
    control = &work->control;

    work->field_AEC = 0;
    work->field_B24 = 0;
    work->field_8FC->class = TARGET_AVAIL;
    work->field_8F8 = 0;
    work->field_B9C = 0;

    action = work->field_8E8;

    control->height = work->body.height;
    control->hzd_height = control->levels[0] + 750;

    time = work->field_8F0++;

    if (action == NULL)
    {
        action = s03d_800CE12C;
        work->field_8E8 = s03d_800CE12C;
    }

    action(work, time);

    action = (void (*)(Work *, int))work->field_8EC;
    if (action != NULL)
    {
        time = work->field_8F4++;
        action(work, time);
    }

    if (act[14] == 0)
    {
        control->r_sphere = GV_NearExp2(control->r_sphere, act[13]);
    }
    else
    {
        control->r_sphere = -1;
    }

    if (work->field_8FC->class & TARGET_POWER)
    {
        work->hom->flag = 1;
    }
    else
    {
        work->hom->flag = 0;
    }

    if (ZAKOCOM_MGR->entries[work->param.fAF8].field_4 == 1)
    {
        work->hom->flag = 0;
    }

    if (!Zako_800D0408(work))
    {
        work->hom->flag = 0;
        work->field_8FC->class = TARGET_AVAIL;
    }

    if (act[2] < 0 && control->grounded)
    {
        act[2] = 0;
    }

    act[2] -= 16;
    control->step.vy = act[2];

    work->field_BA2 = work->field_8FC->vital;
}
void s03d_800D05DC(Work *work, int arg1)
{
    if (arg1 == 0)
    {
        GM_ConfigObjectOverride(&work->body, s03d_word_800C39F0[1], 0, 4, 0x3FE);
    }
    if (!(work->field_AD8 & 1))
    {
        GM_ConfigObjectOverride(&work->body, *(short *)&s03d_dword_800C39E0, 0, 4, 0);
        work->field_8EC = 0;
        work->field_8F4 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
    }
    else if (arg1 < 4)
    {
        work->field_B20 = (*(unsigned short *)&work->control.rot.vy - (arg1 << 8)) & 0xFFF;
    }
    else
    {
        work->field_B20 = (*(unsigned short *)&work->control.rot.vy - 0x400) & 0xFFF;
    }
}
void s03d_800D0698(Work *work, int arg1)
{
    if (arg1 == 0)
    {
        GM_ConfigObjectOverride(&work->body, *(short *)&s03d_dword_800C39F4, 0, 4, 0x3FE);
    }
    if (!(work->field_AD8 & 2))
    {
        GM_ConfigObjectOverride(&work->body, *(short *)&s03d_dword_800C39E0, 0, 4, 0);
        work->field_8EC = 0;
        work->field_8F4 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
    }
    else if (arg1 < 4)
    {
        work->field_B20 = (*(unsigned short *)&work->control.rot.vy + (arg1 << 8)) & 0xFFF;
    }
    else
    {
        work->field_B20 = (*(unsigned short *)&work->control.rot.vy + 0x400) & 0xFFF;
    }
}
void s03d_800D0754(Work *work, int arg1)
{
    work->field_B24 = 0x7D0;
    if (arg1 == 0)
    {
        GM_ConfigObjectOverride(&work->body, ((short *)&s03d_dword_800C39F4)[1], 0, 4, 0x3FE);
    }
    if (!(work->field_AD8 & 4))
    {
        GM_ConfigObjectOverride(&work->body, *(short *)&s03d_dword_800C39E0, 0, 4, 0);
        work->field_8EC = 0;
        work->field_8F4 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
    }
}
void s03d_800D07DC(Work *work, int arg1)
{
    work->field_B24 = 0;
    if (arg1 == 0)
    {
        GM_ConfigObjectOverride(&work->body, *(short *)&s03d_dword_800C3A0C, 0, 4, 0x3FE);
    }
    if (work->body.time2)
    {
        GM_ConfigObjectOverride(&work->body, *(short *)&s03d_dword_800C39E0, 0, 4, 0);
        work->field_8EC = 0;
        work->field_8F4 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
    }
}
void s03d_800D085C(Work *work, int arg1)
{
    work->field_B24 = 0;
    if (arg1 == 0)
    {
        GM_ConfigObjectOverride(&work->body, *(short *)&s03d_dword_800C3A08, 0, 4, 0x3FE);
    }
    if (work->body.time2)
    {
        GM_ConfigObjectOverride(&work->body, *(short *)&s03d_dword_800C39E0, 0, 4, 0);
        work->field_8EC = 0;
        work->field_8F4 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
    }
}
void s03d_800D08DC(Work *work, int arg1)
{
    if (arg1 == 0)
    {
        GM_ConfigObjectOverride(&work->body, ((short *)&s03d_dword_800C3A08)[1], 0, 4, 0x3FE);
    }
    if (work->body.time2)
    {
        GM_ConfigObjectOverride(&work->body, *(short *)&s03d_dword_800C39E0, 0, 4, 0);
        work->field_8EC = 0;
        work->field_8F4 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
    }
}
void s03d_800D0958(Work *work, int arg1)
{
    work->field_B24 = 0;
    if (arg1 == 0)
    {
        GM_ConfigObjectOverride(&work->body, s03d_word_800C3A00[1], 0, 4, 0x3FE);
    }
    if (work->body.time2)
    {
        GM_ConfigObjectOverride(&work->body, *(short *)&s03d_dword_800C39E0, 0, 4, 0);
        work->field_8EC = 0;
        work->field_8F4 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
    }
}
void s03d_800CED94(Work *work, int arg);
void AN_Sleep(SVECTOR *pos);

void s03d_800D09D8(Work *work, int arg)
{
    SVECTOR pos;

    work->field_B24 = 0;

    if (arg == 0)
    {
        GM_ConfigObjectOverride(&work->body, ((short *)&s03d_dword_800C39E0)[18], 0, 4, 0x3FE);

        if (work->control.map->index == GM_PlayerMap && GV_RandU(12) >= 5)
        {
            work->field_AE8 = 240;
        }
    }

    if (arg == 20)
    {
        pos = work->control.mov;
        pos.vy += 500;
        AN_Sleep(&pos);
    }

    if (work->field_AD8 & 0x1000)
    {
        SetMode(work, s03d_800CED94);
        GM_ConfigObjectOverride(&work->body, ((short *)&s03d_dword_800C39E0)[0], 0, 4, 0);
        work->field_8EC = 0;
        work->field_8F4 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
    }
    else if (arg == 130)
    {
        GM_ConfigObjectOverride(&work->body, ((short *)&s03d_dword_800C39E0)[0], 0, 4, 0);
        work->field_8EC = 0;
        work->field_8F4 = 0;
        work->control.turn.vz = 0;
        work->control.turn.vx = 0;
    }
}
void Zako_800D0B18(Work *work, int index, int count)
{
    MATRIX m;

    DG_SetPos(&work->body.objs->objs[index].world);
    DG_MovePos((SVECTOR *)&s03d_dword_800C3A64);
    DG_RotatePos((SVECTOR *)&s03d_dword_800C3A6C);
    ReadRotMatrix(&m);
    NewBlood(&m, count);
}
void Zako_800D0B88(Work *work)
{
    MATRIX  m;
    SVECTOR sv;

    DG_SetPos(&work->body.objs->objs[1].world);
    DG_MovePos((SVECTOR *)&s03d_dword_800C3A74);
    DG_RotatePos((SVECTOR *)&s03d_dword_800C3A7C);
    ReadRotMatrix(&m);
    sv.vx = *(short *)&m.t[0];
    sv.vy = *(short *)&m.t[1];
    sv.vz = *(short *)&m.t[2];
    AN_Fog(&sv);
}
void Zako_800D0BEC(Work *work, int type)
{
    SVECTOR   step = work->field_8D4;
    SVECTOR  *pos = &work->control.mov;
    ITEM_INFO info;

    if (type >= 0)
    {
        if (type < 2)
        {
            info.type = 4;
            info.id = IT_Ration;
            info.num = 1;
            info.message = (const char *)s03d_dword_800C3A84;
        }
        else if (type < 4)
        {
            info.type = 2;
            info.id = WP_Socom;
            info.num = 0xC;
            info.message = (const char *)s03d_dword_800C3A88;
        }
    }
    info.time = 0x384;
    NewItemPut(pos, &step, &info);
}
void *AN_HeadMark(MATRIX *world, int mark);
void  AN_Breath(MATRIX *world);
void *NewLSight(SVECTOR *from, SVECTOR *to, int color);
void *NewBulletEx(int flag, MATRIX *world, int side, int color, int type, int size, int damage, int length, int speed);
void  AN_BulletSmoke(MATRIX *pMtx, int a2);
void *AN_FamasFlash(MATRIX *pMtx);
extern SVECTOR s03d_dword_800C3AA0;
extern SVECTOR s03d_dword_800C3AA8;
int   Zako_800D0F38(Work *work, int value);

void s03d_800D0C90(Work *work, int mark)
{
    if (work->control.map->index == GM_PlayerMap)
    {
        AN_HeadMark(&work->body.objs->objs[6].world, mark);
    }
}

void s03d_800D0CD4(Work *work)
{
    int se1, se2, motion, frame, index;

    motion = work->field_8E0;
    frame = work->m_ctrl.info1.frame;
    index = (work->param.fAF8 % 4) * 2;
    se1 = index + 160;
    se2 = index + 161;

    if (motion == 1)
    {
        if (frame == 22)
        {
            GM_SeSet(&work->control.mov, se2);
        }
        else if (frame == 11)
        {
            GM_SeSet(&work->control.mov, se1);
        }
    }
    else if (motion == 2)
    {
        if (frame == 16)
        {
            GM_SeSet(&work->control.mov, se2);
        }
        else if (frame == 8)
        {
            GM_SeSet(&work->control.mov, se1);
        }
    }
}

void s03d_800D0D6C(Work *work)
{
    if (ZAKOCOM_MGR->field_1C != 1 && work->control.map->index == GM_PlayerMap &&
        GV_Time % 64 == work->param.fAF8 * 16)
    {
        AN_Breath(&work->body.objs->objs[6].world);
    }
}

void s03d_800D0DF0(Work *work)
{
    if (work->field_B26 == 2)
    {
        NewLSight(&GM_PlayerPosition, &work->control.mov, 143);
    }
}

void s03d_800D0E2C(Work *work)
{
    MATRIX *world;
    MATRIX  mat;

    world = &work->body.objs->objs[4].world;
    DG_SetPos(world);
    DG_MovePos(&s03d_dword_800C3AA0);
    DG_RotatePos(&s03d_dword_800C3AA8);
    ReadRotMatrix(&mat);
    NewBulletEx(256, &mat, 2, 1, 0, 10, work->param.field_B18, 10000, 750);
    GM_SeSet(&work->control.mov, SE_ENEMY_SHOT);
    AN_BulletSmoke(world, 0);
    AN_FamasFlash(&mat);
    Zako_800D0F38(work, (int)s03d_800D0E2C);
}
int Zako_800D0EF0(Work *work, int index)
{
    int i;

    for (i = 0; i < 8; i++)
    {
        if (work->field_AA8[i] == 0)
        {
            work->field_AA8[i] = s03d_dword_800C3A90[index];
            return 1;
        }
    }
    return 0;
}
int Zako_800D0F38(Work *work, int value)
{
    int i;

    for (i = 0; i < 8; i++)
    {
        if (work->field_AA8[i] == value)
        {
            work->field_AA8[i] = 0;
            return 1;
        }
    }
    return 0;
}
void Zako_800D0F6C(Work *work)
{
    int i;

    for (i = 0; i < 8; i++)
    {
        if (work->field_AA8[i])
        {
            ((void (*)(Work *))work->field_AA8[i])(work);
        }
    }
}
void Zako_800D0FCC(Work *work)
{
    unsigned short    *src = &work->field_B20;
    RADAR_SIGHT_PARAM *rp = &work->control.radar_param;

    rp->dir = src[0];
    rp->dis = src[2];
    rp->range = src[1];
    rp->r = 0;
}

void Zako_800D0FF4(Work *work)
{
    if (work->field_B33 & 4)
    {
        if (work->field_8FC->damaged & 6)
        {
            work->field_B32 |= 4;
        }
        if (work->field_900.damaged & 0x80)
        {
            work->field_B26 = 2;
        }
    }
}
int NearAsiato(void);
int SearchNearAsiato(HZD_HDL *hzd, SVECTOR *pos, int facedir, int range, int length);
int AsiatoCheck(HZD_HDL *hzd, SVECTOR *pos);

#ifdef MGS_PORT
/* Not matching yet: in the noise check's case 100, the PS1 keeps the distance in s0 and compares into v0; this
   compiles the compare into s0 (2 instructions differ; the other three functions match). Same behaviour. */
int s03d_800D1054(HZD_HDL *hzd, SVECTOR *vec1, SVECTOR *vec2)
{
    int from, to;

    from = HZD_GetAddress(hzd, vec1, -1);
    to = HZD_GetAddress(hzd, vec2, -1);
    from &= 0xFF;
    to &= 0xFF;
    return HZD_ZoneDistance(hzd, from, to);
}

void s03d_800D10B4(Work *work)
{
    CONTROL *control;
    int      dist;

    if (!(work->field_B33 & 0x1))
    {
        return;
    }

    control = &work->control;
    if (control->map->index != GM_PlayerMap)
    {
        return;
    }

    if (GM_NoisePower == 0)
    {
        return;
    }

    switch (GM_NoisePower)
    {
    case 5:
        if (GV_DiffVec3(&GM_NoisePosition, &control->mov) < 500)
        {
            work->field_B32 |= 0x1;
        }
        break;
    case 200:
        if (GV_DiffVec3(&GM_NoisePosition, &control->mov) < 4000)
        {
            work->field_B32 |= 0x1;
        }
        break;
    case 100:
        dist = GV_DiffVec3(&GM_NoisePosition, &control->mov);
        fprintf(1, (char *)s03d_dword_800DB5D4, dist);
        if (dist < 4000 && s03d_800D1054(control->map->hzd, &control->mov, &GM_NoisePosition) < 300)
        {
            work->field_B32 |= 0x1;
            GM_NoiseLength = 0;
            GM_NoisePower = 0;
        }
        break;
    case 255:
        work->field_B32 |= 0x1;
        break;
    }
}

void s03d_800D123C(Work *work)
{
    if (!(work->field_B33 & 0x2))
    {
        return;
    }
    if (work->field_B26 != 2)
    {
        return;
    }
    if (!(GM_PlayerStatus & PLAYER_CB_BOX))
    {
        return;
    }

    if (GV_DiffVec3(&work->field_B34, &GM_PlayerPosition) > 50 || work->field_B3C != GM_WhereList[0]->rot.vy)
    {
        if (ZAKOCOM_MGR->field_1C == 1)
        {
            return;
        }
        work->field_B34 = GM_PlayerPosition;
        work->field_B3C = GM_WhereList[0]->rot.vy;
        work->field_B32 |= 0x2;
    }

    work->field_B26 = 0;
}

void s03d_800D1324(Work *work)
{
    HZD_HDL *hzd;
    SVECTOR *pos;
    short   *vis;

    if (!(work->field_B33 & 0x10) || work->field_ACA == 5)
    {
        return;
    }

    hzd = work->control.map->hzd;
    pos = &work->control.mov;
    vis = (short *)&work->field_B20;

    if (AsiatoCheck(hzd, pos) && SearchNearAsiato(hzd, pos, vis[0], vis[1], vis[2]) >= 0)
    {
        work->field_B32 |= 0x10;
        fprintf(1, (char *)s03d_dword_800DB5E8, NearAsiato());
    }
}
#else
#pragma INCLUDE_ASM("asm/overlays/s03d/s03d_800D1054.s")
#endif
void Zako_800D13E8(Work *work)
{
    SVECTOR unused[2];

    (void)unused;
    work->field_B32 = 0;
}
void s03d_800D13F8(Work *work)
{
    switch (work->field_B26)
    {
    case 0:
        if (work->field_B28 != 255 || !(GM_PlayerStatus & PLAYER_INTRUDE))
        {
            work->field_B28 -= 4;
        }
        break;
    case 1:
        work->field_B28--;
        break;
    case 2:
        work->field_B28++;
        break;
    }

    if (work->field_B28 < 0)
    {
        work->field_B28 = 0;
    }
    else if (work->field_B28 > 255)
    {
        work->field_B28 = 255;
    }
}

#ifdef MGS_PORT
/* Not matching yet: the PS1 gives the guard's position pointer a higher register priority than the work
   pointer (s1/s2 swapped; 17 instructions differ). Same behaviour. */
extern SVECTOR s03d_dword_800C3AB0;

void s03d_800D14AC(Work *work)
{
    SVECTOR  diff;
    SVECTOR *mov;
    SVECTOR *player;

    mov = &work->control.mov;
    player = &GM_PlayerPosition;
    GV_SubVec3(&s03d_dword_800C3AB0, mov, &diff);
    *(int *)&work->field_B98 = GV_VecDir2(&diff);

    GV_SubVec3(player, mov, &diff);
    diff.vy = 0;
    *(int *)&work->field_B94 = GV_VecDir2(&diff);
    work->field_B90 = GV_VecLen3(&diff);
    work->field_B26 = 2;
}
#else
#pragma INCLUDE_ASM("asm/overlays/s03d/s03d_800D14AC.s")
#endif

void s03d_800D153C(Work *work)
{
    if (work->field_8E0 < 0x2D)
    {
        Zako_800D0FCC(work);
        s03d_800D14AC(work);
        Zako_800D13E8(work);
        s03d_800D13F8(work);
        s03d_800D3B5C(work);
        Zako_800D0F6C(work);
    }
    s03d_800D041C(work);
}

void s03d_800D15A8(Work *work)
{
    TARGET  *trg;
    CONTROL *ctrl;
    int      turn;
    int      last_set;

    trg = work->field_8FC;
    turn = 0;
    if (!(trg->damaged & TARGET_PUSH))
    {
        return;
    }

    GV_AddVec3(&trg->offset, &work->control.step, &work->control.step);
    trg->damaged &= ~TARGET_PUSH;

    last_set = work->field_8E0;
    if (last_set == 1 || last_set == 2)
    {
        if (trg->offset.pad != 0)
        {
            if (GV_Time & 0x100)
            {
                if (work->param.fAF8 & 1)
                {
                    turn = trg->offset.pad << 10;
                }
                else
                {
                    turn = (trg->offset.pad + 2) << 10;
                }
            }
            else
            {
                if (work->param.fAF8 & 1)
                {
                    turn = (trg->offset.pad + 2) << 10;
                }
                else
                {
                    turn = trg->offset.pad << 10;
                }
            }
            turn &= 0xFFF;
        }

        ctrl = &work->control;
        ctrl->turn.vy = turn;
        ctrl->r_sphere = GV_NearExp2(ctrl->r_sphere, work->field_8E2);
    }
}
