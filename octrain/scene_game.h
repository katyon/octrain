#pragma once
// 定数 ----------------------------------------------------------------

// クラス --------------------------------------------------------------
class GAME
{
public:
    int state = 0;
    int timer = 0;
    int bgHND = 0;
};

// プロトタイプ宣言 -----------------------------------------------------
void game_init(void);      // 初期設定
void game_update(void);    // 更新処理
void game_draw(void);      // 描画処理
void game_end(void);       // 終了処理