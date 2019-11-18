#pragma once
// 定数 ----------------------------------------------------------------
#define PL_WIDTH    (240)
#define PL_HEIGHT   (332)

// クラス --------------------------------------------------------------
class PLAYER
{
public:
    static void init(void);      // 初期設定
    static void update(void);    // 更新処理
    static void draw(void);      // 描画処理
    static void end(void);       // 終了処理

private:
    int state = 0;
    float posX = 0;
    float posY = 0;
    float sub_posX = 0; // playerの右下の座標
    float sub_posY = 0;
    float pivot_posX = 0; // playerの中心座標
    float pivot_posY = 0;
    float speed = 0;
    int init_hp = 0;
    int hp = 0;
    int sub_hp = 0;
    int init_bullet = 0;
    int bullet = 0;
    int power = 0;
    int plHND[4] = { 0 };
    int bulletHND = 0;
    int hpHND = 0;
    int sub_hpHND = 0;
    int zoomHND = 0;
};