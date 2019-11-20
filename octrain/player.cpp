// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "player.h"
#include "scene_game.h"

// インスタンス宣言 ---------------------------------------------------------------------------------
PLAYER player;

float PLAYER::posX = 0;
float PLAYER::posY = 0;
int PLAYER::hp = 0;
bool PLAYER::detect_hit = false;
bool PLAYER::detect_deth = false;
// 関数実体 ----------------------------------------------------------------------------------------
// 初期設定
void PLAYER::init(void)
{
    player.state = 0;
    player.hit_timer = 0;
    player.at_timer = 0;
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
    player.detect_hit = false;
    player.detect_deth = false;
    player.detect_attack = false;
}

// 更新処理
void PLAYER::update(void)
{
    // debug--------------------------------------------------------
    if (CheckHitKey(KEY_INPUT_A))
    {
        player.posX -= player.speed;
    }
    if (CheckHitKey(KEY_INPUT_D))
    {
        player.posX += player.speed;
    }
    if (CheckHitKey(KEY_INPUT_W))
    {
        player.posY -= player.speed;
    }
    if (CheckHitKey(KEY_INPUT_S))
    {
        player.posY += player.speed;
    }
    if (Input::GetInstance()->GetButton(PL_1, XINPUT_BUTTON_RIGHT_SHOULDER))
    {
        player.hp = player.init_hp;
    }
    if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_LEFT_SHOULDER))
    {
        player.hp -= 10;
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
        player.posX += player.speed / ROOT5;
        player.posY -= player.speed / ROOT5 * 2;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Upper_Right))
    {
        player.posX += player.speed / ROOT2;
        player.posY -= player.speed / ROOT2;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Upper_Right))
    {
        player.posX += player.speed / ROOT5 * 2;
        player.posY -= player.speed / ROOT5;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Right))
    {
        player.posX += player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Lower_Right))
    {
        player.posX += player.speed / ROOT5 * 2;
        player.posY += player.speed / ROOT5;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Lower_Right))
    {
        player.posX += player.speed / ROOT2;
        player.posY += player.speed / ROOT2;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Lower_Right))
    {
        player.posX += player.speed / ROOT5;
        player.posY += player.speed / ROOT5 * 2;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Down))
    {
        player.posY += player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Lower_Left))
    {
        player.posX -= player.speed / ROOT5;
        player.posY += player.speed / ROOT5 * 2;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Lower_Left))
    {
        player.posX -= player.speed / ROOT2;
        player.posY += player.speed / ROOT2;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Lower_Left))
    {
        player.posX -= player.speed / ROOT5 * 2;
        player.posY += player.speed / ROOT5;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Left))
    {
        player.posX -= player.speed;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Before_Upper_Left))
    {
        player.posX -= player.speed / ROOT5 * 2;
        player.posY -= player.speed / ROOT5;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Upper_Left))
    {
        player.posX -= player.speed / ROOT2;
        player.posY -= player.speed / ROOT2;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::After_Upper_Left))
    {
        player.posX -= player.speed / ROOT5;
        player.posY -= player.speed / ROOT5 * 2;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Up))
    {
        player.posY -= player.speed / 3;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Right))
    {
        player.posX += player.speed / 3;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Down))
    {
        player.posY += player.speed / 3;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Left))
    {
        player.posX -= player.speed / 3;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Upper_Right))
    {
        player.posX += player.speed / ROOT2 / 3;
        player.posY -= player.speed / ROOT2 / 3;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Lower_Right))
    {
        player.posX += player.speed / ROOT2 / 3;
        player.posY += player.speed / ROOT2 / 3;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Lower_Left))
    {
        player.posX -= player.speed / ROOT2 / 3;
        player.posY += player.speed / ROOT2 / 3;
    }
    if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Upper_Left))
    {
        player.posX -= player.speed / ROOT2 / 3;
        player.posY -= player.speed / ROOT2 / 3;
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

    // hit
    if (player.detect_hit == true)
    {
        player.hit_timer++;
        if (player.hit_timer > 100)
        {
            player.hit_timer = 0;
            player.detect_hit = false;
        }
    }

    // bullet
    // debug(CheckHitKeyのみ)
    if (player.detect_attack == true)
    {
        player.at_timer++;
        if (player.at_timer > 10)
        {
            player.at_timer = 0;
            player.detect_attack = false;
        }
    }
    else
    {
        if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_A) || CheckHitKey(KEY_INPUT_X))
        {
            player.bullet -= 1;
            player.detect_attack = true;
        }
    }
    if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_B))
    {
        player.bullet -= 2;
    }
    if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_X) || CheckHitKey(KEY_INPUT_R))
    {
        player.bullet = player.init_bullet;
    }
    if (player.bullet < 0)
    {
        player.bullet = 0;
    }
    if (player.hp <= 0)
    {
        player.hp = 0;
        player.detect_deth = true;
    }
    player.sub_posX = player.posX + PL_WIDTH - 1;
    player.sub_posY = player.posY + PL_HEIGHT - 1;
    player.pivot_posX = player.posX + PL_WIDTH / 2;
    player.pivot_posY = player.posY + PL_HEIGHT / 2;
}

// 描画処理
void PLAYER::draw(void)
{
    if (player.detect_hit == true)
    {
        if (player.hit_timer / 15 % 2)
        {
            DrawRectGraphF(player.posX, player.posY, PL_WIDTH * (GAME::timer / 7 % 4), 0, PL_WIDTH, PL_HEIGHT, GAME::spriteHND, true, false, false);
        }
    }
    else
    {
        DrawRectGraphF(player.posX, player.posY, PL_WIDTH * (GAME::timer / 7 % 4), 0, PL_WIDTH, PL_HEIGHT, GAME::spriteHND, true, false, false);
    }
    // UI
    DrawRectGraph(0, 0, 2088, 64, player.init_hp, 64, GAME::spriteHND, true, false, false);
    DrawRectGraph(0, 0, 2088, 0, player.hp, 64, GAME::spriteHND, true, false, false);
    for (int i = 0; i < player.bullet; i++)
    {
        DrawRectGraph(i * 70, 70, 960, 0, 66, 66, GAME::spriteHND, true, false, false);
    }

    // debug------------------------------------------------------------------------
    unsigned int  Cr = GetColor(200, 0, 0);

    DrawFormatString(400, 0, Cr, "player.hp:%d", player.hp);
    DrawFormatString(400, 20, Cr, "player.sub_hp:%d", player.sub_hp);
    DrawFormatString(400, 40, Cr, "bullet:%d", player.bullet);
    DrawFormatString(400, 60, Cr, "hit_timer:%d", player.hit_timer);
    DrawFormatString(400, 80, Cr, "at_timer:%d", player.at_timer);

    DrawBox(player.posX, player.posY, player.posX + PL_WIDTH - 1, player.posY + PL_HEIGHT - 1, Cr, false);
    //---------------------------------------------------------------------------------------------------------
}

// 終了処理
void PLAYER::end(void)
{

}
