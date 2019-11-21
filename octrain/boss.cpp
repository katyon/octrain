// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "boss.h"
#include "common.h"
#include "input.h"
#include "player.h"
#include "scene_game.h"

// インスタンス宣言 ---------------------------------------------------------------------------------
BOSS boss;

float BOSS::posX = 0;
float BOSS::posY = 0;
bool BOSS::detect_hit = false;
bool BOSS::detect_deth = false;
bool BOSS::detect_reverse = false;
bool BOSS::detect_damaged = false;
bool BOSS::detect_close_damaged = false;
// 関数実体 ----------------------------------------------------------------------------------------
// 初期設定
void BOSS::init(void)
{
    boss.state = 0;
    boss.state = 0;
    boss.hit_timer = 0;
    boss.damaged_timer = 0;
    boss.close_damaged_timer = 0;
    boss.at_timer = 0;
    boss.posX = GAME_SCREEN_WIDTH / 2;
    boss.posY = 0;
    boss.pivot_posX = 0;
    boss.pivot_posY = 0;
    boss.speed = 15;
    boss.hp = BOSS_HP;
    boss.sub_hp = BOSS_HP;
    boss.N_attack = 0;
    boss.SPK_attack = 0;
    boss.detect_hit = false;
    boss.detect_deth = false;
    boss.detect_attack = false;
    boss.detect_reverse = false;
    boss.detect_damaged = false;
    boss.detect_close_damaged = false;
}

// 更新処理
void BOSS::update(void)
{
    // debug------------------------
#pragma region RightThumb
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Up))
    {
        boss.posY -= boss.speed;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Before_Upper_Right))
    {
        boss.posX += boss.speed / ROOT5;
        boss.posY -= boss.speed / ROOT5 * 2;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Upper_Right))
    {
        boss.posX += boss.speed / ROOT2;
        boss.posY -= boss.speed / ROOT2;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::After_Upper_Right))
    {
        boss.posX += boss.speed / ROOT5 * 2;
        boss.posY -= boss.speed / ROOT5;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Right))
    {
        boss.posX += boss.speed;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Before_Lower_Right))
    {
        boss.posX += boss.speed / ROOT5 * 2;
        boss.posY += boss.speed / ROOT5;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Lower_Right))
    {
        boss.posX += boss.speed / ROOT2;
        boss.posY += boss.speed / ROOT2;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::After_Lower_Right))
    {
        boss.posX += boss.speed / ROOT5;
        boss.posY += boss.speed / ROOT5 * 2;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Down))
    {
        boss.posY += boss.speed;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Before_Lower_Left))
    {
        boss.posX -= boss.speed / ROOT5;
        boss.posY += boss.speed / ROOT5 * 2;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Lower_Left))
    {
        boss.posX -= boss.speed / ROOT2;
        boss.posY += boss.speed / ROOT2;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::After_Lower_Left))
    {
        boss.posX -= boss.speed / ROOT5 * 2;
        boss.posY += boss.speed / ROOT5;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Left))
    {
        boss.posX -= boss.speed;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Before_Upper_Left))
    {
        boss.posX -= boss.speed / ROOT5 * 2;
        boss.posY -= boss.speed / ROOT5;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Upper_Left))
    {
        boss.posX -= boss.speed / ROOT2;
        boss.posY -= boss.speed / ROOT2;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::After_Upper_Left))
    {
        boss.posX -= boss.speed / ROOT5;
        boss.posY -= boss.speed / ROOT5 * 2;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Up))
    {
        boss.posY -= boss.speed / 3;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Right))
    {
        boss.posX += boss.speed / 3;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Down))
    {
        boss.posY += boss.speed / 3;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Left))
    {
        boss.posX -= boss.speed / 3;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Upper_Right))
    {
        boss.posX += boss.speed / ROOT2 / 3;
        boss.posY -= boss.speed / ROOT2 / 3;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Lower_Right))
    {
        boss.posX += boss.speed / ROOT2 / 3;
        boss.posY += boss.speed / ROOT2 / 3;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Lower_Left))
    {
        boss.posX -= boss.speed / ROOT2 / 3;
        boss.posY += boss.speed / ROOT2 / 3;
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Upper_Left))
    {
        boss.posX -= boss.speed / ROOT2 / 3;
        boss.posY -= boss.speed / ROOT2 / 3;
    }
