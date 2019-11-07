#pragma once
// 定数 ----------------------------------------------------------------

// クラス --------------------------------------------------------------
class GAME
{
public:
    static void init(void);      // 初期設定
    static void update(void);    // 更新処理
    static void draw(void);      // 描画処理
    static void end(void);       // 終了処理

private:
    int state = 0;
    int timer = 0;
    int bgHND = 0;
    int brackHND = 0;
};