#pragma once
// 定数 ----------------------------------------------------------------

// クラス --------------------------------------------------------------
class BOSS
{
private:
    int state = 0;
    int timer = 0;
    int bs_posX = 0;
    int bs_posY = 0;
    int bs_subposX = 0; // playerの右下の座標
    int bs_subposY = 0;
    int bs_speed = 0;
    int bsHND = 0;

public:
    static void init(void);      // 初期設定
    static void update(void);    // 更新処理
    static void draw(void);      // 描画処理
    static void end(void);       // 終了処理

    //static void shot(int shot_posX, int shot_posY);

};