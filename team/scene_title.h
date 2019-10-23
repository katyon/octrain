#pragma once
// 定数 ----------------------------------------------------------------

// クラス --------------------------------------------------------------
class TITLE
{
public:
    int state = 0;
    int timer = 0;
    int bgHND = 0;
};

// プロトタイプ宣言 -----------------------------------------------------
void title_init(void);      // 初期設定
void title_update(void);    // 更新処理
void title_draw(void);      // 描画処理
void title_end(void);       // 終了処理