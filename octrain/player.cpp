// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "player.h"
#include "scene_game.h"

// 変数 --------------------------------------------------------------------------------------------

// インスタンス宣言 ---------------------------------------------------------------------------------
PLAYER player;

// 関数実体 ----------------------------------------------------------------------------------------
// 初期設定
void PLAYER::init(void)
{
    player.state = 0;
    player.posX = 0;
    player.posY = 0;
    player.sub_posX = 0;
    player.sub_posY = 0;
    player.speed = 10;
    LoadDivGraph("Data\\Images\\player.png", 4, 4, 1, 240, 332, player.plHND);
}

// 更新処理
void PLAYER::update(void)
{
    // debug--------------------------------------------------------
    if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A))
    {
        player.posX -= player.speed;
    }
    if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D))
    {
        player.posX += player.speed;
    }
    if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W))
    {
        player.posY -= player.speed;
    }
    if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S))
    {
        player.posY += player.speed;
    }
    //----------------------------------------------------------------

    // 移動
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Left))
    {
        player.posX -= player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Right))
    {
        player.posX += player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Up))
    {
        player.posY -= player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Down))
    {
        player.posY += player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Down))
    {

    }


    // 移動制限
    if (player.posX < 0)
    {
        player.posX = 0;
    }
    if (player.posX > GAME_SCREEN_WIDTH - PL_WIDTH + 1)
    {
        player.posX = GAME_SCREEN_WIDTH - PL_WIDTH + 1;
    }
    if (player.posY < 0)
    {
        player.posY = 0;
    }
    if (player.posY > GAME_SCREEN_HEIGHT - PL_HEIGHT + 1)
    {
        player.posY = GAME_SCREEN_HEIGHT - PL_HEIGHT + 1;
    }

    player.sub_posX = player.posX + PL_WIDTH - 1;
    player.sub_posY = player.posY + PL_HEIGHT - 1;
}

// 描画処理
void PLAYER::draw(void)
{
    DrawExtendGraph(player.posX, player.posY, player.sub_posX, player.sub_posY, player.plHND[GAME::timer / 7 % 4], true);

    // debug------------------------
    unsigned int  Cr = GetColor(200, 0, 0);
    DrawFormatString(100, 0, Cr, "hitcheck_rect:%d", GAME::hitcheck_rect(player.posX, player.posY, PL_WIDTH, PL_HEIGHT, 0, 0, 100, 100));
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Not))
    {
        DrawFormatString(100, 20, Cr, "LeftThumb:Not");
    }
    else
    {
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Up))
            DrawFormatString(100, 20, Cr, "LeftThumb:Up");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Upper_Right))
            DrawFormatString(100, 20, Cr, "LeftThumb:Before_Upper_Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Upper_Right))
            DrawFormatString(100, 20, Cr, "LeftThumb:Upper_Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Upper_Right))
            DrawFormatString(100, 20, Cr, "LeftThumb:After_Upper_Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Right))
            DrawFormatString(100, 20, Cr, "LeftThumb:Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Lower_Right))
            DrawFormatString(100, 20, Cr, "LeftThumb:Before_Lower_Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Lower_Right))
            DrawFormatString(100, 20, Cr, "LeftThumb:Lower_Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Lower_Right))
            DrawFormatString(100, 20, Cr, "LeftThumb:After_Lower_Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Down))
            DrawFormatString(100, 20, Cr, "LeftThumb:Down");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Lower_Left))
            DrawFormatString(100, 20, Cr, "LeftThumb:Before_Lower_Left");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Lower_Left))
            DrawFormatString(100, 20, Cr, "LeftThumb:Lower_Left");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Lower_Left))
            DrawFormatString(100, 20, Cr, "LeftThumb:After_Lower_Left");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Left))
            DrawFormatString(100, 20, Cr, "LeftThumb:Left");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Upper_Left))
            DrawFormatString(100, 20, Cr, "LeftThumb:Before_Upper_Left");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Upper_Left))
            DrawFormatString(100, 20, Cr, "LeftThumb:Upper_Left");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Upper_Left))
            DrawFormatString(100, 20, Cr, "LeftThumb:After_Upper_Left");
    }

    DrawBox(player.posX, player.posY, player.posX + PL_WIDTH - 1, player.posY + PL_HEIGHT - 1, Cr, false);
    //---------------------------
}

// 終了処理
void PLAYER::end(void)
{
    for (int i = 0; i < 4; i++)DeleteGraph(player.plHND[i]);
}
