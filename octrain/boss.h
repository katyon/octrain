#pragma once
// 定数 ----------------------------------------------------------------
#define BOSS_WIDTH    (168)
#define BOSS_HEIGHT   (248)
#define BOSS_HP (600)

// クラス --------------------------------------------------------------
class BOSS
{
public:
    static float posX;
    static float posY;
    static bool detect_hit;     // trueで当たってる
    static bool detect_deth;    // trueで死亡
    static bool detect_reverse; // trueで反転

    static void init(void);     // 初期設定
    static void update(void);   // 更新処理
    static void draw(void);     // 描画処理
    static void end(void);      // 終了処理

private:
    int state = 0;
    int hit_timer = 0;
    int at_timer = 0;
    float pivot_posX = 0;   // bossの中心座標
    float pivot_posY = 0;
    float speed = 0;
    int hp = 0;
    int sub_hp = 0;
    bool detect_attack = false;
};