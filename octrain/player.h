#pragma once
// 定数 ----------------------------------------------------------------

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
    int timer = 0;
    int pl_posX = 0;
    int pl_posY = 0;
    int pl_subposX = 0; // playerの右下の座標
    int pl_subposY = 0;
    int pl_speed = 0;
    int plHND = 0;
};