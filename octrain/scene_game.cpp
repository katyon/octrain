// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "player.h"
#include "scene_game.h"

#include <math.h>

// 変数 --------------------------------------------------------------------------------------------

// インスタンス宣言 ---------------------------------------------------------------------------------
GAME game;

int GAME::timer = 0;
// 関数実体 ----------------------------------------------------------------------------------------
// 初期設定
void GAME::init(void)
{
    game.state = 0;
    game.timer = 0;
    game.bgHND = LoadGraph("Data\\Images\\game_bg.png");

    PLAYER::init();
}

// 更新処理
void GAME::update(void)
{
    switch (game.state)
    {
    case INIT:

        game.state++;
        break;
    case UPDATE:

        PLAYER::update();

        game.timer++;
        // debug
        if (CheckHitKey(KEY_INPUT_1))
        {
            COMMON::nextScene = SCENE_TITLE;
        }
        if (CheckHitKey(KEY_INPUT_2))
        {
            COMMON::nextScene = SCENE_GAME;
        }
        if (CheckHitKey(KEY_INPUT_3))
        {
            COMMON::nextScene = SCENE_RESULT;
        }
        //------
        break;
    }
}

// 描画処理
void GAME::draw(void)
{
    DrawGraph(0, 0, game.bgHND, true);

    PLAYER::draw();
    // debug-----------
    unsigned int  Cr = GetColor(200, 0, 0);
    DrawFormatString(0, 0, Cr, "タイトル:1");
    DrawFormatString(0, 20, Cr, "ゲーム:2");
    DrawFormatString(0, 40, Cr, "リザルト:3");
    //-----------------
}

// 終了処理
void GAME::end(void)
{
    DeleteGraph(game.bgHND);

    PLAYER::end();
}

bool GAME::hitcheck_rect(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bh)
{
    if (bx < (ax + aw) && ax < (bx + bw) && by < (ay + ah) && ay < (by + bh))
    {
        return true;
    }
    return false;
}

bool GAME::hitcheck_circle(int ax, int ay, int ar, int bx, int by, int br)
{
    float a = ax - bx;
    float b = ay - by;
    int c = a * a + b * b;
    c = sqrt(c);

    if (c <= ar + br)
    {
        return true;
    }
    return false;
}