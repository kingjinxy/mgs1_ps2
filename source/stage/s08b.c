#define DECLARE_NEWCHARA_PROTOS
#include "charalst.h"

void *NewBlurSet(int name, int where);
void *NewGlassSet(int name, int where);
void *NewKetchap_s(int name, int where);

CHARA _StageCharacterEntries[] = {
    CHARA_ASIOTOKUN,    /* chara 足音君 */
    CHARA_FADEIO,       /* chara フェードイン・アウト */
    { 0x8e70, (NEWCHARA *)NewGlassSet }, //  CHARA_GLASS,        /* chara ガラス */
    CHARA_PAPER,        /* chara 書類 */
    CHARA_CHAIR,        /* chara 椅子 */
    CHARA_PANEL2,       /* chara パネル２ */
    CHARA_MONITOR1,     /* chara モニタ１ */
    CHARA_NINJA,        /* chara 忍者 */
    CHARA_TEXTURE,      /* chara テクスチャ */
    CHARA_CINEMA,       /* chara シネマスクリーン */
    CHARA_MOVIE,        /* chara ムービー */
    CHARA_WALL,         /* chara 障害物 */
    CHARA_LIFEUP,       /* chara ライフ増加 */
    CHARA_DYNWALL,      /* chara 透明壁 */
    CHARA_CAT_IN,       /* chara カットインカメラ */

    DEMO_FADEIN,
    DEMO_FADEOUT,
    DEMO_TEXT,
    DEMO_BREATH,
    DEMO_SHADOW,
    DEMO_NINJAEYE,
    DEMO_SCOPE,
    DEMO_IRRAYSGOGGLE,
    DEMO_IRRAYSGOGGLE2,
    DEMO_OPTICSCAMOUFLAGE,
    DEMO_OPTICSCAMOUFLAGE2,
    DEMO_UNSHAPEVIEW,
    { 0x0023, (NEWCHARA *)NewKetchap_s }, //  DEMO_URINATIONCIRCLE,
    { 0x0025, (NEWCHARA *)NewBlurSet }, //  DEMO_BLUR,
    DEMO_NINJASWORD,
    DEMO_GUSEFFECT,
    DEMO_TEXT2,

    CHARA_END
};
