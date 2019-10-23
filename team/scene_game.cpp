// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "player.h"
#include "scene_game.h"

// 変数 --------------------------------------------------------------------------------------------
// シーン遷移用変数
extern int nextScene;

// インスタンス宣言 ---------------------------------------------------------------------------------
GAME game;


// 関数実体 ----------------------------------------------------------------------------------------
// 初期設定
void game_init(void)
{
    game.state = 0;
    game.timer = 0;
    game.bgHND = LoadGraph("Data\\Images\\game_bg.png");

    player_init();
}

// 更新処理
void game_update(void)
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
            nextScene = SCENE_TITLE;
        }
        if (CheckHitKey(KEY_INPUT_2))
        {
            nextScene = SCENE_GAME;
        }
        if (CheckHitKey(KEY_INPUT_3))
        {
            nextScene = SCENE_RESULT;
        }
        //------

        player_update();
        break;
    }
}

// 描画処理
void game_draw(void)
{
    DrawGraph(0, 0, game.bgHND, true);

    player_draw();
}

// 終了処理
void game_end(void)
{
    DeleteGraph(game.bgHND);

    player_end();
}