#pragma endregion

    // 遠距離攻撃
    if (CheckHitKey(KEY_INPUT_X))
    {
        boss.detect_damaged = true;
    }
    if (boss.detect_damaged == true)
    {
        boss.damaged_timer++;
        if (boss.damaged_timer > 60)
        {
            boss.damaged_timer = 0;
            boss.detect_damaged = false;
        }
    }
    // 近距離攻撃
    if (CheckHitKey(KEY_INPUT_Z))
    {
        boss.detect_close_damaged = true;
    }
    if (boss.detect_close_damaged == true)
    {
        boss.close_damaged_timer++;
        if (boss.close_damaged_timer > 60)
        {
            boss.close_damaged_timer = 0;
            boss.detect_close_damaged = false;
        }
    }
    //------------------------------
    // 移動制限
    if (boss.posX < 0)
    {
        boss.posX = 0;
    }
    if (boss.posX > GAME_SCREEN_WIDTH - BOSS_WIDTH)
    {
        boss.posX = GAME_SCREEN_WIDTH - BOSS_WIDTH;
    }
    if (boss.posY < 0)
    {
        boss.posY = 0;
    }
    if (boss.posY > GAME_SCREEN_HEIGHT - BOSS_HEIGHT)
    {
        boss.posY = GAME_SCREEN_HEIGHT - BOSS_HEIGHT;
    }

    // hp
    if (boss.detect_hit == true)
    {
        boss.hp -= 50;
    }

    if (BOSS::posX < PLAYER::posX)
    {
        boss.detect_reverse = true;
    }
    else
    {
        boss.detect_reverse = false;
    }

    // N_attack
    switch (boss.N_attack)
    {
    case N_Diffusion:
        break;
    case N_Homing:
        break;
    case N_Column:
        break;
    }
    // SPK
    switch (boss.SPK_attack)
    {
    case SPK_1:
        break;
    case SPK_2:
        break;
    case SPK_3:
        break;
    }
}

// 描画処理
void BOSS::draw(void)
{
    if (boss.detect_reverse == true)
    {
        DrawRectGraphF(boss.posX, boss.posY, 1416 + BOSS_WIDTH * (GAME::timer / 7 % 4), 0, BOSS_WIDTH, BOSS_HEIGHT, GAME::spriteHND, true, true, false);
    }
    else
    {
        DrawRectGraphF(boss.posX, boss.posY, 1416 + BOSS_WIDTH * (GAME::timer / 7 % 4), 0, BOSS_WIDTH, BOSS_HEIGHT, GAME::spriteHND, true, false, false);
    }
    DrawRectGraph(GAME_SCREEN_WIDTH / 2, 0, 2088, 64, BOSS_HP, 64, GAME::spriteHND, true, false, false);
    DrawRectGraph(GAME_SCREEN_WIDTH / 2 + BOSS_HP - boss.hp, 0, 2088, 0, boss.hp, 64, GAME::spriteHND, true, false, false);
    //debug-----
    unsigned int  Cr = GetColor(200, 0, 0);
    DrawFormatString(200, 60, Cr, "boss.detect_damaged:%d", boss.detect_damaged);
    DrawFormatString(200, 80, Cr, "boss.detect_close_damaged:%d", boss.detect_close_damaged);

    DrawBox(boss.posX, boss.posY, boss.posX + BOSS_WIDTH, boss.posY + BOSS_HEIGHT, GetColor(0, 200, 0), false);
    //--------
}

// 終了処理
void BOSS::end(void)
{

}

