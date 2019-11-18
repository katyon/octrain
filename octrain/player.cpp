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
    player.pivot_posX = 0;
    player.pivot_posY = 0;
    player.speed = 10;
    player.init_hp = 500;
    player.hp = player.init_hp;
    player.sub_hp = player.init_hp;
    player.init_bullet = 10;
    player.bullet = player.init_bullet;
    player.power = 0;
    LoadDivGraph("Data\\Images\\player.png", 4, 4, 1, 240, 332, player.plHND);
    player.bulletHND = LoadGraph("Data\\Images\\bullet.png");
    player.hpHND = LoadGraph("Data\\Images\\hp.png");
    player.sub_hpHND = LoadGraph("Data\\Images\\sub_hp.png");
    player.zoomHND = MakeGraph(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT);
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
    if (Input::GetInstance()->GetButton(PL_1, XINPUT_BUTTON_RIGHT_SHOULDER))
    {
        player.hp -= 10;
    }
    if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_LEFT_SHOULDER))
    {
        player.hp = player.init_hp;
    }
    //----------------------------------------------------------------
    // 移動
#pragma region LeftThumb
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Up))
    {
        player.posY -= player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Upper_Right))
    {
        player.posX += player.speed / 2;
        player.posY -= player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Upper_Right))
    {
        player.posX += player.speed;
        player.posY -= player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Upper_Right))
    {
        player.posX += player.speed;
        player.posY -= player.speed / 2;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Right))
    {
        player.posX += player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Lower_Right))
    {
        player.posX += player.speed;
        player.posY += player.speed / 2;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Lower_Right))
    {
        player.posX += player.speed;
        player.posY += player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Lower_Right))
    {
        player.posX += player.speed / 2;
        player.posY += player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Down))
    {
        player.posY += player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Lower_Left))
    {
        player.posX -= player.speed / 2;
        player.posY += player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Lower_Left))
    {
        player.posX -= player.speed;
        player.posY += player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Lower_Left))
    {
        player.posX -= player.speed;
        player.posY += player.speed / 2;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Left))
    {
        player.posX -= player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Upper_Left))
    {
        player.posX -= player.speed;
        player.posY -= player.speed / 2;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Upper_Left))
    {
        player.posX -= player.speed;
        player.posY -= player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Upper_Left))
    {
        player.posX -= player.speed / 2;
        player.posY -= player.speed;
    }
#pragma endregion

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

    // bullet
    if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_A))
    {
        player.bullet -= 1;
    }
    if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_B))
    {
        player.bullet -= 2;
    }
    if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_X))
    {
        player.bullet = player.init_bullet;
    }
    if (player.bullet < 0)
    {
        player.bullet = 0;
    }
    player.sub_posX = player.posX + PL_WIDTH - 1;
    player.sub_posY = player.posY + PL_HEIGHT - 1;
    player.pivot_posX = player.posX + PL_WIDTH / 2;
    player.pivot_posY = player.posY + PL_HEIGHT / 2;
}

// 描画処理
void PLAYER::draw(void)
{
    DrawExtendGraphF(player.posX, player.posY, player.sub_posX, player.sub_posY, player.plHND[GAME::timer / 7 % 4], true);
    // UI
    for (int i = 0; i < player.init_hp; i++)
    {
        DrawGraph(i, 0, player.sub_hpHND, true);
    }
    for (int i = 0; i < player.hp; i++)
    {
        DrawGraph(i, 0, player.hpHND, true);
    }
    for (int i = 0; i < player.bullet; i++)
    {
        DrawGraph(i * 70, 70, player.bulletHND, true);
    }

    // debug------------------------------------------------------------------------
    GetDrawScreenGraph(0, 0, GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, player.zoomHND);
    if (GAME::zoom_mode)
        DrawRotaGraph2(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 2, player.pivot_posX, player.pivot_posY, 1.5, 0, player.zoomHND, false, false);
    unsigned int  Cr = GetColor(200, 0, 0);
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Not))
    {
        DrawFormatString(0, 80, Cr, "LeftThumb:Not");
    }
    else
    {
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Up))
            DrawFormatString(0, 80, Cr, "LeftThumb:Up");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Upper_Right))
            DrawFormatString(0, 80, Cr, "LeftThumb:Before_Upper_Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Upper_Right))
            DrawFormatString(0, 80, Cr, "LeftThumb:Upper_Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Upper_Right))
            DrawFormatString(0, 80, Cr, "LeftThumb:After_Upper_Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Right))
            DrawFormatString(0, 80, Cr, "LeftThumb:Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Lower_Right))
            DrawFormatString(0, 80, Cr, "LeftThumb:Before_Lower_Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Lower_Right))
            DrawFormatString(0, 80, Cr, "LeftThumb:Lower_Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Lower_Right))
            DrawFormatString(0, 80, Cr, "LeftThumb:After_Lower_Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Down))
            DrawFormatString(0, 80, Cr, "LeftThumb:Down");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Lower_Left))
            DrawFormatString(0, 80, Cr, "LeftThumb:Before_Lower_Left");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Lower_Left))
            DrawFormatString(0, 80, Cr, "LeftThumb:Lower_Left");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Lower_Left))
            DrawFormatString(0, 80, Cr, "LeftThumb:After_Lower_Left");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Left))
            DrawFormatString(0, 80, Cr, "LeftThumb:Left");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Upper_Left))
            DrawFormatString(0, 80, Cr, "LeftThumb:Before_Upper_Left");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Upper_Left))
            DrawFormatString(0, 80, Cr, "LeftThumb:Upper_Left");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Upper_Left))
            DrawFormatString(0, 80, Cr, "LeftThumb:After_Upper_Left");
    }

    DrawFormatStringF(100, 0, Cr, "hitcheck_rect:%d", GAME::hitcheck_rect(player.posX, player.posY, PL_WIDTH, PL_HEIGHT, 0, 0, 100, 100));
    DrawFormatString(300, 0, Cr, "player.hp:%d", player.hp);
    DrawFormatString(300, 20, Cr, "player.sub_hp:%d", player.sub_hp);
    DrawFormatString(300, 40, Cr, "bullet:%d", player.bullet);

    DrawBox(player.posX, player.posY, player.posX + PL_WIDTH - 1, player.posY + PL_HEIGHT - 1, Cr, false);
    //---------------------------------------------------------------------------------------------------------
}

// 終了処理
void PLAYER::end(void)
{
    for (int i = 0; i < 4; i++)DeleteGraph(player.plHND[i]);
}
