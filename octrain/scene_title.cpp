// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "scene_title.h"

// 変数 --------------------------------------------------------------------------------------------

// インスタンス宣言 ---------------------------------------------------------------------------------
TITLE title;

// 関数実体 ----------------------------------------------------------------------------------------
// 初期設定
void TITLE::init(void)
{
    title.state = 0;
    title.timer = 0;
    title.bgHND = LoadGraph("Data\\Images\\title_bg.png");
}

// 更新処理
void TITLE::update(void)
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
        if (Input::GetInstance()->GetALLButtonDown(PL_1))
        {
            COMMON::nextScene = SCENE_GAME;
        }
        break;
    }
}

// 描画処理
void TITLE::draw(void)
{
    DrawGraph(0, 0, title.bgHND, true);

    // debug-----------
    unsigned int  Cr = GetColor(200, 0, 0);
    DrawFormatString(0, 0, Cr, "タイトル:1");
    DrawFormatString(0, 20, Cr, "ゲーム:2");
    DrawFormatString(0, 40, Cr, "リザルト:3");

    //-----------------
}

// 終了処理
void TITLE::end(void)
{
    DeleteGraph(title.bgHND);
}
