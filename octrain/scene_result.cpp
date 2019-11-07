// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "scene_result.h"

// 変数 --------------------------------------------------------------------------------------------
// シーン遷移用変数
extern int nextScene;

// インスタンス宣言 ---------------------------------------------------------------------------------
RESULT result;


// 関数実体 ----------------------------------------------------------------------------------------
// 初期設定
void result_init(void)
{
    result.state = 0;
    result.timer = 0;
    result.bgHND = LoadGraph("Data\\Images\\result_bg.png");
}

// 更新処理
void result_update(void)
{
    switch (result.state)
    {
    case INIT:

        result.state++;
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

        break;
    }
}

// 描画処理
void result_draw(void)
{
    DrawGraph(0, 0, result.bgHND, true);
}

// 終了処理
void result_end(void)
{
    DeleteGraph(result.bgHND);
}
