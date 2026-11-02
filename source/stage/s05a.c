#define DECLARE_NEWCHARA_PROTOS
#include "charalst.h"

/* s05a's own constructors (no name for them in charalst.h) */
void *NewAnime_8005E258(int name, int where);
void *NewBlastLine(int name, int where);
void *NewM1E1(int name, int where);
void *s05a_800DBF58(int name, int where);
void *s05a_800E1134(int name, int where);

CHARA _StageCharacterEntries[] = {
    CHARA_ASIOTOKUN, /* chara 足音君 */
    CHARA_FADEIO, /* chara フェードイン・アウト */
    CHARA_SNOW, /* chara 雪 */
    CHARA_SNOWSTORM, /* chara 雪嵐 */
    { 0x9d71, (NEWCHARA *)NewM1E1 }, // CHARA_M1E1,
    { 0xd5ec, (NEWCHARA *)s05a_800E1134 }, // CHARA_M1E1CAME,
    CHARA_SHUTTER, /* chara シャッター */
    CHARA_CLAYMORE, /* chara クレイモア地雷 */
    CHARA_CINEMA, /* chara シネマスクリーン */
    CHARA_SPHERE2, /* chara 天球２ */
    CHARA_WALL, /* chara 障害物 */
    CHARA_CAMERAGUN, /* chara カメラ付随ガン */
    CHARA_TEXTURE, /* chara テクスチャ */
    CHARA_CAMERASHAKE, /* chara カメラ揺らし */
    CHARA_ASIATOKUN, /* chara 足跡君 */
    CHARA_GASEFFECT, /* chara ガス効果 */
    CHARA_DYNWALL, /* chara 透明壁 */
    CHARA_DYNFLOOR, /* chara 透明床 */
    CHARA_SNEBREATH, /* chara スネーク息 */
    CHARA_PADVIBRATE, /* chara パッド振動 */
    CHARA_PADCONTROL, /* chara パッドコントロール */

    DEMO_FADEIN,
    DEMO_FADEOUT,
    DEMO_TEXT,
    { 0x000c, (NEWCHARA *)NewAnime_8005E258 }, // DEMO_MISSILESMOKE,
    DEMO_SHADOW,
    DEMO_UNSHAPEVIEW,
    DEMO_BLUR,
    DEMO_BLACKSMOKE2,
    { 0x0030, (NEWCHARA *)NewBlastLine }, // DEMO_BLASTLINE,
    DEMO_SMOKELINE,
    { 0x0032, (NEWCHARA *)s05a_800DBF58 }, // DEMO_SHELLSMOKE,
    DEMO_GHOST,

    CHARA_END
};
