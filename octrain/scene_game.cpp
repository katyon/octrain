// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "player.h"
#include "boss.h"
#include "shot.h"
#include "scene_game.h"

#include <math.h>

// インスタンス宣言 ---------------------------------------------------------------------------------
GAME game;

int GAME::timer = 0;
int GAME::spriteHND = 0;
bool GAME::zoom_mode = false;

// 関数実体 ----------------------------------------------------------------------------------------
// 初期設定
void GAME::init(void)
{
    GAME::timer = 0;
    game.state = 0;
    game.bgHND = LoadGraph("Data\\Images\\game_bg.png");
    game.spriteHND = LoadGraph("Data\\Images\\game_sprite.png");
    game.zoomHND = MakeGraph(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT);

    PLAYER::init();
    BOSS::init();
    BULLET::init();
}

// 更新処理
void GAME::update(void)
{
    switch (game.state)
    {
    case INIT:

        game.state = UPDATE;
        break;
    case UPDATE:
        PLAYER::update();
        BOSS::update();
        BULLET::update();
        // debug ------------------------------------------
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
        if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_DPAD_UP))
        {
            if (game.zoom_mode == false)
                game.zoom_mode = true;
            else
                game.zoom_mode = false;
        }
        //---------------------------------------------
        if (PLAYER::detect_reverse == true)
        {
            if (PLAYER::detect_hit == false && GAME::hitcheck_rect(PLAYER::posX + 88, PLAYER::posY + 52, 128, 248, BOSS::posX, BOSS::posY, BOSS_WIDTH, BOSS_HEIGHT) == true)
            {
                PLAYER::detect_hit = true;
                PLAYER::hp -= 50;
            }
            if (GAME::hitcheck_rect(PLAYER::posX + 88, PLAYER::posY + 52, 128 + CLOSE_RANGE, 248, BOSS::posX, BOSS::posY, BOSS_WIDTH, BOSS_HEIGHT) == true)
            {
                PLAYER::detect_closerange = true;
            }
            else
            {
                PLAYER::detect_closerange = false;
            }

        }
        else
        {
            if (PLAYER::detect_hit == false && GAME::hitcheck_rect(PLAYER::posX + 24, PLAYER::posY + 52, 128, 248, BOSS::posX, BOSS::posY, BOSS_WIDTH, BOSS_HEIGHT) == true)
            {
                PLAYER::detect_hit = true;
                PLAYER::hp -= 50;
            }
            if (GAME::hitcheck_rect(PLAYER::posX + 24 - CLOSE_RANGE, PLAYER::posY + 52, 128 + CLOSE_RANGE, 248, BOSS::posX, BOSS::posY, BOSS_WIDTH, BOSS_HEIGHT) == true)
            {
                PLAYER::detect_closerange = true;
            }
            else
            {
                PLAYER::detect_closerange = false;
            }
        }
        // 死亡時
        if (PLAYER::detect_deth == true)
        {
            game.state = NEXT;
        }
        // pose
        if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_START))
        {
            game.state = POSE;
        }

        game.timer++;
        break;
    case NEXT:
        COMMON::nextScene = SCENE_RESULT;
        break;
    case POSE:
        if (Input::GetInstance()->GetButtonDown(PL_1, XINPUT_BUTTON_START))
        {
            game.state = UPDATE;
        }
        break;
    }
}

