// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "scene_result.h"

// 変数 --------------------------------------------------------------------------------------------

// インスタンス宣言 ---------------------------------------------------------------------------------
RESULT result;


// 関数実体 ----------------------------------------------------------------------------------------
// 初期設定
void RESULT::init(void)
{
    result.state = 0;
    result.timer = 0;
    result.bgHND = LoadGraph("Data\\Images\\result_bg.png");
}

// 更新処理
void RESULT::update(void)
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
void RESULT::draw(void)
{
    DrawGraph(0, 0, result.bgHND, true);
    // debug-----------
    unsigned int  Cr = GetColor(200, 0, 0);
    DrawFormatString(0, 0, Cr, "タイトル:1");
    DrawFormatString(0, 20, Cr, "ゲーム:2");
    DrawFormatString(0, 40, Cr, "リザルト:3");

    //-----------------
}

// 終了処理
void RESULT::end(void)
{
    DeleteGraph(result.bgHND);
}
