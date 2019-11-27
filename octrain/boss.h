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
    static int hp;
    static bool detect_hit;     // trueで当たってる
    static bool detect_deth;    // trueで死亡
    static bool detect_reverse; // trueで反転
    static bool detect_damaged;
    static bool detect_close_damaged;

    static void init(void);     // 初期設定
    static void update(void);   // 更新処理
    static void draw(void);     // 描画処理
    static void end(void);      // 終了処理

    enum PATTERN
    {
        N_Diffusion, N_Homing, N_Column,
        SPK_1, SPK_2, SPK_3
    };

private:
    int state = 0;
    int hit_timer = 0;
    int damaged_timer = 0;
    int close_damaged_timer = 0;
    int at_timer = 0;
    int move_timer = 0;
    float pivot_posX = 0;   // bossの中心座標
    float pivot_posY = 0;
    float speed = 0;
    int sub_hp = 0;
    int N_attack = 0;
    int SPK_attack = 0;
    int rnd_move_pattern = 0;
    bool detect_attack = false;
    bool detect_useSPK = false;
};