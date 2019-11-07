#pragma once
// 定数 ----------------------------------------------------------------

// クラス --------------------------------------------------------------
class PLAYER
{
public:
    int state = 0;
    int timer = 0;
    int pl_posX = 0;
    int pl_posY = 0;
    int pl_speed = 0;
    int plHND = 0;
};

// プロトタイプ宣言 -----------------------------------------------------
void player_init(void);      // 初期設定
void player_update(void);    // 更新処理
void player_draw(void);      // 描画処理
void player_end(void);       // 終了処理