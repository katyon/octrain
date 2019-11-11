#pragma once
// 定数 ----------------------------------------------------------------

// クラス --------------------------------------------------------------
class GAME
{
public:
    static int timer;

    static void init(void);      // 初期設定
    static void update(void);    // 更新処理
    static void draw(void);      // 描画処理
    static void end(void);       // 終了処理
    static bool hitcheck_rect(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bh);
    static bool hitcheck_circle(int ax, int ay, int ar, int bx, int by, int br);

private:
    int state = 0;
    int bgHND = 0;
};