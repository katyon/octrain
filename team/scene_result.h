#pragma once
// 定数 ----------------------------------------------------------------

// クラス --------------------------------------------------------------
class RESULT
{
public:
    int state = 0;
    int timer = 0;
    int bgHND = 0;
};

// プロトタイプ宣言 -----------------------------------------------------
void result_init(void);      // 初期設定
void result_update(void);    // 更新処理
void result_draw(void);      // 描画処理
void result_end(void);       // 終了処理