// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "player.h"
#include "boss.h"
#include "shot.h"
#include "scene_game.h"

// 変数 --------------------------------------------------------------------------------------------

// インスタンス宣言 ---------------------------------------------------------------------------------
GAME game;

// 関数実体 ----------------------------------------------------------------------------------------
// 初期設定
void GAME::init(void)
{
    game.state = 0;
    game.timer = 0;
    game.bgHND = LoadGraph("Data\\Images\\game_bg.png");
    game.brackHND = LoadGraph("Data\\Images\\brack.png");

    PLAYER::init();
    BOSS::init();
    BULLET::init();
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

        PLAYER::update();
        BOSS::update();
        BULLET::update();
        break;
    }
}

// 描画処理
void GAME::draw(void)
{
    DrawGraph(0, 0, game.bgHND, true);
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
    DrawGraph(0, 0, game.brackHND, true);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    PLAYER::draw();
    BOSS::draw();
    BULLET::draw();
}

// 終了処理
void GAME::end(void)
{
    DeleteGraph(game.bgHND);
    DeleteGraph(game.brackHND);

    PLAYER::end();
    BOSS::end();
    BULLET::end();
}
