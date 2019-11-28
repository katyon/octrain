#pragma once

#include "shot.h"
// 定数 ----------------------------------------------------------------
#define PL_WIDTH    (300)
#define PL_HEIGHT   (332)
#define CLOSE_RANGE (140)

// クラス --------------------------------------------------------------
class PLAYER
{
public:
    static float posX;
    static float posY;
    static float pivot_posX;
    static float pivot_posY;
    static int hp;
    static bool detect_hit;         // true:当たってる
    static bool detect_closerange;  // true:近接範囲内
    static bool detect_deth;        // true:死亡
    static bool detect_reverse;     // true:反転

    static void init(void);     // 初期設定
    static void update(void);   // 更新処理
    static void draw(void);     // 描画処理
    static void end(void);      // 終了処理

private:
    int state = 0;
    int hit_timer = 0;
    int at_timer = 0;
    int close_at1_timer = 0;
    int close_at2_timer = 0;
    float sub_posX = 0;     // playerの右下の座標
    float sub_posY = 0;
    float speed = 0;
    int init_hp = 0;
    int sub_hp = 0;
    int init_bullet = 0;
    int bullet = 0;
    int bullet_count = 0;
    int power = 0;
    bool detect_attack = false;         // true:攻撃中
    bool detect_close_attack1 = false;  // true:攻撃中
    bool detect_close_attack2 = false;  // true:攻撃中

    static int guard_timer; //ガードエフェクト用
    static int zangeki_seHND;
    static int shot_seHND;
    static int guard_seHND;
    static int reload_seHND;
};