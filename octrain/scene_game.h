#pragma once
// 定数 ----------------------------------------------------------------
#include "shot.h"

// クラス --------------------------------------------------------------
class GAME
{
public:
    static int timer;
    static int spriteHND;
    static bool zoom_mode;  // trueでズーム

    static void init(void);      // 初期設定
    static void update(void);    // 更新処理
    static void draw(void);      // 描画処理
    static void end(void);       // 終了処理
    static bool hitcheck_rect(float ax, float ay, int aw, int ah, float bx, float by, int bw, int bh);
    static bool hitcheck_circle(float ax, float ay, int ar, float bx, float by, int br);

private:
    int state = 0;
    int bgHND = 0;
    int zoomHND = 0;
};