#pragma once
// 定数 ----------------------------------------------------------------
#define PL_WIDTH    (200)
#define PL_HEIGHT   (300)

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
    int posX = 0;
    int posY = 0;
    int sub_posX = 0; // playerの右下の座標
    int sub_posY = 0;
    int speed = 0;
    int plHND[4] = { 0 };
};