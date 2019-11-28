#pragma once
// 定数 ----------------------------------------------------------------
#include "shot.h"

enum LEVEL
{
    LEVEL1,
    LEVEL2,
    LEVEL3,
    LEVEL4,
    LEVEL5,
    LEVEL6,
};

// クラス --------------------------------------------------------------
class GAME
{
public:
    static int state;
    static int timer;
    static int spriteHND;
    static bool zoom_mode;  // trueでズーム

    static int tutorial_lv;

    static void init(void);      // 初期設定
    static void game_init(void);
    static void update(void);    // 更新処理
    static void draw(void);      // 描画処理
    static void end(void);       // 終了処理
    static bool hitcheck_rect(float ax, float ay, int aw, int ah, float bx, float by, int bw, int bh);
    static bool hitcheck_circle(float ax, float ay, int ar, float bx, float by, int br);
    static bool hitcheck_circle_withrect(float ax, float ay, int ar, float bx, float by, int bw, int bh);

private:
    int bgHND = 0;
    int zoomHND = 0;
    int efHND = 0;

    static int bgmHND;
    static int clearHND0;
    static int gameoverHND;


    static int decision_seHND; //決定音
    static int select_seHND;

    static int damage_seHND;
    static int shot_attackHND;
};