// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "scene_title.h"

// 変数 --------------------------------------------------------------------------------------------
// シーン遷移用変数
extern int nextScene;

// インスタンス宣言 ---------------------------------------------------------------------------------
TITLE title;


// 関数実体 ----------------------------------------------------------------------------------------
// 初期設定
void title_init(void)
{
    title.state = 0;
    title.timer = 0;
    title.bgHND = LoadGraph("Data\\Images\\title_bg.png");
}

// 更新処理
void title_update(void)
{
    switch (title.state)
    {
    case INIT:

        title.state++;
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
        if (Input::GetInstance()->GetALLButtonDown(PL_1))
        {
            nextScene = SCENE_GAME;
        }
        break;
    }
}

// 描画処理
void title_draw(void)
{
    DrawGraph(0, 0, title.bgHND, true);
}

// 終了処理
void title_end(void)
{
    DeleteGraph(title.bgHND);
}