// 描画処理
void GAME::draw(void)
{
    DrawGraph(0, 0, game.bgHND, true);

    PLAYER::draw();
    BOSS::draw();
    BULLET::draw();
    // debug-----------
    unsigned int  Cr = GetColor(200, 0, 0);
    DrawFormatString(0, 0, Cr, "タイトル(1)");
    DrawFormatString(0, 20, Cr, "ゲーム　(2)");
    DrawFormatString(0, 40, Cr, "リザルト(3)");
    DrawFormatString(0, 60, Cr, "zoom_mode(↑orZ):%d", game.zoom_mode);
    DrawFormatString(200, 0, Cr, "detect_hit:%d", PLAYER::detect_hit);
    DrawFormatString(200, 20, Cr, "detect_closerange:%d", PLAYER::detect_closerange);
    DrawFormatString(200, 40, Cr, "detect_deth:%d", PLAYER::detect_deth);


#pragma region Thumb
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
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Up))
            DrawFormatString(0, 80, Cr, "LeftThumb:Little_Up");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Right))
            DrawFormatString(0, 80, Cr, "LeftThumb:Little_Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Down))
            DrawFormatString(0, 80, Cr, "LeftThumb:Little_Down");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Left))
            DrawFormatString(0, 80, Cr, "LeftThumb:Little_Left");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Upper_Right))
            DrawFormatString(0, 80, Cr, "LeftThumb:Little_Upper_Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Lower_Right))
            DrawFormatString(0, 80, Cr, "LeftThumb:Little_Lower_Right");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Lower_Left))
            DrawFormatString(0, 80, Cr, "LeftThumb:Little_Lower_Left");
        if (Input::GetInstance()->GetLeftThumb(PL_1, THUMB::Little_Upper_Left))
            DrawFormatString(0, 80, Cr, "LeftThumb:Little_Upper_Left");
    }
    if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Not))
    {
        DrawFormatString(0, 100, Cr, "RightThumb:Not");
    }
    else
    {
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Up))
            DrawFormatString(0, 100, Cr, "RightThumb:Up");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Before_Upper_Right))
            DrawFormatString(0, 100, Cr, "RightThumb:Before_Upper_Right");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Upper_Right))
            DrawFormatString(0, 100, Cr, "RightThumb:Upper_Right");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::After_Upper_Right))
            DrawFormatString(0, 100, Cr, "RightThumb:After_Upper_Right");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Right))
            DrawFormatString(0, 100, Cr, "RightThumb:Right");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Before_Lower_Right))
            DrawFormatString(0, 100, Cr, "RightThumb:Before_Lower_Right");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Lower_Right))
            DrawFormatString(0, 100, Cr, "RightThumb:Lower_Right");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::After_Lower_Right))
            DrawFormatString(0, 100, Cr, "RightThumb:After_Lower_Right");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Down))
            DrawFormatString(0, 100, Cr, "RightThumb:Down");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Before_Lower_Left))
            DrawFormatString(0, 100, Cr, "RightThumb:Before_Lower_Left");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Lower_Left))
            DrawFormatString(0, 100, Cr, "RightThumb:Lower_Left");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::After_Lower_Left))
            DrawFormatString(0, 100, Cr, "RightThumb:After_Lower_Left");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Left))
            DrawFormatString(0, 100, Cr, "RightThumb:Left");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Before_Upper_Left))
            DrawFormatString(0, 100, Cr, "RightThumb:Before_Upper_Left");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Upper_Left))
            DrawFormatString(0, 100, Cr, "RightThumb:Upper_Left");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::After_Upper_Left))
            DrawFormatString(0, 100, Cr, "RightThumb:After_Upper_Left");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Up))
            DrawFormatString(0, 100, Cr, "RightThumb:Little_Up");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Right))
            DrawFormatString(0, 100, Cr, "RightThumb:Little_Right");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Down))
            DrawFormatString(0, 100, Cr, "RightThumb:Little_Down");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Left))
            DrawFormatString(0, 100, Cr, "RightThumb:Little_Left");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Upper_Right))
            DrawFormatString(0, 100, Cr, "RightThumb:Little_Upper_Right");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Lower_Right))
            DrawFormatString(0, 100, Cr, "RightThumb:Little_Lower_Right");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Lower_Left))
            DrawFormatString(0, 100, Cr, "RightThumb:Little_Lower_Left");
        if (Input::GetInstance()->GetRightThumb(PL_1, THUMB::Little_Upper_Left))
            DrawFormatString(0, 100, Cr, "RightThumb:Little_Upper_Left");
    }
#pragma endregion

    GetDrawScreenGraph(0, 0, GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, game.zoomHND);
    if (GAME::zoom_mode == true)
    {
        DrawRotaGraph2F(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 2, PLAYER::posX + PL_WIDTH / 2, PLAYER::posY + PL_HEIGHT / 2, 1.5, 0, game.zoomHND, false, false);
    }
    //-----------------
}

// 終了処理
void GAME::end(void)
{
    DeleteGraph(game.bgHND);
    DeleteGraph(game.spriteHND);

    PLAYER::end();
    BOSS::end();
    BULLET::end();
}

bool GAME::hitcheck_rect(float ax, float ay, int aw, int ah, float bx, float by, int bw, int bh)
{
    if (bx < (ax + aw) && ax < (bx + bw) && by < (ay + ah) && ay < (by + bh))
    {
        return true;
    }
    return false;
}


bool GAME::hitcheck_circle(float ax, float ay, int ar, float bx, float by, int br)
{
    float a = ax - bx;
    float b = ay - by;
    float c = a * a + b * b;
    c = sqrt(c);

    if (c <= ar + br)
    {
        return true;
    }
    return false;
}