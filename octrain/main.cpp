// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "player.h"
#include "scene_game.h"
#include "scene_result.h"

// インスタンス宣言 ---------------------------------------------------------------------------------
COMMON common;

int COMMON::curScene = 0;
int COMMON::nextScene = 0;
// WinMain -----------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ウインドウモードで起動
    //ChangeWindowMode(TRUE);

    // フルスクリーンモードで起動
    ChangeWindowMode(FALSE);

    // ゲーム画面の解像度を設定(32ビットカラー(フルカラー))
    SetGraphMode(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, 32);

    // 背景を黒に
    SetBackgroundColor(0, 0, 0);

    // ウインドウのタイトルを設定
    SetMainWindowText("sougetu");

    // ブレンドモードの設定(ノーブレンド)
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    // ゲームシーンの設定




















    COMMON::curScene = SCENE_GAME;
    COMMON::nextScene = SCENE_GAME;

    // ライブラリの初期化
    if (DxLib_Init() < 0)
        return -1;

    // タイトルの初期設定
    GAME::init();

    // フォントデータの読み込み





















    common.font = CreateFontToHandle("GauFontLoveRocketNeo", 70, 1, DX_FONTTYPE_ANTIALIASING);

    // 描画先を裏画面にする
    SetDrawScreen(DX_SCREEN_BACK);

    // InputClass
    Input::Create();
    Input::GetInstance()->Init();

    // ESCキーが押されるか、ウインドウが閉じられるまでループ
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // 画面をクリア
        ClearDrawScreen();

        clsDx();

        // 入力状態の更新処理
        Input::GetInstance()->Updata();

        // ゲームシーン切り替え
        if (COMMON::nextScene != COMMON::curScene)
        {
            // 現シーンの終了処理を行う
#pragma region NowEnd
            switch (COMMON::curScene)
            {
            case SCENE_GAME:
                GAME::end();
                break;
            case SCENE_RESULT:
                RESULT::end();
                break;
            }
#pragma endregion
            // 次シーンの初期化を行う
#pragma region NextInitialize
            switch (COMMON::nextScene)
            {
            case SCENE_GAME:
                GAME::init();
                break;
            case SCENE_RESULT:
                RESULT::init();
                break;
            }
#pragma endregion
            COMMON::curScene = COMMON::nextScene;
        }

        // 現在のシーンの更新処理
#pragma region NowUpdate
        switch (COMMON::curScene)
        {
        case SCENE_GAME:
            GAME::update();
            break;
        case SCENE_RESULT:
            RESULT::update();
            break;
        }
#pragma endregion

        // 現在のシーンの描画処理
#pragma region NowDraw
        switch (COMMON::curScene)
        {
        case SCENE_GAME:
            GAME::draw();
            break;
        case SCENE_RESULT:
            RESULT::draw();
            break;
        }
#pragma endregion

        // 裏画面の内容を表画面に反映
        ScreenFlip();
    }

    // 現在のシーンの終了処理
#pragma region NowEnd
    switch (COMMON::curScene)
    {
    case SCENE_GAME:
        GAME::end();
        break;
    case SCENE_RESULT:
        RESULT::end();
        break;
    }
#pragma endregion

    // お片付け
    Input::Destroy();

    // 全グラフィックの削除
    DxLib::InitGraph();

    // 全音データの削除
    InitSoundMem();

    // ライブラリの終了処理
    DxLib::DxLib_End();

    // ソフト終了
    return 0;
}